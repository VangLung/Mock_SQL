//
// Created by Mateja on 5/2/2024.
//

#ifndef DATABASEPROJECT_CONDITION_H
#define DATABASEPROJECT_CONDITION_H
#include <string>
using namespace std;
#include "Table.h"
#include <set>

class Condition {  //klasa koja proverava uslove
public:
    Condition(string s11, string o, string s22,Table* tabl,set<int>* sett1):row(s11),cmp(s22),op(o),t(tabl),sett(sett1){}
    bool check(string p);
    set<int>* checkEverything();
    ~Condition();

private:
    string row,op,cmp;
    Table* t;
    set<int>* sett;

};


#endif //DATABASEPROJECT_CONDITION_H
