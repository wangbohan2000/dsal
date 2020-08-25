//
// Created by wangbohan on 2020/8/25.
//

#ifndef DSAL_HASCYCLE_H
#define DSAL_HASCYCLE_H

class HasCycle {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(nullptr) {}
    };

public:
    // 快慢指针，相遇即存在环
    bool hasCycle(ListNode *head) {
        auto walker = head;
        auto runner = head;
        while (runner && runner->next) {
            walker = walker->next;
            runner = runner->next->next;
            if (walker == runner) return true;
        }
        return false;
    }
};

#endif //DSAL_HASCYCLE_H
