def functionnnnns(s):
    if (len(s) <= p):
        return("YES")
    else:
        tr = 1
        for k in range(p):
            s0 = s[k::p].replace("?", "")
            if (len(s0) > 1):
                if (len(s0.replace(s0[0], "")) == 0):
                    tr = 1
                else:
                    return ("NO")
            else:
                tr = 1
        if (tr == 1):
            return("YES")
        else:
            return ("NO")


n, p = map(int, input().split(' '))


for i in range(n):
    s = input()
    print(functionnnnns(s))
