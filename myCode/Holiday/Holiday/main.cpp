//
//  main.cpp
//  Holiday
//
//  Created by caiyd on 17/12/18.
//  Copyright © 2017年 caiyd. All rights reserved.
//
// 如果某天是法定节假日，标记为NOMINAL；
// 如果法定节假日是周六或周日，则被调休到顺延的工作日，标记为OBSERVED。
// 如某法定节假日刚好是周五、周六、周日；
// 则调休后，实际休假日为周五、周一、周二。
// 之上的例子用正面的数据结构表示：
// struct EvtOcr {
//     int startDate;   (included)
//     int endDate;     (excluded)
//     int type;        (NOMINAL|OBSERVED)
// }
// vector<EvtOcr> A = {1, 4, NOMINAL}
// vector<EvtOcr> B = {1, 2, OBSERVED}, {4, 6, OBSERVED}
//
// 现在有两个列表，一个记录了nominal的EvtOcr，一个记录了observed的EvtOcr。
// 要求把这两个列表合并，并有如下要求：
// 1. 每一天只出现一次
// 2.
// 3. 代码尽量简短
// 4. 新创建的object尽量少
//
// 上面的例子返回值为｛1,2,NOM|OBS},{2,4,NOM},{4,6,OBS}

#include <vector>
#include <iostream>
#include <string>
using namespace std;

#define NOM     0x01
#define OBS     0x02

struct EvtOcr {
    int startDate;
    int endDate;
    int type;
    EvtOcr(int s, int e, int t):startDate(s),endDate(e),type(t){}
};

void printEvtOcr(vector<EvtOcr*> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i]->startDate << ", ";
        cout << v[i]->endDate << ", ";
        switch (v[i]->type) {
            case NOM:
                cout << "NOM" << endl;
                break;
            case OBS:
                cout << "OBS" << endl;
                break;
            case NOM|OBS:
                cout << "NOM|OBS" << endl;
                break;
            default:
                break;
        }
    }
}

void merge(vector<EvtOcr*> &nominal, vector<EvtOcr*> &observed, vector<EvtOcr*> &res) {
    int i;
    while (nominal.size() && observed.size()) {
        if (nominal[0]->endDate < observed[0]->startDate) {
            res.push_back(nominal[0]);
            nominal.erase(nominal.begin());
        } else if (observed[0]->endDate < nominal[0]->startDate) {
            res.push_back(observed[0]);
            observed.erase(observed.begin());
        } else {
            if (nominal[0]->startDate < observed[0]->startDate) {
                res.push_back(new EvtOcr(nominal[0]->startDate, observed[0]->startDate-1, nominal[0]->type));
                nominal[0]->startDate = observed[0]->startDate;
            } else if (observed[0]->startDate < nominal[0]->startDate) {
                res.push_back(new EvtOcr(observed[0]->startDate, nominal[0]->startDate-1, observed[0]->type));
                observed[0]->startDate = nominal[0]->startDate;
            } else {
                if (nominal[0]->endDate < observed[0]->endDate) {
                    nominal[0]->type |= OBS;
                    res.push_back(nominal[0]);
                    observed[0]->startDate = nominal[0]->endDate + 1;
                    nominal.erase(nominal.begin());
                } else if (observed[0]->endDate < nominal[0]->endDate) {
                    observed[0]->type |= NOM;
                    res.push_back(observed[0]);
                    nominal[0]->startDate = observed[0]->endDate + 1;
                    observed.erase(observed.begin());
                } else {
                    nominal[0]->type |= OBS;
                    res.push_back(nominal[0]);
                    nominal.erase(nominal.begin());
                    observed.erase(observed.begin());
                }
            }
        }
    }
    for (i = 0; i < nominal.size(); i++) {
        res.push_back(nominal[i]);
    }
    for (i = 0; i < observed.size(); i++) {
        res.push_back(observed[i]);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<EvtOcr*> nominal;
    vector<EvtOcr*> observed;
    vector<EvtOcr*> res;
    
    //nominal.push_back(new EvtOcr(1,4,NOM));
    nominal.push_back(new EvtOcr(1,2,NOM));
    nominal.push_back(new EvtOcr(3,7,NOM));
    nominal.push_back(new EvtOcr(10,16,NOM));
    
    observed.push_back(new EvtOcr(1,2,OBS));
    observed.push_back(new EvtOcr(4,6,OBS));
    observed.push_back(new EvtOcr(9,11,OBS));
    observed.push_back(new EvtOcr(16,17,OBS));
    
    merge(nominal, observed, res);
    printEvtOcr(res);
    
    return 0;
}

