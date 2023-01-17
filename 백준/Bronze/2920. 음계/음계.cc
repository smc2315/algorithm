#include <iostream>
using namespace std;
int main()
    {
    bool ase=true, des=true;
    for(int i=0;i<8;i++)
        {
        int n;
        cin>>n;
        if(ase==true&&n == i+1)
            ase=true;
        else
            ase =false;
        if(des==true&&n == 8-i)
            des=true;
        else
            des=false;
        }
    if(ase==true)
        cout<<"ascending";
    else if(des==true)
        cout<<"descending";
    else
        cout<<"mixed";
    return 0;
    }