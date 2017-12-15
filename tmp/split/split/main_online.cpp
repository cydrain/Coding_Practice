//
//  main.cpp
//  split
//
//  Created by caiyd on 17/12/14.
//  Copyright © 2017年 caiyd. All rights reserved.
//

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

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
    map<string,DL_Node*> m;
public:
    DL_List() {
        head = new DL_Node("", NULL);
        tail = new DL_Node("", NULL);
        head->next = tail;
        tail->prev = head;
    }
    ~DL_List() {
        delete head;
        delete tail;
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
    
    void* pop(string key) {
        DL_Node *entry;
        void* data;
        if (m.find(key) != m.end()) {
            entry = m[key];
            detach(entry);
            data = entry->data;
            delete entry;
            return data;
        }
        else {
            return NULL;
        }
    }
    
    void append(string key, void* data) {
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

enum order_cmd {
    ORDER_CMD_BUY = 0,
    ORDER_CMD_SELL,
    ORDER_CMD_CANCEL,
    ORDER_CMD_MODIFY,
    ORDER_CMD_PRINT
};

enum order_type {
    ORDER_TYPE_GFD = 0,
    ORDER_TYPE_IOC
};

struct order {
    order_cmd   cmd;
    order_cmd   cmd2;
    order_type  type;
    int         price;
    int         volume;
    char*       orderID;
    order(): cmd(ORDER_CMD_BUY), cmd2(ORDER_CMD_BUY), type(ORDER_TYPE_GFD), price(0), volume(0), orderID(NULL) {}
    ~order() { delete orderID; }
};

class MatchEngine {
private:
    DL_List* buy_list;
    DL_List* sell_list;
public:
    MatchEngine() {
        buy_list = new DL_List();
        sell_list = new DL_List();
    };
    void trade(order*, order*, int);
    void buy(order*);
    void sell(order*);
    void cancel(order*);
    void modify(order*);
    void print();
    void processOrder(order*);
    void parseLine(const string&);
    void run();
};

void MatchEngine::trade(order* o1, order* o2, int volume) {
    cout << "TRADE ";
    cout << o1->orderID << " " << o1->price << " " << volume << " ";
    cout << o2->orderID << " " << o2->price << " " << volume << endl;
}

void MatchEngine::buy(order* bo) {
    DL_Node *node, *next;
    order *so;
    int volume;
    node = sell_list->begin();
    while (bo->volume > 0 && node != sell_list->end()) {
        next = node->next;
        so = (order*)node->data;
        
        if (bo->price >= so->price) {
            volume = min(bo->volume, so->volume);
            trade(so, bo, volume);
            if (bo->volume >= so->volume) {
                bo->volume -= so->volume;
                sell_list->pop(so->orderID);
                delete so;
            } else {
                so->volume -= bo->volume;
                bo->volume = 0;
            }
        }
        node = next;
    }
    
    if (bo->volume == 0 || bo->type == ORDER_TYPE_IOC) {
        delete bo;
    } else {
        buy_list->append(bo->orderID, bo);
    }
}

void MatchEngine::sell(order* so) {
    DL_Node *node, *next;
    order *bo;
    int volume;
    node = buy_list->begin();
    while (so->volume > 0 && node != buy_list->end()) {
        next = node->next;
        bo = (order*)node->data;
        
        if (so->price <= bo->price) {
            volume = min(so->volume, bo->volume);
            trade(bo, so, volume);
            if (so->volume >= bo->volume) {
                so->volume -= bo->volume;
                buy_list->pop(bo->orderID);
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
        sell_list->append(so->orderID, so);
    }
}

void MatchEngine::cancel(order* o) {
    buy_list->pop(o->orderID);
    sell_list->pop(o->orderID);
}

void MatchEngine::modify(order* o) {
    order *o1;
    o1 = (order*)buy_list->pop(o->orderID);
    if (o1 == NULL) {
        o1 = (order*)sell_list->pop(o->orderID);
    }
    if (o1 == NULL) return;
    
    o1->cmd = o->cmd2;
    o1->price = o->price;
    o1->volume = o->volume;
    
    processOrder(o1);
}

void MatchEngine::print(void) {
    DL_Node* node;
    order* o;
    map<int,int,greater<int>> sm;
    map<int,int,greater<int>> bm;
    cout << "SELL:" << endl;
    if (!sell_list->empty()) {
        for (node = sell_list->begin(); node != sell_list->end(); node = node->next) {
            o = (order*)node->data;
            if (sm.find(o->price) != sm.end()) {
                sm[o->price] += o->volume;
            } else {
                sm[o->price] = o->volume;
            }
        }
        for (auto it = sm.begin(); it != sm.end(); ++it) {
            cout << it->first << " " << it->second << endl;
        }
    }
    
    cout << "BUY:" << endl;
    if (!buy_list->empty()) {
        for (node = buy_list->begin(); node != buy_list->end(); node = node->next) {
            o = (order*)node->data;
            if (bm.find(o->price) != bm.end()) {
                bm[o->price] += o->volume;
            } else {
                bm[o->price] = o->volume;
            }
        }
        for (auto it = bm.begin(); it != bm.end(); ++it) {
            cout << it->first << " " << it->second << endl;
        }
    }
}

void MatchEngine::processOrder(order* o) {
    switch (o->cmd) {
        case ORDER_CMD_BUY:
            cout << o->cmd << " " << o->type << " " << o->price << " " << o->volume << " " << o->orderID << endl;
            buy(o);
            break;
        case ORDER_CMD_SELL:
            cout << o->cmd << " " << o->type << " " << o->price << " " << o->volume << " " << o->orderID << endl;
            sell(o);
            break;
        case ORDER_CMD_CANCEL:
            cout << o->cmd << " " << o->orderID << endl;
            cancel(o);
            break;
        case ORDER_CMD_MODIFY:
            cout << o->cmd << " " << o->orderID << " " << o->cmd2 << " " << o->price << " " << o->volume << endl;
            modify(o);
            break;
        case ORDER_CMD_PRINT:
            cout << o->cmd << endl;
            print();
            break;
        default:
            break;
    }
}

void MatchEngine::parseLine(const string& buf) {
    order *o = new order();
    char *line, *p;
    line = strdup(buf.c_str());
    p = strtok(line, " ");
    if (strcmp(p, "BUY") == 0) {
        o->cmd = ORDER_CMD_BUY;
        p = strtok(NULL, " ");
        o->type = (strcmp(p, "GFD") == 0 ? ORDER_TYPE_GFD : ORDER_TYPE_IOC);
        o->price = atoi(strtok(NULL, " "));
        o->volume = atoi(strtok(NULL, " "));
        o->orderID = strdup(strtok(NULL, " "));
        processOrder(o);
    } else if (strcmp(p, "SELL") == 0) {
        o->cmd = ORDER_CMD_SELL;
        p = strtok(NULL, " ");
        o->type = (strcmp(p, "GFD") == 0 ? ORDER_TYPE_GFD : ORDER_TYPE_IOC);
        o->price = atoi(strtok(NULL, " "));
        o->volume = atoi(strtok(NULL, " "));
        o->orderID = strdup(strtok(NULL, " "));
        processOrder(o);
    } else if (strcmp(p, "CANCEL") == 0) {
        o->cmd = ORDER_CMD_CANCEL;
        o->orderID = strdup(strtok(NULL, " "));
        processOrder(o);
    } else if (strcmp(p, "MODIFY") == 0) {
        o->cmd = ORDER_CMD_MODIFY;
        o->orderID = strdup(strtok(NULL, " "));
        p = strtok(NULL, " ");
        o->cmd2 = (strcmp(p, "BUY") == 0 ? ORDER_CMD_BUY : ORDER_CMD_SELL);
        o->price = atoi(strtok(NULL, " "));
        o->volume = atoi(strtok(NULL, " "));
        processOrder(o);
    } else if (strcmp(p, "PRINT") == 0) {
        o->cmd = ORDER_CMD_PRINT;
        processOrder(o);
    }
    free(line);
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

