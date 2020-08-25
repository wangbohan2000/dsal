#include "LRUCache.h"
#include <ValidPalindrome.h>
#include <iostream>

int main(int argc, char **argv) {
    ValidPalindrome v;
    auto res = v.validPalindrome("abca");
    std::cout << res << std::endl;
    return 0;
}