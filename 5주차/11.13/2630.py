N = int(input())

arr = [[] for _ in range(N)] 

for i in range(N):    
	arr[i] = list(map(int, input().split()))
	
# print(arr)
def sol(r, c, N):
    cnt = 0

    for j in range(N):
        for k in range(N):
            first = arr[r][c]
            # print(arr[j][k])
            if first != arr[j][k]:
                sol(0,0, N//2)
                sol(0, N//2, N//2)
                sol(N//2, 0, N//2)
                sol(N//2, N//2, N//2)
            else:
                cnt += 1
                return
        

sol(0,0,N)