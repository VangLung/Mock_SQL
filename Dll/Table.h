//
// Created by mateja on 1.5.24..
//

#ifndef BAZA_PODATAKA_DATABASE_H


#define BAZA_PODATAKA_DATABASE_H
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include "Exception.h"
#include "FU.h"

using namespace std;



class Table {
    friend class Statement;
    friend class Insert;
    friend class Select;
    friend class Condition;
    friend class Wrapper;
    friend class Update;
    friend class Delete;
    friend class DataBase;
    friend class InnerJoin;
public:
    Table(string t);
    int add(string key, string value);  //dodavanje key value u tabelu
    int insertFirstRow(string s);   //ubacivanje pocetnog reda
    friend ostream& operator <<(ostream& os,const Table& d);
    static Table* CreateTable(string s);
    string getName() const {return this->tableName;}
    bool checkRow(string s) const;
    ~Table();



private:
    map<string, vector<string>>* table;
    string tableName;
};


#endif //BAZA_PODATAKA_DATABASE
