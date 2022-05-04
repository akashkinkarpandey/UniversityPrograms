print("Enter list elements of integer type")
l=tuple(list(map(int,input().split())))
n=int(input("Enter number you want to search "))
fl=-1
for index,item in enumerate(l):
    if item==n:
        fl=index
        break
if fl==-1:
    print("Number not found")
else:
     print(f"Number {n} found at {fl} index ")



