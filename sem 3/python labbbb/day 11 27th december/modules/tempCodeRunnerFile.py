# Python program to display calendar of given month of the year
try:
    import calendar
    y=int(input("Enter a number "))
    m=int(input("Enter a number "))
    if(y<0 or m<0):
        raise Exception
    # display the calendar
    print(calendar.month(y, m))
except:
    print("Invalid year entered ")