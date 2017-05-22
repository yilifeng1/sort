/*************************************************************************
    > File Name: bubblesort.cpp
    > Author: ison
    > Mail: 1171403023@qq.com 
    > Created Time: 2017年05月22日 星期一 18时15分59秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define OK_CODE   0
#define ERR_CODE -1
#define do_return_val(ret, code)\
	do{\
		if(ret){\
			return code;\
		}\
	}while (0);\

int bubblesort(int* arr, int lenth);
int swap(int* a, int* b);
int show(int* arr, int lenth);

int main(int argc, char* argv[])
{
    int ret = 0;
	int lenth = 0;
	int arr[] = {6, 0, 3, 7, 1, 2, 8, 4, 5, 9};
	do_return_val(NULL == argv, ERR_CODE);

	lenth = sizeof(arr)/sizeof(arr[0]);
	ret = bubblesort(arr, lenth - 1);
    do_return_val(ERR_CODE == ret, ret);

	ret = show(arr, lenth);
	do_return_val(ERR_CODE == ret, ret);

	return OK_CODE;
}

int bubblesort(int* arr, int lenth)
{
	int i = 0, j = 0;
	int ret = 0;

    do_return_val(NULL == arr, ERR_CODE);

	for(i; i <= lenth; i++)
	{
		for(j = i; j <= lenth; j++)
		{
			if(arr[i] > arr[j])
			{
				ret = swap(&arr[i], &arr[j]);
				do_return_val(ERR_CODE == ret, ret);
			}
		}
	}

	return OK_CODE;
}

int swap(int* a, int* b)
{
    int tmp = *a;
	do_return_val(NULL == a || NULL == b, ERR_CODE);

	*a = *b;
	*b = tmp;

	return OK_CODE;
}

int show(int* arr, int lenth)
{
    int i = 0;
	do_return_val(NULL == arr, ERR_CODE);

    for(i; i < lenth; i++)
	{
		cout<<arr[i]<<endl;
	}

	return OK_CODE;
}
