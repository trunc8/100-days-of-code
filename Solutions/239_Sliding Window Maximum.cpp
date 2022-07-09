// Solution 1: My solution after understanding the solution to #1696
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max_window;
        deque<int> d;
        d.push_back( 0 );
        for( int i=1; i<nums.size(); i++ ){
            while( d.front() < i-k ){
                d.pop_front();
            }
            if( i > k-1 )
                max_window.push_back( nums.at(d.front()) );
            while( !d.empty() and nums.at( i ) >= nums.at( d.back() )){
                d.pop_back();
            }
            d.push_back( i );
        }
        while( d.front() < nums.size()-k ){
            d.pop_front();
        }
        max_window.push_back( nums.at(d.front()) );
        return max_window;
    }
};

// Solution 2: After reading the discussions. Same logic/data structure but cleaner
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max_window;
        deque<int> d;
        for( int i=0; i<nums.size(); i++ ){
            while( !d.empty() and d.front() == i-k )
                d.pop_front();
            while( !d.empty() and nums.at( i ) >= nums.at( d.back() ))
                d.pop_back();
            d.push_back( i );
            if( i >= k-1 )
                max_window.push_back( nums.at(d.front()) );
        }
        return max_window;
    }
};
