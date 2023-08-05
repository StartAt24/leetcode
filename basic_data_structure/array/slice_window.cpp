#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void Window1() {
    vector<char> s;
    map<char, int> window;
    int left = 0, right =0;
    while(left < right && right < s.size()) {
        // c is the next char to add to window;
        char c = s[right];
        window.insert(std::make_pair(s[left], left));
        // add the window size;
        right++;

        // while (window needs shrink) {
                // window.erase(std::make_pair())
                left++;
        // }

    }
}

void Window2(string s) {
    // a sutiable data structure to store the data;
    map<char, int> window;
    int left =0, right =0;

    while(right < s.size()) {
        // c is the element to be added to the window;
        char c = s[right];
        window.insert({c, right});
        right++;
        //!!! Update data in Window;

        // debug message here, you can check the content of the window;
        cout << "window: [" << s[left] << ":" << s[right] << ")" << endl;

        bool needShrink = false;

        while (left <right && needShrink) {
            char d = s[left];
            // d is the element to be removed from the window;
            // window.erase(d)
            left++;
            //!!! Update data in Window;
        }

    }

}