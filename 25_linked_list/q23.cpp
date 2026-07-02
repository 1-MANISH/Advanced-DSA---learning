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
    Return true if the linked list is a palindrome, otherwise false.
*/

bool isPalindrome(Node* head)
{
        if(head==NULL || head->next==NULL)return true;
        // find mid
        Node* slow=head,*fast=head->next,*mid;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        // reverse half
        mid=slow;
        Node* prev=NULL,*current=slow->next,*nxt;
        while(current!=NULL){
            nxt=current->next;
            current->next=prev;
            prev=current;
            current=nxt;
        }
        // connect both part
        mid->next=prev;
        slow=head,fast=prev;
        // check palindrom
        while(fast!=NULL){
            if(slow->val!=fast->val)return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    LinkedList ll;

    ll.build(n);

    cout << (isPalindrome(ll.head) ? "true" : "false") << '\n';

    return 0;
}
