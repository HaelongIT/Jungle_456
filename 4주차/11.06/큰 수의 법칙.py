N, M, K = map(int, input().split())
data = list(map(int, input().split()))

# N : data의 갯수
# M : 총 더할 횟수
# K : 한개의 요소 최대 가능 횟수

# print(N, M, K)
# print(data)

cnt = 0
ans = 0
# for _ in range(M):

# while cnt <= M:
#     for _ in range(K):
#         ans += max(data)


# cnt로 횟수를 세고
# 리스트를 솔트하고 최댓값을 pop해서 그걸 횟수 이내로 ans에 더하기

data.sort()
# print(data)
# print(data.pop())
        
for _ in range(M):
    if cnt == M:
        break
    if len(data) == 0:
        break
    A = data.pop()

    for _ in range(K):
        if cnt == M:
            break

        ans += A
        cnt += 1

    # if cnt == M:
    #     break
    # ans += max(data)
    # cnt += 1
# 한 개의 요소를 총 K번만 더할 수 있게 무언가 필요

print(ans)