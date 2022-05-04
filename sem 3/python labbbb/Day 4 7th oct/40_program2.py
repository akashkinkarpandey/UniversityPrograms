counting=0
s=input("Enter a string ")
ch=input("Enter character u want  to count ")
for x in s:
    if x==ch:
        counting=counting+1
print(ch,"is present",counting,"times")

