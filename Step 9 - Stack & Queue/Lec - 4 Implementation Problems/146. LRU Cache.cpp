class LRUCache {
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int, Node*> mpp;

    void addNode(Node* newNode) 
    {
        newNode->next = head->next;
        newNode->prev = head;

        head->next->prev = newNode;
        head->next = newNode;

        mpp[newNode->key] = newNode;
    }

    void deleteNode(Node* temp) 
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        mpp.erase(temp->key);

        delete temp;
    }

public:
    LRUCache(int capacity) 
    {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) 
    {
        if (mpp.find(key) == mpp.end())
            return -1;

        Node* oldNode = mpp[key];
        int ans = oldNode->val;
        deleteNode(oldNode);
        Node* newNode = new Node(key, ans);
        addNode(newNode);
        return ans;
    }

    void put(int key, int value) 
    {
        if (mpp.find(key) != mpp.end())
            deleteNode(mpp[key]);
        else if (mpp.size() == capacity)
            deleteNode(tail->prev);

        Node* newNode = new Node(key, value);
        addNode(newNode);
    }
};
