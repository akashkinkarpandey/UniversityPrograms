s=input("Enter a string ")
low=0
high=len(s)-1
fl=0
while low<=high:
    if s[low]!=s[high]:
       fl=1
       break
    low=low+1
    high=high-1

if fl==0:
    print(s,"is palindrome")
else: 
    print(s,"is not palindrome")
