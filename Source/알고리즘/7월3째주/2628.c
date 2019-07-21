#include <stdio.h>

int main()
{
    int li11, li12;
    int li21, li22;
    
    scanf("%d %d", &li11, &li12);
    scanf("%d %d", &li21, &li22);
    
    if( (li11 < li21 && li21 <li12) &&  (li11 > li22 || li22 > li12) 
                                    ||
        (li11 < li22 && li22 <li12) &&  (li11 > li21 || li21 > li12)
                                    ||
        (li12 < li21 && li21 <li11) &&  (li12 > li22 || li22 > li11) 
                                    ||
        (li12 < li22 && li22 <li11) &&  (li12 > li21 || li21 > li11)    )
    {
        printf("cross");
    }else   printf("not cross");

    return 0;
}
