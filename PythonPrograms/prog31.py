#program for removing punctuation from string

punctuations = "!(){}[]-;:,""\<>./?@#$%^&*_~"

my_str = input("Enter string : ")

no_punctuation = ""
for char in my_str:
    if char not in punctuations:
        no_punctuation = no_punctuation + char

print("The string with no punctuation is --> ", no_punctuation)