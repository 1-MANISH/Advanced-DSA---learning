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
    Reverse the nodes from position left to right (1-indexed, inclusive)
    and return the head of the modified list.
*/

Node* reverseBetween(Node* head, int left, int right)
{
    if(head==NULL || head->next==NULL)return head;
    if(left>right)return head;

    Node* current=head,
    *lastHead=head,
    *newHead,*prev=NULL,*nxt=NULL;
    int idx= 1;
    while(idx<left && current!=NULL){
        lastHead=current;
        current=current->next;
        idx++;
    }
    idx=left;
    newHead = current;
    // reverse left->right nodes
    while(idx<=right && current!=NULL){
        nxt=current->next;
        current->next=prev;
        prev=current;
        current=nxt;
        idx++;
    }

    // join links
    if(lastHead==newHead){//reversing from first node
        newHead->next=current;
        return prev;
    }else{
        lastHead->next=prev;
        newHead->next=current;
        return head;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    int left, right;
    cin >> left >> right;

    ll.head = reverseBetween(ll.head, left, right);

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