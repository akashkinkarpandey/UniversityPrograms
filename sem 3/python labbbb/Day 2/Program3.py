t=(float)(input("Enter a score between 0.0 and 1.0 "))
if t>1.0:
    print("Error ")
elif t>=0.9:
    print("A")
elif t>=0.8 and t<0.9:
    print('B')
elif t>=0.7 and t<0.6:
    print('C')
elif t>=0.6 and t<0.7:
    print('D')
else:
    print('F')
