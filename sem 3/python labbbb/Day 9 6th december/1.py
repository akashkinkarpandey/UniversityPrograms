n=int(input("enter a number "))
#part 1
def fibo(n):
   if n <= 1:
       return n
   else:
       return(fibo(n-1) + fibo(n-2))
print("Fibonacci Series: using recursive code ", end = " ")
for i in range(n):
    print(fibo(i+1),end=" ")
print()
#part 2
first = 0
second= 0
sum = 1
count = 1
print("Fibonacci Series: using non recursive code", end = " ")
while(count <= n):
    print(sum, end = " ")
    count += 1
    first = second
    second = sum
    sum = first + second
print()
