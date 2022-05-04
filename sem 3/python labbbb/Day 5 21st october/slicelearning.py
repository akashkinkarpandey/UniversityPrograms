#all about slicing
s="heloworld"
print(s[:len(s)])#print whole

print(s[:len(s):2])#print whole with increment of 2

#print from particular index till end(put position in 1st place)
print(s[1::2])#print from index 1 till end

print(s[2:4])#print from index 2 to 3

print(s[::-1])#reverse whole string

print(s[-2::-1])#reverse from 2nd last index to actual 0th index

print(s[:-4:-1])#reverse last 3 letters

print(s[-2:-4:-1]) #reverse from 2nd last to 3rd last index