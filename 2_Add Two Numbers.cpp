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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* soln = new ListNode();
        ListNode* l3 = soln;
        int carry = 0;
        while (l1 != nullptr and l2 != nullptr) {
            int sum = l1->val + l2->val + carry;
            l3->val = sum % 10;
            carry = sum/10;
            if (l1->next != nullptr or l2->next != nullptr)
                l3->next = new ListNode();
            else if (l1->next == nullptr and l2->next == nullptr and carry == 1)
                l3->next = new ListNode(1);
            l1 = l1->next;
            l2 = l2->next;
            l3 = l3->next;
        }
        while (l1 != nullptr) {
            int sum = l1->val + carry;
            l3->val = sum % 10;
            carry = sum/10;
            if (l1->next != nullptr)
                l3->next = new ListNode();
            else if (carry == 1)
                l3->next = new ListNode(1);
            l1 = l1->next;
            l3 = l3->next;
        }
        while (l2 != nullptr) {
            int sum = l2->val + carry;
            l3->val = sum % 10;
            carry = sum/10;
            if (l2->next != nullptr)
                l3->next = new ListNode();
            else if (carry == 1)
                l3->next = new ListNode(1);
            l2 = l2->next;
            l3 = l3->next;
        }
        
        
        return soln;
    }
};
