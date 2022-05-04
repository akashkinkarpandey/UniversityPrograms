n=int(input("Enter number of key value pairs "))
dict={}
for i in range(n):
    x=input("Enter key ")
    y=(input("Enter value "))
    dict[x]=y

for x in dict:
    print(f"key is {x}, value is {dict[x]}")
