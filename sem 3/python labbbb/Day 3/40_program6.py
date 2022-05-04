c = 1
sum = 0
count = 0
while(c):
    try:
        x = input("Enter ")
        if(x == 'done'):
            print("Sum is", sum)
            print("Count is", count)
            if count != 0:
                print("Average is", sum/count)
            else:
                print("Average is", 0)
            break
        elif (x.isnumeric()==1):
            sum = sum+(int)(x)
            count = count+1
        else: flag=1
    except:
        if flag==1:
            print("Exception occured ")