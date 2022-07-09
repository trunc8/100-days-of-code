class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq; // min binary heap
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for( auto num : nums ){
            pq.push( num );
            if( pq.size()>k ) pq.pop();
        }
    }
    
    int add(int val){
        pq.push( val );
        if( pq.size() > k ) pq.pop();
        return pq.top();
    }
};


void print( vector<int>& heights ){
    for( auto num : heights )
        cout << num << " ";
    cout << endl;
}


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


vector<int> getBitRepresentation( int n ){
    vector<int> bit_rep( ceil(log2(n+1)), 0 );
    int i=0;
    while( n ){
        bit_rep.at( i ) = n%2;
        n = n/2;
        i++;
    }
    return bit_rep;
}


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
