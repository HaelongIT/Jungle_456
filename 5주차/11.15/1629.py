A, B, C = map(int, input().split())

# 제곱을 해도 결국 일정 범위에서 돌고돈다 -> 추측상 4사이클로 도는듯?
# 그럼 4사이클만 저장하고 이후에는 사이클에 맞게 출력만 해주면 되지 않을까?

data = []

for i in range(1,5):
    temp = (A**i)%C
    data.append(temp)

