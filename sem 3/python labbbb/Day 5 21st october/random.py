s=input("Enter a string ")
l=s.split(" ")
t=""
for i in range(0,len(l)):
    if(l[i][0].isupper()):
        t=t+l[i][0]
print(t)

