//
// Created by wangbohan on 2020/8/25.
//

#ifndef DSAL_LRUCACHE_H
#define DSAL_LRUCACHE_H

#include <unordered_map>
#include <list>

class LRUCache {
private:
    int cap_;
    std::list<std::pair<int, int> > cache_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map_;
public:
    LRUCache(int capacity) {
        this->cap_ = capacity;
    }

    int get(int key) {
        // 如果没有，则返回-1
        const auto it = map_.find(key);
        if (it == map_.cend()) return -1;
        // 如果有，则返回并提前到头部
        cache_.splice(cache_.cbegin(), cache_, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        // 如果有，则修改，并提到头部
        const auto it = map_.find(key);
        if (it != map_.cend()) {
            it->second->second = value;
            cache_.splice(cache_.cbegin(), cache_, it->second);
        }
            // 如果没有，则判断cap，添加元素到头部
        else {
            if (cap_ == cache_.size()) {
                // 删掉最后一个元素
                const auto &node = cache_.back();
                map_.erase(node.first);
                cache_.pop_back();
            }
            cache_.emplace_front(key, value);
            map_[key] = cache_.begin();
        }
    }
};

#endif //DSAL_LRUCACHE_H
