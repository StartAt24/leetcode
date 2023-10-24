#include <list>
using namespace std;
class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {

    }
    
    void pushFront(int val) {
        _size1++;
    }
    
    void pushMiddle(int val) {

    }
    
    void pushBack(int val) {
        _size2++;
    }
    
    int popFront() {
        _size1--;
    }
    
    int popMiddle() {

    }
    
    int popBack() {

        _size2--;
    }

private:
    list<int> _firstHalf;
    list<int> _secondHalf;
    int _first1 = 0;
    int _last1 = 0;
    int _first2 = 0;
    int _last2 = 0;
    int _size1 = 0;
    int _size2 = 0;
};