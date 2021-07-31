#include <httplib.h>

using namespace std;
using namespace httplib;

int main(void) {
    Client clientObject("localhost", 8080);
    while (true)
    {
        int endgame=0;
        while(true)
        {
            sleep(1);
            if (!clientObject.Get("print"))
            {}
            else
            {
                if ( auto result = clientObject.Get("print")) {
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
        cout << "1.place Wall\n 2.move" << endl;
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
        }
        else if (C==2)
        {
            string B;
            cin >> B;
            if (B=="R" || B=="L" || B=="U" || B=="D")
            {
                cout << "try again" << endl;
                break;
            }
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
                    if (B!="print")
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