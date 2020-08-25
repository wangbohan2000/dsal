//
// Created by wangbohan on 2020/8/25.
//

#ifndef DSAL_TWOSUM_H
#define DSAL_TWOSUM_H

#include <vector>

using std::vector;

class TwoSum {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        std::size_t l = 0;
        std::size_t r = numbers.size() - 1;
        while (l <= r) {
            int sumNow = numbers[l] + numbers[r];
            if (target == sumNow) {
                return vector<int>{static_cast<int>(l) + 1, static_cast<int>(r) + 1};
            } else if (target > sumNow) {
                l++;
            } else if (target < sumNow) {
                r--;
            }
        }
        return vector<int>{};
    }
};

#endif //DSAL_TWOSUM_H
