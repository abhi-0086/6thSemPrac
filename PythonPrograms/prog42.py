#write a program for catching exceptions in python

# def divide_numbers(a, b):
#     try:
#         result = a / b
#         print("The result is:", result)
#     except ZeroDivisionError:
#         print("Error: Division by zero is not allowed.")
#     except TypeError:
#         print("Error: Please provide two numbers as arguments.")

# # Call the function with valid and invalid arguments
# divide_numbers(10, 2)      # Output: The result is: 5.0
# divide_numbers(10, 0)      # Output: Error: Division by zero is not allowed.
# divide_numbers("10", 2)    # Output: Error: Please provide two numbers as arguments.



import sys

random_list = ['a', 0, 2]

for entry in random_list:
    try:
        print("The entry is",entry)
        res = 1/int(entry)
        break
    except:
        print("Oops!", sys.exc_info()[0],"occured")
        print("Next entry\n")
print("The reciprocal of", entry, "is", res)