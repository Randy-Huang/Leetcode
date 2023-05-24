/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
class UnionFind {
public:
    UnionFind(int size) {
        parents = vector<int>(size);
        for (int i = 0; i < size; i++) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void union_op(int px, int py) {
        parents[px] = py;
    }

private:
    vector<int> parents;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind unionFind = UnionFind(2 * edges.size());

        for (auto& edge : edges) {
            int px = unionFind.find(edge[0]);
            int py = unionFind.find(edge[1]);
            if (px != py) {
                unionFind.union_op(px, py);
            } else {
                return edge;
            }
        } 

        return {};
    }
};
// @lc code=end

