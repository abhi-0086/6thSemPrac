#program to reverse a input string

# #using loop 
# str = input("Enter a string :")
# reversed_str = ""
# for i in range(len(str)-1, -1, -1):
#     reversed_str += str[i]
# print("Original string :",str)
# print("Reversed string :",reversed_str)


# ## using loop 
# #reverse function
def reverse(s):
    str = ""
    for i in s:
        str = i + str
    return str
str = input("Enter a string :")
print("Original string :",str)
print("Reversed string :",reverse(str))


# ##using recursion
# def reverse(s):
#     if len(s) ==0:
#         return ""
#     else:
#         return reverse(s[1:])+s[0]

# str = input("Enter a string :")
# print("Original String :",str)
# print("Reversed string :",reverse(str))




# string = input("Enter a string :")
# for word in reversed(string):
#     print(word, end='')
# print()