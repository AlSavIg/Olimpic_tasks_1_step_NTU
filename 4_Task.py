import math


def F(d, b, t, V):
    return math.ceil(t * (b - d) / V)


d, b, t, p = map(int, input().split())
q_max = math.ceil(t * (b - d) / (p * d))
left, right = 0, d * p + 1

while right - left > 1:
    average = (left + right) // 2
    if F(d, b, t, average) > q_max:
        left = average
    else:
        right = average

print(right)
