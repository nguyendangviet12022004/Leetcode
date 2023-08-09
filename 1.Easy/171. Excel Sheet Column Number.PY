from math import pow
'''Solution: using dict to mark, then using formula: ans += pow(26,i)*d (d is value of A(1),B(2),...)'''
class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        ans = 0
        key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        check = dict()
        for i in range(1,27):
            check.update({key[i-1] : i})
        columnTitle = columnTitle[::-1]

        for i in range(len(columnTitle)):
            ans += pow(26,i)*check[columnTitle[i]]
        return int(ans)

