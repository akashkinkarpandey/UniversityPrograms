def prime(n):
    c=0
    if(n<=1):#1st point of elimination
        return 0
    for i in range(2,n):
        if(n%i==0):#2nd point of elimination
            return 0
    return 1
#take input
n=int(input("Enter a number "))
if(prime(n)==1):
    print(f"{n} is prime ")
else:
    print(f"{n} is not prime ")

