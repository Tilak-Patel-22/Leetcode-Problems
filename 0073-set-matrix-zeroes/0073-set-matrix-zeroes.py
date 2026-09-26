class Solution:
    def setZeroes(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        row = len(matrix)
        col = len(matrix[0])

        zero = []
        one = []

        for i in range(row):
            for j in range(col):
                if matrix[i][j] == 0:
                    zero.append(i)
                    one.append(j)
        
        for i in zero:
            for j in range(col):
                matrix[i][j] = 0
        
        for j in one:
            for i in range(row):
                matrix[i][j] = 0

        return