print("Enter colour names in a single line")
a=list(map(str,input().split()))
print("Enter color codes in a single line")
b=list(map(str,input().split()))
if(len(a)!=len(b)):
    print("Invalid ")
else:
    dict={}
    for i in range(len(a)):
        dict[a[i]]=b[i]
    print(dict)

