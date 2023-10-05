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
        // case 3: 写了并且已经进入下一轮
        // --w _ _ r--


        // --w---r---
        // case1: --w---***r
        // case2: **r--w---***

        // 应该根据实际读取的数据来赋值
        // 
        _read = (_read + s) & _mask;
        _size -= s;
        return s;
    }

    int write(const vector<byte>& in, int s) {
        if (_size + s > _container.size()) {
            resize(_size + s);
        }

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