s=input("Enter a string ")
l=s.split(" ")
t=""
l.reverse()
print(l)
str=""
for i in range(len(l)):
    str=str+l[i]+" "
print(str)
