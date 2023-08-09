class Solution:
    def findRelativeRanks(self, score: list[int]) -> list[str]:
        score2 = score.copy()
        score.sort(reverse=True)
        order = dict()
        for i in range(len(score2)):
            if i == 0 :
                order.update({score2[i]:"Gold Medal "})
            elif i == 1 :
                order.update({score2[i]:"Silver Medal "})
            elif i == 2 :
                order.update({score2[i]:"Bronze Medal "})
            else :
                order.update({score2[i]:str(i+1)})

        return [order[x] for x in score]
           
