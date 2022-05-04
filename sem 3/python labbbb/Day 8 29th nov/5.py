try:
    n=int(input("Enter number of key value pairs "))
    dict={}
    for i in range(n):
        x=input("Enter key ")
        y=int(input("Enter value as integer "))
        dict[x]=y
    val=dict.values()
    maxi=max(val)
    mini=min(val)
    print(f"Max value is {maxi}")
    print(f"Min value is {mini}")
except:
    print("Wrong input")