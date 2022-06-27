class Solution {
public:
    int minPartitions(string n) {
        int max_digit = 0;
        for( auto ch : n ){
            max_digit = max( max_digit, ch - '0' );
        }
        return max_digit;
    }
};
