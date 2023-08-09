'''Solution: using strip() to delete space, then convert noramlly
Complexity: O(1)
'''
class Solution:
    def myAtoi(self, str: str) -> int:
        str = str.strip()
        if not str:
            return 0
        mul = -1 if str[0] == '-' else 1
        if str[0] in ['-','+']:
            str = str[1:]
        res = 0
        for x in str:
            if not x.isdigit():
                break
            res = res*10 + int(x)
        res *= mul
        if(res > 2**31 -1 ):
            res = 2**31 -1
        elif res < -2**31:
            res = -2**31
        return res
