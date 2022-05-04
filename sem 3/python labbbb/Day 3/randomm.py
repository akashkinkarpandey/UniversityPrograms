l1 = list()

largest = 0

smallest = 999

s = 0


n = int(input ("Enter the number of elements:"))

for i in range(n):

        ele = int (input ("Enter the element: "))

        l1.append(ele)


for ele in l1:

         if (ele > largest ):

                largest = ele

         if (ele < smallest):

              smallest = ele

        s = s + ele

average = s / len(l1)

print ("Largest of elements of ", l1, "is: ", largest )

print ("Smallest of elements of ", l1, "is: ", smallest )

print ("Average of list", l1, "is: ", average )
