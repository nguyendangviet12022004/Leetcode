class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        pre_count = 0 
        check = s[0]
        count = 0 
        ans = 0 
        for c in s :
            if c == check :
                count += 1 
            else :
                ans += min(count,pre_count)
                pre_count = count 
                count = 1 
                check = c 
        return ans + min(pre_count,count)