class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector< vector< vector<int> > > dp(
            m, vector< vector<int> >( n, vector<int>(target+1, -1) )
        );
        // return dp.at(m-1).at(0).at(target);
        if( n==1 and target!=1 ) return -1;
        if( houses.at(0) )
            dp.at(0).at( houses.at(0)-1 ).at(1) = 0;
        else{
            for( int j=0; j<n; j++ ){
                dp.at(0).at(j).at(1) = cost.at(0).at(j);
            }
        }
        for( int i=1; i<m; i++ ){
            if( houses.at(i) ){
                for( int k=1; k<=i+1 and k<=target; k++ ){
                    if( houses.at(i-1) ){
                        dp.at(i).at( houses.at(i)-1 ).at(k) = houses.at(i-1)==houses.at(i) ?
                            dp.at(i-1).at( houses.at(i-1)-1 ).at(k) :
                            dp.at(i-1).at( houses.at(i-1)-1 ).at(k-1);
                        continue;
                    }
                    int min_j = INT_MAX;
                    for( int j2=0; j2<n; j2++ ){
                        if( j2==houses.at(i)-1 ){
                            if( dp.at(i-1).at(j2).at(k)==-1 ) continue;
                            min_j = min( min_j, dp.at(i-1).at(j2).at(k) );
                        }
                        else{
                            if( dp.at(i-1).at(j2).at(k-1)==-1 ) continue;
                            min_j = min( min_j, dp.at(i-1).at(j2).at(k-1) );
                        }
                    }
                    dp.at(i).at( houses.at(i)-1 ).at(k) = min_j;
                }
                continue;
            }
            for( int j=0; j<n; j++ ){
                for( int k=1; k<=i+1 and k<=target; k++ ){
                    int min_j = INT_MAX;
                    for( int j2=0; j2<n; j2++ ){
                        if( j2==j ){
                            if( dp.at(i-1).at(j2).at(k)==-1 ) continue;
                            min_j = min( min_j, dp.at(i-1).at(j2).at(k) );
                        }
                        else{
                            if( dp.at(i-1).at(j2).at(k-1)==-1 ) continue;
                            min_j = min( min_j, dp.at(i-1).at(j2).at(k-1) );
                        }
                    }
                    if( min_j == INT_MAX ) continue;
                    dp.at(i).at( j ).at(k) = cost.at(i).at(j) + min_j;
                }
            }
        }
        // for( auto i : dp ){
        //     for( auto j : i ){
        //         for( auto k : i ){
        //             for( auto num : k )
        //                 cout << num << " ";
        //             cout << endl;
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
        int min_j = INT_MAX;
        for( int j2=0; j2<n; j2++ ){
            if( dp.at(m-1).at(j2).at(target)==-1 ) continue;
            min_j = min( min_j, dp.at(m-1).at(j2).at(target) );
        }
        if( min_j==INT_MAX )
            return -1;
        else
            return min_j;
    }
};
