#calculating nPr
try:
    #step 1 calculating factorial
    def fact(n):
        if(n==0 or n==1):
            return n
        return n*fact(n-1)
    #step 2 taking input
    n=int(input("Enter a number n "))
    r=int(input("Enter a number r(r<=n) "))
    #step 3 nPr calculation
    #nPr=n!/(n-r)!
    if(r>n):#we cannot calculate nPr if r>n
        print("Wrong input")
    else:
        answer=(1.0*fact(n))/(fact(n-r))
        print(f"{n}P{r}(nPr) is {answer} ")
except:
    print("Only integer inputs allowed ")



