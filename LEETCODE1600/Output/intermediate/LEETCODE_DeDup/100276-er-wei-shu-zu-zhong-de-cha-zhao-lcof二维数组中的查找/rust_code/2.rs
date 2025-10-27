python []
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if matrix and matrix[0]:
            p = len(matrix[0])
            for mat in matrix:
                if mat[-1] < target:
                    continue
                if mat[0] > target:
                    return False
                m = bisect.bisect(mat, target, hi = p)
                if mat[m - 1] == target:
                    return True
                p = m
        return False