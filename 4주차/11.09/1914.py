import sys

N = int(sys.stdin.readline())

def hanoi(n, start, end):
    mid = 6-start-end
    if n == 1:
        print(start, end)
        return
    else:
        hanoi(n-1, start, mid)
        print(start, end)
        hanoi(n-1, mid, end)

# if N > 20:
#     sys.exit(0)

print(2**N - 1)

if N > 20:
    sys.exit(0)
hanoi(N, 1, 3)