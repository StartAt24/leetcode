#include <iostream>

// 用递归树来计算递归的时间复杂度 主要是节点个数和每个节点的单一时间复杂度


// 三个柱子的定义可能会根据所有情况有变化
// 参数含义为  hanoi 长度， 原始柱子，目标柱子，过度柱子。
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