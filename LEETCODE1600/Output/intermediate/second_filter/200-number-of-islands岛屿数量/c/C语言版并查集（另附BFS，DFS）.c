#define DIR 2
#define ROW 0
#define COL 1

int direct[2][2]={
    1,0,
    0,1
};

/*
    找到根节点 
*/

int Find(int** parent, int i, int j, int row, int col){
    if(parent[i][j]==-1){
        return i*col+j;
    }
    return Find(parent,parent[i][j]/col,parent[i][j]%col,row,col);
}

/*

    进行并查集的合并
    合并条件：没有相同的根节点

    根节点不同时，最终根节点由parent更小的根节点决定

*/

void Union(int** parent, int posi, int posj, int newi, int newj, int row, int col, int* ans){
    int pos_root=Find(parent,posi,posj,row,col);
    int new_root=Find(parent,newi,newj,row,col);
    if(pos_root==new_root){
        return ;
    }
    if(pos_root<new_root){
        parent[new_root/col][new_root%col]=pos_root;
    }else{
        parent[pos_root/col][pos_root%col]=new_root;
    }
    *ans=*ans-1;
}

/*
    parent用来保存对应节点的父亲节点，parent[i][j]==-1时表示(i,j)就是根节点
*/

int numIslands(char** grid, int gridSize, int* gridColSize){
    if(gridSize==0 || *gridColSize==0){
        return 0;
    }
    int ans=gridSize*(*gridColSize);
    int** parent=(int**)malloc(sizeof(int*)*gridSize);
    for(int i=0;i<=gridSize-1;i++){
        parent[i]=(int*)malloc(sizeof(int)*(*gridColSize));
        memset(parent[i],-1,sizeof(int)*(*gridColSize));       
    }
    for(int i=0;i<=gridSize-1;i++){
        for(int j=0;j<=*gridColSize-1;j++){
            if(grid[i][j]=='1'){
                for(int dir=0;dir<=DIR-1;dir++){
                    int newi=i+direct[dir][ROW];
                    int newj=j+direct[dir][COL];
                    if((newi<=gridSize-1) && (newj<=*gridColSize-1) && (grid[newi][newj]=='1')){
                        Union(parent,i,j,newi,newj,gridSize,*gridColSize,&ans);
                    }
                }
            }
            else if(grid[i][j]=='0'){
                ans--;
            }
        }
    }
    return ans;
}