#include <iostream>
#include <vector>
#include <deque>
#include<string>
#include<sstream>
using namespace std;


int main()
{
    int n;
    cin >>n;
   
    for (int i = 0; i < n; i++)
    {
        deque<string> dq;
        int m;
        string s;
        string arr;
        string strbuffer;
        bool reverse = false;
        bool error = false;
        bool empty = false;
        cin >> s;
        cin >> m;
        cin >> arr;
        istringstream ss(arr.substr(1,arr.length()-2));

        while (getline(ss, strbuffer, ','))
        {
            dq.push_back(strbuffer);
            
        }
       
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == 'R')
                reverse = !reverse;
            if (s[j] == 'D')
            {
                if (dq.empty())
                {
                    cout << "error" << endl;
                    error = true;
                    break;
                }
                if (reverse == false)
                    dq.pop_front();
                else
                    dq.pop_back();
            }

        }
        if (error)
            continue;
        if (dq.empty())
            empty = true;
        string strbuffer2 = "";
        strbuffer2 += "[";
        while (!dq.empty())
        {
            if (reverse == true)
            {
                strbuffer2 += dq.back();
                strbuffer2 += ',';
                dq.pop_back();
            }
            else
            {
                strbuffer2 += dq.front();
                strbuffer2 += ',';
                dq.pop_front();
            }
        }
        if (empty)
        {
            strbuffer2 += ']';
        }
        else
            strbuffer2[strbuffer2.length() - 1] = ']';
        cout << strbuffer2 << endl;
    }

    
return 0;
}