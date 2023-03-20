#program to make simple calculator

#function to add two number
def add(x, y):
    return x+y

#function to subtract two number
def subtract(x, y):
    return x-y

#function to subtract two number
def multiply(x, y):
    return x*y

#function to subtract two number
def divide(x, y):
    return x/y

print("Select the operation to be performed : ")
print("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division")

while True:
    #take user input, which operation to 
    choice = input("Enter your choice :")

    if choice in ('1','2','3','4'):
        num1 = int(input("Enter first number : "))
        num2 = int(input("Enter second number : "))
    else:
        print("Invalid Input!")
    
    if choice == '1':
        print(num1,"+",num2,"=",add(num1,num2))
    
    if choice == '2':
        print(num1,"-",num2,"=",subtract(num1,num2))
    
    if choice == '3':
        print(num1,"*",num2,"=",multiply(num1,num2))
    
    if choice == '4':
        print(num1,"/",num2,"=",divide(num1,num2))

    #check if user want to perfrom any further calculation
    next_cal = input("Want to perform any further calculation (y/n) : ")
    if next_cal == 'n':
        break   