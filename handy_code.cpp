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
