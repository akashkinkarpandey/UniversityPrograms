try:
    def gcd_func(a,b):
        if(b==0):
            return a
        return gcd_func(b,a%b)
    c=list(map(int,input("Enter numbers in single line ").split()))
    overall_gcd=0
    for i in range(len(c)):
        overall_gcd=gcd_func(overall_gcd,c[i])
    print("Overall GCD of list  is",overall_gcd)
except:
    print("Wrong Inputs Given ")