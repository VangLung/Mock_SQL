//
// Created by mateja on 1.5.24..
//

#include "Table.h"
#include <iostream>

using namespace std;


Table::Table(string t) {
    this->tableName= t;
    this->table=new map<string, vector<string>>();

}

int Table::insertFirstRow(string s) {
    this->table->insert({s,{}});
    return 1;
}

ostream &operator<<(ostream &os, const Table &d) {
    cout<<d.tableName<<endl;
    for(const auto& i: *d.table)
    {
        cout<<i.first<<" ";
        for(const auto &j : i.second)
            cout<<j<<" ";

        cout<<endl;

    }
    return os;
}

int Table::add(string key, string value) {
    (*table)[key].push_back(value);
    return 1;
}




Table *Table::CreateTable(string s) {
    //CREATE TABLE naziv_tabele (id,ime,prezime,pozicija)



    vector<string> v=FU::split(s,' ');    //splituj sa razmakom

    if(v.size()!=4)
        throw Exception("lose kreirano");

    if(v[0]!="CREATE" && v[1]!="TABLE" || v[2].find_first_of("0123456789")!= string::npos)     //proveri format create-a
        throw Exception("lose kreirano");

    Table* d=new Table(v[2]);
    s=v[3];
    v=FU::split(s,'(');     //splituj naziv od naziva vrsta


    s=v[0];
    v=FU::split(s,')');
    s=v[0];
    v=FU::split(s,',');
    //dobij nazive vrsta
    for(const auto& i: v)    //kreiraj prazne vrste
        d->insertFirstRow(i);


    return d;
}

bool Table::checkRow(string s) const {
    return table->count(s)>0;
}

Table::~Table() {
    delete table;

}


