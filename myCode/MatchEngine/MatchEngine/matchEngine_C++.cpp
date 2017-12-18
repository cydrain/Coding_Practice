/* Wrong Answer: 18, 22, 23 */
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

enum order_cmd {
    ORDER_CMD_NULL = 0,
    ORDER_CMD_BUY,
    ORDER_CMD_SELL,
    ORDER_CMD_CANCEL,
    ORDER_CMD_MODIFY,
    ORDER_CMD_PRINT
};

enum order_type {
    ORDER_TYPE_NULL = 0,
    ORDER_TYPE_GFD,
    ORDER_TYPE_IOC
};

struct order {
    order_cmd   cmd;
    order_cmd   cmd2;
    order_type  type;
    unsigned long price;
    unsigned long volume;
    char*       orderID;
    order(): cmd(ORDER_CMD_NULL), cmd2(ORDER_CMD_NULL), type(ORDER_TYPE_NULL), price(0), volume(0), orderID(NULL) {}
    ~order() { delete orderID; }
};

struct DL_Node {
    string key;
    order* data;
    DL_Node *prev;
    DL_Node *next;
    DL_Node(string k, order* d) : key(k), data(d), prev(NULL), next(NULL) {}
};

/* DL_List is a double-linked list in descending order */
class DL_List {
private:
    DL_Node *head;
    DL_Node *tail;
    map<string,DL_Node*> m;
    bool insert_dir;    /* True: if two elements have same key, insert to front;
                           False: if two elements have same key, insert to back. */
public:
    DL_List(bool flag) {
        head = new DL_Node("", NULL);
        tail = new DL_Node("", NULL);
        head->next = tail;
        tail->prev = head;
        insert_dir = flag;
    }
    ~DL_List() {
        DL_Node *node;
        for (node = head; node; head = head->next) {
            delete node;
        }
    }
    
    bool empty() {
        return (head->next == tail);
    }

    DL_Node* begin() {
        return head->next;
    }
    
    DL_Node* end() {
        return tail;
    }
    
    DL_Node *rbegin() {
        return tail->prev;
    }
    
    DL_Node *rend() {
        return head;
    }
    
    /* delete a node from double-linked list */
    order* erase(string key) {
        DL_Node *entry;
        order* data;
        auto it = m.find(key);
        if (it != m.end()) {
            entry = m[key];
            detach(entry);
            data = entry->data;
            delete entry;
            m.erase(it);
            return data;
        } else {
            return NULL;
        }
    }
    
    /* insert a node into double-linked list with descending order */
    void insert(string key, order* data) {
        DL_Node *entry = new DL_Node(key, data);
        attach(entry);
        m[key] = entry;
    }

private:
    void attach(DL_Node* entry) {
        DL_Node *node = head->next;
        if (insert_dir) {
            /* if price is same, insert to frond */
            while (node != tail && entry->data->price < node->data->price) {
                node = node->next;
            }
        } else {
            /* if price is same, insert to back */
            while (node != tail && entry->data->price <= node->data->price) {
                node = node->next;
            }
        }
        node->prev->next = entry;
        entry->prev = node->prev;
        node->prev = entry;
        entry->next = node;
    }
    void detach(DL_Node* entry) {
        entry->prev->next = entry->next;
        entry->next->prev = entry->prev;
    }
};

/* check string is all digits */
bool isDigit(const char* p) {
    while (*p != '\0') {
        if (*p < '0' || *p > '9') {
            return false;
        }
        p++;
    }
    return true;
}

class MatchEngine {
private:
    DL_List* buy_list;
    DL_List* sell_list;
public:
    MatchEngine() {
        buy_list = new DL_List(false);
        sell_list = new DL_List(true);
    };
    ~MatchEngine() {
        delete buy_list;
        delete sell_list;
    }
    void trade(order*, order*, unsigned long);
    void buy(order*);
    void sell(order*);
    void cancel(order*);
    void modify(order*);
    void print();
    void processOrder(order*);
    void parseLine(const string&);
    void run();
private:
    void printBookInfo(DL_List*);
};

void MatchEngine::trade(order* o1, order* o2, unsigned long volume) {
    cout << "TRADE ";
    cout << o1->orderID << " " << o1->price << " " << volume << " ";
    cout << o2->orderID << " " << o2->price << " " << volume << endl;
}

void MatchEngine::buy(order* bo) {
    DL_Node *node, *prev;
    order *so;
    unsigned long volume;
    
    /* check sell_list from tail to head (from price low to high) */
    node = sell_list->rbegin();
    while (bo->volume > 0 && node != sell_list->rend()) {
        prev = node->prev;
        so = (order*)node->data;
        
        if (bo->price >= so->price) {
            volume = min(bo->volume, so->volume);
            trade(so, bo, volume);
            if (bo->volume >= so->volume) {
                bo->volume -= so->volume;
                sell_list->erase(so->orderID);
                delete so;
            } else {
                so->volume -= bo->volume;
                bo->volume = 0;
            }
        }
        node = prev;
    }
    
    if (bo->volume == 0 || bo->type == ORDER_TYPE_IOC) {
        delete bo;
    } else {
        buy_list->insert(bo->orderID, bo);
    }
}

void MatchEngine::sell(order* so) {
    DL_Node *node, *next;
    order *bo;
    unsigned long volume;
    
    /* check buy_list from head to tail (from price high to low) */
    node = buy_list->begin();
    while (so->volume > 0 && node != buy_list->end()) {
        next = node->next;
        bo = (order*)node->data;
        
        if (so->price <= bo->price) {
            volume = min(so->volume, bo->volume);
            trade(bo, so, volume);
            if (so->volume >= bo->volume) {
                so->volume -= bo->volume;
                buy_list->erase(bo->orderID);
                delete bo;
            } else {
                bo->volume -= so->volume;
                so->volume = 0;
            }
        }
        node = next;
    }
    
    if (so->volume == 0 || so->type == ORDER_TYPE_IOC) {
        delete so;
    } else {
        sell_list->insert(so->orderID, so);
    }
}

void MatchEngine::cancel(order* o) {
    buy_list->erase(o->orderID);
    sell_list->erase(o->orderID);
}

void MatchEngine::modify(order* o) {
    order *o1 = NULL;
    if (o1 == NULL) o1 = buy_list->erase(o->orderID);
    if (o1 == NULL) o1 = sell_list->erase(o->orderID);
    if (o1 == NULL) return;
    
    o1->cmd = o->cmd2;
    o1->price = o->price;
    o1->volume = o->volume;
    
    processOrder(o1);
}

void MatchEngine::printBookInfo(DL_List* list) {
    DL_Node* node;
    order* o;
    unsigned long price = 0, volume = 0;
    if (!list->empty()) {
        for (node = list->begin(); node != list->end(); node = node->next) {
            o = node->data;
            if (o->price != price) {
                if (price != 0) {
                    cout << price << " " << volume << endl;
                }
                price = o->price;
                volume = o->volume;
            } else {
                volume += o->volume;
            }
        }
        cout << price << " " << volume << endl;
    }
}

void MatchEngine::print(void) {
    cout << "SELL:" << endl;
    printBookInfo(sell_list);
    cout << "BUY:" << endl;
    printBookInfo(buy_list);
}

void MatchEngine::processOrder(order* o) {
    switch (o->cmd) {
        case ORDER_CMD_BUY:
            buy(o);
            break;
        case ORDER_CMD_SELL:
            sell(o);
            break;
        case ORDER_CMD_CANCEL:
            cancel(o);
            break;
        case ORDER_CMD_MODIFY:
            modify(o);
            break;
        case ORDER_CMD_PRINT:
            print();
            break;
        default:
            break;
    }
}

void MatchEngine::parseLine(const string& buf) {
    order *o = new order();
    char *line, *p;
    
    try {
        line = strdup(buf.c_str());
        p = strtok(line, " ");
        if (p == NULL) throw exception();
        if (strcmp(p, "BUY") == 0 || strcmp(p, "SELL") == 0) {
            o->cmd = (*p == 'B' ? ORDER_CMD_BUY : ORDER_CMD_SELL);
            
            p = strtok(NULL, " ");
            if (!p || (strcmp(p, "GFD") && strcmp(p, "IOC"))) throw exception();
            o->type = (*p == 'G' ? ORDER_TYPE_GFD : ORDER_TYPE_IOC);
    
            p = strtok(NULL, " ");
            if (!p || !isDigit(p)) throw exception();
            o->price = strtoul(p, NULL, 10);
            
            p = strtok(NULL, " ");
            if (!p || !isDigit(p)) throw exception();
            o->volume = strtoul(p, NULL, 10);
            if (o->price <= 0 || o->volume <= 0) throw exception();
            
            p = strtok(NULL, " ");
            if (!p || *p == '\0') throw exception();
            o->orderID = strdup(p);
            
            /* check extra input */
            if (strtok(NULL, " ")) throw exception();
            
            processOrder(o);
        } else if (strcmp(p, "CANCEL") == 0) {
            o->cmd = ORDER_CMD_CANCEL;
            
            p = strtok(NULL, " ");
            if (!p || *p == '\0') throw exception();
            o->orderID = strdup(p);
            
            /* check extra input */
            if (strtok(NULL, " ")) throw exception();
            
            processOrder(o);
        } else if (strcmp(p, "MODIFY") == 0) {
            o->cmd = ORDER_CMD_MODIFY;
            
            p = strtok(NULL, " ");
            if (!p || *p == '\0') throw exception();
            o->orderID = strdup(p);
            
            p = strtok(NULL, " ");
            if (!p || (strcmp(p, "BUY") && strcmp(p, "SELL"))) throw exception();
            o->cmd2 = (*p == 'B' ? ORDER_CMD_BUY : ORDER_CMD_SELL);
    
            p = strtok(NULL, " ");
            if (!p || !isDigit(p)) throw exception();
            o->price = strtoul(p, NULL, 10);
            
            p = strtok(NULL, " ");
            if (!p || !isDigit(p)) throw exception();
            o->volume = strtoul(p, NULL, 10);
            if (o->price <= 0 || o->volume <= 0) throw exception();
            
            /* check extra input */
            if (strtok(NULL, " ")) throw exception();
            
            processOrder(o);
        } else if (strcmp(p, "PRINT") == 0) {
            o->cmd = ORDER_CMD_PRINT;
            
            /* check extra input */
            if (strtok(NULL, " ")) throw exception();
            
            processOrder(o);
        }
        free(line);
    }
    catch(...) {
        delete o;
        free(line);
    }
}

void MatchEngine::run() {
    string buf;
    while (getline(cin, buf)) {
        parseLine(buf);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    MatchEngine *me = new MatchEngine();
    me->run();
    return 0;
}

