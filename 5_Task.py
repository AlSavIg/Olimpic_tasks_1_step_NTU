def resh2(n, start=2):
    if(n == 1):
        return 1
    else:
        resultate = 0
        i = 1
        while i*i <= n:
            if n % i == 0:
                div2 = n//i
                if i > 1 and i >= start:
                    resultate += resh2(n // i, i + 1)
                if div2 > 1 and div2 != i and div2 >= start:
                    resultate += resh2(n // div2, div2 + 1)
            i = i + 1
        return resultate


n = int(input())
print(resh2(n))
