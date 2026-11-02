class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i;
        int minPrice=INT_MAX,best=0;
        for(i=0;i<prices.size();i++){
            minPrice=min(minPrice,prices[i]);
            best=max(best,prices[i]-minPrice);
        }return best;
    }
};