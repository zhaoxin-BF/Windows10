def fact(n):
    if(n==1):
        return n
    else:
        return n*fact(n-1)
print(fact(3))

def vs(s):
    if s == "":
        return s
    else:
        return s[-1] + vs(s[:-1])
print(vs("123456"))
    
