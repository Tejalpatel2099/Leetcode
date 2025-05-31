// A  LRU cache is Ds that stores limited number of items and evicts LRU item
// when capacity is exceeded. It supports get and put operations and our goal is
// to keep recently accessed items esaily available and remove older ones.
// implement LRU cache class that implements contructor that takes constructor
// where it takes capacity and initialize capacity.

// Questions:-
// 1. Can we assume that the capacity is always a positive integer greater than
// zero?
// 2. Are the key and value both integers, or should the cache support more
// generic types?
// 3. Should we overwrite the value if the same key is inserted again using
// put(key, value)?

// so , to achieve O(1) time for both get and put i can thinnk of is using
// hashmap - to store key and a pointer to node in DLL.(Node position) DLL -
// every node will  store actual key value pair Dummy head previous points to
// null and next to tail   and dummy tail previous points to head and nexct to
// null. and whenevr we will access (get) a key - move that node top front (most
// recent) and when (put) a key - if key exist , update its value and move front
// and if does not exist we will add a new node at front and if cache exceeds
// the capacity  we will remove the node at tail (least reecntly used). Time
// complexity :-  O(1) space complexity :- O(N) - hasmap and DLL both takes O(N)

class LRUCache {
public:
    // Define a doubly linked list node
    class Node {
    public:
        int key, value; // Each node stores a key-value pair
        Node* prev;     // Pointer to the previous node
        Node* next;     // Pointer to the next node

        // Constructor to initialize a new node with key and value
        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr; // Initialize pointers to null
        }
    };

    int cap; // Maximum capacity of the cache and its global variable
    unordered_map<int, Node*> m; // Hash map: key → actual key from put  and
                                 // value is related Node in DLL
    Node* head;                  // Dummy head of the doubly linked list
    Node* tail;                  // Dummy tail of the doubly linked list

    // Constructor: Initializes the cache with a given capacity
    LRUCache(int capacity) {
        cap = capacity;

        // Create dummy head and tail nodes with their values,
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        // Link dummy head and tail together
        head->next = tail;
        tail->prev = head;
    }

    // Returns the value of the key if present, else returns -1
    int get(int key) {
        // If key is found in map
        if (m.find(key) != m.end()) {
            Node* resNode = m[key];   // Get the node
            int res = resNode->value; // Store the result to return

            // I have to update order in DLL because of the LRU key
            // Move the accessed node to the front (most recently used)
            deleteNode(resNode); // Remove it from its current position
            addNode(resNode);    // Add it right after head

            return res; // Return the value
        }
        return -1; // Key not found
    }

    // i will just write helper function which will be use for get and put
    // Helper function to add a node right after the head (mark as most recently
    // used)
    void addNode(Node* newNode) {
        Node* temp = head->next; // Temporarily store the current first node
        head->next = newNode;    // Link head to the new node
        newNode->prev = head;    // Set new node's prev to head
        newNode->next = temp;    // Link new node to the old first node
        temp->prev = newNode;    // Set old first node's prev to new node
    }

    // Helper function to remove a node from the list
    void deleteNode(Node* delNode) {
        Node* prevNode = delNode->prev; // Get previous node
        Node* nextNode = delNode->next; // Get next node
        prevNode->next = nextNode;      // Link prev node to next node
        nextNode->prev = prevNode;      // Link next node back to prev node
    }

    // Insert or update a key-value pair
    void put(int key, int value) {
        // If key already exists
        if (m.find(key) != m.end()) {
            Node* existingNode = m[key]; // Get the existing node
            existingNode->value = value; // Update its value

            // Move it to the front
            deleteNode(existingNode);
            addNode(existingNode);
        } else {
            // If the cache is at full capacity
            if (m.size() == cap) {
                Node* lru = tail->prev; // Get the least recently used node
                                        // (just before tail)
                m.erase(lru->key);      // Remove it from the map
                deleteNode(lru);        // Remove it from the list
            }

            // Create a new node and add it to the front
            Node* newNode = new Node(key, value);
            addNode(newNode); // Insert it after head
            m[key] = newNode; // Add to the map
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */