//
// Created by Mateja on 5/2/2024.
//

#ifndef DATABASEPROJECT_WRAPPER_H
#define DATABASEPROJECT_WRAPPER_H

#include <string>
using namespace std;
#include "Table.h"
#include "Condition.h"


class Wrapper {  //klasa koja pripremi za proveru uslova
public:
    Wrapper(int s, vector<string> qq, vector<string> ss,Table* tt):start(s),q(qq),selector(ss),t(tt){}
    set<int>* wrap();

private:
    int start;
    vector<string> q;
    vector<string> selector;
    Table* t;

};


#endif //DATABASEPROJECT_WRAPPER_H
