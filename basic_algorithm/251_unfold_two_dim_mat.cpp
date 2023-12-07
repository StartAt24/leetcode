#include <vector>
using namespace std;

class Vector2D{
public:
    Vector2D(vector<vector<int>> vec): _vec(vec) {

    }

    int next() {
        if(!hasNext())
            return -1;
        int ret = _vec[i][j];
        j++;
        return ret;
    }

    bool hasNext() {
        // this while will also skip empty array
        while(i<_vec.size() && j == _vec[i].size()) {
            // jump to next row
            i++;
            // reset j 
            j = 0;
        }

        if (i == _vec.size())
            return false;
        
        return true;
    }

private:
    vector<vector<int>> _vec;
    // use two index fot two dimension;
    int i = 0;
    int j = 0;
};
