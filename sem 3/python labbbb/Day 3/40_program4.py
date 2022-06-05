i=1
for i in range (1,1001,1):
    c=0
    for j in range(2,i,1):
        if(i%j==0):
            c=c+1
    if c==0 and i!=1:
        print(i,"is prime")



