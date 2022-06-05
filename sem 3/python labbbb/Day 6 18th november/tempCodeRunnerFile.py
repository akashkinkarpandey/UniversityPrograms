l1=[]
l2=[]
while True:
    x=input("Enter element of list 1 1,press -1 to exit ")
    if(x=="-1"):
        break
    l1.append(x)

while True:
    x=input("Enter element of list 2,press -1 to exit ")
    if(x=="-1"):
        break
    l2.append(x)
fl=0
if(len(l1)!=len(l2)):
    print("Not same list")
else:
    for i in range(len(l1)):
        if(l1[i]!=l2[i]):
            fl=1
            break
if fl==0:
    print("Same List")
else:
     print("Not same list")