//
// Created by wangbohan on 2020/8/25.
//

#ifndef DSAL_JUDGESQUARESUM_H
#define DSAL_JUDGESQUARESUM_H

class JudgeSquareSum {
public:
    bool judgeSquareSum(int c) {
        using ull = unsigned long long;
        // 判断是否有两个数的平方和等于c 输入5       1*1 + 2*2 == 5
        auto sq = sqrt(c);
        ull l = 0, r = static_cast<ull>(sq + 1);
        while (l <= r) {
            ull powSum = l * l + r * r;
            if (powSum == c) return true;
            else if (powSum < c) l++;
            else r--;
        }
        return false;
    }
};

#endif //DSAL_JUDGESQUARESUM_H
