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
    Reorder the list in place from
        L0 -> L1 -> ... -> Ln-1
    to
        L0 -> Ln-1 -> L1 -> Ln-2 -> L2 -> ...
    Do not return anything; modify the list in place.
*/

void reorderList(Node* head)
{
        if(head==NULL || head->next==NULL)return;
        Node* p1,*p2,*slow=head,*fast=head->next,*current,*nxt,*t1,*t2,*prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        current=slow->next;
        while(current!=NULL){
            nxt=current->next;
            current->next=prev;
            prev=current;
            current=nxt;
        }
        slow->next=prev;
        p1=head,p2=prev;
        while(p2!=NULL){
            t1=p1->next;
            t2=p2->next;
            p1->next=p2;
            if(t1!=prev)
                p2->next=t1;
            p1=t1;
            p2=t2;
        }
        if(t1==slow)
        slow->next=NULL;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    reorderList(ll.head);

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