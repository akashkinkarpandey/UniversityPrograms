
c=0
n=int(input("Enter size of stack "))
l=[]*n

def push(x):
    global c
    if(c==n):
        print("Overflow ")
        return
    l.append(x)
    c=c+1

def pop():
    global c
    if(c==0):
        print("Nothing to delete ")
        return
    print(f"{l[-1]} is deleted ")
    l.pop()
    c=c-1


def main():
    while(True):
        print("Enter 1 for push ")
        print("Enter 2 for pop ")
        print("Enter any other number to exit ")
        choice=int(input("Enter choice "))
        if choice==1:
            x=int(input("Enter element "))
            push(x)
        elif choice==2:
            pop()
        else: 
            print("Exiting ")
            exit()




if __name__ == '__main__':
    main()


    



