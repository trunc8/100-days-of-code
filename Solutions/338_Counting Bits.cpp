// Solution 1: O(NlogN)
class Solution {
public:
    int num_ones( int n ){
        int sum_ones = 0;
        while( n ){
            sum_ones += n%2;
            n = n/2;
        }
        return sum_ones;        
    }
    vector<int> countBits(int n) {
        vector<int> bit_count( n+1 );
        for( int i=0; i<=n; i++ ){
            bit_count.at( i ) = num_ones( i );
        }
        return bit_count;
    }
};

// Solution 2: O(N), referred discussions. Not very novel though
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bit_count( n+1 );
        bit_count.at(0) = 0;
        for( int i=1; i<=n; i++ ){
            if( i & 1 )
                bit_count.at( i ) = 1+bit_count.at( i>>1 );
            else
                bit_count.at( i ) = bit_count.at( i>>1 );
        }
        return bit_count;
    }
};

// Solution 3: Using __builtin_popcount
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bit_count( n+1 );
        for( int i=1; i<=n; i++ )
            bit_count.at( i ) = __builtin_popcount( i );
        return bit_count;
    }
};
