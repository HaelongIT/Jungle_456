# 1. 솔루션 팁
# 2-1. 해결전략
# 2-2. 구현

import sys

N = int(sys.stdin.readline())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(N)] 
     
cnt_w = 0
cnt_b = 0

# print(arr)
def sol(r, c, N):

    global cnt_b
    global cnt_w

    first = arr[r][c]
    for j in range(r, r+N):
        for k in range(c, c+N):
            if first != arr[j][k]:
                sol(r, c, N//2)
                sol(r, c+N//2, N//2)
                sol(r+N//2, c, N//2)
                sol(r+N//2, c+N//2, N//2)
                return

    if first == 0:
        cnt_w += 1
    elif first == 1:
        cnt_b += 1

sol(0,0,N)
print(cnt_w)
print(cnt_b)