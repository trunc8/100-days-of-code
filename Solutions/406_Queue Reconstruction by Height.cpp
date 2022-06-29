class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort( people.begin(), people.end(), 
             [](vector<int> a, vector<int> b){
                 return a[0]!=b[0] ? a[0]<b[0] : a[1]<b[1];
             } );
        vector<vector<int>> q( people.size(), {-1,0} );
        for( auto person : people ){
            int k = person[1];
            bool inserted = false;
            int pos = 0;
            while( pos < people.size() ){
                if( k==0 and q.at(pos)[0]==-1 ){
                    q.at(pos) = person;
                    inserted = true;
                    break;
                }
                k -= ( q.at(pos)[0]==-1 or q.at(pos)[0] >= person[0] );
                pos++;
            }
        }
        return q;
    }
};
