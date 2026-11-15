#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int in[n], ou[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &in[j]);
        }
        if ((in[0] + in[1] == in[2]) || (in[1] + in[2] == in[0]) || (in[2] + in[0] == in[1]))
        {
            ou[i] = 1;
        }
        else
        {
            ou[i] = 0;
        }
    }
    for(int i = 0;i < n;i++){
        if(ou[i] == 1){
            printf("YES");
        }
        else{
            printf("NO");
        }
    }
}