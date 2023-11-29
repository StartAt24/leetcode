#include <map>
#include <list>
#include <string>
#include <queue>
using namespace std;

class SnakeGame{
public:
    SnakeGame(int width, int height, vector<vector<int>>& foodVec) {
        m = height;
        n = width;

        // initialize the position of snake
        set.insert(encode(0, 0));
        body.push_back(encode(0, 0));
        for (const auto& p: foodVec) {
            food.push_back(encode(p[0], p[1]));
        }

        alive = true;
    }

    int move(string direction) {
        if (!alive)
            return -1;

        int head = body.front();
        int x = head/n, y = head % n;
        // 计算移动之后的坐标
        int nx = x, ny = y;
        if (direction == "U") {
            nx--;
        }

        if (direction == "L") {
            ny--;
        }

        if (direction == "R") {
            ny++;
        }

        if (direction == "D") {
            nx++;
        }

        int code = encode(nx, ny);
        if (code < 0 || code > m*n) {
            alive = false;
            return -1;
        }
        // 前进
        body.push_back(code);
        if (!food.empty() && food.front() == code) {
            food.pop_front();
            // 吃到了食物，不删除尾巴
        } else {
            set.erase(body.back());
            body.pop_back();
        }

        if (set.count(code)) {
            // 咬到了自己
            alive = false;
            return -1;
        }

        set.insert(code);
        // 得分是食物个数即身体长度减一
        return body.size() - 1;
    }

private:
    // 将二位坐标 变成一维的index;
    int encode(int x, int y) {
        return x*n + y;
    }


    // a list to hold the position of body
    deque<int> body;
    // a set to hod the position of body;
    unordered_set<int> set;

    deque<int> food;

    // m x n board
    int m;
    int n;
    // 
    bool alive;
};