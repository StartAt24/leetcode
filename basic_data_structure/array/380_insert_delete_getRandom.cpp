#include <iostream>
#include <vector>
#include <map>
using std::unordered_map;
using std::vector;

class RandomizedSet {
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (_valToIndex.count(val))
            return false;
        
        _valToIndex[val] = _nums.size();
        _nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!_valToIndex.count(val))
            return false;

        int index = _valToIndex[val];
        _valToIndex[_nums.back()] = index;
        std::swap(_nums[index], _nums.back());
        _nums.pop_back();

        _valToIndex.erase(val);
        return true;

    }
    
    int getRandom() {
        return _nums[rand()%_nums.size()];
    }

private:
    // store the value of element
    vector<int> _nums;
    // store the index of each element
    unordered_map<int, int> _valToIndex;

};
