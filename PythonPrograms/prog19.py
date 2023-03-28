#program to find number is +ve, -ve or 0 using if-else ladder

num = float(input("Enter number to check : "))
if num > 0:
    print(num,"is positive number")
elif num == 0:
    print("You have entered zero")
else:
    print(num,"is negative number")