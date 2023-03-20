#program to display power of 2 using anonymous function

num_terms = int(input("Enter nnumber of terms : "))

#use anonymous function
result = list(map(lambda x:2**x,range(num_terms)))

print("Total number of terms are : ")
for i in range(num_terms):
    print("2 raised to power ",i,"is",result[i] )