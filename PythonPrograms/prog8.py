#program to find largest of three number

num1, num2, num3 = map(int, input("Enter three numbers:").split())
if(num1>num2 and num1>num3):
    print("Greatest number is",num1)
elif(num2>num1 and num2>num3):
    print("Greatest number is",num2)
elif(num3>num1 and num3>num2):
    print("Greatest number is",num3)
else:
    print("All three numbers are equal!")