/*
 * @lc app=leetcode id=685 lang=cpp
 *
 * [685] Redundant Connection II
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

    void unionOp(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px != py) {
            parents[px] = py;
        }
    }

private:
    vector<int> parents;
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int size = edges.size() + 1; // paretns array starts from 0
        UnionFind unionFind = UnionFind(size);

        /* 
         * If a node has two paretns, it causes conflict
         * There are 3 cases will cause a rooted tree invalied with extra edge
         * 1. has a cycle: [1,2],[2,3],[3,1]]
         *              1 ← 3
         *              ↓ ↗
         *              2
         * 2. conflict and has a cycle: [1,2],[2,3],[3,1],[4,2]
         *              2 ← 4
         *            ↗   ↘ 
         *           1  ←  3       
         * 3. conflict only: [1,2],[1,3],[2,3]
         *    (Notice that this graph looks like case 1 but it isn't a circle here)
         *              1 → 3
         *              ↓ ↗
         *              2
         */
        vector<int> cycle = vector<int>(2, -1);
        vector<int> conflict = vector<int>(2, -1);

        /* 
         * Use parent vector to remember what the last node is
         * Unlinke parents[] we defined in UnionFind, parent vector
         * just only to record the edge information and don't need to
         * unite them together. For example: 
         *      given an edge[1, 2] => parent[1] = 2
         * if we use parents in UnionFind, it'll return a root node and 
         * cause a wrong information. 
         */
        vector<int> parent(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }

        /* 
         * Strategy for iterating the graph to find the invalid cycle or conflict:
         * give an edge [u, v]
         * 1. if parent[v] != v, it means we've already iterate an edge and assign a parent to v
         *    then we need to set [u, v] a conflict
         * 2. if not, let parent[v] = u
         * 2-1. find the u and v parents in UnionFind, if find(v) == find(u), it has a cycle in the graph
         *      set edge[u, v] a cycle
         * 2-2. if not, union(u, v)
         * By above operation, we can see there is no edge can be CYCLE and CONFLICT at the same time.
         * 
         * Now then we need to judge which invalid edge we need to return
         * Consider these following cases:
         * 1. If conflict < 0, the invalid must be cycle which is the last edge we remember and return it.
         * 2. If conflict >= 0, we assume conflict = [u, v], then there are two cases we need to handle:
         * 2-1. if cycle >= 0, we've assigned [u, v] as conflict edge, it cannot be cycle at the same time,
         *      so there are another invalid edge exist and it cause cycle and it is also the parent of v,
         *      therefore, it's parent[v], so we return [parent[v], v]
         * 2-2. if cycle < 0, just return conflict [u, v].
         * */

        for (auto& edge : edges) {
            int p = edge[0];
            int c = edge[1];
            if (parent[c] != c) { 
                // c is already have parent before iterating early edge
                conflict = edge;
            } else {
                parent[c] = p;
                if (unionFind.find(c) == unionFind.find(p)) { // cycle
                    cycle = edge;
                } else {
                    unionFind.unionOp(c, p);
                }
            }
        }

        if (conflict[0] < 0) {
            return cycle;
        } else {
            if (cycle[0] >= 0) {
                return {parent[conflict[1]], conflict[1]};
            } else {
                return conflict;
            }
        }
    }
};
// @lc code=end

