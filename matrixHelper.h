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
    void wall_placer(int p, int q, int r)
    {
        if (r==1)
        {
            x[p][q]='w';
            x[p+1][q]='w';
            x[p-1][q]='w';
        }
        else if (r==2)
        {
            x[p][q]='w';
            x[p][q+1]='w';
            x[p][q-1]='w';
        }
    }
    void condition1(char A)
    {
        if (A=='R')
        {
            if (j1<10 && x[i1][j1+1]!='0' && x[i1][j1+1]!='w')
            {
                x[i1][j1]='0';
                x[i1][j1+2]='A';
            }
            else if (j1<10 && x[i1][j1+1]!='w')
            {
                x[i1][j1]='0';
                x[i1][j1+1]='A';
                j1+=1;
            }
            else if (x[i1][j1+1]=='w')
            {
                cout << "there is a wall, you can't move this way" << endl;
            }
            else
            {
                cout << "you cant move this way!" << endl;
            }
        }
        else if (A=='L')
        {
            if (j1>0 && x[i1][j1-1]!='0' && x[i1][j1-1]!='w')
            {
                x[i1][j1]='0';
                x[i1][j1-2]='A';
            }
            else if (j1>0 && x[i1][j1-1]!='w')
            {
                x[i1][j1]='0';
                x[i1][j1-1]='A';
                j1-=1;
            }
            else if (x[i1][j1-1]=='w')
            {
                cout << "there is a wall, you can't move this way" << endl;
            }
            else
            {
                cout << "you cant move this way!" << endl;
            }
        }
        else if (A=='U')
        {
            if (i1>0 && x[i1-1][j1]!='0' && x[i1-1][j1]!='w')
            {
                x[i1][j1]='0';
                x[i1-2][j1]='A';
            }
            else if (i1>0 && x[i1-1][j1]=='w')
            {
                x[i1][j1]='0';
                x[i1-1][j1]='A';
                i1-=1;
            }
            else if (x[i1-1][j1]=='w')
            {
                cout << "there is a wall, you can't move this way" << endl;
            }
            else
            {
                cout << "you cant move this way!" << endl;
            }
        }
        else if (A=='D')
        {
            if (i1<10 && x[i1+1][j1]!='0' && x[i1+1][j1]!='w')
            {
                x[i1][j1]='0';
                x[i1+2][j1]='A';
            }
            else if (i1<10 && x[i1][j1+1]!='w')
            {
                x[i1][j1]='0';
                x[i1+1][j1]='A';
                i1+=1;
            }
            else if (x[i1][j1+1]=='w')
            {
                cout << "there is a wall, you can't move this way" << endl;
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