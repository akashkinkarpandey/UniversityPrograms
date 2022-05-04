s=input("Enter a sentence ")
sp=0
v=0
c=0
p=0
for x in s:
    if ((x>='A' and x<='Z') or (x>='a' and x<='z')):
        if (x=='a' or x=='e' or x=='i' or x=='o' or x=='u' or x=='A' or x=='E' or x=='I' or x=='O' or x=='U'):
            v=v+1
            continue
        else:
            c=c+1
            continue
    if x>='0' and x<='9':
        n=n+1
        continue
    if x==' ':
        sp=sp+1
        continue
    p=p+1
    


print('Number of words are',sp+1)
print('Number of vowels are',v)
print('Number of consonants are',c)
print('Number of punctuations are',p)



        
        




