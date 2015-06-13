#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int inf=0x3f3f3f3f;
const int MAX_N=18;
char map[110][110];
int num,width,height;
int dist[25][25],vis[25][25];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int dp[(1<<18)-1][20];

class Node{
public:
    int x,y,d;
};

Node checkpoint[20],start,goal;

int distance(int s,int t){
    queue<Node> que;
    Node node;
    memset(vis,0,sizeof(vis));
    node.x=checkpoint[s].x,node.y=checkpoint[s].y,node.d=0;
    vis[node.x][node.y]=1;
    que.push(node);
    while(!que.empty()){
        node=que.front();
        que.pop();
        int x1,y1;
        x1=node.x,y1=node.y;
        if(x1==checkpoint[t].x&&y1==checkpoint[t].y) return node.d;
        for(int i=0;i<4;i++){
            int x2=x1+dx[i];
            int y2=y1+dy[i];
            if(x2>=0&&x2<height&&y1>=0&&y2<width&&vis[x2][y2]==0&&map[x2][y2]!='#'){
                vis[x2][y2]=1;
                Node node1;
                node1.x=x2,node1.y=y2,node1.d=node.d+1;
                que.push(node1);
            }
        }
    }
    return inf;
}

int dfs(int status,int vis){
    if(dp[status][vis]!=-1) return dp[status][vis];
    if(status==0) return dp[status][vis]=dist[0][vis];
    int res=inf;
    for(int i=1;i<=num;i++){
        if(status&(1<<(i-1))){
            res=min(res,dfs(status&(~(1<<(i-1))),i)+dist[i][vis]);//problem
        }
    }
    return dp[status][vis]=res;
}

int main(){
    cin>>width>>height;
    num=0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>map[i][j];
            if(map[i][j]=='S'){
                start.x=i;
                start.y=j;
            }
            else if(map[i][j]=='G'){
                goal.x=i;
                goal.y=j;
            }
            else if(map[i][j]=='@'){
                checkpoint[++num].x=i;
                checkpoint[num].y=j;
            }
        }
    }
    checkpoint[0].x=start.x,checkpoint[0].y=start.y;
    checkpoint[num+1].x=goal.x,checkpoint[num+1].y=goal.y;
    memset(dist,0,sizeof(dist));
    int flag=1;
    for(int i=0;i<=num+1;i++){
        for(int j=0;j<=num+1;j++){
            if(i!=j){
                dist[i][j]=dist[j][i]=distance(i,j);
                if(dist[i][j]==inf){
                    flag=0;
                    break;
                }
            }
        }
        if(flag==0) break;
    }
    if(flag==0){
        cout<<"-1"<<endl;
        return 0;
    }
    if(num==0){
        cout<<dist[0][1]<<endl;
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    int res=inf;
    for(int i=1;i<=num;i++){
        res=min(dfs((1<<(num))-1,i)+dist[i][num+1],res);
    }
    cout<<res<<endl;
    return 0;
}
