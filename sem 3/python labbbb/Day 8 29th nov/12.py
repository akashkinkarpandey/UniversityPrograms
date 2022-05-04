n=int(input("Enter number of students "))
dict={}
newdict={}
Sum=0
maxi= -2147483648
name=""
for i in range(n):
    x=input("Enter student name ")
    print(f"Enter marks of {x}")
    l=list(map(int,input().split()))
    Sum=sum(l)
    if(Sum>maxi):
        maxi=Sum
        name=x
    dict[x]=l
    newdict[x]=Sum
print(f"New Dictionary is {newdict}")
print(f"Topper is {name} ,highest total marks is {maxi}")

