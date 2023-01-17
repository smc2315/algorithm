#include <iostream>
#include<string>
#include <map>
#include <sstream>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    string name;
    string ques;
    map<int, string> m1;
    map<string, int> m2;
    for (int i = 1; i <= N; i++)
    {
        cin >> name;
       m1.insert(pair<int, string>(i,name));
       m2.insert(pair<string, int>(name, i));
    }
    for (int i = 0; i < M; i++)
    {
        cin >> ques;
        
        if (ques[0] >= 'A' && ques[0] <= 'Z')
        {
            
            cout << m2[ques]<<"\n";
        }
        else
        {
            std::stringstream ssInt(ques);
            int n = 0;
            ssInt >> n;
            cout << m1[n] << "\n";
        }
    }
    return 0;


}