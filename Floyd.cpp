#include<stdio.h>
  
#define SIZE 110  
#define INF 1000000;  
 
int map[SIZE][SIZE];  //邻接矩阵存储 
int path[SIZE][SIZE]; //路径矩阵
int n;  


// 求最短路径
int floyd(int from, int to){ //从起点到目标点 
    
    int i,j,k;  

    // 中间节点k
    for(k=1; k<=n; k++){

        // 起点i
        for(i=1; i<=n; i++){

            // 终点j
            for(j=1; j<=n; j++){


                // 更新距离和路径
                if(map[i][j]>(map[i][k]+map[k][j]) && i!=j){

                    // 距离
                    map[i][j]=map[i][k]+map[k][j];

                    // 路径
                    path[i][j]=path[i][k];
                }
            }
        }
    }

    return map[from][to];
}
  
  
int main () {  

    n = 6;

    //设一开始每个点都不可达，路径矩阵设置为直达
    for(int i = 1 ; i <= n ; ++i){  
        for(int j = 1 ; j <= n ; ++j){  
            map[i][j] = INF; 
            path[i][j]=j;
        }  
    }

    //测试数据 
    map[1][2] = 6;  
    map[1][3] = 3;
    map[2][3] = 2;
    map[2][4] = 5;
    map[3][4] = 3;
    map[3][5] = 4;
    map[4][5] = 2;
    map[4][6] = 3;
    map[5][6] = 5;


    // 初始化邻接矩阵
    int temp = INF;

    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            if(map[i][j] == temp){
                map[i][j] = map[j][i];
                
            }
        }
    }
 
    
    int ans = floyd(1,6);  
 
    printf("%d\n",ans); 

    
    // 打印路径
    printf("%d", 1);
    int k=path[1][6];
    
    while(k!=6){
        printf("->%d", k);
        k=path[k][6];
        
    } 
    printf("->%d", 6);

    return 0;  
} 
 
/*  边的数据 
1 2 6
1 3 3
2 3 2
2 4 5
3 4 3
3 5 4
4 5 2
4 6 3
5 6 5
*/
