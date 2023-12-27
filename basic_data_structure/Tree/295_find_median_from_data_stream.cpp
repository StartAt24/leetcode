#include <vector>
#include <queue>
using namespace std;
class MedianFinder {
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (!_minHeap.empty() && num > _minHeap.top()) {

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
