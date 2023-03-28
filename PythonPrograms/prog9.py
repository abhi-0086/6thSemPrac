#program to print table of a number

num = int(input("Enter a number : "))
print("Table of ", num)
for i in range(0, 11):
    print(num,'x',i,'=',num*i)