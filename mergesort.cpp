/*************************************************************************
    > File Name: mergesort.cpp
    > Author: ison
    > Mail: 1171403023@qq.com 
    > Created Time: 2017年05月20日 星期六 13时27分59秒
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

int mergesort(int* arr, int start, int end);
int merge(int* arr, int start, int midd, int end);
int show(int* arr, int lenth);

int main(int argc, char* argv[])
{
	int ret = 0;
	int arr[] = {6, 8, 1, 3, 0, 9, 7, 2, 5, 4};

	do_return_val(NULL == argv, ERR_CODE);

	ret = mergesort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
	do_return_val(ERR_CODE == ret, ERR_CODE);

	ret = show(arr, sizeof(arr)/sizeof(arr[0]));
	do_return_val(ERR_CODE == ret, ERR_CODE);

	return OK_CODE;
}

int mergesort(int* arr,int start,int end)
{
	int ret = 0;
	int midd = (start + end)/2;

    do_return_val(NULL == arr, ERR_CODE);

	if(start < end)
	{
		ret = mergesort(arr, start, midd);
		do_return_val(ERR_CODE == ret, ERR_CODE);

		ret = mergesort(arr, midd + 1, end);
		do_return_val(ERR_CODE == ret, ERR_CODE);

		ret = merge(arr, start, midd, end);
		do_return_val(ERR_CODE == ret, ERR_CODE);
	}

	return OK_CODE;
}

int merge(int* arr, int start, int midd, int end)
{
	int i = start;
	int j = midd + 1;
	int k = 0;
	int* tmp_arr = NULL;

	do_return_val(NULL == arr, ERR_CODE);

    tmp_arr = new int[end - start + 1];

    while(i <= midd && j <= end)
	{
	    if(arr[i] < arr[j])	
		{
			tmp_arr[k++] = arr[i++];
		}
		else
		{
			tmp_arr[k++] = arr[j++];
		}
	}
	while(i <= midd)
	{
		tmp_arr[k++] = arr[i++];
	}
	while(j <= end)
	{
		tmp_arr[k++] = arr[j++];
	}

	for(i = 0; i < k; i++)
	{
		arr[start++] = tmp_arr[i]; 
	}

	delete []tmp_arr;

	return OK_CODE;
}

int show(int* arr, int lenth)
{
	int ret = 0;
	int i = 0;

    do_return_val(NULL == arr, ERR_CODE);

	for(i; i < lenth; i++)
	{
		cout<<arr[i]<<endl;
	}

	return OK_CODE;
}
