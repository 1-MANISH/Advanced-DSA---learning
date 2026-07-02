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
    The list is sorted in non-decreasing order. Delete all duplicates so that
    each value appears only once, and return the head of the modified list.
*/

Node* deleteDuplicates(Node* head)
{
        if(head==NULL || head->next==NULL)return head;
        Node* prev=head;
        Node* current=head->next;
        while(current!=NULL){
            while(current!=NULL && prev->val==current->val){
                current=current->next;
            }
            if(current){
                prev->next=current;
                prev=current;
                current=current->next;
            }else{
                prev->next=NULL;
            }
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

    ll.head = deleteDuplicates(ll.head);

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
