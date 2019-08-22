#include <stdio.h>
#include <stdlib.h>
#include "sort.h"



void InsertSort(int *src, int n)//ֱ�Ӳ�������(�����㹻Сʱ����,����Խ�������Խ��)
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
void ShelSort(int *src, int n)//ϣ�����򣺲���������Ż����Ȳ���������΢��һ��
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
//�鲢����Ҫ����һ����ʱ�Ŀռ�(�൱�ڶ������ĺ���)
void dealMergeDort(int *src, int *tmp, int start, int end)//�����Լ��ĺ���ʵ��
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
void MergeSort(int *src, int n)//�鲢��������ӿ�
{
	int *tmp = (int *)malloc(n*sizeof(int));
	dealMergeDort(src, tmp, 0, n - 1);
	free(tmp);
}