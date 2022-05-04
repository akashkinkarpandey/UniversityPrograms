i=1
for i in range (1,1001,1):
    j=i
    sum=0
    while j>0:
        d=j%10
        sum+=(d*d*d)
        j=j//10
    if(sum==i):
        print(i,"is armstrong")


