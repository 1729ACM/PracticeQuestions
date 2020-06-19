#include<stdio.h>
#include <string.h>
#define MAX 100010
int dp[MAX];
int a[MAX];
int vis[MAX];
int n;
void dfs(int pos)
{
    if(pos ==-1) return ;
    dfs(vis[pos]);
    printf("%d  ",a[pos]);
}
int main()
{
    while(scanf("%d",&n) && n!=0 )
    {
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        memset(vis,-1,sizeof(vis));// visit for marking element
        int inputIndex = 0;
        int maxlen = 0 ,maxlenIndex,flag = 0;
        while(inputIndex<n) scanf("%d",a[inputIndex++]);
        for(int i = 0 ;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(a[i]>a[j] &&(dp[i]<dp[j]+1))
                {
                    dp[i] = dp[j]+1;
                    vis[i] = j;
                    if(maxlen<dp[i])
                    {
                        maxlen = dp[i];
                        maxlenIndex = i;
                    }
                }
            }
        }
        printf("The max length is %d\n",maxlen+1);
        printf("The longest increasing sequence is \n");
        dfs(maxlenIndex);
    }
}