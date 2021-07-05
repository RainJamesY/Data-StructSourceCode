//数组模拟邻接表运行
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 存储
#define maxn 100

struct edge {
    int v, next;				//v是当前插入的vertex，next是下一个vertex
} e[maxn * 2];					//按照读入顺序储存所有读入的边的信息
int p[maxn], eid, d[maxn];		//p[]储存每个顶点连接的第一个顶点

void init() {
    eid = 0;
    memset(p, -1, sizeof(p));
}

void insert(int x, int y) {
    e[eid].v = y;
    e[eid].next = p[x];		//用p[x]中的值（上一个顶点的索引）作为数组e的下标索引，头插法更新p[x]对应顶点
    p[x] = eid;
	eid++;					//先将当前eid赋给p[x]作为顶点x更新的那条边的下标，再eid++，为读入下一条边做准备
	//p[x]中对应的是填入的顶点对应的边在edge数组里的下标
} 

void insert2(int x, int y) {
    insert(x, y);
    insert(y, x);
}
int main()
{
	int n;
// 遍历所有边
	for (int i = 1; i <= n; i++) {
    	for (int j = p[i]; ~j; j = e[j].next) {  // ~j 相当于 j != -1
        	printf("->%d ", e[j].v);
    	}
	}

}