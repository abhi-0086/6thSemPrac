#program to convert to binary number using recursion

def convert_to_binary(n):
    if n > 1:
        convert_to_binary(n//2)
    print(n%2, end='')

num = int(input("Enter decimal value : "))

print("The binary value for",num,"is", end=' ')
convert_to_binary(num)
print()