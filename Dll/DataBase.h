//
// Created by Mateja on 5/1/2024.
//

#ifndef DATABASEPROJECT_DATABASE_H
#define DATABASEPROJECT_DATABASE_H
#include "Table.h"
#include <fstream>


class DataBase {
    friend class DropTable;
public:
    DataBase(string s):name(s){tables=new vector<Table*>();}
    Table* checkTable(Table* t) const;
    int addTable(Table* t);
    string printTables() const;
    void writeFile(string path) const;
    static DataBase* readFile(string path);
    string saveSQL(string path) const;
    ~DataBase();

private:
    string name;
    vector <Table*> *tables;
};


#endif //DATABASEPROJECT_DATABASE_H
