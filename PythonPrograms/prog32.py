#program to check if string are anagram are not

#input strings
str1 = input("Enter first string : ")
str2 = input("Enter second string : ")

#convert string to lowercase
str1 = str1.lower()
str2 = str2.lower()

#check if length is same
if len(str1) != len(str2):
    print("Input strings are not anagrams")
else:
    sorted_str1 = sorted(str1)
    sorted_str2 = sorted(str2)
    if sorted_str1 == sorted_str2:
        print("Input strings are anagram")
    else:
        print("Input strings are not anagram.")

