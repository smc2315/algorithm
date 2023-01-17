#include <iostream>
#include <string>
using namespace std;
int main()
    {
    string s;
    int arr[26]={-1,};
    cin>>s;
    for(int i=0;i<26;i++)
        {
        cout<<(int)s.find(i+97)<<" ";
       
           
        }

      
    return 0;
    }