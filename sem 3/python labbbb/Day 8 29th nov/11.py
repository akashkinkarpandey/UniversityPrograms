dict={}
n=int(input("Enter number of key value pairs "))
for i in range(n):
    x=input("Enter key ")
    y=input("Enter value ")
    dict[x]=y

newdict={}

for x in dict:
    newdict[dict[x]]=x
print(f"Input-ed dict is {dict}")
print(f"New dict dict is {newdict}")
