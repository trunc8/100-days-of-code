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

// Solution 1: Pretty bad, redundant, unclean
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

// Solution 2: Got rid of obvious redundancies
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3_root = new ListNode();
        ListNode* l3 = l3_root;
        int carry = 0;
        while( l1 and l2 ) {
            int sum = l1->val + l2->val + carry;
            l3->val = sum % 10;
            carry = sum/10;
            if ( l1->next or l2->next or carry )
                l3->next = new ListNode( carry );
                // If l1 or l2 nodes are left, overwrite val in next loop
            l1 = l1->next;
            l2 = l2->next;
            l3 = l3->next;
        }
        if( !l1 ) // If l1 is empty, make it point to l2
            l1 = l2;
        while( l1 ) {
            int sum = l1->val + carry;
            l3->val = sum % 10;
            carry = sum/10;
            if ( l1->next or carry )
                l3->next = new ListNode( carry );
            l1 = l1->next;
            l3 = l3->next;
        }        
        return l3_root;
    }
};

// Solution 3: Referred discussions. Uses ternary operator and some tricks
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3_root = new ListNode();
        ListNode* l3 = l3_root;
        int carry = 0;
        while( l1 or l2 or carry ) {
            int sum = ( l1 ? l1->val : 0 ) + 
                      ( l2 ? l2->val : 0 ) + 
                      carry;
            carry = sum/10;
            l3->next = new ListNode( sum % 10 );
            l3 = l3->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return l3_root->next;
    }
};
