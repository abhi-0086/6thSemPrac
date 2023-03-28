#program to find LCM of two numbers

def compute_lcm(x,y):
    #find the greatest number of two
    if x > y:
        max = x
    else:
        max = y
    
    while 1:
        if (max%x == 0) and (max%y == 0):
            lcm = max
            break
        else:
            max += 1

    return lcm 

num1, num2 = map(int, input("Enter two number : ").split())
print("LCM of",num1,"and",num2,"is",compute_lcm(num1,num2))