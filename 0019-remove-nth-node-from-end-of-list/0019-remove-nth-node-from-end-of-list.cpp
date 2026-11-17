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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) return NULL;
        ListNode *temp = head;
        int cnt = 1;
        while(temp->next){
        
            temp =temp->next;
            cnt++;
        }
        int ans = cnt - n;
        if(ans==0)return head->next;
        
        int cnt2 = 1;
        temp = head;
        while(cnt2 != ans && temp->next){
            temp = temp->next;
            cnt2++;
        }
        ListNode *Node_to_delete = temp->next;
        temp->next = Node_to_delete->next;
        Node_to_delete->next = NULL;

        return head;

    }
};