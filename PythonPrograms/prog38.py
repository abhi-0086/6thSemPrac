#write a program to catch multiple excptions as a paranthesized tuple (in one line)

string = input()
try:
    num = int(input())
    print(string+num)

except(TypeError, ValueError) as e:
    print(e)