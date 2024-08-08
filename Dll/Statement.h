//
// Created by Mateja on 5/2/2024.
//

#ifndef DATABASEPROJECT_STATEMENT_H
#define DATABASEPROJECT_STATEMENT_H
#include "DataBase.h"
#include "Exception.h"
#include "FU.h"

class Statement {
public:
    Statement(string t, DataBase* d){
        this->s=t;
        this->dbms=d;
    }

    virtual string execute()=0;

protected:
    string s;
    DataBase* dbms;

};


#endif //DATABASEPROJECT_STATEMENT_H
