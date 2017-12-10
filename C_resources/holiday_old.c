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

bool lessThan(EvtOcr *e1, EvtOcr *e2) {
    if (e1->endDate < e2->endDate) {
        return true;
    }
    else if (e1->endDate > e2->endDate) {
        return false;
    }
    else {
        if (e1->startDate < e2->startDate) {
            return true;
        }
        else if (e1->startDate > e2->startDate) {
            return false;
        }
    }
    return false;
}

EvtOcr* createEvtOcr(int start, int end, int type) {
    if (start >= end) return NULL;
    return (new EvtOcr(start, end, type));
}

void merge2EvtOcr(EvtOcr *e1, EvtOcr *e2, vector<EvtOcr*> &res) {
    EvtOcr *newEvt;
    if (e1->startDate == e1->endDate) return;
    if (e1->endDate <= e2->startDate) {
        res.push_back(e1);
        return;
    }

    if (e1->startDate < e2->startDate) {
        newEvt = createEvtOcr(e1->startDate, e2->startDate, e1->type);
        res.push_back(newEvt);
        e1->startDate = e2->startDate;
    }
    else if (e1->startDate > e2->startDate) {
        newEvt = createEvtOcr(e2->startDate, e1->startDate, e2->type);
        res.push_back(newEvt);
        e2->startDate = e1->startDate;
    }

    e1->type |= e2->type;
    res.push_back(e1);
    e2->startDate = e1->endDate;
    return;
}

void merge(vector<EvtOcr*> &nominal, vector<EvtOcr*> &observed, vector<EvtOcr*> &res) {
    vector<EvtOcr*> total;
    int i = 0, j = 0;
    while (i < nominal.size() && j < observed.size()) {
        if (lessThan(nominal[i], observed[j])) {
            total.push_back(nominal[i++]);
        }
        else {
            total.push_back(observed[j++]);
        }
    }
    while (i < nominal.size()) {
        total.push_back(nominal[i++]);
    }
    while (j < observed.size()) {
        total.push_back(observed[j++]);
    }

    for (i = 1; i < total.size(); i++) {
        merge2EvtOcr(total[i-1], total[i], res);
    }
    i--;
    if (total[i]->startDate != total[i]->endDate) {
        res.push_back(total[i]);
    }
}

int main(void) {
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

