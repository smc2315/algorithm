#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    int a;
    int count = 0;
    int min=1000000;
    int max = -1000000;
    
    scanf("%d", &n);
    
    while(n--)
    {
        scanf("%d ",&a);
        if(a>max)
        {
            max = a;
        }
        if(a<min)
        {
            min = a;
        }
    }
    printf("%d %d", min,max);
    return 0;
}