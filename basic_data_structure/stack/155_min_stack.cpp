#include <stack>
using namespace std;
class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        _container.push(val);
        if (_minStk.empty() || val <= _minStk.top()) {
            _minStk.push(val);
        }
    }
    
    void pop() {
        int val = _container.top();
        _container.pop();
        if (val == _minStk.top()) {
            _minStk.pop();
        }
    }
    
    int top() {
        return _container.top();
    }
    
    int getMin() {
        return _minStk.top();
    }
private:
    stack<int> _container;
    stack<int> _minStk;
};