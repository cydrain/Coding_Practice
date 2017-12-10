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

struct LRUEntry {
    int key;
    int data;
    LRUEntry *prev;
    LRUEntry *next;
    LRUEntry(int k, int d) : key(k), data(d), prev(NULL), next(NULL) {}
};
    
class LRUCache{
private:
    LRUEntry *head;
    LRUEntry *tail;
    vector<LRUEntry*> entries;
    map<int,LRUEntry*> m;
    int used;
    int size;
public:
    LRUCache(int capacity) {
        LRUEntry *entry;
        head = new LRUEntry(0, 0);
        tail = new LRUEntry(0, 0);
        for (int i = 0; i < capacity; i++) {
            entry = new LRUEntry(0, 0);
            entries.push_back(entry);
        }
        
        head->next = tail;
        tail->prev = head;
        used = 0;
        size = capacity;
    }
    
    int get(int key) {
        LRUEntry *entry;
        if (m.find(key) != m.end()) {
            entry = m[key];
            detach(entry);
            attach(entry);
            return entry->data;
        }
        else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        LRUEntry *entry;
        int old_key;
        if (m.find(key) != m.end()) {
            entry = m[key];
            entry->data = value;
            detach(entry);
            attach(entry);
        }
        else {
            if (used < size) {
                entry = entries[used++];
            }
            else {
                entry = tail->prev;
                m.erase(entry->key);
                detach(entry);
            }
            entry->key = key;
            entry->data = value;
            attach(entry);
            m[key] = entry;
        }
    }
private:
    void attach(LRUEntry* entry) {
        head->next->prev = entry;
        entry->next = head->next;
        head->next = entry;
        entry->prev = head;
    }
    void detach(LRUEntry* entry) {
        entry->prev->next = entry->next;
        entry->next->prev = entry->prev;
    }
};
