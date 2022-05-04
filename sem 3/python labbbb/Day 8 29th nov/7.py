try:
    n=int(input("Enter number of key value pairs "))
    dict={}
    for i in range(n):
        x=input("Enter key as string ")
        y=int(input("Enter value as integer "))
        dict[x]=y
    ans=1
    for x in dict:
        ans=ans*dict[x]
    print(f"Product of values is {ans}")
except:
    print("Wrong input")

