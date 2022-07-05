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
