#include <iostream>

using namespace std;

class Matrix
{
private:
    char **x;
    int i1, j1, i2, j2, i3, j3, i4, j4;
public:
    Matrix()
    {
        x=new char* [11];
        for (int i=0; i<11; i++)
        {
            x[i]=new char [11];
            for (int j=0; j<11; j++)
                x[i][j]='0';
        }
        x[0][0]='A';
        x[0][10]='B';
        i1=0;
        j1=0;
        i2=0;
        j2=10;
    }
    void creat_player(int n)
    {
        if (n==3)
        {
            x[10][0]='C';
            i3=10;
            j3=0;
        }
        else if (n==4)
        {
            x[10][0]='C';
            x[10][10]='D';
            i3=10;
            j3=0;
            i4=10;
            j4=10;
        }
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
    string can_go_r1()
    {
        if (x[i1][j1+1]=='0' && x[i1][j1+1]!='w')
        {
            return "1";
        }
        else
        {
            return "";
        }
    }
    string can_go_l1()
    {
        if (x[i1][j1-1]=='0' && x[i1][j1-1]!='w')
        {
            return "1";
        }
        else
        {
            return "";
        }
    }
    string can_go_d1()
    {
        if (x[i1+1][j1]=='0' && x[i1+1][j1]!='w')
        {
            return "1";
        }
        else
        {
            return "";
        }
    }
    string can_go_u1()
    {
        if (x[i1-1][j1]=='0' && x[i1-1][j1]!='w')
        {
            return "1";
        }
        else
        {
            return "";
        }
    }
    string can_go_r2()
    {
        if (x[i2][j2+1]=='0' && x[i2][j2+1]!='w')
        {
            return "1";
        }
        else
        {
            return "";
        }
    }
    string can_go_l2()
    {
        if (x[i2][j2-1]=='0' && x[i2][j2-1]!='w')
        {
            return "1";
        }
        else
        {
            return "";
        }
    }
    string can_go_d2()
    {
        if (x[i2+1][j2]=='0' && x[i2+1][j2]!='w')
        {
            return "1";
        }
        else
        {
            return "";
        }
    }
    string can_go_u2()
    {
        if (x[i2-1][j2]=='0' && x[i2-1][j2]!='w')
        {
            return "1";
        }
        else
        {
            return "";
        }
    }
    string can_go_r3()
    {
        if (x[i3][j3+1]=='0' && x[i3][j3+1]!='w')
        {
            return "1";
        }
        else
        {
            return "";
        }
    }
    string can_go_l3()
    {
        if (x[i3][j3-1]=='0' && x[i3][j3-1]!='w')
        {
            return "1";
        }
        else
        {
            return "";
        }
    }
    string can_go_d3()
    {
        if (x[i3+1][j3]=='0' && x[i3+1][j3]!='w')
        {
            return "1";
        }
        else
        {
            return "";
        }
    }
    string can_go_u3()
    {
        if (x[i3-1][j3]=='0' && x[i3-1][j3]!='w')
        {
            return "1";
        }
        else
        {
            return "";
        }
    }
    string can_go_r4()
    {
        if (x[i4][j4+1]=='0' && x[i4][j4+1]!='w')
        {
            return "1";
        }
        else
        {
            return "";
        }
    }
    string can_go_l4()
    {
        if (x[i4][j4-1]=='0' && x[i4][j4-1]=='0')
        {
            return "1";
        }
        else
        {
            return "";
        }
    }
    string can_go_d4()
    {
        if (x[i4+1][j4]=='0' && x[i4+1][j4]!='w')
        {
            return "1";
        }
        else
        {
            return "";
        }
    }
    string can_go_u4()
    {
        if (x[i4-1][j4]=='0' && x[i4-1][j4]!='w')
        {
            return "1";
        }
        else
        {
            return "";
        }
    }
    void condition1(char A)
    {
        if (A=='R')
        {
            if (j1<10 && x[i1][j1+1]!='w')
            {
                x[i1][j1]='0';
                x[i1][j1+1]='A';
                j1+=1;
            }
            else if (j1<10 && x[i1][j1+1]!='0' && x[i1][j1+1]!='w')
            {
                x[i1][j1]='0';
                x[i1][j1+2]='A';
            }
            else
            {
                if (x[i1][j1+1]=='w')
                {
                    cout << "there is a wall, you can't move this way" << endl;
                }
                else
                {
                    cout << "you cant move this way!" << endl;
                }
            }
        }
        else if (A=='L')
        {
            if (j1>0 && x[i1][j1-1]!='w')
            {
                x[i1][j1]='0';
                x[i1][j1-1]='A';
                j1-=1;
            }
            else if (j1>0 && x[i1][j1-1]!='0' && x[i1][j1-1]!='w')
            {
                x[i1][j1]='0';
                x[i1][j1-2]='A';
            }
            else
            {
                if (x[i1][j1-1]=='w')
                {
                    cout << "there is a wall, you can't move this way" << endl;
                }
                else
                {
                    cout << "you cant move this way!" << endl;
                }
            }
        }
        else if (A=='U')
        {
            if (i1>0 && x[i1-1][j1]!='w')
            {
                x[i1][j1]='0';
                x[i1-1][j1]='A';
                i1-=1;
            }
            else if (i1>0 && x[i1-1][j1]!='0' && x[i1-1][j1]!='w')
            {
                x[i1][j1]='0';
                x[i1-2][j1]='A';
            }
            else
            {
                if (x[i1-1][j1]=='w')
                {
                    cout << "there is a wall, you can't move this way" << endl;
                }
                else
                {
                    cout << "you cant move this way!" << endl;
                }
            }
        }
        else if (A=='D')
        {
            if (i1<10 && x[i1][j1+1]!='w')
            {
                x[i1][j1]='0';
                x[i1+1][j1]='A';
                i1+=1;
            }
            else if (i1<10 && x[i1+1][j1]!='0' && x[i1+1][j1]!='w')
            {
                x[i1][j1]='0';
                x[i1+2][j1]='A';
            }
            else
            {
                if (x[i1][j1+1]=='w')
                {
                    cout << "there is a wall, you can't move this way" << endl;
                }
                else
                {
                    cout << "you cant move this way!" << endl;
                }
            }
        }
        else
        {
            cout << "try again" << endl;;
        }
    }
    void condition2(char A)
    {
        if (A=='R')
        {
            if (j2<10 && x[i2][j2+1]!='w')
            {
                x[i2][j2]='0';
                x[i2][j2+1]='B';
                j2+=1;
            }
            else if (j2<10 && x[i2][j2+1]!='0' && x[i2][j2+1]!='w')
            {
                x[i2][j2]='0';
                x[i2][j2+2]='B';
            }
            else
            {
                if (x[i2][j2+1]=='w')
                {
                    cout << "there is a wall, you can't move this way" << endl;
                }
                else
                {
                    cout << "you cant move this way!" << endl;
                }
            }
        }
        else if (A=='L')
        {
            if (j2>0 && x[i2][j2-1]!='w')
            {
                x[i2][j2]='0';
                x[i2][j2-1]='B';
                j2-=1;
            }
            else if (j2>0 && x[i2][j2-1]!='0' && x[i2][j2-1]!='w')
            {
                x[i2][j2]='0';
                x[i2][j2-2]='B';
            }
            else
            {
                if (x[i2][j2-1]=='w')
                {
                    cout << "there is a wall, you can't move this way" << endl;
                }
                else
                {
                    cout << "you cant move this way!" << endl;
                }
            }
        }
        else if (A=='U')
        {
            if (i2>0 && x[i2-1][j2]!='w')
            {
                x[i2][j2]='0';
                x[i2-1][j2]='B';
                i2-=1;
            }
            else if (i2>0 && x[i2-1][j2]!='0' && x[i2-1][j2]!='w')
            {
                x[i2][j2]='0';
                x[i2-2][j2]='B';
            }
            else
            {
                if (x[i2-1][j2]=='w')
                {
                    cout << "there is a wall, you can't move this way" << endl;
                }
                else
                {
                    cout << "you cant move this way!" << endl;
                }
            }
        }
        else if (A=='D')
        {
            if (i2<10 && x[i2][j2+1]!='w')
            {
                x[i2][j2]='0';
                x[i2+1][j2]='B';
                i2+=1;
            }
            else if (i2<10 && x[i2+1][j2]!='0' && x[i2+1][j2]!='w')
            {
                x[i2][j2]='0';
                x[i2+2][j2]='B';
            }
            else
            {
                if (x[i2][j2+1]=='w')
                {
                    cout << "there is a wall, you can't move this way" << endl;
                }
                else
                {
                    cout << "you cant move this way!" << endl;
                }
            }
        }
        else
        {
            cout << "try again" << endl;;
        }
    }
    void condition3(char A)
    {
        if (A=='R')
        {
            if (j3<10 && x[i3][j3+1]!='w')
            {
                x[i3][j3]='0';
                x[i3][j3+1]='C';
                j3+=1;
            }
            else if (j3<10 && x[i3][j3+1]!='0' && x[i3][j3+1]!='w')
            {
                x[i3][j3]='0';
                x[i3][j3+2]='C';
            }
            else
            {
                if (x[i3][j3+1]=='w')
                {
                    cout << "there is a wall, you can't move this way" << endl;
                }
                else
                {
                    cout << "you cant move this way!" << endl;
                }
            }
        }
        else if (A=='L')
        {
            if (j3>0 && x[i3][j3-1]!='w')
            {
                x[i3][j3]='0';
                x[i3][j3-1]='C';
                j3-=1;
            }
            else if (j3>0 && x[i3][j3-1]!='0' && x[i3][j3-1]!='w')
            {
                x[i3][j3]='0';
                x[i3][j3-2]='C';
            }
            else
            {
                if (x[i3][j3-1]=='w')
                {
                    cout << "there is a wall, you can't move this way" << endl;
                }
                else
                {
                    cout << "you cant move this way!" << endl;
                }
            }
        }
        else if (A=='U')
        {
            if (i3>0 && x[i3-1][j3]!='w')
            {
                x[i3][j3]='0';
                x[i3-1][j3]='C';
                i3-=1;
            }
            else if (i3>0 && x[i3-1][j3]!='0' && x[i3-1][j3]!='w')
            {
                x[i3][j3]='0';
                x[i3-2][j3]='C';
            }
            else
            {
                if (x[i3-1][j3]=='w')
                {
                    cout << "there is a wall, you can't move this way" << endl;
                }
                else
                {
                    cout << "you cant move this way!" << endl;
                }
            }
        }
        else if (A=='D')
        {
            if (i3<10 && x[i3][j3+1]!='w')
            {
                x[i3][j3]='0';
                x[i3+1][j3]='C';
                i3+=1;
            }
            else if (i3<10 && x[i3+1][j3]!='0' && x[i3+1][j3]!='w')
            {
                x[i3][j3]='0';
                x[i3+2][j3]='C';
            }
            else
            {
                if (x[i3][j3+1]=='w')
                {
                    cout << "there is a wall, you can't move this way" << endl;
                }
                else
                {
                    cout << "you cant move this way!" << endl;
                }
            }
        }
        else
        {
            cout << "try again" << endl;;
        }
    }
    void condition4(char A)
    {
        if (A=='R')
        {
            if (j4<10 && x[i4][j4+1]!='w')
            {
                x[i4][j4]='0';
                x[i4][j4+1]='D';
                j4+=1;
            }
            else if (j4<10 && x[i4][j4+1]!='0' && x[i4][j4+1]!='w')
            {
                x[i4][j4]='0';
                x[i4][j4+2]='D';
            }
            else
            {
                if (x[i4][j4+1]=='w')
                {
                    cout << "there is a wall, you can't move this way" << endl;
                }
                else
                {
                    cout << "you cant move this way!" << endl;
                }
            }
        }
        else if (A=='L')
        {
            if (j4>0 && x[i4][j4-1]!='w')
            {
                x[i4][j4]='0';
                x[i4][j4-1]='D';
                j4-=1;
            }
            else if (j4>0 && x[i4][j4-1]!='0' && x[i4][j4-1]!='w')
            {
                x[i4][j4]='0';
                x[i4][j4-2]='D';
            }
            else
            {
                if (x[i4][j4-1]=='w')
                {
                    cout << "there is a wall, you can't move this way" << endl;
                }
                else
                {
                    cout << "you cant move this way!" << endl;
                }
            }
        }
        else if (A=='U')
        {
            if (i4>0 && x[i4-1][j4]!='w')
            {
                x[i4][j4]='0';
                x[i4-1][j4]='D';
                i4-=1;
            }
            else if (i4>0 && x[i4-1][j4]!='0' && x[i4-1][j4]!='w')
            {
                x[i4][j4]='0';
                x[i4-2][j4]='D';
            }
            else
            {
                if (x[i4-1][j4]=='w')
                {
                    cout << "there is a wall, you can't move this way" << endl;
                }
                else
                {
                    cout << "you cant move this way!" << endl;
                }
            }
        }
        else if (A=='D')
        {
            if (i4<10 && x[i4][j4+1]!='w')
            {
                x[i4][j4]='0';
                x[i4+1][j4]='A';
                i4+=1;
            }
            else if (i4<10 && x[i4+1][j4]!='0' && x[i4+1][j4]!='w')
            {
                x[i4][j4]='0';
                x[i4+2][j4]='D';
            }
            else
            {
                if (x[i4][j4+1]=='w')
                {
                    cout << "there is a wall, you can't move this way" << endl;
                }
                else
                {
                    cout << "you cant move this way!" << endl;
                }
            }
        }
        else
        {
            cout << "try again" << endl;;
        }
    }
};