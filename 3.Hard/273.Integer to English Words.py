'''Solution: Recursion and Marked'''


to19 = 'One Two Three Four Five Six Seven Eight Nine Ten Eleven Twelve Thirteen Fourteen Fifteen Sixteen Seventeen Eighteen Nineteen'.split()
tens = 'Twenty Thirty Forty Fifty Sixty Seventy Eighty Ninety'.split()

bignum = {
        1000000000:'Billion',
        1000000:'Million',
        1000:'Thousand'
}
# good example of recusion 

class Solution:
    def numberToWords(self, num: int)-> str : 
        def word(n):
            if n < 20:
                return to19[n-1:n]
            if n < 100:
                return [tens[n // 10 -2 ]] + word(n % 10)
            if n < 1000:
                return [to19[n//100 -1]]+ ['Hundred'] + word(n % 100)
            
            for num,words in bignum.items():
                if n >= num:
                    return word(n//num) + [words] + word(n % num)
                
        return ' '.join(word(num)) or 'Zero'
