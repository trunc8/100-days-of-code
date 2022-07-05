class Solution {
public:
    vector<int> getSortPositions( const vector<int>& nums ){
        vector<int> sorted_pos( nums.size(), 0 );
        for( int i=0; i<nums.size(); i++ ){
            sorted_pos.at(i) = i;
        }
        sort( sorted_pos.begin(), sorted_pos.end(),
            [&]( int p1, int p2 ){
                return nums.at(p1) < nums.at(p2);
            });
        return sorted_pos;
    }
    int candy(vector<int>& ratings) {
        int tot_candies = 0;
        vector<int> candies( ratings.size(), 1 );
        vector<int> sorted_pos = getSortPositions( ratings );
        for( auto pos : sorted_pos ){
            int num = ratings.at( pos );
            int next = min( pos+1, (int)ratings.size()-1 );
            int prev = max( pos-1, 0 );
            int next_num = ratings.at( next );
            int prev_num = ratings.at( prev );
            if( num > prev_num ){
                candies.at( pos ) = candies.at( prev )+1;
            }
            if( num > next_num ){
                candies.at( pos ) = max( candies.at( pos ),
                                        candies.at( next )+1 );
            }
            tot_candies += candies.at(pos);
        }
        return tot_candies;
    }
};
