/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */

// @lc code=start
// Solution 1: Dijkstra’s Algorithm (BFS + min heap)
// class Solution {
// public:
//     typedef pair<int /*height*/, int /*idx = (x * n + y)*/> iPair;

//     int swimInWater(vector<vector<int>>& grid) {
//         int res = 0;
//         int n = grid.size();

//         unordered_set<int> visited{ 0 };

//         vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

//         priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

//         pq.push(make_pair(grid[0][0], 0));
//         while (!pq.empty()) {
//             int idx = pq.top().second;
//             int height = pq.top().first; pq.pop();
//             vector<int> u = {(idx / n), (idx % n)};
//             res = max(height, res);
//             //printf("pop: point: grid[%d][%d], height: %d, res: %d\n",u[0], u[1], height, res );

//             if (u[0] == n -1 && u[1] == n -1) {
//                 break;
//             }

//             for (auto& dir : dirs) {
//                 vector<int> v = {u[0] + dir[0], u[1] + dir[1]};
//                 int idxV = v[0] * n + v[1];
//                 if ((v[0] < 0 || v[0] >= n || v[1] < 0 || v[1] >= n) || visited.count(idxV)) {
//                     continue;
//                 }

//                 visited.insert(idxV);
//                 //printf("push %d\n", grid[v[0]][v[1]]);
//                 pq.push(make_pair(grid[v[0]][v[1]], idxV));
//             }
//         }

//         return res;
//     }
// };
// Solution 2: Binary search + BFS (or DFS using stack)
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // first step to start, the result should be
        // greater or equal to grid[0][0] at least
        // if initial is 0, it causes failed  
        // in some cases
        int left = grid[0][0]; 

        // destination can be as infinity
        int right = INT_MAX;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (!hasPath(grid, mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    bool hasPath(vector<vector<int>>& grid, int mid) {
        int n = grid.size();

        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        unordered_set<int> visited;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int i = q.front() / n; 
            int j = q.front() % n; q.pop();
            if (i == n - 1 && j == n - 1) {
                return true;
            }

            for (auto dir : dirs) {
                int tempI = i + dir[0];
                int tempJ = j + dir[1];
                int idx = tempI * n + tempJ;
                if (tempI < 0 || tempI >= n || tempJ < 0 || tempJ >= n || 
                    visited.count(idx) ||
                    grid[tempI][tempJ] > mid) {
                    continue;
                }

                visited.insert(idx);
                q.push(idx);
            }
        }

        return false;
    }    
};
// @lc code=end

