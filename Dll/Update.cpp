//
// Created by Mateja on 5/2/2024.
//

#include "Update.h"

string Update::execute() {
    vector<string> v=FU::split(s,' ');

    if(v[2]!="SET")
        throw Exception("NE POSTOJI DATA KOMANDA " + v[2]);
    Table* t=dbms->checkTable(new Table(v[1]));
    if(!t)
        throw Exception("DATA TABELA NE POSTOJI" + v[1]);

    if(v.size()<4) throw Exception("NEDOSTAJE STA ZELITE DA UPDATE");
    vector<string> selector;
    vector<string> values;
    vector<string> v3=FU::split(v[3],',');
    for(const auto& i : v3)
    {
        vector<string> v4=FU::split(i,'=');
        selector.push_back(v4[0]);
        values.push_back(v4[1]);
        if(!t->checkRow(v4[0]))
            throw Exception("DATA KOLONA "+v4[0]+" NE POSTOJI");
    }

    if(v[4]!="WHERE")
        throw Exception("NE POSTOJI DATA KOMANDA " + v[4]);

    Wrapper* w=new Wrapper(5,v,selector,t);
    set<int>* ind=w->wrap();


        for(const auto& j : *ind)
            for(int i=0;i<values.size();i++)
                (*t->table)[selector[i]][j]=values[i];








        return "Kolona je ispesno update-ovana!\n";


}
