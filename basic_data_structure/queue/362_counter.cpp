#include <map>
#include <queue>

using namespace std;
class HitCounter{
public:
    HitCounter() {
    }

    void hit (int timestamp) {
        _hitMap[timestamp]++;
    }
    // timestamp是递增的, 即每次 调用 getHits传递进来的 timestamp都是慢慢变大的
    // 不会出现回头查询的情况

    int getHits(int timestamp) {
        int ret = 0;

        for(const auto [k, v] : _hitMap) {
            if ( timestamp - k <= 300) {
                ret += v;
            }
        }
        return ret;
    }

private:
    unordered_map<int, int> _hitMap;
};

class HitCounter2{
public:
    HitCounter2() {
    }

    void hit (int timestamp) {
        _hit.push(timestamp);
    }
    // timestamp是递增的, 即每次 调用 getHits传递进来的 timestamp都是慢慢变大的
    // 不会出现回头查询的情况
    // 所以每次getHits之后 需要把太久远的数据清除掉

    int getHits(int timestamp) {
        while(!_hit.empty() && timestamp - _hit.front() > 300) {
            _hit.pop();
        }

        return _hit.size();
    }

private:
    std::queue<int> _hit;
};