python3 []
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """

        i, j = m-1, n-1
        len = m + n-1
        while i >= 0 and j >= 0: 
            if A[i] > B[j]:
                A[len] = A[i]
                len -= 1
                i -= 1
            else:
                A[len] = B[j]
                len -= 1
                j -= 1

        while j >= 0 and len >= 0:
            A[len] = B[j]
            len -= 1
            j -= 1