#include <httplib.h>
#include <fstream>

using namespace std;
using namespace httplib;

int hase_enterd_wrong=0;
int main(void) {
    int port;
    ifstream file1("PortFile.txt", ios :: binary);
    file1 >> port;
    file1.close();
    if (hase_enterd_wrong)
    {
        port-=1;
    }
    hase_enterd_wrong=0;

    cout << port << endl;

    ofstream file2("PortFile.txt", ios :: binary);
    file2 << port+1;
    file2.close();
    Client clientObject("localhost", port);
    while (true)
    {
        int endgame=0;
        while(true)
        {
            sleep(1);
            if (!clientObject.Get("print8080"))
            {}
            else
            {
                if ( auto result = clientObject.Get("print8080")) {
                    if ( result->status == 200 ) {
                        string s = result->body;
                        cout << s << endl;
                        if (s[125]!='0')    //125 is 126th element in string s. which is x[5][5]
                        {
                            cout << "player " << s[125] << " won!" << endl;
                            endgame=1;
                            clientObject.Get("stop");
                            break;
                        }
                    }
                    else
                    {
                        cout << "it's not your turn yet!" << endl;
                    }
                }
                else {
                    auto err = result.error();
                }
                break;
            }
        }
        if (endgame)
        { // it means one of the players has reached the x[5][5]
            break;
        }
        int C;
        cout << "1.place Wall\n2.move" << endl;
        cin >> C;
        if (C==1)
        {
            int p, q, r;
            cout << "enter the index and the way you like to place a wall: \n1.vertical \n2.horizonal" << endl;
            cin >> p >> q >> r;
            ofstream index_file("index.txt", ios:: binary);
            index_file << p << ' ' << q << ' ' << r;
            index_file.close();
            clientObject.Get("wall");
            if (auto result = clientObject.Get("print8080")) {
                if ( result->status == 200 ) {
                    string s = result->body;
                    cout << s << endl;
                }
            }
            clientObject.Get("stop");
        }
        else if (C==2)
        {
            string B;
            cin >> B;
            while (!(B=="R" || B=="L" || B=="U" || B=="D"))
            {
                cout << "try again" << endl;
                cin >> B;
            }
            if (B=="R")
            {
                string s;
                s = "can_move_R" + to_string(port);
                if (!clientObject.Get(s.data()))
                {
                    cout << "try again" << endl;
                    hase_enterd_wrong=1;
                    continue;
                }
            }
            else if (B=="L")
            {
                string s;
                s= "can_move_L" + to_string(port);
                if (!clientObject.Get(s.data()))
                {
                    cout << "try again" << endl;
                    cin >> B;
                    hase_enterd_wrong=1;
                    continue;
                }
            }
            else if (B=="U")
            {
                string s;
                s = "can_move_U" + to_string(port);
                if (!clientObject.Get(s.data()))
                {
                    cout << "try again" << endl;
                    hase_enterd_wrong=1;
                    continue;
                }
            }
            else if (B=="D")
            {
                string s;
                s = "can_move_D" + to_string(port);
                if (!clientObject.Get(s.data()))
                {
                    cout << "try again" << endl;
                    hase_enterd_wrong=1;
                    continue;
                }
            }
            B+=to_string(port);
            if (auto result = clientObject.Get(B.data())) {
                if ( result->status == 200 ) {
                    string s = result->body;
                    cout << s << endl;
                    if (s[125]!='0')
                    {
                        cout << "player " << s[125] << " won!" << endl;
                        clientObject.Get("stop");
                        break;
                    }
                    if (B!="print8080" && B!="print8081" && B!="print8082" && B!="print8083")
                    {
                        clientObject.Get("stop");
                    }
                }
                else
                {
                    cout << "there is something wrong. try again!" << endl;
                }
            }
            else {
                auto err = result.error();
            }
        }
    }
}