/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    if(prices.length > 0){
     let profit = 0, min = prices[0], max = prices[0];
      for(let i=1; i< prices.length; i++){
          if(prices[i] < prices[i-1]){
              profit += prices[i-1] - min;
              min = prices[i];
          }
      }
      profit += prices[prices.length-1] - min;
        return profit;
    } else {
        return 0;
    }
};