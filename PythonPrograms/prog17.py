#program to add two matrices

matrix1 = [[1,2,3],[4,5,6],[7,8,9]]
matrix2 = [[1,0,0],[0,1,0],[0,0,1]]

result = [[0,0,0],[0,0,0],[0,0,0]]

for i in range (len(matrix1)):
    for j in range (len(matrix1[0])):
        result[i][j] = matrix1[i][j] + matrix2[i][j]

for k in result:
    print(k)



### another way
# matrix1 = []
# matrix2 = []
# row, col = map(int, input("Enter the number of row and columns : ").split(' '))

# #input in matrix1
# print("Enter elemnts of matrix1 ->")
# for i in range(0, row):
#     temprow = []
#     for j in range(0, col):
#         element = int(input("Enter element ("+str(i+1)+","+str(j+1)+") : "))
#         temprow.append(element)
#     matrix1.append(temprow)

# #input in matrix2
# print("Enter elemnts of matrix2 ->")
# for i in range(0, row):
#     temprow = []
#     for j in range(0, col):
#         element = int(input("Enter element ("+str(i+1)+","+str(j+1)+") : "))
#         temprow.append(element)
#     matrix2.append(temprow)

# #adding both matrix
# result = []
# for i in range(0, row):
#     temprow = []
#     for j in range(0, col):
#         temprow.append(matrix1[i][j] + matrix2[i][j])
#     result.append(temprow)

# print("\nPrinting sum of matrix : ")
# for i in result:
#     print(i)