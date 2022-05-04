try:
    hr=(int)(input("Enter hours worked "))
    rate=(int)(input("Enter rate per hour "))
    given=0.0
    if hr>40:
        t=hr-40
        given+=(t*1.5*rate)
        given+=(hr*rate)
    else:
        given+=(hr*rate)
    print("PAY IS ",given)
except:
    print("Enter Numberic Type")
    exit()
