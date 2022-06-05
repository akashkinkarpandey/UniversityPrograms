try:
    import calendar
    n=int(input("Enter a number "))
    if(n<0):
        raise Exception
    # using calendar to print calendar of year
    print (f"The calendar of year {n} is : ")
    print (calendar.calendar(n))
except:
    print("Invalid year entered ")