list=[]
while True:
    x=int(input("Enter integer element of list ,press -1 to exit "))
    if(x==-1):
        break
    list.append(x)
list.sort()
print(list)