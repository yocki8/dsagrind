class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int x) {
        
        int n = 0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            temp = temp->next;
            n++;
        }

        ListNode* header = new ListNode();
        header->next = head;

        x = n-x+1;
        temp = header;
        while(--x) temp = temp->next;

        temp->next = temp->next->next;
        return header->next;

    }
};