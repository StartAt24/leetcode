#include <vector>
using std::vector;

class solution {
public:
    int maxSubSequence(vector<int> arr) {
        // loop
        int max = 0;
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            for (int j = i; j < arr.size(); j++) {
                sum = arr[i] + arr[j];
            }
            
        }
    }
}