#include <httplib.h>
#include <iostream>
#include <string>
#include "matrixHelper.h"
#include <fstream>
using namespace std;
using namespace httplib;
matrix mat;
int main(void)
{
    Server srv;
    //----------------------------------------------first port-----------------------------------------------------------------------------------
    srv.Get("R", [](const Request& req, Response& res)
    {
        mat.condition1('R');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("L", [](const Request& req, Response& res)
    {
        mat.condition1('L');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("U", [](const Request& req, Response& res)
    {
        mat.condition1('U');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    srv.Get("D", [](const Request& req, Response& res)
    {
        mat.condition1('D');
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    //--------------------------------------------------print---------------------------------------------------------------------------------
    srv.Get("print", [](const Request& req, Response& res)
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
        mat.wall_placer(i, j, how);
        string str;
        str= mat.convert_to_string();
        res.set_content(str, "text/plain");
    });
    //---------------------------------------------------stop---------------------------------------------------------------------------------
    srv.Get("stop", [&](const Request& req, Response& res) {
        srv.stop();
    });
    //----------------------------------------------listening port---------------------------------------------------------------------------------- 
    srv.listen("localhost", 8080);
    cout << "listening on port 8080" << endl;
    return 0;
}