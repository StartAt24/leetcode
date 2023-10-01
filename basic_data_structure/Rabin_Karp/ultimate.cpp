#include "common.hpp"

int rabinKarp(string txt, string pat) {
    const int L = pat.length();
    const int R = 256;
    // 取一个比较大的素数作为求模的除数
    // 比较大可以 reduce hash collision.
    // 素数可以 reduce hash collision.
    const long Q = 1658598167;
    // R^(L-1) 的结果
    long RL = 1;
    for (int i = 1; i <= L-1; i++) {
        RL = (RL * R) % Q;
    }

    // 计算模式串的哈希，时间O(L)
    long patHash = 0;
    for (int i = 0; i < pat.length(); i++) {
        patHash = (R * patHash + pat[i]) % Q;
    }

    long windowHash = 0;

    int left = 0, right = 0;
    while (right < txt.length()) {
        windowHash = ((R * windowHash) % Q + txt[right]) % Q;
        right ++;

        if (right - left == L) {
            if (windowHash == patHash) {
                if (pat.compare(txt.substr(left, L)) == 0) {
                    return left;
                }
            }
        }

        windowHash = (windowHash - (txt[left] * RL)%Q + Q) % Q;
        left++;
    }

    return -1;
}