#include <stdio.h>

int main()
{
    int a,b;
    int num =0;
    int count = 0;
    
    for(int i=0;i<10;i++)
    {
        scanf("%d %d",&a,&b);
        count = count - a +b;
        if(num<count)
        {
            num = count;
            
        }
        
     
        
    }
    printf("%d\n",num);
    return 0;
}