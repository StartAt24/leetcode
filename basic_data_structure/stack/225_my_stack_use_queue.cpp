#include <queue>
#include <algorithm>
using namespace std;

class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        // 将主队列和辅助队列对调
        std::swap(_qMain, _qBackup);
        // 将元素放进队列的头部，用来模拟stack的后进先出
        _qMain.push(x);
        while(!_qBackup.empty()){
            _qMain.push(_qBackup.front());
            _qBackup.pop();
        }
    }
    
    int pop() {
        int ret = _qMain.front();
        _qMain.pop();
        return ret;
    }
    
    int top() {
        return _qMain.front();
    }
    
    bool empty() {
        return _qMain.empty();
    }

private:

    queue<int> _qMain;
    queue<int> _qBackup;
};