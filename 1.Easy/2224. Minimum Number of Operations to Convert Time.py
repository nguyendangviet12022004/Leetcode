class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        step = [60, 15,5,1]
        ans = 0 

        time1 = [int(x) for x in current.split(":")]
        time2 = [int(x) for x in correct.split(":")]
        h = time2[0] - time1[0]
        m = time2[1] - time1[1]

        h = h + 12 if h < 0 else h 
        if m < 0 : 
            h -= 1 
            m += 60 
        s = h * 60 + m
        print(s)
        for x in step :
            ans += s //x 
            s %= x
        return ans

Solution().convertTime(current = "09:41", correct = "10:34" )
print(9*60 + 41 - 10 * 60 - 34)