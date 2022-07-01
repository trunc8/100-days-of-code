class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long moves = 0;
        sort( nums.begin(), nums.end() );
        int median = nums.at( nums.size()/2 );
        for( auto num : nums ){
            moves += abs( num - median );
        }
        return moves;
    }
};
