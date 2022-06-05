#Write a program that has a dictionary of your friends’ name (as keys) and their birthdays.
#Print the items in the dictionary in a sorted order. Prompt the user to enter a name and check
#if it is present in the dictionary. If the name does not exist, then ask the user to enter DOB.
#Add the details in the dictionary.


#n=int(input("Enter a the no of students : "))

from collections import OrderedDict
dict = {}

n=int(input("Enter number of key value pairs "))
    #dict = {}
for i in range(n):
    name = input("Enter the name : ")
    dob = input("Enter the dob in dd-mm-yyyy format (eg. 17-2-2002) : ")
    dict[name] = dob
dict1 = OrderedDict(sorted(dict.items()))
#for name in dict:
    #print(f"key is {name}, value is {dict[name]}")
print(f"orderd way is {dict1}")
z=input("ENTER A NAME:\t")
f=0
for name in dict:
    if(name==z):
        f=1
        print("found")
        break
if(f==0):
    dob = input("Enter the dob in dd-mm-yyyy format (eg. 17-2-2002) : ")
    dict2={} 
    dict1[z]=dob
    dict2 = OrderedDict(sorted(dict1.items()))
    print(f"orderd way is {dict2}")