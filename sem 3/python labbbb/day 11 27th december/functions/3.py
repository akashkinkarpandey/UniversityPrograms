try:
    def add(a,b):
        return a+b
    def multiply(a,b):
        return a*b
    def subtract(a,b):
        return a-b
    def divide(a,b):
        return a/b
    def exponentiation(a,b):
        return a**b
    x=input("Enter operator which may be *,/,-,+,^  ")     
    a=int(input("Enter number "))
    b=int(input("Enter number "))     
    if(x=="*"):
        print(multiply(a,b))
    elif(x=="+"):
        print(add(a,b))
    elif(x=="-"):
        print(subtract(a,b))
    elif(x=="/"):
        print(divide(a,b))
    elif(x=="^"):
        print(exponentiation(a,b))
except:
    print("Wrong Inputs ")
