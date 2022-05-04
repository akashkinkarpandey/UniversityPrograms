a=(int)(input("Enter a number "))
b=(int)(input("Enter a number "))
c=(int)(input("Enter a number "))
e=0
if a>b:
    e=a
if e>c:
    print(e,"is maximum")
else:
    print(c,"is maximum")

if a<b:
    e=a
if e<c:
    print(e,"is minimum")
else:
    print(c,"is minimum")
