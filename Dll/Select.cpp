//
// Created by Mateja on 5/2/2024.
//

#include <iostream>
#include "Select.h"

using namespace std;


string Select::execute() {
    vector<string> q=FU::split(s, ' ');
    if (q.size() < 3) return "Nepravilna komanda";
    Table* t=this->dbms->checkTable(new Table(q[3]));
    if(!t)
        throw Exception("DATA TABELA NE POSTOJI");
    vector<string> selector;
    int vel=0;
    if(q[1]=="*")
        for(const auto& i : *t->table) {
            selector.push_back(i.first);
        }

    else {
        selector = FU::split(q[1], ',');
        for(const auto& i : selector)
            if(!t->checkRow(i))
                throw Exception("DATI RED "+ i+ " "+ " NE POSTOJI TABELI");
    }

    string sendJava = "";
    if(q.size()==4)
    {
        for(const auto& i : selector)
        {
            sendJava=sendJava+i+" ";
            vector<string> v=(*t->table)[i];
            for(const auto& j: v)
            {
                sendJava = sendJava + j + " ";
            }
            sendJava += "\n";
        }
        sendJava += "\n";
        return sendJava;
    }

    string str=q[4];
    if(str!="WHERE")
        throw Exception("NEPRAVILNO NAPISAN WHERE");
    int start=5;
    //odavde

    Wrapper* w=new Wrapper(start,q,selector,t);
    set<int>* ind=w->wrap();
    //dovde
    for(const auto& i : selector)
    {
        sendJava = sendJava + i + " ";
        for(const auto& j : *ind)
        {
            if((*t->table)[i][j].length()>1)
                sendJava=sendJava+(*t->table)[i][j]+" ";
        }
        sendJava += "\n";
    }
    sendJava += "\n";
    return sendJava;





}
