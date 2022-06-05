dict={}
newdict={}
n=int(input("Enter number of key value pairs "))
for i in range(n):
    x=float(input("Enter metres value "))
    y=int(x)*100
    dict[x]=y
for x in dict:
    newdict[dict[x]]=x
print(f"Input-ed dict is {dict}")
print(f"New dict dict is {newdict}")