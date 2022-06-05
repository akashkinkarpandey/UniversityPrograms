l=[1,2]
c=5
def f():
    print(c)
    # global c
    # c=c+2
    # print(c)
    l.append(3)
    print(l)
f()
# print(c)