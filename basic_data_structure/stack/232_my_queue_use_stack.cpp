#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        _In.push(x);
    }
    
    // header of queue
    int pop() {
        transfer();
        int ret = _Out.top();
        _Out.pop();
        return ret;
    }
    
    // header of queue;
    int peek() {
        transfer();
        return _Out.top();
    }
    
    bool empty() {
        return  _In.empty() && _Out.empty();
    }
private:
    void transfer() {
        if (_Out.empty()) {
            while(!_In.empty()) {
                _Out.push(_In.top());
                _In.pop();
            }
        }
    }

    stack<int> _In;
    stack<int> _Out;
};