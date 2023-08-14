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
        auto pos = head;

        while (pos->next)
        {
            auto cur = pos;
            int min = pos->val;
            auto min_el = pos;
            
            while (cur)
            {
                if (cur->val < min)
                {
                    min = cur->val;
                    min_el = cur;
                }
                cur = cur->next;
            }

            std::swap(min_el->val, pos->val);
            pos = pos->next;
        }

        return head;
    }
};
