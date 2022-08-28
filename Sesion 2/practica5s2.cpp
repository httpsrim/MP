#include <iostream>
using namespace std;

int a,b;

int main()
{
    cout<<"numero 1 ";
    cin>>a;
    cout<<"numero 2 ";
    cin>>b;
    if(a%b == 0||b%a == 0)
    {
        cout<<"un numero divide a otro";
    }
        else
        {
            cout<<"ningun numero divide al otro";
        }
    return 0;
}