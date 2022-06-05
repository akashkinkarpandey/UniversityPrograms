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
        continue
    if x==' ':
        sp=sp+1
        continue
    p=p+1

word=0
t=0
infinite=1
lel=0
i=0
while infinite==1:
    x=s[i]
    fl=0
    if (((x>='A' and x<='Z') or (x>='a' and x<='z')) and i<len(s)):
        word=word+1
        fl=1
        while (((x>='A' and x<='Z') or (x>='a' and x<='z')) and i<len(s)):
            i=i+1
            if(i<len(s)):
                x=s[i]
    if fl==0:
        i+=1
    if(i==len(s)):
        break

print('Number of words are',word)
print('Number of vowels are',v)
print('Number of consonants are',c)
print('Number of punctuations are',p)