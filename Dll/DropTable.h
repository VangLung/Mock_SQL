//
// Created by Mateja on 5/2/2024.
//

#ifndef DATABASEPROJECT_DROPTABLE_H
#define DATABASEPROJECT_DROPTABLE_H
#include "Statement.h"
#include "Exception.h"

class DropTable: public Statement {
public:
    DropTable(string s, DataBase* d): Statement(s, d){}
    string execute() override;


};


#endif //DATABASEPROJECT_DROPTABLE_H
