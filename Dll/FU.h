//
// Created by Mateja on 5/2/2024.
//

#ifndef DATABASEPROJECT_FU_H
#define DATABASEPROJECT_FU_H

#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>



using namespace std;
class FU {
public :
    static vector<string> split(string s, char spl);
    static string removeSpacesAfterComma(string input);
    static string removeSpacesAfterChar(string s, char t);
    static string removeSpacesBeforeChar(string s, char t);





};


#endif //DATABASEPROJECT_FU_H


//CREATE TABLE Firme (naziv,oblast,gazda)
//CREATE TABLE Zaposleni (ime,prezime,jmbg,pozicija)
//INSERT INTO Zaposleni (ime,prezime,jmbg,pozicija) VALUES (Mateja  ,rista ,   123,sef)
//INSERT INTO Zaposleni (ime,prezime,jmbg,pozicija) VALUES (Mitar,Miric,443,zaposleni)
//INSERT INTO Zaposleni (ime,prezime,jmbg,pozicija) VALUES (Jovan,Jovic,666,cistac)
//INSERT INTO Zaposleni (ime,prezime,jmbg,pozicija) VALUES (Pera,Kostic,999,zubar)
//INSERT INTO Firme (naziv,oblast,gazda) VALUES (Zlatiboarac,meso,Pera)
//INSERT INTO Firme (naziv,oblast,gazda) VALUES (Titan,cement,Grk)
//SELECT ime,prezime FROM Zaposleni WHERE ime=Pera AND prezime=Peric
//UPDATE Zaposleni SET ime=Jelica,prezime=Protic WHERE ime=Pera
//SELECT * FROM Zaposleni z INNER JOIN Firme f ON z.ime=f.gazda WHERE naziv=Titan
//UPDATE   Zaposleni SET ime=Milo  ,  prezime=Protic    WHERE ime=Pera
//DELETE FROM Zaposeni WHERE prezime=rista