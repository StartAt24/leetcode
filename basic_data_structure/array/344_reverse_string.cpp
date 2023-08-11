#include <vector>
using namespace std;

class solution{
public:
    void reverseString(vector<char>& s){
        int left = 0, right = s.size()-1;
        auto swap = [&](int l, int r) {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
        };

        while (left < right) {
            swap(left, right);
            left++;
            right--;
        }
    }
private:
};