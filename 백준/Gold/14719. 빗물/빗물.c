#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main()
{
    int count = 0;
    int h, w;
    int a[500];
    

    scanf("%d %d", &h, &w);
    for (int i = 0; i < w; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < w-1; i++)
        
    {
        int max1 = 0;
        int max2 = 0;
        for (int j = 0; j < i; j++)
        {
            max1 = max1 > a[j] ? max1 : a[j];
        }

        for (int j = i + 1; j < w; j++)
        {
            max2 = max2 > a[j] ? max2 : a[j];
        }
       

        count += (max1 < max2 ? max1 : max2) - a[i] > 0 ? (max1 < max2 ? max1 : max2) - a[i] : 0;
        
    }
    printf("%d", count);
}