#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void parser(string input, vector<string> &lexic)
{
    string kata="";
    for (long i=0; i<input.length(); i++)
    {
        if (input[i] != ' ' && input[i] != '(' && input[i] != ')')
        {
            kata+=input[i];
        }
        else
        {
            if ((input[i]==' '))
            {
                if (kata!="")
                {
                    lexic.push_back(kata);
                }
                kata="";
            }
            else if (input[i]=='(' || input[i]==')')
            {
                if (kata != "")
                {
                    lexic.push_back(kata);
                    kata="";
                }
                lexic.push_back(string(1,input[i]));
            }
        }
    }
    if (kata!="")
    {
        lexic.push_back(kata);
    }
}


int getToken(string lexic)
{
    if ((lexic[0]=='p' || lexic[0]=='q' || lexic[0]=='r' || lexic[0]=='s') && (lexic.length()==1))
    {
        return 1;
    }
    else if(lexic[0]=='n' && lexic[1]=='o' && lexic[2]=='t')
    {
        return 2;
    }
    else if(lexic[0]=='a' && lexic[1]=='n' && lexic[2]=='d')
    {
        return 3;
    }
    else if(lexic[0]=='o' && lexic[1]=='r')
    {
        return 4;
    }
    else if (lexic[0]=='x' && lexic[1]=='o' && lexic[2]=='r')
    {
        return 5;
    }
    else if (lexic[0]=='i' && lexic[1]=='f')
    {
        if (lexic.length()==3 && lexic[2] =='f')
        {
            return 8;
        }
        else if (lexic.length()==2)
        {
            return 6;
        }
        else
        {
            return 0;
        }
    }
    else if (lexic[0]=='t' && lexic[1]=='h' && lexic[2]=='e' && lexic[3]=='n')
    {
        return 7;
    }
    else if (lexic[0]=='(')
    {
        return 9;
    }
    else if (lexic[0]==')')
    {
        return 10;
    }
    else
    {
        return 0;
    }
}

void Proses2(vector<string> &lexic, vector<string> &lexic2)
{
    cout << lexic.size() << endl;
    lexic2.push_back("#");
    lexic2.push_back("S");

    int i = 0;
    if (getToken(lexic[i]) == 1)
    {
        lexic2.pop_back();
        lexic2.push_back("E");
        lexic2.push_back("1");
    }
    else if (getToken(lexic[i]) == 2)
    {
        lexic2.pop_back();
        lexic2.push_back("A");
        lexic2.push_back("2");
    }
    else if (getToken(lexic[i]) == 6)
    {
        lexic2.pop_back();
        lexic2.push_back("A");
        lexic2.push_back("7");
        lexic2.push_back("A");
        lexic2.push_back("6");
    }
    else if (getToken(lexic[i]) == 9)
    {
        lexic2.pop_back();
        lexic2.push_back("10");
        lexic2.push_back("S");
        lexic2.push_back("9");
    }


    while (i < lexic.size())
    {
        switch (getToken(lexic[i]))
        {
        case 1:
            if (lexic2.back() == "1")
            {
                lexic2.pop_back();
            }
            cout << "Masuk 1" << endl;
            cout << lexic2.back() << endl;
            if (lexic2.back() == "E")
            {
                int a = i + 1;
                if (a < lexic.size())
                {
                    if (getToken(lexic[a]) == 3)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("D");
                        lexic2.push_back("3");
                        cout << "3/D" << endl;
                    }
                    else if (getToken(lexic[a]) == 4)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("D");
                        lexic2.push_back("4");
                    }
                    else if (getToken(lexic[a]) == 5)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("D");
                        lexic2.push_back("5");
                    }
                    else if (getToken(lexic[a]) == 8)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("D");
                        lexic2.push_back("8");

                    }
                    else if (getToken(lexic[a]) == 1)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("WQWQ");
                    }
                    else
                    {
                        lexic2.pop_back();
                    }
                }
                else
                {
                    lexic2.pop_back();

                }
            }
            else if (lexic2.back() == "#")
            {
                lexic2.push_back("APAYAA");
            }
            cout << lexic2.back() << endl;
            i++;
            break;

        case 2:
            cout << "Masuk 2" << endl;
            cout << lexic2.back() << endl;
            if (lexic2.back() == "2")
            {
                lexic2.pop_back();
            }
            if (lexic2.back() == "A")
            {
                int a = i + 1;
                if (a < lexic.size())
                {
                    if (getToken(lexic[a]) == 1)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("E");
                        lexic2.push_back("1");
                    }
                    else if (getToken(lexic[a]) == 9)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("10");
                        lexic2.push_back("S");
                        lexic2.push_back("9");
                    }
                }
            }
            else if (lexic2.back() == "#")
            {
                lexic2.push_back("APAYAA");
            }
            cout << lexic2.back() << endl;
            i++;
            break;
        case 3:
            cout << "Masuk 3" << endl;
            cout << lexic2.back() << endl;
            if (lexic2.back() == "3")
            {
                lexic2.pop_back();
                cout << lexic2.back() << endl;
            }
            if (lexic2.back() == "D")
            {
                int a = i + 1;
                if (a < lexic.size())
                {
                    if (getToken(lexic[a]) == 1)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("E");
                        lexic2.push_back("1");
                    }
                    else if (getToken(lexic[a]) == 9)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("10");
                        lexic2.push_back("S");
                        lexic2.push_back("9");
                    }
                    else if (getToken(lexic[a]) == 2)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("A");
                        lexic2.push_back("2");
                    }
                }
                else
                {
                    lexic2.push_back("WEW");
                }
            }
            if (lexic2.back() == "#")
            {
                lexic2.pop_back();
            }
            cout << lexic2.back() << endl;
            i++;
            break;
        case 4:
            cout << "Masuk 4" << endl;
            cout << lexic2.back() << endl;
            if (lexic2.back() == "4")
            {
                lexic2.pop_back();
                cout << lexic2.back() << endl;
            }
            if (lexic2.back() == "D")
            {
                int a = i + 1;
                if (a < lexic.size())
                {
                    if (getToken(lexic[a]) == 1)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("E");
                        lexic2.push_back("1");
                    }
                    else if (getToken(lexic[a]) == 9)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("10");
                        lexic2.push_back("S");
                        lexic2.push_back("9");
                    }
                    else if (getToken(lexic[a]) == 2)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("A");
                        lexic2.push_back("2");
                    }
                }
                else
                {
                    lexic2.push_back("WEW");
                }
            }
            if (lexic2.back() == "#")
            {
                lexic2.pop_back();
            }
            cout << lexic2.back() << endl;
            i++;
            break;
        case 5:
            cout << "Masuk 5" << endl;
            cout << lexic2.back() << endl;
            if (lexic2.back() == "5")
            {
                lexic2.pop_back();

            }
            if (lexic2.back() == "D")
            {
                int a = i + 1;
                if (a < lexic.size())
                {
                    if (getToken(lexic[a]) == 1)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("E");
                        lexic2.push_back("1");
                    }
                    else if (getToken(lexic[a]) == 9)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("10");
                        lexic2.push_back("S");
                        lexic2.push_back("9");
                    }
                    else if (getToken(lexic[a]) == 2)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("A");
                        lexic2.push_back("2");
                    }
                }
                else
                {
                    lexic2.push_back("WEW");
                }
            }
            if (lexic2.back() == "#")
            {
                lexic2.pop_back();
            }
            cout << lexic2.back() << endl;
            i++;
            break;
        case 6:
            cout << "Masuk 6" << endl;
            cout << lexic2.back() << endl;
            if (lexic2.back() == "6")
            {
                lexic2.pop_back();
            }
            if (lexic2.back() == "A")
            {
                int a = i + 1;
                if (a < lexic.size())
                {
                    if (getToken(lexic[a]) == 1)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("E");
                        lexic2.push_back("1");
                    }
                    else if (getToken(lexic[a]) == 9)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("10");
                        lexic2.push_back("S");
                        lexic2.push_back("9");
                    }
                }
                else
                {
                    lexic2.push_back("WEW");
                }
            }
            if (lexic2.back() == "#")
            {
                lexic2.pop_back();
            }
            cout << lexic2.back() << endl;
            i++;
            break;
        case 7:
            if (lexic2.back() == "7")
            {
                lexic2.pop_back();
            }
            if (lexic2.back() == "A")
            {
                int a = i + 1;
                if (a < lexic.size())
                {
                    if (getToken(lexic[a]) == 1)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("E");
                        lexic2.push_back("1");
                    }
                    else if (getToken(lexic[a]) == 9)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("10");
                        lexic2.push_back("S");
                        lexic2.push_back("9");
                    }
                }
                else
                {
                    lexic2.push_back("WEW");
                }
            }
            if (lexic2.back() == "#")
            {
                lexic2.pop_back();
            }
            cout << lexic2.back() << endl;
            i++;
            break;
        case 8:
            cout << "Masuk 8" << endl;
            cout << lexic2.back() << endl;
            if (lexic2.back() == "8")
            {
                lexic2.pop_back();
                cout << lexic2.back() << endl;
            }
            if (lexic2.back() == "D")
            {
                int a = i + 1;
                if (a < lexic.size())
                {
                    if (getToken(lexic[a]) == 1)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("E");
                        lexic2.push_back("1");
                    }
                    else if (getToken(lexic[a]) == 9)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("10");
                        lexic2.push_back("S");
                        lexic2.push_back("9");
                    }
                    else if (getToken(lexic[a]) == 2)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("A");
                        lexic2.push_back("2");
                    }
                }
                else
                {
                    lexic2.push_back("WEW");
                }
            }
            if (lexic2.back() == "#")
            {
                lexic2.pop_back();
            }
            cout << lexic2.back() << endl;
            i++;
            break;
        case 9:
            cout << "Masuk 9" << endl;
            cout << lexic2.back() << endl;
            if (lexic2.back() == "9")
            {
                lexic2.pop_back();
            }
            if (lexic2.back() == "S")
            {
                int a = i + 1;
                if (a < lexic.size())
                {
                    if (getToken(lexic[a]) == 1)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("E");
                        lexic2.push_back("1");
                    }
                    else if (getToken(lexic[a]) == 6)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("A");
                        lexic2.push_back("7");
                        lexic2.push_back("A");
                        lexic2.push_back("6");
                    }
                    else if (getToken(lexic[a]) == 2)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("A");
                        lexic2.push_back("2");
                    }
                    else if (getToken(lexic[a])== 9)
                    {
                        lexic2.pop_back();
                        lexic2.push_back("10");
                        lexic2.push_back("S");
                        lexic2.push_back("9");
                    }
                }
                else
                {
                    lexic2.push_back("WEW");
                }
            }
            if (lexic2.back() == "#")
            {
                lexic2.pop_back();
            }
            cout << lexic2.back() << endl;
            i++;
            break;
        case 10:
            cout << "Masuk 10" << endl;
            cout << lexic2.back() << endl;
            if (lexic2.back() == "10")
            {
                lexic2.pop_back();
            }
            cout << lexic2.back() << endl;
            i++;
            break;
        }
    }
    if (lexic2.back() == "#")
    {
        lexic2.pop_back();
    }
}

int main()
{
    const string tokenInfo[4] = {"ERROR", "OPERAND", "OPERATOR", "GROUPING"};
    bool err = false;
    vector<string> lexic;
    vector<string> lexic2;
    int token;
    string input;

    cout<<"Input : ";
    getline(cin, input);

    transform(input.begin(), input.end(), input.begin(), ::tolower);

    cout<<"Output : " << endl;
    parser(input,lexic);

    for (long i=0; i<lexic.size(); i++)
    {
        cout << lexic[i] << "\t";
        token = getToken(lexic[i]);
        if ((token!=0)&&(!err))
        {
            cout<<token << "\t";
            if (token==1)
            {
                cout << tokenInfo[token];
            }
            else if (token==9 || token==10)
            {
                cout << tokenInfo[3];
            }
            else
            {
                cout << tokenInfo[2];
            }
        }
        else if ((token==0)&&(!err))
        {
            cout << "ERROR" << "\t";
            cout<<tokenInfo[token];
            err = true;
        }
        cout << endl;
    }

    cout<<endl;

    cout << "CEK VALID : " << endl;
    if (!err)
    {
        Proses2(lexic, lexic2);

        if(lexic2.empty())
        {
            cout << "\nHASIL AKHIR : VALID" << endl;
        }
        else
        {
            cout << "\nHASIL AKHIR : TIDAK VALID" << endl;
        }
    }
    else
    {
        cout << "HASIL AKHIR : ERROR" << endl;
    }

    return 0;
}
