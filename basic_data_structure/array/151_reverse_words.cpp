#include "common.hpp"
class Solution {
public:
    string reverseWords(string s) {
        string res;
        //step1: clean data;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c != ' '){
                res.append(1, c);
            }
            // 如果当前是字符串是空格,并且他的末尾没有添加过空格，则添加一个空格
            else if (!res.empty() && res.back() != ' ') {
                res.append(1, ' ');
            }
        }

        if (res.empty()) {
            return "";
        }
        // 刚刚的情况可能导致末尾有空格，清除后面的空格,至多只会有一个空格
        if (res.back() == ' '){
            res.erase(res.size() - 1);
        }

        // step2: reverse string
        swap(res, 0, res.size()-1);

        // step3: reverse each word and remove extra space;
        for (int i =0; i < res.size();) {
            for (int j = i; j < res.size(); j++) {
                // j is the last one or the next of j is empty
                if (j+1 == res.size() || res[j+1] == ' ') {
                    //the string is [i, j];
                    swap(res, i, j);
                    i = j + 2;
                    // break for loop;
                    break;
                }
            }
        }
        return res;
    }

private:
    void swap(string& s, int l, int r){
        while (l < r) {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r--;
        }
    }
};