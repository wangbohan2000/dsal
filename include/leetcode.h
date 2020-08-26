//
// Created by wbhan on 2020/8/25.
//

#ifndef DSAL_LEETCODE_H
#define DSAL_LEETCODE_H

#include <string>
#include <list>
#include <unordered_map>
#include <vector>


using std::string;
using std::size_t;
using std::list;
using std::unordered_map;
using std::pair;
using std::vector;
using std::copy;

class Solution {
public:

    /// 双指针

    // 88. 合并两个有序数组
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int tail = m + n - 1, tail1 = m - 1, tail2 = n - 1;
        while (tail != tail1) {
            if (tail1 >= 0 && nums1[tail1] > nums2[tail2]) nums1[tail--] = nums1[tail1--];
            else nums1[tail--] = nums2[tail2--];
        }
    }

    // 141. 环形链表
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    bool hasCycle(ListNode *head) {
        auto walker = head, runner = head;
        while (runner && runner->next) {
            walker = walker->next;
            runner = runner->next->next;
            if (walker == runner) return true;
        }
        return false;
    }

    // 146. LRU缓存机制
    class LRUCache {
    private:
        std::size_t cap_;
        list<pair<int, int>> cache_;
        unordered_map<int, decltype(cache_)::iterator> map_;
    public:
        LRUCache(int capacity) {
            this->cap_ = capacity;
        }

        int get(int key) {
            // 查询map
            const auto it = this->map_.find(key);
            // 没有返回-1
            if (it == this->map_.cend()) return -1;
            // 有则返回值，并提到头部
            this->cache_.splice(this->cache_.cbegin(), cache_, it->second);
            return it->second->second;
        }

        void put(int key, int value) {
            const auto it = this->map_.find(key);
            // 如果有，更新对应的值，并放到开头
            if (it != this->map_.cend()) {
                it->second->second = value;
                this->cache_.splice(this->cache_.cbegin(), cache_, it->second);
            }
                // 如果没有，先判断容量，不够则删除最后一个，然后在开头添加元素，然后添加到map
            else {
                if (this->cache_.size() == this->cap_) {
                    auto last = this->cache_.back();
                    this->map_.erase(last.first);
                    this->cache_.pop_back();
                }
                this->cache_.emplace_front(pair<int, int>{key, value});
                this->map_[key] = this->cache_.begin();
            }
        }
    };

    // 167. 两数之和 II - 输入有序数组
    vector<int> twoSum(vector<int> &numbers, int target) {
        std::size_t l = 0, r = numbers.size() - 1;
        while (l <= r) {
            auto sumNow = numbers[l] + numbers[r];
            if (sumNow > target) r--;
            else if (sumNow < target) l++;
            else return vector<int>{static_cast<int>(l + 1), static_cast<int>(r + 1)};
        }
        return vector<int>{};
    }

    // 680. 验证回文字符串 Ⅱ   删除s中的一个字符之后s为回文串则返回true
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            char c1 = s[l], c2 = s[r];
            if (c1 == c2) {
                ++l;
                --r;
            } else {
                return isPalindrome(s, l, r - 1) || isPalindrome(s, l + 1, r);
            }
        }
        return true;
    }

    bool isPalindrome(string s, std::size_t left, std::size_t right) {
        for (; left < right; left++, right--) {
            if (s[left] != s[right]) {
                return false;
            }
        }
        return true;
    }
};

#endif //DSAL_LEETCODE_H
