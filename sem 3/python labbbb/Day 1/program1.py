a=int(input("Enter a number "))
b=int(input("Enter a number "))

#Mathematical Operators

pdt=a*b
diff=a-b
sum=a+b
div=a/b

print("Sum is ",sum)
print("Difference is ",diff)
print("Product is ",pdt)
print("Quotient is ",div)

#Logical Operators

if a>0 and b>0:
    print("The numbers are greater than 0")
elif ((a>0 and b<0) or (a<0 and b>0)):
    print("Atleast one number is  greater than 0")
else:
    print("Neither of numbers is greater than zero")
    
#Bitwise Operators

print("Bitwise and of 2 numbers is ",a&b)
print("Bitwise or of 2 numbers is ",a|b)
print("Bitwise xor of 2 numbers is ",a^b)

