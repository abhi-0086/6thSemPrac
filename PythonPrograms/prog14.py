#program to print n fibonacci terms

n1, n2 = 0, 1
num_terms = int(input("Enter number of terms required :"))
count = 1
if num_terms <= 0:
    print("Please enter a positive number!")
elif num_terms == 1:
    print("Fibonacci series upto",num_terms,"terms :")
    print(n1)
else:
    print("Fibonacci series upto",num_terms,"terms :")
    while count <= num_terms:
        if count == num_terms:
            print(n1)
        else:
            print(n1,end=', ')
        temp = n1 + n2
        n1 = n2
        n2 = temp
        count += 1
