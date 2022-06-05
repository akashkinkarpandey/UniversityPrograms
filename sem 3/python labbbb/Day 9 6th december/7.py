#Simple Interest is principal*rate*time
try:
    age=int(input("enter age "))
    principal=int(input("Enter principal amount "))
    rate=0.0
    if(age>=60):
        rate=0.12
    elif(age>=0 and age<60):
        rate=0.10
    else:
        raise Exception
    t=int(input("Enter  number of years "))
    interest=(principal*rate*t)
    print("Interest is",interest)
except:
    print("Wrong inputs given ")



