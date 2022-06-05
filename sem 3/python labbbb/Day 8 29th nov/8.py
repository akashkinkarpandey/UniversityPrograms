# Creates a sorted dictionary (sorted by key)
from collections import OrderedDict
dict={}
try:
    n=int(input("Enter number of key value pairs "))
    for i in range(n):
        x=input("Enter key as string ")
        y=int(input("Enter value as integer "))
        dict[x]=y

    dict1 = OrderedDict(sorted(dict.items()))
    print(f"Dictionary in items sorted way is {dict1}")
except:
    print("Wrong Input")