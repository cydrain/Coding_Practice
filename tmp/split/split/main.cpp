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
using namespace std;

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

void processOrder(order* o) {
    switch (o->cmd) {
        case ORDER_CMD_BUY:
            cout << o->cmd << " " << o->type << " " << o->price << " " << o->volume << " " << o->orderID << endl;
            break;
        case ORDER_CMD_SELL:
            cout << o->cmd << " " << o->type << " " << o->price << " " << o->volume << " " << o->orderID << endl;
            break;
        case ORDER_CMD_CANCEL:
            cout << o->cmd << " " << o->orderID << endl;
            break;
        case ORDER_CMD_MODIFY:
            cout << o->cmd << " " << o->orderID << " " << o->cmd2 << " " << o->price << " " << o->volume << endl;
            break;
        case ORDER_CMD_PRINT:
            cout << o->cmd << endl;
            break;
        default:
            break;
    }
}

void parseLine(const string& buf) {
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
    } else if (strcmp(p, "SELL") == 0) {
        o->cmd = ORDER_CMD_SELL;
        p = strtok(NULL, " ");
        o->type = (strcmp(p, "GFD") == 0 ? ORDER_TYPE_GFD : ORDER_TYPE_IOC);
        o->price = atoi(strtok(NULL, " "));
        o->volume = atoi(strtok(NULL, " "));
        o->orderID = strdup(strtok(NULL, " "));
    } else if (strcmp(p, "CANCEL") == 0) {
        o->cmd = ORDER_CMD_CANCEL;
        o->orderID = strdup(strtok(NULL, " "));
    } else if (strcmp(p, "MODIFY") == 0) {
        o->cmd = ORDER_CMD_MODIFY;
        o->orderID = strdup(strtok(NULL, " "));
        p = strtok(NULL, " ");
        o->cmd2 = (strcmp(p, "BUY") == 0 ? ORDER_CMD_BUY : ORDER_CMD_SELL);
        o->price = atoi(strtok(NULL, " "));
        o->volume = atoi(strtok(NULL, " "));
    } else if (strcmp(p, "PRINT") == 0) {
        o->cmd = ORDER_CMD_PRINT;
    }
    processOrder(o);
    free(line);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string buf;
    while (getline(cin, buf)) {
        parseLine(buf);
    }
    return 0;
}
