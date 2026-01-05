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
        ListNode* dummyHead = new ListNode(0); // Dummy node to simplify result list creation
        ListNode* current = dummyHead;
        int carry = 0; // Initialize carry
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Start with carry from the previous step
            
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10; // Compute carry for the next digit
            current->next = new ListNode(sum % 10); // Create a new node for the current digit
            current = current->next; // Move to the next node
        }
        
        return dummyHead->next; // Return the next node of dummy head (the actual result)
    }
};