#include <stdio.h>
#include <string.h>

int main()
{
    int a,b;
    int arr[10000];
    int count = 0;
    
    scanf("%d %d", &a, &b);
    
    for(int i = 1; i<=a;i++)
    {
        if(a%i == 0)
        {
            arr[count++] = i;
        }
    }
    printf("%d",arr[b-1]);
    return 0;
}