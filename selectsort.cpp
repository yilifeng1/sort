/*************************************************************************
    > File Name: selectsort.cpp
    > Author: ison
    > Mail: 1171403023@qq.com 
    > Created Time: 2017年05月22日 星期一 19时16分19秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define OK_CODE   0
#define ERR_CODE -1
#define do_return_val(ret, code)\
	do{\
        if(ret)\
		{\
			return code;\
		}\
	}while (0);\

int selectsort(int* arr, int lenth);
int swap(int* a, int* b);
int show(int* arr, int lenth);

int main(int argc, char* argv[])
{
    int ret = 0;
	int lenth = 0;
    int arr[] = {6, 9, 0, 1, 7, 4, 3, 2, 5, 8};

	do_return_val(NULL == argv, ERR_CODE);

	lenth = sizeof(arr)/sizeof(arr[0]);
	ret = selectsort(arr, lenth);
	do_return_val(ERR_CODE == ret, ret);

	ret = show(arr, lenth);
	do_return_val(ERR_CODE == ret, ret);

	return OK_CODE;
}

int selectsort(int* arr, int lenth)
{
    int ret = 0;
    int i = 0, j = 0;
	int tmp = 0;
	do_return_val(NULL == arr, ERR_CODE);

    for(i; i < lenth; i++)
	{
		tmp = i;
	    for(j = i; j < lenth; j++)
		{
			if(arr[tmp] > arr[j])
			{
				tmp = j;
			}
		}
		ret = swap(&arr[i], &arr[tmp]);
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
