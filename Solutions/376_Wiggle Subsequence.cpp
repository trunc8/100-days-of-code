//Solution 1: O(n^2)
class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        if( a.size() <= 1 ) return a.size();
        vector<pair<int, int> > dyn_len( a.size(), make_pair(1, 1) );
        int longest = 1;
        for( int i=a.size()-2; i>=0; i-- ){
            for( int j=i+1; j<a.size(); j++ ){
                if( a.at(i) > a.at(j) and 
                   dyn_len.at(i).first <= dyn_len.at(j).second ){
                    dyn_len.at(i).first = 1+dyn_len.at(j).second;
                    longest = max( longest, dyn_len.at(i).first );
                }
                if( a.at(i) < a.at(j) and 
                   dyn_len.at(i).second <= dyn_len.at(j).first ){
                    dyn_len.at(i).second = 1+dyn_len.at(j).first;
                    longest = max( longest, dyn_len.at(i).second );
                }
            }            
        }
        
        return longest;
        
    }
};

//Solution 2: O(n)
