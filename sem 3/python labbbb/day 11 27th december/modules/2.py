try:
    import calendar
    def check(n):
        if(n<0):
            raise Exception
        if((n%4==0 and n%100!=0) or (n%400==0)):
            return 1
        else:
            return 0
    print("Enter range of year from ... to ...")
    x=int(input("First input "))
    y=int(input("Second input "))
    c=0
    for i in range(x,y+1,1):
        if(check(i)):
            c=c+1
            print(f"year {i} is Leap")
        else: print(f"year {i} is not leap ")
    print(f"Total {c} leap years ")
except:
    print("Invalid input given")
