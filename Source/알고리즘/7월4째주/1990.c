#include <stdio.h>

int main()
{
    char n[500]={0};
    
    int cnt=0;
    for(int i=0; i<500; i++)
    {
        scanf("%c", &n[i]);
        if(n[i]=='\n')  
        {   
            n[i] = 0;
            break;
        }
        n[i] -= '0';
    }
    
    
    for(int i=499; i!=-1; i--)
    {
        if(n[i]!=-48)
        {
            cnt += n[i];
        }
    }
    
    if(cnt%3==0)
    {
        printf("1");
    }else{
        printf("0");
    }
    
    return 0; 
    
}
