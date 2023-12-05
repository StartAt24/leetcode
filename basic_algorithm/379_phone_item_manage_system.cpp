#include <queue>
#include <set>

using namespace std;

class PhoneDirectory {
public:
    PhoneDirectory(int maxNumbers) {
        while(maxNumbers) {
            _availables.push(maxNumbers--);
        }
    }

    int get() {
        if (_availables.empty())
            return -1;
        int number = _availables.front();
        _availables.pop();
        _used.insert(number);
        return number;
    }

    bool check(int number) {
        return !_used.contains(number);
    }

    void release(int number) {
        if(_used.contains(number)) {
            _used.erase(number);
            _availables.push(number);
        }
    }

private:
    queue<int> _availables;
    unordered_set<int> _used;
};