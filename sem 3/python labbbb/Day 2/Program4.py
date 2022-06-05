b=(input("Enter C for Celsius or F for Fahrenheit "))
a=(int)(input("Enter a Temperature "))
t=0
if b=='C':
    t=((9*a)/5 +32)
    print("In Fahrenheit temperature is ",t)
elif b=='F':
    t=5*(a-32)/9
    print("In Celsius temperature is ",t)
else :
    print('Wrong choice entered') 

