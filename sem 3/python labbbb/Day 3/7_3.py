x = input("Enter a number and keep on entering and when you are done TYPE `done` : ")

maximum = int(x)
minimum = int(x)
while(x != 'done'):

    num = 0
    if(x[0] == '-'):
        num = x[1:-1]
    else:
        num = x

    try:
        if(num.isnumeric()):
            if(int(x) > maximum):
                maximum = int(x)

            if(int(x) < maximum):
                minimum = int(x)

        else:
            raise Exception

    except:
        print("PLEASE ENTER A NUMBER")

    x = input("Enter a number and keep on entering and when you are done TYPE `done` : ")


print()


if(x == 'done'):
    print("RESULTS : ")
    print('Min: ',minimum)
    print('Max: ',maximum)
