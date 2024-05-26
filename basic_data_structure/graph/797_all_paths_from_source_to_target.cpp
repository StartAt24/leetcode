#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        _target = graph.size()-1;
        traverse(graph, 0, {});
        return _res;
    }

private:
    void traverse(vector<vector<int>>& graph, int idx, vector<int> path) {
        // idx 是节点的号码
        path.push_back(idx);

        if (idx == _target) {
            _res.push_back(path);
        }

        for (int v : graph[idx]) {
            traverse(graph, v, path);
        }
    }

    int _target;
    vector<vector<int>> _res;
};