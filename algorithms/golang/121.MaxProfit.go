// Source : https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
// Author : Lianfeng Shen
// Date   : 2019-04-30

func maxProfit(prices []int) int {
	if len(prices) < 2 {
		return 0
	}

	minPrice := prices[0]
	maxProfit := 0

	for _, price := range prices {
		if price < minPrice {
			minPrice = price
		} else if price-minPrice > maxProfit {
			maxProfit = price - minPrice
		}
	}

	return maxProfit
}