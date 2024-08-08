//
// Created by Mateja on 5/2/2024.
//

#ifndef DATABASEPROJECT_INSERT_H
#define DATABASEPROJECT_INSERT_H
#include "Statement.h"

class Insert: public Statement{
public:
    Insert(string s, DataBase* d): Statement(s, d){}
    string execute() override;



};


#endif //DATABASEPROJECT_INSERT_H
