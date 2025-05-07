
class Solution {
    public:
        vector<pair<int, int>> dir = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
        };
        
        bool isValid(int x, int y, vector<vector<int>>& grid) {
            int n = grid.size();
            return (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 0);
        }
         // T.C - O(n*m log(n*m)))
         // S.C - O(n*m)
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
            if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
    
            queue<pair<int, int>> q;
            q.push({0, 0});
            if(n==1) return 1;
            grid[0][0] = 1; 
          
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
    
                int dist = grid[x][y];
                
                if (x == n - 1 && y == n - 1) return dist;
       
                for (auto [dx, dy] : dir) {
                    int nx = x + dx, ny = y + dy;
                   
                    if (isValid(nx, ny, grid)) {
                        q.push({nx, ny});
                        grid[nx][ny] = dist + 1; 
                    }
                }
            }
            
            return -1;
        }
    };
    