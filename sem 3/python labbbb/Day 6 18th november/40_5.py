list=[]
list1=[1,2,3]
list2=[-1,-3,-2]
list.append(list1)
list.append(list2)
print(list)

a=[]
while(1):
    b=[]
    choice=input("enter choice yes or no ")
    if(choice=="no"):
        break
    while(1):
        x=int(input("enter a number,enter -1 to exit "))
        if(x==-1):
            break
        b.append(x)
    a.append(b)

print(a)
