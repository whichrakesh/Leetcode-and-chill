class Node{
    public:
    Node(int key, int val, Node* prev, Node *next){
        this->prev = prev;
        this->next = next;
        this->value = val;
        this->key = key;
    }
    Node *prev, *next;
    int value;
    int key;
};

class LRUCache {
    Node *front, *back;
    unordered_map<int, Node*> map;
    int capacity;
    int length;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->length = 0;
        front = NULL;
        back = NULL;
        map = unordered_map<int, Node*>();
    }
    
    void putBack(int key){
        Node* node = map[key];
        if(back != node){
            if(node->next != NULL){
                node->next->prev = node->prev;    
            }
            if(node->prev != NULL){
                node->prev->next = node->next;    
            } else {
                front = node->next;
            }
            back->next = node;
            node->prev = back;
            node->next = NULL;
            back = node;   
        }
    }
    
    int get(int key) {
        if(map[key] != NULL){
            if(length != 1){
                putBack(key);
            }
            return map[key]->value;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(map[key] != NULL){
            map[key]->value = value;
            if(length != 1){
                putBack(key);
            }
        } else {
            if(length < capacity){
                Node* newNode = new Node(key, value, back, NULL);
                map[key] = newNode;
                if(back != NULL){
                    back->next = newNode;   
                } else {
                    front = newNode;
                }
                back = newNode;
                length++;
            } else if(length == 1 && capacity == 1){
                Node* newNode = new Node(key, value, NULL, NULL);
                map[front->key] = NULL;
                delete front;
                map[key] = newNode;
                front = newNode;
                back = newNode;
            }
            else{
                Node* newNode = new Node(key, value, back, NULL);
                map[front->key] = NULL;
                if(front->next != NULL){
                    front->next->prev = NULL;   
                }
                Node *oldFront = front;
                front = front->next;
                delete oldFront;
                
                back->next = newNode;
                newNode->prev = back;
                newNode->next = NULL;
                back = newNode;
                map[key] = newNode;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */