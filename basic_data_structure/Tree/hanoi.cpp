#include <iostream>

// 三个柱子的定义可能会根据所有情况有变化
void Hanoi(int size, int src, int dst, int mid) {
    if (size == 1) {
        Move(src, dst);
        return;
    }

    Hanoi(size-1, src, mid, dst);
    Move(src, dst);
    Hanoi(size-1, mid, dst, src);
}

void Move(int src, int dst) {

}