/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
// Solution 1: DFS
// class Solution {
// public:
//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//         // create map to store those known values of equations
//         unordered_map<string, unordered_map<string, double>> known;
//         for (int i = 0; i < equations.size(); i++) {
//             string a = equations[i][0];
//             string b = equations[i][1];
//             known[a][b] = values[i];
//             known[b][a] = 1.0 / values[i];
//         }

//         // 
//         vector<double> res;
//         for (auto& question : queries) {
//             string a = question[0];
//             string b = question[1];

//             if (!known.count(a) || !known.count(b)) {
//                 res.push_back(-1.0);
//                 continue;
//             } 

//             unordered_set<string> visited;
//             res.push_back(divide(known, visited, a, b));
//         }

//         return res;
//     }

//     double divide(unordered_map<string, unordered_map<string, double>>& known, 
//                   unordered_set<string>& visited,
//                   string& a, 
//                   string& b) 
//     {
//         if (a == b) {
//             return 1.0;
//         }

//         if (known.count(a) && known[a].count(b)) {
//             return known[a][b];
//         }

//         visited.insert(a);
//         // printf("visited size: %lu, current: [%s:%s]\n", visited.size(), a.c_str(), b.c_str());
//         for (auto& element : known[a]) {
//             // for finding result a / b, we need to find the c such that
//             // (a / c) * (c / b) 
//             string c = element.first;
//             if (visited.count(c)) {
//                 continue;
//             }

//             double partialResult = divide(known, visited, c, b);
//             if (partialResult > 0) {
//                 printf("executeed");
//                 return known[a][c] * partialResult;
//             }
//         }

//         // if we couldn't find the result
//         return -1.0;
//     }
// };


// Solution 2: Union-find
class UnionFind 
{
private:
    vector<int> parents;
    vector<double> weight; // use to represent as values

public:
    UnionFind(int n) {
        parents = vector<int>(n);
        weight = vector<double>(n);

        for (int i = 0; i < n; i++) {
            parents[i] = i;
            weight[i] = 1.0;
        }
    }

    void union_op(int x, int y, double value) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return;
        }

        // two unions are already compressed by find()
        // it doesn't matter to choose which one as new root
        parents[rootX] = rootY; 

        // x->rootX->rootY = weight[x] * weight[rootX]
        // y->rootY = weight[y]
        // given value is x->y 
        // then we have weight[x] * weight[rootX] = value * weight[y]
        weight[rootX] = value * weight[y] / weight[x];
    }

    int find(int x) {
        // Use path compression
        if (parents[x] != x) {
            int origin = parents[x];
            parents[x] = find(parents[x]);

            // when a path has compressed, we need to updaet x's weight
            // to origin multiple x 
            // if origin is alerady root, it's weight should be 1.0
            weight[x] *= weight[origin];

        }
        return parents[x];
    }

    double isConnected(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return weight[x] / weight[y];
        } 

        return -1.0;
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        // Use index so that x (or y) can map to parents' index
        unordered_map<string, int> map(2 * equations.size());
        int index = 0;

        UnionFind unionFind(2 * equations.size());

        for (int i = 0; i < equations.size(); i++) {
            string x = equations[i][0];
            string y = equations[i][1];
            double val = values[i];

            if (!map.count(x)) {
                map[x] = index;
                index++;
            }

            if (!map.count(y)) {
                map[y] = index;
                index++;
            }

            unionFind.union_op(map[x], map[y], val);
        }

        vector<double> res;
        for (auto& query : queries) {
            string x = query[0];
            string y = query[1];

            if (!map.count(x) || !map.count(y)) {
                res.push_back(-1.0);
                continue;
            } 

            int idxX = map[x];
            int idxY = map[y];
            res.push_back(unionFind.isConnected(idxX, idxY));
        }

        return res;
    }
};
// @lc code=end

