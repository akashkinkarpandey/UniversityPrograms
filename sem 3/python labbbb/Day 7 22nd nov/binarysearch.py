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


    