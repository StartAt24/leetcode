#include "common.hpp"
#include <cstddef>

class RingBuffer {
public:
    RingBuffer(int cap) {
        _container.resize(cap);
        _mask = CeilToPowerOfTwo(cap) - 1;
    }

    int read(vector<std::byte>& out, int s) {
        if(IsEmpty()) {
            return 0;
        }
        // shrink?
        if (_size <= _container.size()/4) {
            resize(_container.size()/2);
        }

        // 最多只能读取size个数据
        s = s < _size ? s : _size;

        // 以下均为ringbuffer没满的情况
        // 不存在元素位于写指针之后，
        // 如果有的话 则说明队列已经满了，已经在前面的条件里被过滤了

        // case 1: 写了但是没有读
        // r --- w _ _
        // case 2: 写了也读了一点
        // ***r --- w _ _
        // 这两种情况都可以直接读取
        // _read 指向的是可读的元素的第一个的位置
        // _write 指向的是可写元素的第一个的位置，
        // 两者是等价的，所以说 if里的判断条件是一致的
        if (_read + s <= _container.size()) {
            std::copy(_container.begin() + _read, _container.begin() + _read + s, out);
        } else {
            // case 3: 写了并且已经进入下一轮
            // --w _ _ r--
            std::copy(_container.begin() + _read, _container.end(), out);
            std::copy(_container.begin(), _container.begin() + (_container.size() - _read), std::back_inserter(out));
        }

        _read = (_read + s) & _mask;
        _size -= s;
        return s;
    }

    int write(const vector<byte>& in, int s) {
        if (_size + s > _container.size()) {
            resize(_size + s);
        }

        // case 1: r---w_ _
        if (_write >= _read) {
            // case 1.1: r --w 写入之后变为 r--**w
            // 0,1,2,3,_,_
            if (_container.size() - _write >= s) {
                std::copy(in.begin(), in.begin() + s, _container.begin() + _write);
            } else {
                // case 1.2: r---w 写入之后变为 **w _ _ r---*
                int n1 = _container.size() - _write;
                int n2 = s - n1;
                std::copy(in.begin(), in.begin() + n1, _container.begin() + _write);
                std::copy(in.begin() + n1, in.begin() + s, _container.begin());
            }
        } else {
            std::copy(in.begin(), in.begin() + s, _container.begin() + _write);
        }

        _write = (_write + s) & _mask;

        _size += s;
        return s;
    }

private:
    int CeilToPowerOfTwo(int cap) {
        int mask = 1;
        while(mask < cap) {
            mask *= 2;
        }
        return mask;
    }

    bool IsEmpty() {
        return _size == 0;
    }

    void resize(int n) {
        int newCap = CeilToPowerOfTwo(n);
        vector<byte> newContainer(newCap);
        int ret = read(newContainer);
        _container.swap(newContainer);

        // update basic information;
        _read = 0;
        _write = ret;
        _mask = newCap - 1;
    }

private:
    vector<byte> _container;

    int _size = 0;
    int _read = 0;
    int _write = 0;
    int _mask = 0;
};