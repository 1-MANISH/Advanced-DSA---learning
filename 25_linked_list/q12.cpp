class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* nxt ;
        while(current!=NULL){
            nxt = current->next;
            current->next=prev;
            prev=current;
            current=nxt;
        }
        return prev;
    }
};