T = int(input())

def primenumber(N):
    for i in range(2, N):
        if N % i == 0:
            return False
        return True

def gold(k):
    for i in range(int(K/2), 1, -1):
        if primenumber(i) == True:
            # print(i)
            print(i, K-i)
            return

for _ in range(T):
    K = int(input())
    gold(K)