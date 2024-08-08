//
// Created by Mateja on 5/2/2024.
//

#include "Wrapper.h"

set<int>* Wrapper::wrap() {
    vector<string> v;
    int vel;
      //treba
    for(int i=start;i<q.size();i++)  //pokupi uslove
        if(q[i]!="AND")
            v.push_back(q[i]);

    vector<string> v1;
    set<int> *ind=new set<int>();

    for(const auto& i : selector)  //prebroj broj vrsta
    {
        vel= (*t->table)[i].size();
        break;
    }
    for(int i=0;i<vel;i++)
    {
        ind->insert(i);
    }
    Condition* cond = nullptr;
    for(const auto& i : v)
    {
        if(i.find("=") != std::string::npos) {
            v1=FU::split(i,'=');
            if(!t->checkRow(v1[0]))
                throw Exception("DATI RED "+v1[0]+ " NE POSTOJI");
            cond=new Condition(v1[0],v1[1],"=",t,ind);

        }
        if(i.find(">") != std::string::npos) {
            v1=FU::split(i,'>');
            cond=new Condition(v1[0],v1[1],">",t,ind);

        }
        if(i.find("<") != std::string::npos) {
            v1=FU::split(i,'<');
            cond=new Condition(v1[0],v1[1],"<",t,ind);
        }

        ind=cond->checkEverything();

    }
    return ind;
}
