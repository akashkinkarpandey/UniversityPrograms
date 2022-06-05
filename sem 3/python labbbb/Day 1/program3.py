x=int(input("Enter real part of 1st number "))
y=int(input("Enter imaginary part of 1st number "))
z=complex(x,y)
a=int(input("Enter real part of 2nd number "))
b=int(input("Enter imaginary part of 2nd number "))
c=complex(a,b)
print("The 2 numbers are")
print(z)
print(c)
d=z+c
e=z-c
f=z*c
g=z/c
print("Sum is ",end="")
print(d)
print("Difference is ",end="")
print(e)
print("Product is ",end="")
print(f)
print("Division is ",end="")
print(g)