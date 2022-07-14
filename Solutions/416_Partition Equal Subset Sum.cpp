class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot_sum = 0;
        for( auto num : nums )
            tot_sum += num;
        if( tot_sum%2 ) return false;
        //if tot_sum is odd
        int target = tot_sum/2;
        vector< vector<bool> > dp( 
            nums.size()+1, vector<bool>(target+1, 0) );
        // i->number of nums, j->target sum
        for( int i=0; i<=nums.size(); i++ )
            dp[i][0] = 1;
        for( int i=1; i<=nums.size(); i++ ){
            for( int j=1; j<=target; j++ ){
                dp[i][j] = dp[i-1][j];
                if( nums.at(i-1) <= j )
                    dp[i][j] = dp[i][j] or dp[i-1][j-nums.at(i-1)];
            }            
        }
        return dp.at(nums.size()).at(target);
    }
};
