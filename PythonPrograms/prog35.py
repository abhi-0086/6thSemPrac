#write a program to count the number of each vowel

def count_vowels(string):
    vowels = {'a': 0, 'e': 0, 'i': 0, 'o': 0, 'u': 0}
    for char in string:
        if char.lower() in vowels:
            vowels[char.lower()] += 1
    return vowels

string = input("Enter a string: ")
vowel_count = count_vowels(string)
print(vowel_count)
