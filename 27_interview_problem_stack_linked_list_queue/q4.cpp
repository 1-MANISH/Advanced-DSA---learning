#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below.
    LRUCache(int capacity) -- initialize the cache with the given capacity.
    int  get(int key)      -- return the value if present, else -1.
    void put(int key, int value) -- insert/update; evict the least recently
                                    used entry if the capacity is exceeded.
    Both get and put must run in O(1) average time.
*/

class Node{
    public:
    int key,value;
    Node* prev,*next;
    Node(int key,int value){
        this->key=key;
        this->value=value;
        this->prev=this->next=NULL;
    }
};

class LRUCache {
    Node* head,*tail;
    int max_size,current_size;
    unordered_map<int,Node*>mapping;

    void deleteNode(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        if(prev!=NULL)
            prev->next=next;
        else
            head=next;
        if(next!=NULL)
            next->prev=prev;
        else
            tail=prev;

        node->prev=NULL;
        node->next=NULL;
        mapping.erase(node->key);
        current_size--;
        delete node;
    }

    void addNewNodeAtHead(int key,int value){
        Node* newNode = new Node(key,value);
        if(current_size==0){
            head=tail=newNode;
            mapping[key]=head;
            current_size++;
            return;
        }
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        mapping[key]=head;
        current_size++;
    }
public:
    LRUCache(int capacity) {
        this->max_size=capacity;
        this->current_size=0;
    }
    
    int get(int key) {
        if(current_size==0) return -1; // no values - empty
        auto it = mapping.find(key);
        if(it==mapping.end())return -1;// key not exist
        if(it->second==head)return head->value;// head  wants then no issue - already most-recent used
        // delete that node  - make new node and insert at head 
        Node* nodeToDelete = it->second;
        int value=nodeToDelete->value;
        deleteNode(nodeToDelete);
        addNewNodeAtHead(key,value);
        return head->value;
    }
    
    void put(int key, int value) {
        if(current_size==0){// edge case - new node
            addNewNodeAtHead(key,value);
            return;
        }
        auto it = mapping.find(key);
        if(it!=mapping.end()){// key_exist - overwrite or delete this one add new node at head
            Node* nodeToDelete = it->second;
            deleteNode(nodeToDelete);
            addNewNodeAtHead(key,value);
            return;
        }
        if(current_size < max_size){// as usual insert node at head 
            addNewNodeAtHead(key,value);
            return;
        }
        // over putting -  delete least used-TAIL and insert at head
        deleteNode(tail);
        addNewNodeAtHead(key,value);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cap, q;
    cin >> cap >> q;

    LRUCache cache(cap);

    string op;

    while (q--)
    {
        cin >> op;

        if (op == "get")
        {
            int k;
            cin >> k;
            cout << cache.get(k) << '\n';
        }
        else
        {
            int k, v;
            cin >> k >> v;
            cache.put(k, v);
            cout << "null" << '\n';
        }
    }

    return 0;
}