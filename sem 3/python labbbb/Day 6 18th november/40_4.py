list=[]
while True:
    x=int(input("Enter integer element of list ,press -1 to exit "))
    if(x==-1):
        break
    list.append(x)
y=int(input("Enter index of element you want to find "))
try:    
    print("Index is",list.index(y))
except:
    print("Index not found")
