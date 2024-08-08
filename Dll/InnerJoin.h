//
// Created by Mateja on 5/9/2024.
//

#ifndef DATABASEPROJECT_INNERJOIN_H
#define DATABASEPROJECT_INNERJOIN_H

#include "Statement.h"
#include "DataBase.h"
#include "Select.h"
#include "Wrapper.h"
#include "DropTable.h"


class InnerJoin:public Statement {
public:
    InnerJoin(string v, DataBase* d): Statement(v,d){}
    string execute() override;

};


#endif //DATABASEPROJECT_INNERJOIN_H
