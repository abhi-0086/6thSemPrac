#program to convert input decimal value to other number system

decimal_num = int(input("Enter a decimal number: "))
# Converting decimal to binary
binary_num = bin(decimal_num)
# Converting decimal to octal
octal_num = oct(decimal_num)
# Converting decimal to hexadecimal
hexadecimal_num = hex(decimal_num)

print("The decimal number", decimal_num, "in binary is:", binary_num)
print("The decimal number", decimal_num, "in octal is:", octal_num)
print("The decimal number", decimal_num, "in hexadecimal is:", hexadecimal_num)
