class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if( nums.size() == 0 ) return 0;
        set<int> s;
        for( auto num : nums ){
            s.insert(num);
        }
        int longest = 1;
        int prev_num = INT_MIN;
        int curr_len = 1;
        for( auto num : s ){
            if( num == prev_num+1 ){
                curr_len++;
                longest = max(longest, curr_len);
            }
            else{
                curr_len = 1;
            }
            prev_num = num;
        }
        return longest;
    }
};
