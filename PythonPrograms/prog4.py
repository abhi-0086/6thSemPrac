#program to find simple interest

principal = float(input("Enter principal amount : "))
ROI = float (input("Enter rate of interest : "))
time = float(input("Enter time : "))
print("Simple interest : ",principal*ROI*time/100)