n = int(input("Enter a number "))
c = 0
d = 1
if(n <= 1):
    print("Not Prime")
else:
    for i in range(2, n, 1):
        if (n % i) == 0:
            c = c+1
    if(c == 0):
        print("Prime")
    else:
        print("Not Prime")
