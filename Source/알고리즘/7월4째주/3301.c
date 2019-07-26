#include <stdio.h>
#include <stdlib.h>

int main()
{
    double n;
    scanf("%lf", &n);
    
    if(n<0)
    {
        n = -n;
    }
    
    
    if((int)(n*1000)%1000==0)
        printf("%d", (int)n);
    else
        printf("%.10g", n);
    
    
    return 0; 
    
}
