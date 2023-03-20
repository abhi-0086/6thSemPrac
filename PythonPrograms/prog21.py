#program to find factors of number

def factors(n):
    for i in range(1,n+1):
        if n%i == 0:
            if i != n:
                print(i, end=", ")
            else:
                print(i)

num = int(input("Enter a number : "))
print("The factors of",num,"are : ")
factors(num)