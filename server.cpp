#include <httplib.h>
#include <iostream>
#include <string>
#include "matrixHelper.h"
#include <fstream>
using namespace std;
using namespace httplib;
Matrix mat;
int main(void)
{
    Server srv;
    //----------------------------------------------first port--------------------------------------------------------------------------------
    srv.Get("R8080", [](const Request& req, Response& res)
    {
        mat.condition1('R');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("L8080", [](const Request& req, Response& res)
    {
        mat.condition1('L');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("U8080", [](const Request& req, Response& res)
    {
        mat.condition1('U');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("D8080", [](const Request& req, Response& res)
    {
        mat.condition1('D');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    //-----------------------------------------------second port------------------------------------------------------------------------------
    srv.Get("R8081", [](const Request& req, Response& res)
    {
        mat.condition2('R');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("L8081", [](const Request& req, Response& res)
    {
        mat.condition2('L');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("U8081", [](const Request& req, Response& res)
    {
        mat.condition2('U');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("D8081", [](const Request& req, Response& res)
    {
        mat.condition2('D');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    //------------------------------------------------third port------------------------------------------------------------------------------
    srv.Get("R8082", [](const Request& req, Response& res)
    {
        mat.condition3('R');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("L8082", [](const Request& req, Response& res)
    {
        mat.condition3('L');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("U8082", [](const Request& req, Response& res)
    {
        mat.condition3('U');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("D8082", [](const Request& req, Response& res)
    {
        mat.condition3('D');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    //--------------------------------------------------fourth port---------------------------------------------------------------------------
    srv.Get("R8083", [](const Request& req, Response& res)
    {
        mat.condition4('R');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("L8083", [](const Request& req, Response& res)
    {
        mat.condition4('L');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("U8083", [](const Request& req, Response& res)
    {
        mat.condition4('U');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("D8083", [](const Request& req, Response& res)
    {
        mat.condition4('D');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    //--------------------------------------------------print---------------------------------------------------------------------------------
    srv.Get("print8080", [](const Request& req, Response& res)
    {
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("print8081", [](const Request& req, Response& res)
    {
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("print8082", [](const Request& req, Response& res)
    {
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("print8083", [](const Request& req, Response& res)
    {
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    //-----------------------------------------------wall palcer------------------------------------------------------------------------------
    srv.Get("wall", [](const Request& req, Response& res)
    {
        ifstream ff("index.txt");
        int i, j, how;
        ff >> i >> j >> how;
        cout << i << ' ' << j << ' ' << how << endl;
        ff.close();
        mat.wall_placer(i, j, how);
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    //---------------------------------------------------check first port------------------------------------------------------------------------
    srv.Get("can_move_R8080", [](const Request& req, Response& res)
    {
        string s;
        s = mat.can_go_r1();
        res.set_content(s, "text/plain");
    });
    srv.Get("can_move_L8080", [](const Request& req, Response& res)
    {
        string s;
        s = mat.can_go_l1();
        res.set_content(s, "text/plain");
    });
    srv.Get("can_move_U8080", [](const Request& req, Response& res)
    {
        string s;
        s = mat.can_go_u1();
        res.set_content(s, "text/plain");
    });
    srv.Get("can_move_D8080", [](const Request& req, Response& res)
    {
        string s;
        s = mat.can_go_d1();
        res.set_content(s, "text/plain");
    });
    //-----------------------------------------------------check second port------------------------------------------------------------------
    srv.Get("can_move_R8081", [](const Request& req, Response& res)
    {
        string s;
        s = mat.can_go_r2();
        res.set_content(s, "text/plain");
    });
    srv.Get("can_move_L8081", [](const Request& req, Response& res)
    {
        string s;
        s = mat.can_go_l2();
        res.set_content(s, "text/plain");
    });
    srv.Get("can_move_U8081", [](const Request& req, Response& res)
    {
        string s;
        s = mat.can_go_u2();
        res.set_content(s, "text/plain");
    });
    srv.Get("can_move_D8081", [](const Request& req, Response& res)
    {
        string s;
        s = mat.can_go_d2();
        res.set_content(s, "text/plain");
    });
    //-----------------------------------------------------check third port-------------------------------------------------------------------
    srv.Get("can_move_R8082", [](const Request& req, Response& res)
    {
        string s;
        s = mat.can_go_r3();
        res.set_content(s, "text/plain");
    });
    srv.Get("can_move_L8082", [](const Request& req, Response& res)
    {
        string s;
        s = mat.can_go_l3();
        res.set_content(s, "text/plain");
    });
    srv.Get("can_move_U8082", [](const Request& req, Response& res)
    {
        string s;
        s = mat.can_go_u3();
        res.set_content(s, "text/plain");
    });
    srv.Get("can_move_D8082", [](const Request& req, Response& res)
    {
        string s;
        s = mat.can_go_d3();
        res.set_content(s, "text/plain");
    });
    //-----------------------------------------------------check fourth port------------------------------------------------------------------
    srv.Get("can_move_R8083", [](const Request& req, Response& res)
    {
        string s;
        s = mat.can_go_r4();
        res.set_content(s, "text/plain");
    });
    srv.Get("can_move_L8083", [](const Request& req, Response& res)
    {
        string s;
        s = mat.can_go_l4();
        res.set_content(s, "text/plain");
    });
    srv.Get("can_move_U8083", [](const Request& req, Response& res)
    {
        string s;
        s = mat.can_go_u4();
        res.set_content(s, "text/plain");
    });
    srv.Get("can_move_D8083", [](const Request& req, Response& res)
    {
        string s;
        s = mat.can_go_d4();
        res.set_content(s, "text/plain");
    });
    //---------------------------------------------------stop---------------------------------------------------------------------------------
    srv.Get("stop", [&](const Request& req, Response& res) {
        srv.stop();
    });
    //----------------------------------------------number of players-------------------------------------------------------------------------
    ofstream f("PortFile.txt", ios::binary);
    f << 8080;
    f.close();
    int n = 0;
    while ( n < 2 || n > 4 ) {
        cout << "Enter the number of players (2~4): " << endl;
        cin >> n;
        if (n<2 || n>4)
        {
            cout << "Enter another numer" << endl;
        }
    }
    mat.creat_player(n);
    //-----------------------------------------------listening port---------------------------------------------------------------------------
    while(n==2) {
        srv.listen("localhost", 8080);
        cout << "listening on 8080 port" << endl;
        srv.listen("localhost", 8081);
        cout << "listening on 8081 port" << endl;
    }
    while(n==3) {
        srv.listen("localhost", 8080);
        cout << "listening on 8080 port" << endl;
        srv.listen("localhost", 8081);
        cout << "listening on 8081 port" << endl;
        srv.listen("localhost", 8082);
        cout << "listening on 8082 port" << endl;
    }
    while(n==4) {
        srv.listen("localhost", 8080);
        cout << "listening on 8080 port" << endl;
        srv.listen("localhost", 8081);
        cout << "listening on 8081 port" << endl;
        srv.listen("localhost", 8082);
        cout << "listening on 8082 port" << endl;
        srv.listen("localhost", 8083);
        cout << "listening on 8083 port" << endl;
    }
    return 0;
};