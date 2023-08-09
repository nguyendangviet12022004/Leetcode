'''
Solution1 : Using bin() to convert to bin , then built a function to reverse it , finally using int() to conver bin to dec 
Complexity : 0(1)
'''
class Solution:
    def findComplement(self, num: int) -> int:
        n = str(bin(num))[2:]

        def reverse_bin(s:str)-> str:
            arr = ['1' if x == '0' else '0' for x in s]
            return "".join(arr)
        
        return int(reverse_bin(n),2)


'''
Solution 2: Using while loop to convert , using pre array to store result of pow(2,i)
Complexity:O(1)
'''

class Solution2:
    def findComplement(self,num:int) -> int:
        ans = 0
        pre = [1]
        for i in range(1,32):
            pre.append(pre[i-1] << 1)
        index = 0
        while num :
            ans += pre[index] * (1 ^ (num % 2))
            num //= 2
            index += 1
        
        return ans

