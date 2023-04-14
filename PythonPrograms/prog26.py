#transpose of a matrix using nested loop

matrix1 = [[1,2,3], [4,5,6], [7,8,9]]
result = [[0,0,0], [0,0,0], [0,0,0]]

print("The matrix is : ", matrix1)
for i in range(len(matrix1)):
    for j in range(len(matrix1[0])):
        result[j][i] = matrix1[i][j]

print("The transapose of the matrix is : ")
for r in result:
    print(r)