class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort( horizontalCuts.begin(), horizontalCuts.end() );
        sort( verticalCuts.begin(), verticalCuts.end() );
        long long max_hort = horizontalCuts.at(0);
        long long max_vert = verticalCuts.at(0);
        int i;
        for( i=1; i<horizontalCuts.size(); i++ ){
            max_hort = max( (int)max_hort, horizontalCuts.at(i) -
                           horizontalCuts.at(i-1) );
        }
        max_hort = max( (int)max_hort, h - horizontalCuts.at(i-1) );
        
        
        for( i=1; i<verticalCuts.size(); i++ ){
            max_vert = max( (int)max_vert, verticalCuts.at(i) -
                           verticalCuts.at(i-1) );
        }
        max_vert = max( (int)max_vert, w - verticalCuts.at(i-1) );
        
        return (max_hort*max_vert)%(1000000007);
    }
};
