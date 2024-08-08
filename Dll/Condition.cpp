//
// Created by Mateja on 5/2/2024.
//

#include "Condition.h"

bool Condition::check(string p)  {
    if(cmp=="=")
        return p==op;
    if(cmp==">")
        return p>op;
    return p<op;
}


set<int> *Condition::checkEverything() {
    int cnt=0;
    for(const auto& i: (*t->table)[row])
    {
        if(!check(i))
            sett->erase(cnt);

        cnt++;
    }

    return sett;
}

Condition::~Condition() {
    delete sett;

}
