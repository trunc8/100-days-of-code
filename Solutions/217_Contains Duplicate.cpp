// Solution 1: My solution
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        for( int i=1; i<nums.size(); i++ ){
            if( nums.at(i) == nums.at(i-1) )
                return true;
        }
        return false;
    }
};


// Solution 2: Referred discussion. Using hashtable
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> um;
        for( auto num : nums ){
            if( um.find( num ) != um.end() )
                return true;
            um[ num ] = true;
        }
        return false;
    }
};
