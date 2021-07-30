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
        string B;
        cin >> B;
        if (auto result = clientObject1.Get(B.data())) {
            if ( result->status == 200 ) {
                string s = result->body;
                cout << s << endl;
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