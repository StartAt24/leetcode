#include "BTree.h"
class Solution {
    // code -> value，节点编码到节点值的映射
    unordered_map<int, int> tree;
    // 记录所有路径和
    int sum = 0;

public:
    int pathSum(vector<int>& nums) {
        for (int& code : nums) {
            int value = code % 10;
            code = code / 10;
            // 记录节点编码到值的映射
            tree[code] = value;
        }
        // 输入已经排序，第一个就是根节点
        int rootCode = nums[0] / 10;
        // 遍历二叉树求所有路径总和
        traverse(rootCode, 0);
        return sum;
    }
    
private:
    // 二叉树遍历函数，顺便记录遍历过得路径之和
    void traverse(int code, int path) {
        if (!tree.count(code)) {
            return;
        }
        // 当前遍历到的节点值
        int value = tree[code];
        int depth = code / 10, id = code % 10;
        // 左右子节点的编码
        int leftCode = encode(depth + 1, id * 2 - 1);
        int rightCode = encode(depth + 1, id * 2);

        if (!tree.count(leftCode) && !tree.count(rightCode)) {
            sum += path + value;
            return;
        }
        // 二叉树遍历框架
        traverse(leftCode, path + value);
        traverse(rightCode, path + value);
    }

    // 将 (depth, id) 编码为十进制两位数
    int encode(int depth, int id) {
        return 10 * depth + id;
    }
}