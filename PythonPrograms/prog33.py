#program to use a global variable in nested function

def foo():
    x = 20

    def bar():
        global x
        x = 25

    print("Value of x before calling bar -->",x)
    print("Now calling bar function...")
    bar()
    print("Value of x after calling bar -->",x)

#main function
foo()
print("Value of x in main -->",x)