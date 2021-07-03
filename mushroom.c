#include <stdio.h>
#include <stdlib.h>
//�������Ӧ��
//ʹ��ǰ��Ҫ����ElemType
//ע������Ӧ����1��ͷ
//nΪ�������һ���±�
//��Ҫ���˶���cmp��������������1�������Ϸ���0


typedef struct mashroom
{
	int guard, life;
	/* data */
}Mashroom;

typedef Mashroom ElemType;
int cmp(ElemType a, ElemType b)
{
	return(a.life < b.life);
}

void swap(ElemType *a,ElemType *b)
{
    ElemType temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void sift(ElemType a[], int low, int high, int (*cmp)(ElemType, ElemType))
{
    int i = low, j = 2 * i;
    ElemType tmp = a[i];
    while(j<=high)
    {
        if (j < high && cmp(a[j], a[j + 1]))	
	    j++;
	if (cmp(tmp, a[j]))
	{													     
	    a[i] = a[j];												           
		i = j;												
	    j = 2 * i;         
	}									        
	else		
	    break;

    }		        
    a[i] = tmp;
}

void sort(ElemType *a,int n)
{
    int i;
    for (i = n / 2; i >= 1;i--)
	sift(a, i, n, cmp);			
    for (i = n; i >= 2;i--)				    
    {					    		
        swap(a+1, a + i);
	sift(a, 1, i - 1, cmp);
    }
}



int main()
{
	int n, m, h, b;
	freopen("milk.in", "r", stdin);
    //freopen("milk.out", "w", stdout);
	scanf("%d %d %d %d", &n, &m, &h, &b);
	int hit = h+b, cnt=0;
	Mashroom arr[5005];
	//��ʼ��
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d", &arr[i].guard, &arr[i].life);
	}
	//������
	sort(arr, n);

	//�жϴ�����
	for(int j=1;j<=n&&m>0;j++)
	{
		if(hit>=arr[j].guard){
			if(m>=arr[j].life){
				cnt++;
				m-=arr[j].life;
			} else {
				m -=arr[j].life;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}