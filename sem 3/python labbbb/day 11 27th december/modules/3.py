# Python program to display calendar of given month of the year
try:
    import calendar
    y=int(input("Enter a year "))
    m=int(input("Enter a month "))
    if(y<0 or m<=0 or m>12):
        raise Exception
    # display the calendar
    print(calendar.month(y, m))
except:
    print("Invalid input given ")