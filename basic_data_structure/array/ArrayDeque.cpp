#include <vector>

using namespace std;
const int kDefaultSize = 10;

template<typename T>
class ArrayDeque {
public:
    ArrayDeque(int cap) {
        _container.resize(cap);
    }
    ArrayDeque() {
        _container.resize(kDefaultSize);
    }

    void PushBack(T t) {

    }

    void PopBack() {

    }

    void PushFront(T t) {

    }

    void PopFront() {

    }

private:
    vecotr<T> _cotainer;

};