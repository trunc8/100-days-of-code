// Solution 1: Min Heap self-constructed. Had to look up discussions to evade TLE
class KthLargest {
private:
    vector<int> heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for( int i=0; i<nums.size(); i++ ){
            this->add( nums.at(i) );
        }
    }
    
    int add(int val){
        if( heap.size() < k ){
            heap.push_back( val );
            int pos = heap.size() - 1;
            while( val < heap.at( ( pos-1 )/2 ) ){
                heap.at( pos )    = heap.at( ( pos-1 )/2 );
                pos                 = ( pos-1 )/2;
                heap.at( pos )    = val;
            }
            return heap.at(0);
        }
        if( heap.size() >= k and val <= heap.at(0) )
            return heap.at(0);
        // Safe to access as k>0
        heap.at(0) = val;
        int pos = 0;
        while( true ){
            if( pos*2 + 1 >= heap.size() ){
                break;
            }
            int left_child  = heap.at( pos*2 + 1 );
            int right_child = INT_MAX;
            if( pos*2 + 2 < heap.size() ){
                right_child = heap.at( pos*2 + 2 );
            }
            if( right_child < left_child and right_child < val ){
                heap.at( pos )  = right_child;
                pos             = pos*2 + 2;
                heap.at( pos )  = val;
            }
            else if( left_child < val ){
                heap.at( pos )  = left_child;
                pos             = pos*2 + 1;
                heap.at( pos )  = val;
            }
            else break;
        }
        return heap.at(0);
    }
};

// Solution 2: Using priority_queue STL
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
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

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
