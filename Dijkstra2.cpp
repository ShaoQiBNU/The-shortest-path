#include<stdio.h>
  
#define SIZE 110  
#define INF 1000000;  
 
int map[SIZE][SIZE];  //邻接矩阵存储 
int dist[SIZE];      //d[i]表示起点到i这个点的距离 
int visit[SIZE];  //节点是否被访问 
int n;  


// 求最短路径
int dijkstra(int from, int to){ //从起点到目标点 
    
    int i,j;  
    
    // 起点为已访问状态
    visit[from]=1;

    // 初始化dist
    for(i = 1 ; i <= n ; i ++){
        visit[i] = 0;   //一开始每个点都没被访问 
        dist[i] = map[from][i];  //起点到其他点的距离 
    }

    int temp=0;

    // N 个顶点需要做 N - 1 次循环
    for(i = 1 ; i < n ; ++i){

        //对除起点的每一个点进行最短计算 
        int min = INF;  //记录最小dist[i] 
        
        int pos;  

        // 循环遍历所有顶点
        for(j = 1 ; j <= n ; ++j){

            //记录temp到与其连接点的最小距离的点 
            if(!visit[j] && min > map[temp][j]){  
                pos = j;  
                min = map[temp][j];  
            }  
        }

        // 将顶点放入S中
        visit[pos] = 1;

        // 更新temp
        temp=pos;
        
        // 更新dist
        for(j = 1 ; j <= n ; ++j){
            if(!visit[j] && (dist[j] > (dist[pos] +map[pos][j]))){ //如果j节点没有被访问过&&j节点到起节点的最短路径>pos节点到起节点的最短路径+pos节点到j节点的路径  
                dist[j] = dist[pos] + map[pos][j];    //更新j节点到起节点的最短路径    
            }  
        }  
    }  
  
    return dist[to];
}
  
  
int main () {  

    n = 6;

    //设一开始每个点都不可达 
    for(int i = 1 ; i <= n ; ++i){  
        for(int j = 1 ; j <= n ; ++j){  
            map[i][j] = INF;  
        }  
    }

    //测试数据 
    map[1][2] = 6;  
    map[1][3] = 3;
    map[2][3] = 2;
    map[2][4] = 5;
    map[3][4] = 3;
    map[3][5] = 4;
    map[4][6] = 3;
    map[5][6] = 5;


    // 初始化邻接矩阵
    int temp = INF;

    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            if(map[i][j] == temp)
                map[i][j] = map[j][i];
        }
    }
 
    int ans = dijkstra(1,6);  
 
    printf("%d",ans);  
 
    return 0;  
} 
 
/*  边的数据 
1 2 6
1 3 3
2 3 2
2 4 5
3 4 3
3 5 4
4 6 3
5 6 5
*/
