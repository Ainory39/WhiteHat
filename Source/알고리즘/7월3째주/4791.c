#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mC, nC, l;
    int cnt=0;    //잡을 수 있는 동물의 수
    scanf("%d %d %d", &mC, &nC, &l);
    int m[mC];  //사대의 위치
    int nX[nC];  //동물의 위치
    int nY[nC];
    
    for(int i=0; i<mC; i++)  // 사대 위치 입력
    {
        scanf("%d ", &m[i]);
    }
    
    for(int i=0; i<nC; i++)  // 동물 위치 입력
    {
        scanf("%d %d", &nX[i], &nY[i]);
    }
    
    for(int i=0; i<nC; i++)     // i번째 동물의 사냥 가능 여부
    {
        for(int j=0; j<mC; j++) // j번째 사대에서의 사냥 가능 여부
        {
            if(l >= abs(m[j]-nX[i])+nY[i])
            {
                cnt++;
                break;
            }
        }
    }    
    
    printf("%d", cnt);

    return 0;
}
