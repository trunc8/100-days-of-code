class Solution {
public:
    int minDeletions(string s) {
        int del = 0;
        unordered_map<char, int> freq_map;
        for( auto ch : s ){
            freq_map[ch]++;
        }
        set<int> unique;
        for( auto elem : freq_map ){
            int freq = elem.second;
            while( freq and unique.find( freq ) != unique.end() ){
                freq--;
                del++;
            }
            unique.insert( freq );
        }
        return del;
    }
};
