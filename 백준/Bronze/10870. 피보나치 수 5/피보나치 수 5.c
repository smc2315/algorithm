#include <stdio.h>

int main()
{
    int n;
    int a = 0;
    int b = 1;
    int temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        temp = b;
        
        b = a+b;
        a= temp;
    }
    printf("%d",a);
    return 0;
}