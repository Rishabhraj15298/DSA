class Solution {
private:
    ListNode* solve(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* next1 = curr1->next;
        ListNode* curr2 = list2;
        ListNode* next2 = curr2->next;

        while (next1 != nullptr && curr2 != nullptr) {
            if (curr2->val >= curr1->val && curr2->val <= next1->val) {
                // Insert curr2 between curr1 and next1
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;

                // Update pointers
                curr1 = curr2;
                curr2 = next2;
            } else {
                // Move curr1 and next1 forward
                curr1 = next1;
                next1 = next1->next;
                if (next1 == nullptr) {
                    // Append remaining elements of list2 to list1
                    curr1->next = curr2;
                    break;
                }
            }
        }
        return list1;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = list1;
        ListNode* prev = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                prev = list1;
                list1 = list1->next;
            } else {
                prev->next = list2;
                list2 = list2->next;
                prev->next->next = list1;
                prev = prev->next;
            }
        }

        if (list2 != nullptr) {
            prev->next = list2;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
