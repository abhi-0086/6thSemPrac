#write a program to sort alphbetically the words of a string provided by the user

my_str = input("Enter a sentence : ")

words = []
for word in my_str.split():
    words.append(word.lower())

words.sort()

for word in words:
    print(word)