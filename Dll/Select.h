//
// Created by Mateja on 5/2/2024.
//

#ifndef DATABASEPROJECT_SELECT_H
#define DATABASEPROJECT_SELECT_H
#include "Statement.h"
#include "Condition.h"
#include "Wrapper.h"

class Select: public Statement {
public:
    Select(string v, DataBase* d): Statement(v,d){}

    string execute() override;

};


#endif //DATABASEPROJECT_SELECT_H
