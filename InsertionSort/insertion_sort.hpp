/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        auto new_head = new ListNode();
        auto pos = head;
        while (pos)
        {
            auto cur = new_head;
            bool flag = false;
            while (cur->next)
            {
                if (pos->val <= cur->next->val)
                {
                    auto tmp = cur->next;
                    cur->next = new ListNode(pos->val);
                    cur->next->next = tmp;
                    flag = true;
                    break;
                }

                cur = cur->next;
            }
            if (!flag)
                cur->next = new ListNode(pos->val);

            pos = pos->next;
        }

        return new_head->next;        
    }
};
