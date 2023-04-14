#program to print factorial of a number using recursion

def fact(n):
    if n == 1:
        return 1
    else:
        return n*fact(n-1)

num = int(input("Enter a number : "))

if num < 0:
    print("Invalid input, Enter a positive integer!")
elif num == 0:
    print("The factorial of 0 is 1")
else:
    print("The factorial", num, "is", fact(num))