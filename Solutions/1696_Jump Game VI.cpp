// Solution 1: Using max heap
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> scores( nums.size() );
        scores.back() = nums.back();
        
        auto comp = [](pair<int,int> a, pair<int, int> b){
                return a.first < b.first;
            };
        priority_queue< 
            pair<int, int>, 
            vector< pair<int, int> >,
            decltype( comp ) > pq( comp );
        pq.push( make_pair( scores.back(), nums.size()-1 ) );
        
        for( int i=nums.size()-2; i>=0; i-- ){
            while( pq.top().second > i+k )
                pq.pop();
            int max_jump = pq.top().first;
            scores.at( i ) = nums.at( i ) + max_jump;
            pq.push( make_pair( scores.at( i ), i ) );
        }        
        return scores.front();
    }
};


// Solution 2: Referred discussions, using deque
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> scores( nums.size() );
        scores.front() = nums.front();
        deque<int> d;
        d.push_back( 0 );
        for( int i=1; i<nums.size(); i++ ){
            while( d.front() < i-k )
                d.pop_front();
            scores.at(i) = nums.at(i) + scores.at(d.front());
            // score at d.front() will be max because of the wipeout in below while loop
            // Before addition of i to the deque, any existing large score would have wiped out
            // any previous larger score, ensuring that the fittest
            // i.e. largest (prior to addition of ith score) survives at the start of the deque
            while( !d.empty() and scores.at(i) >= scores.at(d.back()) )
                d.pop_back();
            d.push_back( i );
        }
        return scores.back();
    }
};
