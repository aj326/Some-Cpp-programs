#include <iostream>
using namespace std;

#define UC 0
#define LC 1
#define P  2
const char* p = "~!?,. ;\"\'";
void decode(int n, int& state)
{
    int r = 0;
    // cout << "number:" << n << "\n";
    // cout << "decoding\n";
    if(state == UC)
    {
        // cout << "state == UC\n";
        if (n%27 == 0)
            {
                state = LC;
                return;
            }
        cout << char((n % 27)+0x40);
    }
if(state == LC)
    {
        // cout << "state == LC\n";
        if (n%27 == 0)
            {
                state = P;
                return;
            }
        cout << char((n % 27)+0x60);
    }
    if(state == P)
    {
        // cout << "state == P\n";
        if (n%9 == 0)
            {
                state = UC;
                return;
            }
        cout << p[n%9];
    }
}
int main()
{
    char c;
    int n=0;
    int state = UC;
    cout << "test\n";
    cout << "p array: " << p << "\n";
    while(cin.get(c))
    {
        if(c == ',' || c == '\n')
        {
            decode(n,state);
            // cout << "state:" << state << "\n";
            n = 0;
        }
        else
        {
            n = c - '0' + n*10;
        }
        if(c == '\n')
            {
                cout << c;
                state = UC;
            }
    }
}
