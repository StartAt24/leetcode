#include "common.hpp"
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        _visited.resize(numCourses, false);
        _onPath.resize(numCourses, false);
        auto graph = buildGraph(numCourses, prerequisites);
        for (int i = 0; i < numCourses; i++) {
            traverse(i, graph);
        }
        if (_hasCircle)
            return {};
        std::reverse(_res.begin(), _res.end());
        return _res;
    }


private:
    void traverse(int id, const vector<vector<int>>& graph) {
        if (_onPath[id]) {
            _hasCircle = true;
            return;
        }

        if (_visited[id]) {
            return;
        }
        _onPath[id] = true;
        _visited[id] = true;

        for(auto n : graph[id]) {
            traverse(n, graph);
        }
        // first visited node;
        _res.push_back(id);
        _onPath[id] = false;
    }

    vector<vector<int>> buildGraph(int numCourses, const vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }

    bool _hasCircle = false;
    vector<bool> _visited;
    vector<bool> _onPath;
    vector<int> _res;
};