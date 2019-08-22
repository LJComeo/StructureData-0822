#include <stdio.h>
#include <stdlib.h>
#include "sort.h"



void InsertSort(int *src, int n)//直接插入排序(数组足够小时最优,数组越有序插排越快)
{
	int i, j;
	int tmp;
	for (i = 1; i < n; i++)
	{
		tmp = src[i];
		for (j = i; j>0 && src[j - 1]>tmp; j--)
		{
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}
}
void ShelSort(int *src, int n)//希尔排序：插入排序的优化，比插入排序稍微快一点
{
	int i, j, k;
	int gap , tmp;
	for (gap = n / 2; gap; gap /= 2)
	{
		for (k = 0; k<gap; k++, gap /= 2)
		{
			for (i = gap + k; i < n; i += gap)
			{
				tmp = src[i];
				for (j = i; j >= gap && src[j - gap]>tmp; j-=tmp)
				{
					src[j] = src[j - gap];
				}
				src[j] = tmp;
			}
		}
	}
}
//归并排序要借助一个临时的空间(相当于二叉树的后序)
void dealMergeDort(int *src, int *tmp, int start, int end)//里面自己的函数实现
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	dealMergeDort(src, tmp, start, mid);
	dealMergeDort(src, tmp, mid + 1, end);
	int a = start;
	int b = mid + 1;
	int c = start;
	while (a<=mid && b<=end)
	{
		if (src[a] < src[b])
		{
			tmp[c] = src[a];
			a++;
		}
		else
		{
			tmp[c] = src[b];
			b++;
		}
		c++;
	}
	for (; a <= mid; a++,c++)
	{
		tmp[c] = src[a];
	}
	for (; b <= end; b++, c++)
	{
		tmp[c] = src[b];
	}
	int i;
	for (i = start; i <= end; i++)
	{
		src[i] = tmp[i];
	}
}
void MergeSort(int *src, int n)//归并排序的外界接口
{
	int *tmp = (int *)malloc(n*sizeof(int));
	dealMergeDort(src, tmp, 0, n - 1);
	free(tmp);
}