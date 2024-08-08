//
// Created by Mateja on 5/2/2024.
//

#include <iostream>
#include "Delete.h"
using namespace std;

string Delete::execute() {
    vector<string> v=FU::split(s,' ');
    if(v[1]!="FROM")
        throw Exception("NE POSTOJI DATA KOMANDA " + v[1]);
    Table* t=dbms->checkTable(new Table(v[2]));
    if(!t)
        throw Exception("DATA TABELA NE POSTOJI" + v[2]);
    if(v[3]!="WHERE")
        throw Exception("NE POSTOJI DATA KOMANDA " + v[3]);

    vector<string> temp=FU::split(v[4],'=');
    vector<string> selector;
    selector.push_back(temp[0]);
    Wrapper* w=new Wrapper(4,v,selector,t);
    set<int> *ind=w->wrap();

    Table* t1=new Table(t->getName());
    for(auto& i: *t->table)
    {
        string key=i.first;
        t1->insertFirstRow(key);

        for(int j=0;j<i.second.size();j++)
        {
            auto it = ind->find(j);
            if (it == ind->end())
                t1->add(key,i.second[j]);
        }
    }
    string drop=string("DROP TABLE ")+t->getName();
    DropTable* d=new DropTable(drop,dbms);
    d->execute();
    dbms->addTable(t1);
    return "Uklanjanje kolona je uspesno izvrseno";

}
