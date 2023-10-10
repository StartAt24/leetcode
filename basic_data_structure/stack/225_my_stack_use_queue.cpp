#include <queue>
using namespace std;

class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        _qIn.push(x);
    }
    
    int pop() {
        MoveData();
        int ret = _qOut.back();
        _qOut.pop();
        return ret;
    }
    
    int top() {
        MoveData();
        return _qOut.back();
    }
    
    bool empty() {
        return _qIn.empty() && _qOut.empty();
    }
private:
    void MoveData() {
        if (_qOut.empty()) {
            while(!_qIn.empty()) {
                _qOut.push(_qIn.back());
                _qOut.pop();
            }
        }
    }
    // stack
    // top -------  end
    // [1, 2, 3, 4, 5..
    // queue
    // [1, 2, 3, 4, 5]
    // []

    queue<int> _qIn;
    queue<int> _qOut;
};