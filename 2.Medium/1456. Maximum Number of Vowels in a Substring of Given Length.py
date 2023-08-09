'''
Solution1:
    Using Mark Arrray To Count The numbers of vowel letters:
Exmaple :   String  --> a b c i i i d e f
            Array       1 1 1 2 3 4 4 5 6
Complexity: O(n)
'''

class Solution1: 
    def maxVowels(self, s: str, k: int) -> int:
        def check_vowel(s : str):
            return s in "ueoai"
        
        r = len(s)
        s = " " + s
        arr = [0]
        for i in range(1,r + 1):
            if(check_vowel(s[i])):
                arr.append(arr[i-1] + 1)
            else :
                arr.append(arr[i-1])
        ans = 0

        for i in range(1,r-k+2):
            ans = max(ans,arr[i+k-1] - arr[i-1])
        return ans


'''
Solution2: 
    Just check normal,don't need to have array to mark (chek k first  elements)
For example:
    a b c i i i d e f 
        0 --> 2 : 1 vowel
        1 --> 3 : 1 - check(0) + check(3) 
        2 --> 4 : 1 - check(1) + check(4)
        ...
Complexity : O(n)
'''

class Solution2: 
    def maxVowels(self, s: str, k: int) -> int:
        def check(s:str)-> int:
            return 1 if s in "ueoai" else 0
        temp = 0
        ans = 0
        for i in range(k):
            temp += check(s[i])
        ans = temp
        for i in range(1,len(s)-k+1):
            temp -= check(s[i-1])
            temp += check(s[i+k-1])
            ans = max(ans,temp)
        return ans 
            

