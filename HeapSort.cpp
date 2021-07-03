//ʹ��ǰ��Ҫ����ElemType
//ע������Ӧ����1��ͷ
//nΪ�������һ���±�
//��Ҫ���˶���cmp

//int up(ElemType a, ElemType b)

typedef int ElemType;

void swap(ElemType *a,ElemType *b)
{
    ElemType temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void sift(ElemType a[],
    int low,
    int high,
    int (*cmp)(ElemType, ElemType))
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

int cmp(ElemType a, ElemType b){
	
}