//����ģ���ڽӱ�����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// �洢
#define maxn 100

struct edge {
    int v, next;				//v�ǵ�ǰ�����vertex��next����һ��vertex
} e[maxn * 2];					//���ն���˳�򴢴����ж���ıߵ���Ϣ
int p[maxn], eid, d[maxn];		//p[]����ÿ���������ӵĵ�һ������

void init() {
    eid = 0;
    memset(p, -1, sizeof(p));
}

void insert(int x, int y) {
    e[eid].v = y;
    e[eid].next = p[x];		//��p[x]�е�ֵ����һ���������������Ϊ����e���±�������ͷ�巨����p[x]��Ӧ����
    p[x] = eid;
	eid++;					//�Ƚ���ǰeid����p[x]��Ϊ����x���µ������ߵ��±꣬��eid++��Ϊ������һ������׼��
	//p[x]�ж�Ӧ��������Ķ����Ӧ�ı���edge��������±�
} 

void insert2(int x, int y) {
    insert(x, y);
    insert(y, x);
}
int main()
{
	int n;
// �������б�
	for (int i = 1; i <= n; i++) {
    	for (int j = p[i]; ~j; j = e[j].next) {  // ~j �൱�� j != -1
        	printf("->%d ", e[j].v);
    	}
	}

}