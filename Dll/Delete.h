//
// Created by Mateja on 5/2/2024.
//

#ifndef DATABASEPROJECT_DELETE_H
#define DATABASEPROJECT_DELETE_H
#include "Statement.h"
#include "DataBase.h"
#include "Wrapper.h"
#include "DropTable.h"

class Delete: public Statement {
public:
    Delete(string v, DataBase* d): Statement(v,d){}
    string execute() override;
};


#endif //DATABASEPROJECT_DELETE_H
