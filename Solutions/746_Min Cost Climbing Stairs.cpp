class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp( cost.size() );
        dp.at( cost.size() - 1 ) = cost.at( cost.size() - 1 );
        dp.at( cost.size() - 2 ) = cost.at( cost.size() - 2 );
        for( int i=(int)cost.size()-3; i>=0; i-- ){
            dp.at( i ) = cost.at( i ) + min(
                dp.at( i+1 ), dp.at( i+2 )
            );
        }
        return min( dp.at(0), dp.at(1) );
    }
};
