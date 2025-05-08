class Solution {
    public:
        bool valid(int x, int y, vector<vector<int>>& moveTime) {
            if (x >= 0 && y >= 0 && x < moveTime.size() && y < moveTime[0].size()) {
                return true;
            }
            return false;
        }
    
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        typedef pair<pair<int, int>, pair<int, int>> P;
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int n = moveTime.size();
            int m = moveTime[0].size();
            vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
            priority_queue<P, vector<P>, greater<P>> pq;
            pq.push({{0, 0}, {0, 0}});
            distance[0][0] = moveTime[0][0];
            while (!pq.empty()) {
                P temp = pq.top();
                pq.pop();
                int dist = temp.first.first;
                int flag = temp.first.second;
                int x = temp.second.first;
                int y = temp.second.second;
                if (x == n - 1 && y == m - 1) {
                    return dist;
                }
                for (auto it : dir) {
                    int nx = it.first + x;
                    int ny = it.second + y;
                    if (valid(nx, ny, moveTime)) {
                        int a = max(dist, moveTime[nx][ny]);
                        if (flag == 0) {
                            if (distance[nx][ny] > 1 + a) {
                                pq.push({{a + 1, 1}, {nx, ny}});
                                distance[nx][ny] = 1 + a;
                            }
                        } else {
                            if (distance[nx][ny] > 2 + a) {
                                pq.push({{a + 2, 0}, {nx, ny}});
                                distance[nx][ny] = 2 + a;
                            }
                        }
                    }
                }
            }
            return 0;
        }
    };