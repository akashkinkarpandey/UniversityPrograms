try:
  x = int(input("Enter a number "))
  if x < 0:
    raise Exception
  print("Square root is ",x**(0.5))
except:
  print("Sorry, no numbers below zero")
