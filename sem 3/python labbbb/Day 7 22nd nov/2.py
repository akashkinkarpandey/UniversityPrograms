#for copying an array by value
print("Enter 1 for linear search")
print("Enter 2 for binary search")
n1 = int(input("Enter choice "))
if(n1 == 1):
    print("Enter list elements of integer type")
    l = tuple(list(map(int, input().split())))
    n = int(input("Enter number you want to search "))
    fl = -1
    for index, item in enumerate(l):
        if item == n:
            fl = index
            break
    if fl == -1:
        print(f"Number {n} not found")
    else:
        print(f"Number {n} found at {fl} index ")
elif(n1 == 2):
    from copy import deepcopy
    print("Enter list elements of integer type")
    a=(list(map(int,input().split())))
    copy=deepcopy(a)
    n=int(input("Enter number you want to search "))
    a.sort()
    fl=-1
    l=0
    h=len(a)-1
    while l<=h:
        mid=((l+h)>>1)
        if(a[mid]==n):
            fl=mid
            break
        elif(a[mid]>n):
            h=mid-1
        elif(a[mid]<n):
            l=mid+1

    if fl==-1:
        print("Number not found ")
    else:
        i=copy.index(a[fl])
        print(f"Number {n} found at index {i} of original list ")


    
else:
    print("Wrong choice ")
    


