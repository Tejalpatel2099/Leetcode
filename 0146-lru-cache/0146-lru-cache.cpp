class LRUCache {
    public:
        class Node {
        public:
        int key, value;
        Node* prev;
        Node* next;

        // constructor 
        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr; // preva and next pointers null 
        }
    };

    int cap;

    unordered_map<int, Node*> m;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;
     head = new Node(-1,  -1);
     tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
        
    }
    void addNode(Node* newNode) {
        // Always add new node right after head
        Node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }
    void deleteNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
     int get(int key) {
        if (m.find(key) != m.end()) {
            Node* resNode = m[key];
            int res = resNode->value;
            // Move the accessed node to the front
            deleteNode(resNode);
            addNode(resNode);
            return res;
        }
        return -1;
    }
    
   void put(int key, int value) {
        if (m.find(key) != m.end()) {
            // Update value and move node to front
            Node* existingNode = m[key];
            existingNode->value = value;
            deleteNode(existingNode);
            addNode(existingNode);
        } else {
            if (m.size() == cap) {
                // Remove least recently used (LRU)
                Node* lru = tail->prev;
                m.erase(lru->key);
                deleteNode(lru);
            }
            Node* newNode = new Node(key, value);
            addNode(newNode);
            m[key] = newNode;
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */