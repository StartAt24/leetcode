#include <stack>
#include <map>

using namespace std;
// 这里的频率是指 在容器里的元素的数量
class FreqStack{
public:
    void push(int val) {
        int freq = _valToFreq[val]++;

        if (!_freqToVals.count(freq)) {
            _freqToVals[freq] = stack<int>();
        }
        _freqToVals[freq].push(val);

        _maxFreq = max(_maxFreq, freq);
    }

    int pop(){
        auto vals = _freqToVals[_maxFreq];
        int v = vals.top();
        vals.pop();

        int freq = _valToFreq[v]--;
        
        if (vals.empty()) {
            _maxFreq--;
        }

        return v;
    }

private:
    int _maxFreq;
    // 记录频率freq对应的val列表, 用stack可以保证 记录元素的先后顺序。
    unordered_map<int, stack<int>> _freqToVals;
    // 每次 pop之后实际上元素个数变少，所以要修改他的频率
    unordered_map<int, int> _valToFreq;

};