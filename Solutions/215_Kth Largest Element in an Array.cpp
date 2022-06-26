// Solution 1: Unhappy lol. Just used an STL function
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums.at( nums.size()-k );
    }
};

// Solution 2: Slower solution, but happier with this
// Leveraging my solution in #703
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // min binary heap
        for( auto num : nums ){
            pq.push( num );
            if( pq.size()>k ) pq.pop();
        }
        return pq.top();
    }
};
