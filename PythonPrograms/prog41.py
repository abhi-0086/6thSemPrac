#write a program to return multiple values from a function

def calculate_sales_info(sales_list):
    # Calculate the total sales, highest sale, and lowest sale
    total_sales = sum(sales_list)
    highest_sale = max(sales_list)
    lowest_sale = min(sales_list)
    # Return the results as a tuple
    return total_sales, highest_sale, lowest_sale

#return values using dictionary
def name():
    n1 = "Tony"
    n2 = "Peter"
    return {1:n1, 2:n2}

# Call the function with a list of sales figures
sales_figures = [1000, 2000, 1500, 2500, 1800]
total_sales, highest_sale, lowest_sale = calculate_sales_info(sales_figures)

# Print the results
print("Return values using commas using tuple : ")
print("Total sales:", total_sales)
print("Highest sale:", highest_sale)
print("Lowest sale:", lowest_sale)
print("\nReturn values using dictionary : ")
names = name()
print(names)
