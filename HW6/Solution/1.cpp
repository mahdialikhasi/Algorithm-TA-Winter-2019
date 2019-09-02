#include <stdio.h>
#include <string.h>
#define MAX 102
 
int T,R,C,M,N,W;
int g[MAX][MAX], v[MAX][MAX], c[MAX][MAX];
 
int incr[2]={1,-1};
void dfs(int x, int y){
    int i,j,m,n;
    if(v[x][y]) 
        return;
    v[x][y]=1;
    for(i=0; i<2;i++){
        for(j=0;j<2;j++){
            m = x+incr[i]*M;
            n = y+incr[j]*N;
            if(m>=0 && m < R && n>=0 && n<C && g[m][n]!=-1){
                c[m][n]++;
                dfs(m,n);
            }
            m = x+incr[i]*N;
            n = y+incr[j]*M;
            if(m>=0 && m < R && n>=0 && n<C && g[m][n]!=-1){
                c[m][n]++;
                dfs(m,n);
            }
        }
    }
}
 
int main(){
    int t,i,j,even,odd;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        /* clean-up */
        memset(v,0,sizeof v);
        memset(g,0,sizeof g);
        memset(c,0,sizeof c);
        even=odd=0;
        /* Input Begin */
        scanf("%d %d %d %d %d",&R,&C,&M,&N,&W);
        while(W--){
            scanf("%d %d",&i,&j);
            g[i][j] = -1;
        }
        /* Input end */
        dfs(0,0);
        /* Count evens and odds */
        for(i=0;i<R;i++) {
            for(j=0;j<C;j++){
                /* We counted twice */
                if(M==0||N==0||M==N)
                    c[i][j]/=2;
                
                if(c[i][j] || (!i && !j)) { 
                    if(c[i][j] % 2 == 0) even++; 
                    else odd++;
                }
            }
            
        }
        printf("Case %d: %d %d\n",t,even,odd);
    }
    return 0;
}