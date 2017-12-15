/*
 * LRU Cache
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and set.
 *   get(key) - Get the value (will always be positive) of the key if the key
 *              exists in the cache, otherwise return -1.
 *   set(key, value) - Set or insert the value if the key is not already present.
 *                     When the cache reached its capacity, it should invalidate
 *                     the least recently used item before inserting a new item. 
 */

struct DL_Node {
    string key;
    void* data;
    DL_Node *prev;
    DL_Node *next;
    DL_Node(string k, void* d) : key(k), data(d), prev(NULL), next(NULL) {}
};
    
class DL_List {
private:
    DL_Node *head;
    DL_Node *tail;
    map<string&,DL_Node*> m;
    int used;
    int size;
public:
    DL_List() {
        head = new DL_Node("", NULL);
        tail = new DL_Node("", NULL);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    ~DL_List() {
        delete head;
        delete tail;
    }
    
    bool empty() {
        return (head->next == tail);
    }

    bool has_next(DL_Node* node) {
        return (node->next != tail);
    }

    DL_Node* get_next(Dl_Node* node) {
        return node->next;
    }

    int get(string& key, void* &data) {
        DL_Node *entry;
        void* data;
        if (m.find(key) != m.end()) {
            entry = m[key];
            detach(entry);
            data = entry->data;
            delete entry;
            return 0;
        }
        else {
            return -1;
        }
    }
    
    void append(string& key, void* data) {
        DL_Node *entry = new DL_Node(key, data);
        attach(entry);
        m[key] = entry;
    }

private:
    void attach(DL_Node* entry) {
        tail->prev->next = entry;
        entry->prev = tail->prev;
        tail->prev = entry;
        entry->next = tail;
    }
    void detach(DL_Node* entry) {
        entry->prev->next = entry->next;
        entry->next->prev = entry->prev;
    }
};
