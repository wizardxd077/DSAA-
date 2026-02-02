class Solution {                           // Define the Solution class
public:                                   // Public access specifier

    ListNode* mergeTwoLists(ListNode* l1,  // Function to merge two sorted linked lists
                            ListNode* l2) 
    {                                     

        // If first list is empty, return second list
        if (l1 == NULL) 
            return l2;

        // If second list is empty, return first list
        if (l2 == NULL) 
            return l1;

        // Ensure l1 starts with smaller value
        if (l1->val > l2->val) 
            std::swap(l1, l2);

        // res will store the head of the merged list
        ListNode* res = l1;

        // Continue merging while both lists have nodes
        while (l1 != NULL && l2 != NULL) {

            // Pointer to track last valid node in l1
            ListNode* tmp = NULL;

            // Move forward in l1 while its values are smaller or equal to l2
            while (l1 != NULL && l1->val <= l2->val) {
                tmp = l1;                 // Store current node
                l1 = l1->next;            // Move l1 forward
            }

            // Connect last smaller node of l1 to l2
            tmp->next = l2;

            // Swap l1 and l2 so l1 always points to smaller list
            std::swap(l1, l2);
        }

        // Return the head of merged list
        return res;
    }
};
