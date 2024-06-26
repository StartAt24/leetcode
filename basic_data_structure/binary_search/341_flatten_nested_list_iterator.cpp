/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#include <vector>
#include <list>
using std::vector;
using std::list;
class NestedInteger;

class NestedIterator {
private:
    vector<int> _container;
    vector<int>::iterator _it;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flat(nestedList);
        _it  = _container.begin();
    }
    
    int next() {
        int res = *_it;
        _it++;
        return res;
    }
    
    bool hasNext() {
        return _it != _container.end();
    }

private:
    void flat(const vector<NestedInteger>& nestedList) {
        for (const auto& l : nestedList) {
            if (l.isInteger()) {
                _container.push_back(l.getInteger());
            } else {
                flat(l.getList());
            }
        }
    }
};