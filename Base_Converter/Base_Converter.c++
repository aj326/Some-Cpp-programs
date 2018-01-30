#include <iostream>
#include <stdio.h>
#include <math.h>       /* pow */
#include <iomanip>      /*to cout hex */
const int hexVals[] = {10, 11, 12, 13, 14, 15};

using namespace std;
int binTo(int n)
{
    int r = 0;
    short int bit = 0;
    while (n && bit < 32)
    {
        r += pow(2, bit++) * (n & 1);
        // cout << r << "\n";
        n /= 10;
    }
    return r;
}
int toBin(int n)
{
    int r = 0;
    short int bit = 0;
    while (n && bit < 32)
    {
        r += pow(10, bit++) * (n & 1);
        // cout << r << "\n";
        n >>= 1;
    }
    return r;
}
void changeBase(int n, char in, char out)
{
    if (in == 'B')
    {
        switch (out)
        {
        case 'X': cout << "0x" << hex << binTo(n); break;
        case 'D': cout << binTo(n); break;
        case 'B': cout << "0b" << n; break;
        }
    }
    else
    {
        switch (out)
        {
        case 'X': cout << "0x" << hex << n; break;
        case 'D': cout << n; break;
        case 'B': cout << "0b" << toBin(n); break;
        }
    }
}
int main(int argc, char const *argv[])
{
    char c;
    char in, out;
    int n = 0;
    int isIn = 0;
    while (cin.get(c))
    {
        if (c == '\n') printf("\n");
        else if (c == 'B' || c == 'D' || c == 'X')
        {
            if (!isIn)
            {
                isIn = 1;
                in = c;
                // cout << "grabbing in: " << c << "\n";
            }

            else
            {
                isIn = 0;
                out = c;
                // printf("n = %d; in = %c; out %c\n", n, in, out);
                changeBase(n,in,out);
                n = 0;
            }
        }
        else
        {
            if ( in == 'X')
            {
                if (c <= '9') n = c - '0' + n * 0x10;
                else n = hexVals[c - 'a'] + n * 0x10;
                // cout << hex << n << "\n";
            }
            else n = c - '0' + n * 10;
        }
    }

    return 0;
}
