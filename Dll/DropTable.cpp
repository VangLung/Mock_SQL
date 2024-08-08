//
// Created by Mateja on 5/2/2024.
//

#include "DropTable.h"

string DropTable::execute()
    {
        vector<string> v=FU::split(s,' ');
        if(v[1]!="TABLE")
            throw Exception("GRESKA U DRUGOJ RECI");
        vector<Table*> *t=dbms->tables;
        int k=0;
        for(auto& i : *t)
        {
            if(i->getName()==v[2])
            {
                t->erase(t->begin()+k);
                k=-1;
                break;
            }
            k++;
        }
        if(k==-1)
            return "Data tabela je uspesno uklonjena";
        throw Exception("NE POSTOJI DATA TABELA");
    }

