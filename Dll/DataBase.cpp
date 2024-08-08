//
// Created by Mateja on 5/1/2024.
//

#include "DataBase.h"

#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <set>

#include <iostream>
using namespace std;

int DataBase::addTable(Table *t) {
    for(const auto& i: *this->tables)
        if(i->getName()==t->getName())
        {
            throw Exception("Tabela sa datim nazivom je vec prisutna");
            return 0;
        }
    this->tables->push_back(t);
    return 1;
}

Table* DataBase::checkTable(Table *p) const {
    vector<Table*> *t=this->tables;
    for(const auto& i : *t)
    {
        if(i->getName()==p->getName())
        {
            return i;
        }
    }

    return nullptr;
}

string DataBase::printTables() const {
    string ret = "";
    for(const auto& i : *tables)
    {
        ret=ret+i->getName() + " ";
    }
    ret+="\n";
    return ret;

}

void DataBase::writeFile(string path) const {
    ofstream outputFile(path);
    if(!outputFile.is_open())
        throw Exception("DATA PUTANJA NIJE DOBRA");

    outputFile<<this->name<<endl;
    outputFile<<"================================="<<endl;

    for(const auto& tab : *tables){
        outputFile<<tab->getName()<<endl;
        for (const auto& par : *tab->table) {
            outputFile << par.first << " ";
//            for (const string& v : par.second) {
//                outputFile << v << " ";
//            }
            for(int i=0;i<par.second.size();i++)
            {
                outputFile << par.second[i];
                if(i!=par.second.size()-1)
                    outputFile<<" ";
            }
            outputFile << endl;
        }

        outputFile<<"================================="<<endl;
    }



    outputFile.close();
}

DataBase* DataBase::readFile(string path) {
    string k;
    ifstream inputFile(path);
    getline(inputFile,k);
    DataBase* d=new DataBase(k);
    getline(inputFile,k);
    int cnt=0;
    Table* t=nullptr;

    while (getline(inputFile, k))
    {
        if(k!="=================================")
        {
            if(cnt==0)
            {
                t=new Table(k);
            }
            else
            {
                vector<string> v=FU::split(k,' ');
                t->insertFirstRow(v[0]);
                int b=0;
                for(const auto& i : v)
                {
                    if(b!=0)
                        t->add(v[0],i);
                    b++;
                }
            }
            cnt++;
        }
        else
        {
            cnt=0;
            d->addTable(t);
        }


    }

    return d;

}

string DataBase::saveSQL(string path) const{

    auto add = [](string a, string b) {
        return a + b;
    };
    string ret="";
    ret+="CREATE DATABASE "+this->name+"\n";

    for(const auto& i : *tables)
    {
        string s="CREATE TABLE "+i->getName()+ "(";
        for(const auto& j : *i->table)
        {
            s=s+add(j.first," varchar(255),");
        }
        s.pop_back();
        s+=")\n";
        ret+=s;
    }


    vector<string> insert;
    vector<int> counter;
    for(const auto& i : *tables) {
        string s="INSERT INTO "+i->getName()+" (";
        for (const auto &j: *i->table)
            s += j.first + ",";
        s.pop_back();
        s+=") VALUES (";
        insert.push_back(s);
    }
    int cnt=0;
    int pok=0;
    for(const auto& i : *tables)
    {
        for(const auto &j : *i->table)
        {
            pok++;
            for(const auto &k : j.second)
            {
                if(k.size()>1)
                    cnt++;
            }

            counter.push_back(cnt);
            cnt=0;
            break;
        }
    }
    set<string> res;
    for(const auto& n : counter)
    {
        for(int ind=0;ind<n;ind++)
        {
            int b=0;
            for(const auto& i : *tables)
            {
                string s="";
                for(const auto& j : *i->table)
                {
                    if(j.second[ind].size()>1) {
                        s += j.second[ind] + ",";
                    }
                }
                if(s.size()>1)
                {
                    s.pop_back();
                    res.insert(insert[b]+s+")");
                }
                b=(b+1)%pok;
            }
        }
    }





    for(const auto& i : res)
    {
        ret+=i+"\n";
    }

    ofstream outputFile(path);
    if(!outputFile.is_open())
        throw Exception("DATA PUTANJA NIJE DOBRA");

    outputFile<<ret;




    return ret;
}

DataBase::~DataBase() {
    delete tables;

}
