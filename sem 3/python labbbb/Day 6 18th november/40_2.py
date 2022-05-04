list=[]
while True:
    x=int(input("Enter integer element of list ,press -1 to exit "))
    if(x==-1):
        break
    list.append(x)
x=int(input("Enter a number whose frequency is to be found "))
count = list.count(x)
print('Count of',x,'is', count)