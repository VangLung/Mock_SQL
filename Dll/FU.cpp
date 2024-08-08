//
// Created by Mateja on 5/2/2024.
//

#include "FU.h"

vector <string> FU::split(string s, char spl) {

        vector<string> v;
        string t = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != spl) {
                t += s[i];
            } else {
                if(t!="")
                    v.push_back(t);
                t = "";
            }

        }
        v.push_back(t);
        return v;

}

string FU::removeSpacesAfterComma(string s) {
    string result;
    bool flag = false;

    for (char ch : s) {
        if(ch!=' ' && ch!=',') {
            result += ch;
            flag=false;
        }

        if(ch==',')
        {
            flag=true;
            result+=ch;
        }


        if(ch==' ')
        {
            if(!flag)
                result+=ch;
        }


    }

    return result;
}

string FU::removeSpacesAfterChar(string s, char t) {
    string result;
    bool flag = false;

    for (char ch : s) {
        if(ch!=' ' && ch!=t) {
            result += ch;
            flag=false;
        }

        if(ch==t)
        {
            flag=true;
            result+=ch;
        }


        if(ch==' ')
        {
            if(!flag)
                result+=ch;
        }


    }

    return result;
}

string FU::removeSpacesBeforeChar(string s, char t) {
    string result;
    string help;
    bool flag=false;

    for(char c : s)
    {
        if(c!=' '  && c!=t)
        {
            if(flag)
            {
                result+=" ";
                flag=false;
            }
            result+=c;
        }
        if(c==t) {
            result += c;
            flag=false;
        }

        if(c==' ')
            flag=true;
    }

    return result;
}





