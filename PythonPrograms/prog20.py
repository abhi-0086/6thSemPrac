#program to check number is +ve, -ve or 0 using nested if-else

num = float(input("Enter number to check : "))
if num >= 0:
    if num == 0:
        print("You have entered zero")
    else:
        print(num,"is a positive number")
else:
    print(num,"is negative number")