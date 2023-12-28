#include <vector>
#include <queue>
using namespace std;
class MedianFinder {
public:
    MedianFinder() {

    }
    
    // _minHeap的堆顶元素必须大于_maxHeap的堆顶元素
    void addNum(int num) {
        if (_minHeap.size() >= _maxHeap.top()) {
            // 需要插入 _maxHeap; 

            // 先插入 _minHeap
            _minHeap.push(num);

            // 再将 _minHeap的堆顶插入到 _maxHeap;
            int temp = _minHeap.top();
            _minHeap.pop();
            
            _maxHeap.push(temp);
        } else {
            _maxHeap.push(num);
            int temp = _maxHeap.top();
            _maxHeap.pop();

            _minHeap.push(temp);
        }

    }
    
    double findMedian() {
        if (_minHeap.size() < _maxHeap.size()) {
            return _maxHeap.top();
        } else if (_minHeap.size() > _maxHeap.size()) {
            return _minHeap.top();
        }

        return (_minHeap.top() + _maxHeap.top()) / 2;
    }
private:
    // 小顶堆, 实际存放的是 数值较大的那一半元素
    priority_queue<int> _minHeap;
    // 大顶堆，实际存放的是 数值较小的那一半元素
    priority_queue<int> _maxHeap;
};
