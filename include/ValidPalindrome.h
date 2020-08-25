//
// Created by wangbohan on 2020/8/25.
//

#ifndef DSAL_VALIDPALINDROME_H
#define DSAL_VALIDPALINDROME_H

#include <string>

using std::string;

class ValidPalindrome {
public:
    static bool validPalindrome(const string &s) {
        for (std::size_t i = 0, j = s.size() - 1;
             i < j;
             i++, j--) {
            if (s[i] != s[j]) return validPalindrome(s, i, j - 1) || validPalindrome(s, i + 1, j);
        }
        return true;
    }

private:
    static bool validPalindrome(string s, std::size_t i, std::size_t j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};

#endif //DSAL_VALIDPALINDROME_H
