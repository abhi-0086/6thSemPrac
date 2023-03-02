#program to print prime number between 900 to 1000

low_limit = 900
high_limit = 1000
print("Prime numbers between",low_limit,"&",high_limit,":")
for i in range(low_limit, high_limit+1):
    for j in range(2,i):
        if(i%j == 0):
            break
    else:
        print(i)