class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        s = "".join(s.split('-'))[::-1].upper()
        ans = ""
        for i in range(0,len(s),k):
            if i + k < len(s):
                ans += s[i:i+k] + '-'
            else :
                ans += s[i:]
        return ans[::-1]
