#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int v)
    {
        val = v;
        next = nullptr;
    }
};

class LinkedList {
public:

    Node* head;

    LinkedList()
    {
        head = nullptr;
    }

    void build(int n)
    {
        Node* tail = nullptr;

        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            Node* node = new Node(x);

            if(!head)
            {
                head = tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
        }
    }
};

/*
    Implement only the function below.
    Reverse the nodes of the list k at a time and return the new head.
    If the number of nodes is not a multiple of k, the leftover nodes at the
    end remain in their original order.
*/

int linkedListLength(Node* head){
        int len = 0 ;
        Node* current = head;
        while(current!=NULL){
            len++;
            current=current->next;
        }
        return len;
}

Node* reverseKGroup(Node* head, int k)
{
        if(head==NULL || head->next==NULL)return head;
        int n = linkedListLength(head);
        if(k>n)return head;
        int rem = n ,idx = 1 , left = 1 ,right = k;
        Node* lastHead=head,*newHead=head,*prev=NULL,*current=head,*nxt;
        while(rem-k>=0){
            while(idx<=right){
                nxt=current->next;
                current->next=prev;
                prev=current;
                current=nxt;
                idx++;
            }
            if(lastHead==newHead){
                head=prev;
                lastHead->next=current;
                newHead=current;
            }else{
                lastHead->next=prev;
                lastHead=newHead;
                lastHead->next=current;
                newHead=current;
            }
            rem-=k;
            left = idx;
            right=left+k-1;
        }
        return head;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    int k;
    cin >> k;

    ll.head = reverseKGroup(ll.head, k);

    Node* cur = ll.head;

    bool first = true;

    while(cur)
    {
        if(!first)
        {
            cout << ' ';
        }

        first = false;

        cout << cur->val;

        cur = cur->next;
    }

    cout << '\n';

    return 0;
}