#include <httplib.h>

using namespace std;
using namespace httplib;

int main(void) {
    Client clientObject1("localhost", 8080);
    while (true)
    {
        while(true)
        {
            sleep(1);
            if (!clientObject1.Get("print"))
            {}
            else
            {
                if ( auto result = clientObject1.Get("print")) {
                    if ( result->status == 200 ) {
                        string s = result->body;
                        cout << s << endl;
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
            clientObject1.Get("wall");
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
            if (auto result = clientObject1.Get(B.data())) {
                if ( result->status == 200 ) {
                    string s = result->body;
                    cout << s << endl;
                    if (B!="print")
                    {
                        clientObject1.Get("stop");
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