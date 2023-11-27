#include <stack>
#include <map>

using namespace std;
class FreqStack{
public:
    void push(int val) {

    }

    int pop(){
        return -1;
    }

private:
    int _maxFreq;
    unordered_map<int, int> _freqToElement;
};