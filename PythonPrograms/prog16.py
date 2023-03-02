#program to print calendar of input month

import calendar
year = int(input("Enter year : "))
month = int(input("Enter the month : "))
print(calendar.month(year, month))