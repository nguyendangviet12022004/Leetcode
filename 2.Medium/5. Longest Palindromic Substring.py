'''
 * Solution : Dynamic Progaming : Use 2-dimensional arrays to mark if s.substr(x,y) is a Palindromic String and use it to check a[x][y] = a[x+1][y-1] & s[x] == s[y]
 *  Complexity : O(n)
'''

class Solution:
    def longestPalindrome(self, s: str) -> str:
        arr = []
        ans = 1
        for i in range(len(s)):
            arr.append([])
            for j in range(len(s)):
                arr[i].append(False)
        for i in range(len(s)):
            arr[i][i] = True
        
        for j in range(1,len(s)):
            for i in range(j-1,-1,-1):
                if(s[i] == s[j]):
                    if(j - i == 1 or arr[i+1][j-1]) :
                        arr[i][j] = True
                        ans = max(ans,j-i+1)
                    else: 
                        arr[i][j] = False
                else:
                    arr[i][j] = False
        return ans

                        
        