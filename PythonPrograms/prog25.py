#program to print fibonacci series using recursion

def fibonacci(n):
    if n<=1:
        return n
    else:
        return fibonacci(n-1) + fibonacci(n-2)

num_terms = int(input("Enter the number of terms : "))

if num_terms <= 0:
    print("Invalid input!")
    print("Please enter a positive number")
else:
    print("Fibinacci series upto", num_terms, "is : ")
    for i in range(num_terms):
        if i == num_terms-1:
            print(fibonacci(i))
        else:
            print(str(fibonacci(i)) + ",", end=" ")