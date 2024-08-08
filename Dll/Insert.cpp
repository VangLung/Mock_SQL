//
// Created by Mateja on 5/2/2024.
//

#include "Insert.h"
#include <regex>

int countWords(const std::string str) {
    std::regex wordRegex("\\s+");
    std::sregex_token_iterator iter(str.begin(), str.end(), wordRegex, -1);
    std::sregex_token_iterator end;

    int count = 0;
    for (; iter != end; ++iter) {
        ++count;
    }
    return count;
}


string Insert::execute()
    {
        if(countWords(s)!=6)
           throw Exception("GRESKA U DUZINI KOMANDE");
        vector<string> v=FU::split(s,' ');
        if(v[1]!="INTO")
            throw Exception("GRESKA U DRUGOJ RECI");
        Table* t=dbms->checkTable(new Table(v[2]));
        if(!t)
            throw Exception("DATA TABELA NE POSTOJI");

        v[3]=v[3].substr(1,v[3].size()-2);
        v[5]=v[5].substr(1,v[5].size()-2);

        vector<string> rows=FU::split(v[3],',');
        vector<string> values=FU::split(v[5],',');

        if(rows.size()!=values.size())
            throw Exception("BROJEVI ARGUMENATA SE NE POKLAPAJU");

        for(const auto& i : rows)
        {
            if(!t->checkRow(i))
                throw Exception("RED " + i + " SE NE NALAZI U DATOJ TABELI");

        }

        if(rows.size() < t->table->size())
            throw Exception("NULL VREDNOST NISU DOZVOLJEN!!!");

        for(int i=0;i<rows.size();i++)
        {
            t->add(rows[i],values[i]);
        }





        return "Kolona je uspesno umetnuta";

    }

