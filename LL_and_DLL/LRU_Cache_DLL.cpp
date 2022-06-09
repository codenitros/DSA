// https://leetcode.com/problems/lru-cache/


// DLL and hashmap needed
// DLL will have key, value in least recently used from right to left (tail to head)
// hash map will have detail of where a particular key exists in DLL

// DLL here acts as a Queue
// In DLL Queue searching element takes linear time
// So we need hashmap which stores key-->address mapping

class LRUCache {
public:
    class node{
        public:
            int key;
            int val;

            node* next;
            node* prev;

            node(int k, int v){
                key = k;
                val = v;
            }
    };
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
    unordered_map<int, node*> mMap;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    
    void insertNode(node* newNode){
        node* temp = head->next;
        newNode->next = temp;
        temp->prev = newNode;
        newNode->prev = head;
        head->next = newNode;
    }
    
    void deleteNode(node* newNode){
        node* previ = newNode->prev;
        node* nexi = newNode->next;
        previ->next = nexi;
        nexi->prev = previ;
    }
    
    
    
    int get(int key) {
        if(mMap.find(key)!=mMap.end()){
            node* existingNode = mMap[key];
            mMap.erase(key);
            deleteNode(existingNode);
            insertNode(existingNode);
            mMap[key] = head->next;
            return existingNode->val;
        }else{
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        if(mMap.find(key)!=mMap.end()){
            node* existingNode = mMap[key];
            mMap.erase(key);
            deleteNode(existingNode);
        }
        
        if(mMap.size() == cap){
            mMap.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        insertNode(new node(key, value));
        mMap[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
