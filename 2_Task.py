from math import ceil


N = int(input())
h = list(map(int, input().split()))
i = 1

while i < N:
    if h[i] > h[i - 1]:
        average_more = ceil((h[i] + h[i-1]) / 2)
        average_less = int((h[i] + h[i-1]) / 2)
        h[i - 1] = average_more
        h[i] = average_less
        i = 1
    else:
        i += 1
print(*h)
