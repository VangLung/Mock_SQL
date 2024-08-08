#include <iostream>
#include "Statement.h"
#include "Table.h"
#include <string>
#include "Exception.h"
#include "DataBase.h"
#include "DropTable.h"
#include "Insert.h"
#include "FU.h"
#include "Select.h"
#include "Update.h"
#include "Delete.h"
#include "InnerJoin.h"
#include <regex>


string Radi(DataBase* d, string k)
{
    bool saved = false;
    Statement* command = nullptr;
    bool work = true;
    int cnt;
    Table* t = nullptr;
    cnt = 0;
    
    try {


        k = FU::removeSpacesAfterChar(k, ',');
        k = FU::removeSpacesBeforeChar(k, ',');
        k = FU::removeSpacesAfterChar(k, '(');
        k = FU::removeSpacesBeforeChar(k, ')');
        k = FU::removeSpacesAfterChar(k, '=');
        k = FU::removeSpacesBeforeChar(k, '=');
        vector<string> v = FU::split(k, ' ');
        if (v[0] == "CREATE") {
            t = Table::CreateTable(k);
            d->addTable(t);
            return "Tabela uspesno dodata\n";
        }
        else {
            if (v[0] == "DROP")
                command = new DropTable(k, d);

            if (v[0] == "INSERT")
                command = new Insert(k, d);

            if (v[0] == "SELECT") {
                command = new Select(k, d);
                if (v.size() >= 9) {
                    if (v[4] == "INNER" || v[5] == "INNER")
                        command = new InnerJoin(k, d);
                }
            }

            if (v[0] == "UPDATE")
                command = new Update(k, d);


            if (v[0] == "DELETE")
                command = new Delete(k, d);

            if (v[0] == "SHOW" and v[1] == "TABLES")
            {
                return d->printTables();
                

            }
            if (v[0] == "QUIT")
            {
                if (!saved && cnt == 0)
                {
                    cout << "Niste sacuvali datu bazu. Ukoliko zelite da je sacuvate, napisite SAVE [putanja], gde putanja predstavlja put do fajla" << endl;
                    cnt++;
                }
                else
                    work = false;


            }

            if (v[0] == "SAVE")
            {
                string path = v[1];
                d->writeFile(path);
                saved = true;
                return "Sacuvano!\n";

                //"C:\\Users\\Mateja\\Desktop\\ispis.txt"
            }

            if (v[0] == "EXPORT")
            {
                d->saveSQL(v[1]);
                return "Eksportovano!\n";

            }


            if (command) {
               return command->execute();
                cnt = 0;
                command = nullptr;

            }
            return "DATA KOMANDA SE NE NALAZI U LISTI KOMANDI";


        }

    }
        

        catch (Exception e)
        {
           return e.what();
        }

       

    }





int main() {


        string s;
        Table *t;
        DataBase *d;
        cout << "Dobar dan!" << endl;
        cout << "Unesite 1 ukoliko zelite da kreirate novu bazu, odnosno 2 ukoliko zelite da je ucitate" << endl;
        string k;
        int cnt=0;
        while(true)
        {
            std::getline(std::cin, k);
            if (k == "1") {
                cout << "Unesite naziv baze podataka" << endl;
                std::getline(std::cin, k);
                d = new DataBase(k);
                break;
            } else if (k== "2")
            {

                cout<< "Unesite putanju sa koje zelite da ucitate bazu"<<endl;
                std::getline(std::cin,k);
                d=DataBase::readFile(k);
                break;
            }

            cout<< "Pogresno unet broj"<<endl;
        }


        Radi(d, "SELECT * FROM Zaposleni");
       

       
        delete d;














}
