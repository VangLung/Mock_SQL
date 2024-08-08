//
// Created by Mateja on 5/1/2024.
//

#ifndef DATABASEPROJECT_EXCEPTION_H

#define DATABASEPROJECT_EXCEPTION_H
#include <string>
using namespace std;

class Exception: public std::exception {

public:
    Exception(string s):txt(s){}
    string what()
    {
        return this->txt+"\n";
    }

private:
    string txt;

};


#endif //DATABASEPROJECT_EXCEPTION_H
