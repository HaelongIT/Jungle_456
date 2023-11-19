N = int(input())

arr = [[] for _ in range(N)] 

for i in range(N):
    arr[i] = list(map(int, input().split()))
     
cnt_w = 0
cnt_b = 0
	
# print(arr)
def sol(r, c, N):
    # global cnt_w
    # global cnt_b

    # for j in range(N):
    #     for k in range(N):
    #         first = arr[r][c]
    #         # print(arr[j][k])
    #         if first != arr[j][k]:
    #             sol(0,0, N//2)
    #             sol(0, N//2, N//2)
    #             sol(N//2, 0, N//2)
    #             sol(N//2, N//2, N//2)
    #         else:
    #             cnt += 1
    #             return


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

    if first == 0:
        cnt_w += 1
    elif first == 1:
        cnt_b += 1

sol(0,0,N)
print(cnt_w)
print(cnt_b)