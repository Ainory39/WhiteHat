#include <stdio.h>
#include <stdlib.h>

static int cnt=0;

void func(int a, short *c)
{
    cnt++;  // 반복 수를 카운트
    if(*c==0)   // 반복 제어 변수가 0이라면 반복을 멈춤
        return;
        
    if(a==1)    // a가 1이되었다면 반복을 멈춤
        *c=0;
    
    if(a%2==0)  // 짝수라면 a/=2
    {
        a = a/=2;
        func(a, c);
    }
    else if(a!=1)   // 홀수이고 1이 아니라면 a=3a+1
    {
        a=3*a+1;
        func(a, c);
    }
}

int main()
{
	int a, b;
	short c=1;  // 반복 제어 변수
	scanf("%d %d", &a, &b);
	
	int *rst = (int*)calloc((b-a+1) ,sizeof(int));
	
	int temp;
	
	for(int i=a; i<=b; i++)
	{
		cnt=0;
		c=1;
		func(i, &c);
		rst[i-a] = cnt;
	}
	
	for(int i=0; i<b-a-1; i++)
	{
		if(rst[i]<rst[i+1])
		{
			temp = i+a+1;
		}
	}
	
	printf("%d %d", temp, rst[temp-a]);
	free(rst);
	
	return 0;
}
