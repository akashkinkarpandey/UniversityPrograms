n=int(input("Enter number of key value pairs "))
dict={}  
for i in range(n):
    x=input("Enter key ")
    y=(input("Enter value "))
    dict[x]=y
y=input("Enter item to be found ")
fl=0
for x in dict:
    if x==y:
        fl=1
        print(f"{y} is found")
        break
if fl==0:
    print(f"{y} not found ")




