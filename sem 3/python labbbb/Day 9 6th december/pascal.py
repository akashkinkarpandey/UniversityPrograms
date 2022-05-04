n=int(input("Enter number of rows "))
print("Pascals triangle is ")
l=[]
for i in range(n):
    l1=[]
    l1.append(1)
    for j in range(1,i):
        l1.append(l[i-1][j-1]+l[i-1][j])
    if(i!=0):
        l1.append(1)
    l.append(l1)
space=n-1
for i in range(len(l)):
    for j in range(space):
        print(end=" ")
    for j in range(len(l[i])):
        print(l[i][j],end=" ")
    space=space-1
    print()
