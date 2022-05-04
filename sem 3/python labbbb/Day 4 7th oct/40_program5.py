s=input("Enter a sentence ")
new=""
list = s.split(" ")
for i in range(len(list)-1):
    if list[i]!=list[i+1]:
        new+=list[i]+" "
print(new+list[len(list)-1])
