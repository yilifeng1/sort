/*************************************************************************
    > File Name: quicksort.cpp
    > Author: ison
    > Mail: 1171403023@qq.com 
    > Created Time: 2017年05月20日 星期六 10时44分07秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define ERR_CODE -1
#define OK_CODE   0
#define do_return_val(ret, code)\
	do{\
	    if(ret)\
		{\
		    return code;\
		}\
	}while (0);\

int quicksort(int* arr, int start, int end);
int partition(int* arr, int start, int end);
int swap(int* a, int* b);
int show(int* arr, int lenth);

int main(int argc, char* argv[])
{
	int ret = 0;
    int arr[] = {6, 2, 9, 1, 8, 0, 3, 7, 4, 5};

    do_return_val(NULL == argv, ERR_CODE);

	ret = quicksort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
	do_return_val(OK_CODE != ret, ERR_CODE);

	ret = show(arr, sizeof(arr)/sizeof(arr[0]));
	do_return_val(OK_CODE != ret, ERR_CODE);

    return OK_CODE;
}

int quicksort(int* arr, int start, int end)
{
    int ret = 0;
	int midd = 0;

	do_return_val(NULL == arr, ERR_CODE);

	if(start < end)
	{
	    midd = partition(arr, start, end);
		do_return_val(ERR_CODE == midd, ERR_CODE);

		ret = quicksort(arr, start, midd);
		do_return_val(ERR_CODE == ret, ERR_CODE);

		ret = quicksort(arr, midd + 1, end);
		do_return_val(ERR_CODE == ret, ERR_CODE);
	}

	return OK_CODE;
}

int partition(int* arr, int start, int end)
{
    int ret = 0;
	int tmp = arr[start];

	do_return_val(NULL == arr, ERR_CODE);

	while(start < end)
	{
	    while(start < end && tmp < arr[start])
		{
		    start++; 
		}
		while(start < end && tmp > arr[end])
		{
		    end--;
		}
		swap(&arr[start], &arr[end]);
	}

	return start;
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
	do_return_val(NULL == arr, ERR_CODE);

	for(int i = 0; i < lenth; i++)
	{
		cout<<arr[i]<<endl;
	}

	return OK_CODE;
}

