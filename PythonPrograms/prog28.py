#find sum of natural number using recursion

#recursive function for sum of natural number
def sum_num(n):
    if n <= 1:
        return 1
    else:
        return n + sum_num(n-1)

num = int(input("Enter a number : "))
if num < 0:
    print("Invalid input!")
    print("Enter a positive integer")
else:
    print("Sum of ",num,"natural numbers is ", sum_num(num))
