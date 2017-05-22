/*************************************************************************
    > File Name: heapsort.cpp
    > Author: ison
    > Mail: 1171403023@qq.com 
    > Created Time: 2017年05月22日 星期一 17时32分15秒
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

int heapsort(int* arr, int lenth);
int heap(int* arr, int start, int lenth);
int swap(int* a, int* b);
int show(int* arr, int lenth);

int main(int argc, char* argv[])
{
    int ret = 0;
	int lenth = 0;
    int arr[] = {6, 9, 0, 2, 7, 3, 8, 5, 1, 4};

	do_return_val(NULL == argv, ERR_CODE);

	lenth = sizeof(arr)/sizeof(arr[0]);
	ret = heapsort(arr, lenth - 1);
	do_return_val(ERR_CODE == ret, ret);

	ret = show(arr, lenth);
	do_return_val(ERR_CODE == ret, ret);

	return OK_CODE;
}

int heapsort(int* arr, int lenth)
{
	int i = 0;
    int ret = 0;

	do_return_val(NULL == arr, ERR_CODE);

	for(i = lenth/2; i >= 0; i--)
	{
		ret = heap(arr, i, lenth);
		do_return_val(ERR_CODE == ret, ret);
	}
    ret = swap(&arr[0], &arr[lenth]);
	do_return_val(ERR_CODE == ret, ret);

	for(i = lenth - 1; i > 0; i--)
	{
		ret = heap(arr, 0, i);
		do_return_val(ERR_CODE == ret, ret);
		ret = swap(&arr[0], &arr[i]);
		do_return_val(ERR_CODE == ret, ret);
	}

	return OK_CODE;
}

int heap(int* arr, int start, int lenth)
{
    int i = 0;
	int ret = 0;
	int index = 0;

	do_return_val(NULL == arr, ERR_CODE);

	for(i = start; i <= lenth/2; i++)
	{
		index = i;
		if(2 * i + 1 < lenth && arr[index] > arr[2 * i + 1])
		{
			index = 2 * i + 1;
		}
		if(2 * i + 2 < lenth && arr[index] > arr[2 * i + 2])
		{
			index = 2 * i + 2;
		}
		if(index != i)
		{
			ret = swap(&arr[index], &arr[i]);
			do_return_val(ERR_CODE == ret, ret);
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
