#function calculates maximum
def max_func(a,b):
    if a>b:
        return a
    else:
        return b

a=int(input("Enter a number "))
b=int(input("Enter a number "))
c=int(input("Enter a number "))
print("Maximum number is",max_func(max_func(a,b),c))