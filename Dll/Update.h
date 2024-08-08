//
// Created by Mateja on 5/2/2024.
//

#ifndef DATABASEPROJECT_UPDATE_H
#define DATABASEPROJECT_UPDATE_H

#include "Statement.h"
#include "DataBase.h"
#include "Wrapper.h"

class Update :public Statement{
public:
    Update(string s, DataBase* d): Statement(s, d){}
    string execute() override;
};


#endif //DATABASEPROJECT_UPDATE_H
