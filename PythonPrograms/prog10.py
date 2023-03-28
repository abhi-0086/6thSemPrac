#program to print sum for natural numbers

num = int(input("Enter a number :"))
numSum = num*(num+1)/2
print("Sum =",numSum)
if(num<0):
    print("Enter a positive number!")
else:
    sum = 0
    while(num>0):
        sum += num
        num -= 1
    print("Sum is ",sum)