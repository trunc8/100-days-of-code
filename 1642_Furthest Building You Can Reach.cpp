class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        long long int top_k_sum = 0; // k = no. of ladders
        long long int total_sum = 0;
        for( int i=heights.size()-1; i>=1; i-- ){
            heights[i] = max( 0, heights[i]-heights[i-1] );
        }
        for( int i=1; i<heights.size(); i++ ){
            total_sum += heights[i];
            
            if( pq.size() < ladders ){
                pq.push( heights[i] );
                top_k_sum += heights[i];
            }
            else if( pq.size() and heights[i] > pq.top() ){
                //pq.size() = ladders != 0
                top_k_sum -= pq.top();
                top_k_sum += heights[i];
                pq.push( heights[i] );
                pq.pop();
            }
            if( total_sum - top_k_sum > bricks) {
                return ( i-1 );
            }
        }
        return heights.size()-1;
    }

    void print( vector<int>& heights ){
        for( auto num : heights )
            cout << num << " ";
        cout << endl;
    }
};
