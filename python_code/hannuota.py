#汉诺塔问题
def han(n):
    count = 0
    if n == 1:
        count =1
    else:
        count=2*han(n-1)+1
    return count

print(han(10))

count = 0
def hanoi(n,src,dst,mid):
    global count
    if n == 1:
        print("{}:{}->{}".format(1,src,dst))
        count +=1
    else:
        hanoi(n-1,src,mid,dst)
        print("{}:{}->{}".format(n,src,dst))
        count +=1
        hanoi(n-1,mid,dst,src)

hanoi(10,"A","C","B")
print(count)
