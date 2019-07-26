#include <stdio.h>

int main()
{
    int pas[3]={0};
    int jui[2]={0};
    
    
    for(int i=0; i<3; i++)
    {
        scanf("%d", &pas[i]);
    }
    for(int i=0; i<2; i++)
    {
        scanf("%d", &jui[i]);
    }
    
    
    int minP=pas[0];
    int minJ=jui[0];
    
    for(int i=1; i<3; i++)
    {
        if(minP > pas[i]) minP = pas[i];
    }
    for(int i=1; i<2; i++)
    {
        if(minJ > jui[i]) minJ = jui[i];
    }
    
    float n = (minP+minJ)/10.0;
    
    n += minP + minJ;
    printf("%.1f", n);
    
    
    
    
    return 0; 
    
}
