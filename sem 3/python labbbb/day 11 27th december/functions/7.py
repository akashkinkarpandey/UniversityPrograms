# average calculation
n=int(input("Enter a number "))
avg=(n+1)/2
print(f"Average is from 1 to {n} is {avg}")
# median calculation
median=0
if(n&1):
    median=(n//2)+1
else:
    median=((n//2)+((n//2)+1))/2
print(f"Median from 1 to {n} is {median}")
print("For mode calculation, enter list of numbers in single line separated by spaces ")
l=list(map(int,input().split()))
dict={}
for i in l:
    if (i in dict):
            dict[i] += 1
    else:
            dict[i] = 1
print(dict)
maxi=-1
maxi_item=0
for x in dict:
    if(maxi<dict[x]):
        maxi=dict[x]
        maxi_item=x
print(f"Mode is {maxi_item} present {maxi} times")








