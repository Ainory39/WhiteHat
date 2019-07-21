#include <stdio.h>
#define A 300
#define B 60
#define C 10

int main()
{
    int t; 
    int a=0, b=0, c=0;
    
    scanf("%d", &t);
    
    while(1)
    {
        if(t-A>=0)      // A로 할 수 있는 만큼 버튼을 누른다.
        {
            t-=A;
            a++;
        }
        else if(t-B>=0) // A로 충분히 눌렀다면 B를 누른다.
        {
            t-=B;
            b++;
        }
        else if(t-C>=0) // 연속
        {
            t-=C;
            c++;
        }
        else    break;
    }
    
    if(t==0)
    {
        printf("%d %d %d", a, b, c);
    }
    else
    {
        printf("-1");
    }

    return 0;
}
