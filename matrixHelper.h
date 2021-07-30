#include <iostream>

using namespace std;

class matrix
{
private:
    char **x;
    int i1, j1;
public:
    matrix()
    {
        x=new char* [11];
        for (int i=0; i<11; i++)
        {
            x[i]=new char [11];
            for (int j=0; j<11; j++)
                x[i][j]='0';
        }
        x[0][0]='A';
        i1=0;
        j1=0;
    }
    string convert_to_string()
    {
        string res;
        for (int i=0; i<11; i++)
        {
            for (int j=0; j<11; j++){
                res+=x[i][j];
                res+=' ';
            }
            res+='\n';
        }
        return res;
    }
    void condition1(char A)
    {
        if (A=='R')
        {
            if (j1<10)
            {
                x[i1][j1]='0';
                x[i1][j1+1]='A';
                j1+=1;
            }
            else
            {
                cout << "you cant move this way!" << endl;
            }
        }
        else if (A=='L')
        {
            if (j1>0)
            {
                x[i1][j1]='0';
                x[i1][j1-1]='A';
                j1-=1;
            }
            else
            {
                cout << "you cant move this way!" << endl;
            }
        }
        else if (A=='U')
        {
            if (i1>0)
            {
                x[i1][j1]='0';
                x[i1-1][j1]='A';
                i1-=1;
            }
            else
            {
                cout << "you cant move this way!" << endl;
            }
        }
        else if (A=='D')
        {
            if (i1<10)
            {
                x[i1][j1]='0';
                x[i1+1][j1]='A';
                i1+=1;
            }
            else
            {
                cout << "you cant move this way!" << endl;
            }
        }
        else
        {
            cout << "try again" << endl;;
        }
    }
};