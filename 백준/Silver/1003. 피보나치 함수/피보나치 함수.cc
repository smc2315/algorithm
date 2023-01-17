#include <iostream>
using namespace std;

int main()
{
  int T, N, F[41] = { 0, 1 };
  for(int n = 2; n <= 40; n++) F[n] = F[n-1] + F[n-2];

  cin >> T;
  for(int i = 0; i < T; i++)
  {
    cin >> N;
    if (N == 0) printf("1 0\n");
    else printf("%d %d\n", F[N-1], F[N]);
  }
  return 0;
}