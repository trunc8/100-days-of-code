class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit      = 0;
        int min_so_far  = prices.at(0);
        for( int i=1; i<prices.size(); i++ ){
            if( min_so_far > prices.at(i) ){
                min_so_far = prices.at(i);
            }
            else {
                profit = max( profit, prices.at(i)-min_so_far );
            }
        }
        return profit;
    }
};
