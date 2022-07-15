class Solution {
private:
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    int m, n;
public:
    int explore( int i, int j ){
        int area = 0;
        queue< pair<int, int> > q;
        q.push( make_pair(i,j) );
        // cout << "Explore: " << i << " " << j << endl;
        int new_i, new_j;
        while( !empty(q) ){
            i = q.front().first;
            j = q.front().second;
            // cout << "Inside" << endl;
            new_i = i, new_j = j-1;
            if( new_j>=0 and grid[new_i][new_j] and !visited[new_i][new_j] ){
                visited[new_i][new_j] = 1;
                q.push( make_pair(new_i,new_j) );
            }
            new_i = i-1, new_j = j;
            if( new_i>=0 and grid[new_i][new_j] and !visited[new_i][new_j] ){
                visited[new_i][new_j] = 1;
                q.push( make_pair(new_i,new_j) );
            }
            new_i = i, new_j = j+1;
            if( new_j<n and grid[new_i][new_j] and !visited[new_i][new_j] ){
                visited[new_i][new_j] = 1;
                q.push( make_pair(new_i,new_j) );
            }
            new_i = i+1, new_j = j;
            // cout << "Grid: " << grid[new_i][new_j] << endl;
            // cout << "Visited: " << visited[new_i][new_j] << endl;
            if( new_i<m and grid[new_i][new_j] and !visited[new_i][new_j] ){
                visited[new_i][new_j] = 1;
                q.push( make_pair(new_i,new_j) );
                // cout << new_i << " " << new_j << endl;
            }
            area++;
            q.pop();
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        m = grid.size();
        n = grid.at(0).size();
        visited.resize(m, vector<bool>(n, 0) );
        this->grid = grid;
        for( int i=0; i<m; i++ ){
            for( int j=0; j<n; j++ ){
                if( grid[i][j] and !visited[i][j] ){
                    visited[i][j] = true;
                    int area = explore( i, j );
                    // cout << area << endl;
                    max_area = max( max_area, area );
                }
            }
        }
        return max_area;
    }
};
