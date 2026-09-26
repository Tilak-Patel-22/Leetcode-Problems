class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        mini = prices[0]
        maxi= 0
        i = 1
        while i<len(prices):
            profit = prices[i] - mini
            if profit>maxi:
                maxi = profit
            if prices[i] < mini:
                mini = prices[i]
            i+=1
        return maxi            
        