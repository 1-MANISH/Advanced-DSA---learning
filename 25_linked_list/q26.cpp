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


class Node
{
    public:
        int key, value;
    Node *prev, *next;
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->prev = this->next = NULL;
    }
};

class LRUCache {
    public:
    Node * head;    //most recent used
    Node * tail;    // least recent used
    unordered_map<int, Node*> mapping;  //key->Node
    int currentSize, capacity;
    LRUCache(int capacity)
    {
        this->head = NULL;
        this->tail = NULL;
        this->capacity = capacity;
        this->currentSize = 0;
    }

    int get(int key)
    {
        auto ptr = mapping.find(key);
        if (ptr == mapping.end()) return -1;
        else
        {
            Node *node = ptr->second;
            if (currentSize == 1 || node == head) return head->value;
            else
            {
                if (node == tail)
                {
                    tail = node->prev;
                    tail->next = NULL;
                    node->next = head;
                    head->prev = node;
                    node->prev = NULL;
                    head = node;
                    return head->value;
                }
                else
                {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                    node->prev = NULL;
                    node->next = head;
                    head->prev = node;
                    head = node;
                    return head->value;
                }
            }
        }
    }

    void put(int key, int value)
    {
        auto ptr = mapping.find(key);
        if (ptr != mapping.end())
        {
            Node *node = ptr->second;
            Node* prevNode = node->prev;
            Node* nextNode = node->next;
            if(capacity==1 || node==head){
                node->value=value;
                return;
            }else if(node==tail){
                prevNode->next=NULL;
                tail=prevNode;
                node->value=value;
                node->prev = NULL;
                node->next=head;
                head->prev=node;
                head=node;
                return;
            }else{
                prevNode->next=nextNode;
                nextNode->prev=prevNode;
                node->prev=NULL;
                node->next=head;
                head->prev=node;
                node->value=value;
                head=node;
                return;
            }
            
            
        }
        else
        {

            if (currentSize == 1 && currentSize == capacity)
            {
                auto ptr = mapping.find(tail->key);
                Node *currentNode = ptr->second;
                mapping.erase(ptr);
                currentNode->key = key;
                currentNode->value = value;
                head = tail = currentNode;
                mapping[key] = currentNode;
                return;
            }
            else if (currentSize == capacity)
            {
                auto ptr = mapping.find(tail->key);
                Node *tailNode = ptr->second;
                Node *prevNode = tailNode->prev;
                mapping.erase(ptr);
                Node *newNode = new Node(key, value);
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
                mapping[key] = head;
                delete tailNode;
                prevNode->next = NULL;
                tail = prevNode;
                return;
            }
            else
            {
                Node *newNode = new Node(key, value);
                newNode->next = head;
                if (head != NULL)
                    head->prev = newNode;
                else
                    tail = newNode;
                head = newNode;
                this->currentSize++;
                mapping[key] = head;
                return;
            }
        }
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