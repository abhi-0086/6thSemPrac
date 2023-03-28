#program to find armstrong number between interval

#function to check if number is armstrong or not
def isArmstrong(num):
    order = len(str(num))
    sum = 0
    temp = num
    while(temp > 0):
        digit = temp % 10
        sum += digit ** order
        temp //= 10
    if(num == sum):
        return True
    else:
        return False
    
a = int(input("Enter the lower limit of the interval: "))
b = int(input("Enter the upper limit of the interval: "))
print("Armstrong number between",a,"and",b,"are : ")
for i in range(a, b+1):
    if(isArmstrong(i)):
        print(i)



