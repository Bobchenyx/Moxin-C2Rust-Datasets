#include<stdio.h>
#include<math.h>
#include<stdlib.h>
 
#define MAX 10
 
int *map[MAX][MAX];       //可接受的地图极大值为MAX*MAX
int s_number[(MAX + 1) / 2];  //待分配的岛屿编号数组牌
int count;                //目前岛屿数量
int *current;             //岛数分配指针
 
 
						  //数据初始化
void init(int m, int n) {
	//将岛屿编号牌初始化，分配指针指向第一个
	for (int k = 0; k < m*n / 2 + 1; k++)
		s_number[k] = k;
	current = &s_number[0];
 
	//岛屿数量归0
	count = 0;
 
	//将实际地图初始化为0，代表水域
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = current;
	current++;//current = &s_number[1]
}
 
//并查集，二维数组下查root、合并关键操作
int unify(int x, int y, int nx, int ny, int m, int n) {
	//对插入节点周围的（newx,newy）进行探测
	if (nx < 0 || nx >= m || ny < 0 || ny >= n)
		return 0;
	else if (*map[nx][ny] != 0) {
		if (*map[x][y] == 0) {
			map[x][y] = map[nx][ny];
			return 1;
		}
		else {
			if (*map[nx][ny] != *map[x][y]) {
				map[nx][ny] = map[x][y];
				count--;//岛数减一
				return 1;
			}
			else return 1;
		}
	}
	else return 0;
}
 
void join(int *p, int m, int n) {
	//查看是否重复添加
	if (*map[p[0]][p[1]] == 0) {
		//并查集归根
		int u = unify(p[0], p[1], p[0], p[1] - 1, m, n);//左方节点
		int d = unify(p[0], p[1], p[0], p[1] + 1, m, n);//右方节点
		int l = unify(p[0], p[1], p[0] - 1, p[1], m, n);//上方节点
		int r = unify(p[0], p[1], p[0] + 1, p[1], m, n);//下方节点
		if (u + d + l + r == 0) {
			map[p[0]][p[1]] = current;
			count++;
			current++;
		}
	}
}
 
int* numIslands2(int m, int n, int** positions, int positionsSize, int* positionsColSize, int* returnSize) {
	init(m, n);
	int *number = NULL;
	number = (int*)malloc(sizeof(int) * positionsSize);
 
	//依次加入每个位置
	for (int i = 0; i < positionsSize; i++) {
		join((int*)positions + i * 2, m, n);
		number[i] = count;
	}
 
	*returnSize = positionsSize;
	return number;
}
 
int main() {
	int a[4][2] = { { 0,0 },{ 0, 1 },{ 1,2 },{ 2,1 } };
	int m = 3, n = 3, c = 0;
	int ps = 4;
	int *returnSize = &c;
	int *q = numIslands2(m, n, (int**)a, ps, &c, returnSize);
	printf("%d %d %d %d", *q, *(q + 1), *(q + 2), *(q + 3));
	return 0;
}