/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 */

// @lc code=start
class UnionFind {
public:
    int c;
    vector<int> parent;

    UnionFind(int n) {
        c = n;
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    void unionNodes(int p, int q) {
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

    int findParent(int x) {
        if (x != parent[x]) {
            parent[x] = findParent(parent[x]);
        }

        return parent[x];
    }

    int count() {
        return c;
    }
};


class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // the laws of equations
        // 1. reflective: a==a must hold for all variable a.
        // 2. symmetric: if a==b holds, then we have b==a.
        // 3. transtive: if a==b and b==c, then we have a==c.
        return union_find(equations);
    }

    bool union_find(vector<string>& equations) {
        UnionFind uf(26);
        
        for (auto equation : equations) {
            if (equation[1] == '=') {
                char x = equation[0];
                char y = equation[3];
                printf("x: %d, y: %d\n", x-'a',y-'a');
                uf.unionNodes(x - 'a', y - 'a');
                printf("count: %d\n",uf.count());
            }
        }

        for (auto equation : equations) {
            if (equation[1] == '!') {
                char x = equation[0];
                char y = equation[3];
                if (uf.connected(x - 'a', y - 'a')) {
                    return false;
                }
            }
        }

        return true;
    }
};
// @lc code=end

