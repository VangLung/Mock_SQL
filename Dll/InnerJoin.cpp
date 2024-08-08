//
// Created by Mateja on 5/9/2024.
//

#include "InnerJoin.h"


string retWithouthPoint(string s)
{
    if(s.find(".")!=string::npos)
        return s.erase(0,2);

    return s;
}

string InnerJoin::execute() {
    vector<string> v=FU::split(s,' ');

    if(v[0]!="SELECT")
        throw Exception("NEPOZNATA NAREDBA");

    if(v[2]!="FROM")
        throw Exception("Ocekuje se from umesto "+v[2]);

    Table* t1=dbms->checkTable(new Table(v[3]));
    if(!t1)
        throw Exception("DATA TABELA NE POSTOJI: "+ v[3]);

    int b=4;
    if(v[b+1]=="INNER")
        b++;
    else
        if(v[b]!="INNER")
            throw Exception("NEPRAVILNA KOMANDA: "+v[b]);


    b++;
    if(v[b]!="JOIN")
        throw Exception("NERAPVILA KOMANDA: "+v[b]);

    b++;

    Table* t2=dbms->checkTable(new Table(v[b]));

    b++;
    if(v[b]!="ON")
        b++;
    if(v[b]!="ON")
        throw Exception("NEMA ON");

    b++;
    vector<string> eq=FU::split(v[b],'=');
    b++;
    if(eq.size()!=2)
        throw Exception("NEVALIDAN BROJ ARGUMENATA");

    string key1= retWithouthPoint(eq[0]);
    string key2= retWithouthPoint(eq[1]);

    if(!t1->checkRow(key1))
        throw Exception("DATO POLJE SE NE NALAZI U TABELI "+ t1->getName());

    if(!t2->checkRow(key2))
        throw Exception("DATO POLJE SE NE NALAZI U TABELI "+ t2->getName());

    Table* t3=new Table("Hibrid");

    vector<string> keys1;
    vector<string> keys2;

    for(const auto& i : *t1->table)
    {
        t3->insertFirstRow(i.first);
        keys1.push_back(i.first);
    }

    for(const auto& i : *t2->table)
    {
        t3->insertFirstRow(i.first);
        keys2.push_back(i.first);
    }

    set<int> indexes;
    vector<string> v1=(*t1->table)[key1];
    vector<string> v2=(*t2->table)[key2];


    set<pair<int,int>> tp;
    for(int i=0;i<v1.size();i++)
    {
        for(int j=0;j<v2.size();j++)
        {
            if(v1[i]==v2[j] && v1[i].size()>1)
            {
                pair<int,int> tmp;
                tmp.first=i;
                tmp.second=j;
                tp.insert(tmp);
            }
        }
    }






    for(const auto& i : tp)
    {
        int ind1=i.first;
        int ind2=i.second;

        for(const auto& j : keys1)
            t3->add(j,(*t1->table)[j][ind1]);
        for(const auto& j : keys2)
            t3->add(j,(*t2->table)[j][ind2]);

    }


    string s1=v[0]+" "+v[1]+" FROM "+t3->getName();

    for(int i=b;i<v.size();i++)
    {
        s1=s1+" "+v[i];
    }

    DataBase* d;
    d=new DataBase("tocak");
    d->addTable(t3);

    Select* s=new Select(s1,d);
    return s->execute();




    return "InnerJoin izvrsen uspesno";













}
