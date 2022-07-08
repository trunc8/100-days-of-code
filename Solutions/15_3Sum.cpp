class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if( nums.size() <= 2) return vector<vector<int>>();
        // handling edge case
        
        sort( nums.begin(), nums.end() );
        unordered_set<int> us( nums.begin(), nums.end() );
        set<vector<int>> s;
        if( count(nums.begin(), nums.end(), 0)>=3 )
            s.insert(vector<int>{0,0,0});
        for(int i=0; i<nums.size()-2; i++){
            for(int j=i+1; j<nums.size()-1; j++){
                if( us.find( -(nums.at(i)+nums.at(j)) )!=us.end() ){
                    if( -(nums.at(i)+nums.at(j))>nums.at(j) )
                // for(int k=j+1; k<nums.size(); k++){
                //     if( nums.at(i)+nums.at(j)+nums.at(k) == 0 ){
                        s.insert(vector<int>{
                            nums.at(i),nums.at(j),-(nums.at(i)+nums.at(j))
                        });
                //     }
                    else if( -(nums.at(i)+nums.at(j))==nums.at(j) and nums.at(j) ){
                        if( count(nums.begin(), nums.end(), nums.at(j))>=2 )
                            s.insert(vector<int>{
                                nums.at(i),nums.at(j),-(nums.at(i)+nums.at(j))
                            });
                    }
                }
            }
        }
        return vector<vector<int>>( s.begin(), s.end() );
    }
};
