#startswith
txt = "Cricket starts"
x = txt.startswith("Cricket")
print(x)

#endswith
txt = "Cricket starts"
x = txt.endswith("tarts")
print(x)

#number present or not
x ="hiwo4rldd"
if(x.isalnum()):
    print("True")
else:
    print("false")

name = "hello WORLD"
print(name.capitalize())

#replace
str="abey"
print(str.replace("e","b"))

#count
fruits = ['world', 'ban', 'helo']
x = fruits.count("cherry")
print(x)

#upper case
a = "plant trees"
x = a.upper()
print(x)