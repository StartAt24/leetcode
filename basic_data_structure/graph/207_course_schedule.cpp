#include "common.hpp"
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        _visited.resize(numCourses, false);
        _inPath.resize(numCourses, false);
        auto graph = buildGraph(numCourses, prerequisites);
        for (int i = 0; i < numCourses; i++) {
            traverse(graph, i);
        }

        return _canFinish;
    }
private:
    void traverse(vector<vector<int>>& graph, int idx) {
        if (_inPath[idx]) {
            _canFinish = false;
            return;
        }

        if (_visited[idx] || !_canFinish) {
            return;
        }

        _visited[idx] = true;
        _inPath[idx] = true;

        // 遍历当前的这个节点的所有能达到的节点
        for (int t: graph[idx]) {
            traverse(graph, t);
        }

        _inPath[idx] = false;
    }

    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph;
        graph.resize(numCourses);
        for (auto edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];
            // add a path in graph "from -> to"
            graph[from].push_back(to);
        }
        return graph;
    }

    bool _canFinish = true;
    vector<int> _visited;
    vector<int> _inPath;
};