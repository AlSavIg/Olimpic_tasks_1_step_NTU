
# # def solve(n, start = 2):
# #     if n == 1:
# #         return 1
# #     else:
# #         result = 0
# #         for i in range(start, n+1):
# #             if n % i == 0:
# #                 if n == 48: print (i)
# #                 result += solve(n // i, i +1)
# #         return result

# def getdiv(n):
#     l = []
#     i = 1
#     while i*i <= n:
#         if n%i == 0:
#             div2 = n//i
#             if i > 1: l.append(i)
#             if div2 > 1 and div2 != i: l.append(div2)
#         i = i + 1
#     return l


# def solve2(n, start = 2):
#     if n == 1:
#         return 1
#     else:
#         result = 0
#         i = 1
#         for i in getdiv(n):
#             result += solve2(n // i, i+1)
#         return result

# n = int(input())
# print(solve2(n))

import math

def F(d, b, t, V):
  return math.ceil(t * (b - d) / V)

d, b, t, p = map(int, input().split())
q_max = math.ceil(t * (b - d) / (p * d))
left, right = 0, d * p + 1

while right - left > 1:
    middle = (left + right) // 2
    if F(d, b, t, middle) > q_max:
        left = middle
    else :
        right = middle

print(right)