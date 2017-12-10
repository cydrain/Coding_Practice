// A simple LRU cache written in C++
// map (instead of hash_map) + double linked list
#include <iostream>
#include <vector>
#include <map>
using namespace std;

template <class K, class T>
struct Node {
    K key;
    T data;
    Node *prev, *next;
};

template <class K, class T>
class LRUCache {
    private:
        map<K, Node<K,T>* > hashmap_;
        vector<Node<K,T>* > free_entries_;  // available entries
        Node<K,T> *head_, *tail_;
        Node<K,T> *entries_;                // 

    private:
        void detach(Node<K,T>* node);
        void attach(Node<K,T>* node);

    public:
        LRUCache(size_t size);
        ~LRUCache();
        void Put(K key, T data);
        T Get(K key);
};

template <class K, class T>
LRUCache<K,T>::LRUCache(size_t size) {
    entries_ = new Node<K,T>[size];
    for (int i = 0; i < size; i++) {
        free_entries_.push_back(entries_+i);
    }

    head_ = new Node<K,T>;
    tail_ = new Node<K,T>;
    head_->prev = NULL;
    head_->next = tail_;
    tail_->prev = head_;
    tail_->next = NULL;
}

template <class K, class T>
LRUCache<K,T>::~LRUCache() {
    delete head_;
    delete tail_;
    delete []entries_;
}

template <class K, class T>
void LRUCache<K,T>::Put(K key, T data) {
    Node<K,T> *node = hashmap_[key];
    if (node) {
        node->data = data;
        detach(node);
        attach(node);
    }
    else {
        if (free_entries_.empty()) {
            node = tail_->prev;
            hashmap_.erase(node->key);
            detach(node);
        }
        else {
            node = free_entries_.back();
            free_entries_.pop_back();
        }
        node->key = key;
        node->data = data;
        hashmap_[key] = node;
        attach(node);
    }
}

template <class K, class T>
T LRUCache<K,T>::Get(K key) {
    Node<K,T> *node = hashmap_[key];
    if (node) {
        detach(node);
        attach(node);
        return node->data;
    }
    else {  // if not hit, return T's default
        return T();
    }
}

// detach node from the double linked list
template <class K, class T>
void LRUCache<K,T>::detach(Node<K,T>* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

// attach node to the front if the double linked list
template <class K, class T>
void LRUCache<K,T>::attach(Node<K,T>* node) {
    node->next = head_->next;
    node->prev = head_;
    head_->next->prev = node;
    head_->next = node;
}

int main() {
    LRUCache<int, string> lru_cache(100);
    lru_cache.Put(1, "one");
    cout << lru_cache.Get(1) << endl;
    if (lru_cache.Get(2) == "") {
        lru_cache.Put(2, "two");
    }
    cout << lru_cache.Get(2) << endl;
    cout << lru_cache.Get(3) << endl;
    return 0;
}

