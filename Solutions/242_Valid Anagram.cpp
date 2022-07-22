class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> um;
        for( auto ch : s ){
                um[ch]++;
        }
        for( auto ch : t ){
            if( um.find(ch) == um.end() )
                return false;
            else
                um[ch]--;
        }
        for( auto elem : um ){
            if( elem.second )
                return false;
        }
        return true;
    }
};
