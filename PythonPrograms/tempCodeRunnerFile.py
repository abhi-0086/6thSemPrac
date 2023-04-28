import sys

random_list = ['a', 0, 2]

for entry in random_list:
    try:
        print("The entry is",entry)
        res = 1/int(entry)
        break
    except:
        print("Oops!", sys.exc_info()[0],"occured")
        print("Next entry\n")
print("The reciprocal of", entry, "is", res)