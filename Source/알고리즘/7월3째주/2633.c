#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    int arr[n], rst=0;    //rst : k보다 큰 수의 위치
    
    for(int i=0; i<n; i++)
    {
        scanf("%d ", &arr[i]);
        if(arr[i]>=k && rst==0) // k 이상이고 rst가 입력된 상태가 아니라면
        {
            rst=i+1;
        }
        else if(i==n-1 && rst==0) // i가 n-1이 될때까지 rst가 입력된 상태가 아니라면
        {
            rst=n+1;
        }
    }
    
    printf("%d", rst);

    return 0;
}
