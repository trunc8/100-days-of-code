class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort( boxTypes.begin(), boxTypes.end(),
            [](vector<int> b1, vector<int> b2){
                return b1.at(1) > b2.at(1);
            });
        int max_units = 0;
        int cum_boxes = 0;
        for( auto b : boxTypes ){
            if( cum_boxes + b.at(0) >= truckSize ){
                max_units += ( truckSize - cum_boxes )*b.at(1);
                break;
            }
            max_units += b.at(0)*b.at(1);
            cum_boxes += b.at(0);
        }
        return max_units;
    }
};
