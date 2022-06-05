c=1
sum=0
count=0
maxi=-2147483648
mini=2147483647
while(c):
    try:
        x=input("Enter ")
        if(x=='done'):
            print("Sum is",sum)
            print("Count is",count)
            if count!=0:
                print("Average is",sum/count)
                print("Maximum is",maxi)
                print("Minimum is",mini)
            else:
                print("Average is",0)
                print("No Max found")
                print("No Min found")
            break
        elif (x.isnumeric()==1):
            sum=sum+(int)(x)
            maxi=max(maxi,int(x))
            mini=min(mini,int(x))
            count=count+1
        else: raise Exception
    except:
        print("Exception occured")
    







