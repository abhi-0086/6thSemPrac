#program to print right angled triangle pattern

num_row = int(input("Enter number of rows :"))
for i in range(0, num_row):
    for j in range(0, i+1):
        print("# ", end='')
    print()