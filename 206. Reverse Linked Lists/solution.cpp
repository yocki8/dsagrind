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
    ListNode* recur(ListNode* head){

        if(head==NULL || head->next==NULL) return head;
        ListNode* node = recur(head->next);
        node->next = head;
        head->next = NULL;
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        
        ListNode* tail = head;
        while(tail!=NULL && tail->next!=NULL) tail = tail->next;
        recur(head);
        return tail;
    }
};