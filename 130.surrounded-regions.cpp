/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class UnionFind {
public:
    vector<int> parent;
    int c;
    
    UnionFind(int size) {
        c = size;
        for (int i = 0; i < size; i++) {
            parent.push_back(i);
        }
    }

    void connect(int p, int q) {
        int rootP = findParent(p);
        int rootQ = findParent(q);

        if (rootP != rootQ) {
            parent[rootQ] = rootP;
            c--;
        }
    }

    bool connected(int p, int q) {
        return findParent(p) == findParent(q);
    }

    int findParent(int p) {
        if (p != parent[p]) {
            parent[p] = findParent(parent[p]);
        }

        return parent[p];
    }

    int count() {
        return c;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        union_find(board);
    }

    void dfs(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Iterate 4 edge lines to find the 'O' and modify them to '#'
        // because only the 'O' elements which lie in 4 edges can't 
        // surrounded by X in 4 directions, which means those 'O'
        // can't be repplaced to 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m -1) || (j == 0 || j == n-1))  {
                    //printf("i: %d, j = %d\n", i, j);
                    if (board[i][j] == 'O') {
                        dfs(board, i, j);
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //printf("i: %d, j: %d, char: %c\n",i,j,board[i][j]);
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                    continue;
                } 
                
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        int m = board.size();
        int n = board[0].size();

        board[x][y] = '#';

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if ((0 <= nx && nx < m && 0 <= ny && ny < n) && (board[nx][ny] == 'O')) {
                dfs(board, nx, ny);
            }
        }
    }

    void bfs(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m-1) || (j == 0 || j == n-1)) {
                    if (board[i][j] == 'O') {
                        bfs(board, i, j);
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }

                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void bfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();

        board[i][j] = '#';

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> que;
        que.push({i, j});

        while (!que.empty()) {
            pair<int, int> point = que.front(); que.pop();
            int x = point.first;
            int y = point.second;

            for (auto dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if ((0 <= nx && nx < m && 0 <= ny && ny < n) && (board[nx][ny] == 'O')) {
                    que.push({nx, ny});
                    board[nx][ny] = '#';
                }
            }
        }
    }

    void union_find(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        // index is from 0 to (m*n)
        UnionFind uf(m * n + 1); // + 1 which means for dummy node
        int dummy = m * n; // put dummy node at the end of the union
        
        // solution
        // let all 'O' elements that lie on the 4 edges 
        // to connect to dummy node

        // steps 1: iterate 4 edges 
        // we need to map 2D elements to vector elements
        // first we iterate left edge and right edge 2 edges 
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                uf.connect(i * n, dummy);
            }

            if (board[i][n-1] == 'O') {
                uf.connect(i * n + (n - 1), dummy);
            }
        }

        // second we iterate top and bottom edges
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                uf.connect(j, dummy);
            }

            if (board[m-1][j] == 'O') {
                uf.connect(n * (m -1) + j, dummy);
            }
        }
        
        // steps 2: iterate all elements equals to '0' except for 4 edges
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (board[i][j] == 'O') {
                    for (auto dir : directions) {
                        int x = i + dir.first;
                        int y = j + dir.second;
                        if (board[x][y] == 'O') {
                            // connect 4 edges of board[i][j]
                            // if the element is 'O' lies on the edge
                            // or it's next to the 'O' element that lies 
                            // on the edge
                            uf.connect(x * n + y, i * n + j);
                        }
                    }
                }
            }
        }
        
        // step 3: iterate all elements equals to '0' except for 4 edges
        // and replace 'O' to 'X' which are can be surrounded by 'X'
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (!uf.connected(i * n + j, dummy)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// @lc code=end

