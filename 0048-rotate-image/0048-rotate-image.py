class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        result = [[0]*n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                result[j][n-1-i] = matrix[i][j]
        matrix[:] = result
        