#write a program to spilit a list into evenly sized chunks

def chunkify(lst, chunk_size):
    """
    Splits a list into evenly sized chunks.
    
    Args:
    lst (list): The list to split.
    chunk_size (int): The size of each chunk.
    
    Returns:
    list: A list of chunks, where each chunk is a list of elements from the original list.
    """
    return [lst[i:i+chunk_size] for i in range(0, len(lst), chunk_size)]

#ask for chunk size from user
chunk_size = int(input("Enter chunk size : "))

my_list = []
size = int(input("Enter number of elemnts in list : "))

print("Enter List elements : ")
input_str = input()
# split the input string into a list of strings
input_list = input_str.split()

for i in range(size):
    element = int(input_list[i])
    my_list.append(element)

chunked_list = chunkify(my_list, chunk_size)
print(chunked_list)


