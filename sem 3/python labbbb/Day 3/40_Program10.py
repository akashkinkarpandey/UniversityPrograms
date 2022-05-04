try:
    x=int(input("Enter a number "))
    if(x<0):
        raise Exception("Sorry, no numbers below zero")
    else:
        print("Square is ",x*x)
except:
    print("You should have entered a number")



