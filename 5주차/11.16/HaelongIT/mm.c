#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "mm.h"
#include "memlib.h"

team_t team = {
    /* Team name */
    "2",
    /* First member's full name */
    "Son Yongjae",

    /* First member's email address */
    "soja0529@gmail.com",
    
    /* Second member's full name (leave blank if none) */
    "",
    /* Second member's email address (leave blank if none) */
    ""};

#define ALIGNMENT 8
// 할당하는 기준이 더블워드(8byte)

#define ALIGN(size) (((size) + (ALIGNMENT - 1)) & ~0x7)
// 사이즈를 8의 배수로 맞춰주기 위한 부분
// 8보다 작으면 8으로 맞추고, 크면 8의 배수로 맞춘다

#define SIZE_T_SIZE (ALIGN(sizeof(size_t)))
// size_t의 크기가 8보다 작아서 8로 정렬됨
//--------------------------------------------------------
#define WSIZE 4
// 워드의 크기는 4바이트 

#define DSIZE 8
// 더블워드의 크기는 8바이트 

#define CHUNKSIZE (1 << 12)
// 청크사이즈는 힙 확장 기본크기

// --------------------매크로-------------------
#define MAX(x, y) ((x) > (y) ? (x) : (y))
// 크기 비교

#define PACK(size, alloc) ((size) | (alloc))
// 헤더와 푸터에 저장할 값 : 사이즈와 할당비트를 결합함

#define GET(p) (*(unsigned int *)(p))
// p가 참조하는 워드 반환

#define PUT(p, val) (*(unsigned int *)(p) = (val))
// p가 가리키는 곳에 val 저장

#define GET_SIZE(p) (GET(p) & ~0x7)
// 사이즈를 만들 때 뒤에 3비트를 날려보내기

#define GET_ALLOC(p) (GET(p) & 0x1)
// 할당 했음

#define HDRP(bp) ((char *)(bp)-WSIZE)
// 헤더 찾기

#define FTRP(bp) ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)
// 푸터 찾기

#define NEXT_BLKP(bp) ((char *)(bp) + GET_SIZE(((char *)(bp)-WSIZE)))
// 다음 블록 포인터 찾기

#define PREV_BLKP(bp) ((char *)(bp)-GET_SIZE(((char *)(bp)-DSIZE)))
// 이전 블록의 포인터 찾기
//--------------------------------------------------------
static void *extend_heap(size_t);
static void *coalesce(void *);
static void *find_fit(size_t);
static void place(void *, size_t);
static void *heap_listp;

// 힙을 생성하는 함수
int mm_init(void) {
    if ((heap_listp = mem_sbrk(4 * WSIZE)) == (void *)-1) {
    // 4워드 사이즈만큼 힙을 증가시켰는데 실패(-1반환) 했을 경우
        return -1;
        // -1을 반환한다
    }

    PUT(heap_listp, 0);
    // 정렬패딩 넣기
    PUT(heap_listp + (1 * WSIZE), PACK(DSIZE, 1));
    // 프롤로그 헤더 : PACK(DSIZE, 1)을 넣는다
    PUT(heap_listp + (2 * WSIZE), PACK(DSIZE, 1));
    // 프롤로그 푸터 : PACK(DSIZE, 1)을 넣는다
    PUT(heap_listp + (3 * WSIZE), PACK(0, 1));
    // 에필로그 헤더 : PACK(0, 1)을 넣는다

    heap_listp += (2 * WSIZE);
    // 에필로그 헤더 뒤로 이동
    if (extend_heap(CHUNKSIZE / WSIZE) == NULL)
    // extend_heap으로 청크사이즈(블록단위로 변경)만큼 추가
    // 만약 NULL이 반환(extend_heap이 실패)
        return -1;
    return 0;
    // 성공하면 0 반환
}

// 가용블럭에 할당하기
void *mm_malloc(size_t size) {
    size_t asize;
    // 조정된 블록 사이즈

    size_t extendsize;
    // 확장할 사이즈

    char *bp;
    // 블록 포인터

    if (size == 0)
    // size를 0으로 할당해달라는 건 잘못된 요청임
        return NULL;

    // 사이즈 조정
    if(size <= DSIZE)
        asize = 2 * DSIZE;
        // size가 기준 사이즈인 더블워드보다 작으면 조정
        // 최소 블록 크기는 16바이트(헤더 4 + 푸터 4 + 저장공간 8)
    else
        asize = DSIZE * ((size + (DSIZE) + (DSIZE - 1)) / DSIZE);
        // 나머지는 무조건 8의 배수로 올림처리함

    if ((bp = find_fit(asize)) != NULL) {
    // 가용블럭을 찾아서 쓸만한게 있다면
        place(bp, asize);
        // 할당한다
        return bp;
        // 새로 할당된 블록의 포인터를 리턴한다
    }

    // 적합한 가용블럭을 못찾았다면
    extendsize = MAX(asize, CHUNKSIZE);
    // 조정된 사이즈와 힙 확장 기본크기를 비교해서 큰것을 고르고

    if ((bp = extend_heap(extendsize / WSIZE)) == NULL)
    // 고른 크기만큼 늘리고, 실패했으면(NULL 반환)
        return NULL;
        // NULL을 반환
    
    // 늘린것을 성공했으면
    place(bp, asize);
    // 가용블럭을 할당한다
    return bp;
    // 블록 포인터를 리턴한다
}

// 가용블럭 반환하기
void mm_free(void *bp) {
    size_t size = GET_SIZE(HDRP(bp));
    // 헤더로 이동해서 사이즈를 구하고 size에 초기화

    PUT(HDRP(bp), PACK(size, 0));
    // 헤더에 할당을 취소(0)시키고
    PUT(FTRP(bp), PACK(size, 0));
    // 푸터도 할당을 취소(0)시킨다
    coalesce(bp);
    // 병합한다
}

// 재할당하기
void *mm_realloc(void *ptr, size_t size) {
// 매개변수로 '기존 메모리 블록 포인터'와 '변경될 크기'를 넣음

    if (size <= 0)
    {
    // 재할당 사이즈가 0이면
        mm_free(ptr);
        // 반환시키고
        return 0;
        // 0을 리턴
    }
    if (ptr == NULL) {
    // 기존 할당받은 메모리 블록이 없으면
        return mm_malloc(size);
        // malloc으로 메모리 할당받고 반환
    }

    // 재할당 사이즈0이 아니고, 동시에 기존 할당받은 메모리 블록 있으면
    
    void *newp = mm_malloc(size);
    // 가용블록 할당 받아서 포인터에 초기화 

    if (newp == NULL) {
    // 할당을 실패한 경우
        return 0;
        // 0을 리턴한다
    }

    // 데이터 복사하기

    size_t oldsize = GET_SIZE(HDRP(ptr));
    // 기존 블럭의 사이즈를 oldsize에 초기화

    if (size < oldsize) {
    // 기존 블럭의 사이즈가 새 블럭 사이즈보다 크면
        oldsize = size;
        // 기존 블럭 사이즈보다 작은 블럭 사이즈로 재할당하면
        // 일부 데이터만 복사된다(짤려서 복사됨)
    }
    memcpy(newp, ptr, oldsize);
    // 새로 할당한 블럭으로 기존 블럭의 데이터를 oldsize만큼 복사

    mm_free(ptr);
    // 복사가 끝나서 기존 블럭은 반환

    return newp;
    // 새로 할당받은 가용블럭의 포인터 반환
}

// 힙 확장하기
static void *extend_heap(size_t words) {
    char *bp;
    // 블록 포인터
    size_t size;
    // 확장할 크기(더블워드로 정렬을 유지)

    size = (words % 2) ? (words + 1) * WSIZE : words * WSIZE;
    // words를 받아서 더블워드로 정렬을 유지시킴

    if ((long)(bp = mem_sbrk(size)) == -1)
    // size만큼 힙을 늘리고 long으로 캐스팅해서 bp에 초기화했는데,
    // 실패했을 때는
        return NULL;
        // NULL을 반환

    // 힙 확장이 성공했을 때는
    PUT(HDRP(bp), PACK(size, 0));
    // 헤드를 확장한 블록의 크기랑 미할당이라고 넣음

    PUT(FTRP(bp), PACK(size, 0));
    // 푸터에 확장한 블록의 크기랑 미할당이라고 넣음

    PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));
    // 에필로그 블록 헤더에 (0, 1)을 넣음

    return coalesce(bp);
    // 병합 후 coalesce 함수에서 반환된 블록 포인터 반환
}

// 병합하기
static void *coalesce(void *bp){
    size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));
    // 이전 블록 할당 상태 확인

    size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
    // 다음 블록 할당 상태 확인

    size_t size = GET_SIZE(HDRP(bp));
    // size에 현재 블록 사이즈 초기화

    if (prev_alloc && next_alloc)
    { /* Case 1 : 모두 할당된 경우 */
        return bp;
        // 할당하게 없어서 bp를 리턴
    }

    else if (prev_alloc && !next_alloc)
    { /* Case 2 : 다음 블록만 빈 경우 */
        size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
        // size : 현재블록 사이즈 + 다음 블록 사이즈

        PUT(HDRP(bp), PACK(size, 0));
        // 현재 블록 헤더 재설정(새로운 size로)

        PUT(FTRP(bp), PACK(size, 0));
        // 다음 블록 푸터 재설정(새로운 size로)
        // (PUT(HDRP(bp), PACK(size, 0))에서 헤더를 재설정해서
        // 다음 블록 푸터로 넘어갈 수 있음)
    }

    else if (!prev_alloc && next_alloc)
    { /* Case 3 : 이전 블록만 빈 경우 */
        size += GET_SIZE(HDRP(PREV_BLKP(bp)));
        // size : 현재블록 사이즈 + 이전 블록 사이즈
        PUT(FTRP(bp), PACK(size, 0));
        // 이전 블록 헤더 재설정(새로운 size로)

        PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
        // 현재 블록 푸터 재설정(새로운 size로)

        bp = PREV_BLKP(bp);
        // 이전 블록의 시작점으로 블록포인터 이동
        // (이전 블록이랑 병합해서 bp를 옮겨야 함)
    }

    else
    { /* Case 4 : 이전 블록과 다음 블록 모두 빈 경우 */
        size += GET_SIZE(HDRP(PREV_BLKP(bp))) + GET_SIZE(FTRP(NEXT_BLKP(bp)));
        // size : 현재블록 사이즈 + 이전 블록 사이즈 + 다음 블록 사이즈
        
        PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
        // 이전 블록 헤더 재설정(새로운 size로)

        PUT(FTRP(NEXT_BLKP(bp)), PACK(size, 0));
        // 다음 블록 푸터 재설정(새로운 size로)
        // (PUT(HDRP(bp), PACK(size, 0))에서 헤더를 재설정해서
        // 다음 블록 푸터로 넘어갈 수 있음)

        bp = PREV_BLKP(bp);
        // 이전 블록의 시작점으로 블록포인터 이동
        // (이전 블록이랑 병합해서 bp를 옮겨야 함)
    }
    return bp;
    // 병합된 블록의 포인터를 반환
}

// 가용 블록 검색
static void *find_fit(size_t asize){

    void *bp;

    for (bp = heap_listp; GET_SIZE(HDRP(bp)) > 0; bp = NEXT_BLKP(bp)) {
    // bp는 heap_listp로 초기화해서
    // 첫번째 블록(주소: 힙의 첫 부분 + 8bytes)부터 탐색 시작

    // 계속해서 다음 블록 포인터로 이동

    // 마지막에 에필로그 블록을 만나면 GET_SIZE하면 0이 돼서
    // 마지막까지 탐색하고 멈춘다

        if (!GET_ALLOC(HDRP(bp)) && (asize <= GET_SIZE(HDRP(bp)))) {
        // 가용 상태이면서 동시에 사이즈가 적합하다면(찾던 가용블럭)
            return bp;
            // 해당 블록 포인터를 리턴함
        }
    }

    return NULL;
    // 못찾았으면 NULL 반환
}

// 할당하기
static void place(void *bp, size_t asize) {

    size_t csize = GET_SIZE(HDRP(bp));
    // csize에 현재 블록의 크기를 초기화

    if ((csize - asize) >= (2 * DSIZE)) {
    // 만약 현재 블록 크기와 내가 할당해야할 블록의 크기의 차이가
    // 최소 블록크기(16)보다 크거나 같다면(분할해야 함)

    // 최소 블록 크기 16바이트 할당 (헤더 4 + 푸터 4 + 저장공간 8)

        PUT(HDRP(bp), PACK(asize, 1));
        // 현재 블록 헤더에 할당할 크기만큼 재설정
        PUT(FTRP(bp), PACK(asize, 1));
        // 푸터 재설정

        bp = NEXT_BLKP(bp);
        // 블록 포인터 다음 블록으로 이동

        PUT(HDRP(bp), PACK(csize - asize, 0));
        // 남은 크기를 다음 블록 헤더에 재설정
        PUT(FTRP(bp), PACK(csize - asize, 0));
        // 남은 크기를 다음 블록 푸터에 재설정
    }
    else {
    // 만약 현재 블록 크기와 내가 할당해야할 블록의 크기의 차이가
    // 최소 블록크기(16)보다 작다면(분할할 필요가 없음)
        PUT(HDRP(bp), PACK(csize, 1));
        PUT(FTRP(bp), PACK(csize, 1));
    }
}