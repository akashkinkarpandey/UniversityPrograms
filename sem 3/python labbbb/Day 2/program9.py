a=(int)(input("Enter a number "))
t=a
s=0
while t>0:
    d=t%10
    s=s+(d*d*d)
    t=t//10
if s==a:
    print("Number is Armstrong")
else :
    print("Number is not Armstrong")
