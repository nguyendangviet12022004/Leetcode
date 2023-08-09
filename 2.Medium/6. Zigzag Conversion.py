'''1               9                 17                   25
   2           8  10             16  18               24  26
   3      7       11         15      19          23       27
   4  6           12   14            20    22             28
   5               13                21                   29 

   n =0 : 8 - 8 - 8 -8 
   n = 1: 6 - 2, 6 - 2 , 6 -2 , ...
   n = 2: 4 -4 -4 -4 -4 -4,...
   n = 3: 2 -6 - 2 - 6 - 2 - 6,...    
   
   k = 2*(n-1)
   formula: x = 8, y = 0 (k -i)
            x = 6, y = 2 (k - 2*i)2*i)
            x = 
   '''
'''Solution: Using formula above to creat string (cautious: if n ==1 return s right away)'''
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if(numRows == 1):
            return s
        k = 2*(numRows - 1)
        
        ans = ""
        for i in range(numRows):
            step = k - 2*i
            if(step ==0):
                step = k
            j = i
            while(j < len(s)):
                
                ans += s[j]
                j += step 
                step = k - step
                if(step == 0):
                    step = k
        return ans
                
print(Solution().convert("ABCDEFGHIJKLMNOP",1))
