/*************************************************************************
    > File Name: insertsort.cpp
    > Author: ison
    > Mail: 1171403023@qq.com 
    > Created Time: 2017年05月23日 星期二 11时11分39秒
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

int insertsort(int* arr, int lenth);
int swap(int* a, int* b);
int show(int* arr, int lenth);

int main(int argc, char* argv[])
{
    int ret = 0;
	int lenth = 0;
	int arr[] = {6, 0, 9, 7, 1, 4, 5, 3, 2, 8};
	do_return_val(NULL == argv, ERR_CODE);

	lenth = sizeof(arr)/sizeof(arr[0]);
    ret = insertsort(arr, lenth);
	do_return_val(ERR_CODE == ret, ret);

	ret = show(arr, lenth);
	do_return_val(ERR_CODE == ret, ret);

	return OK_CODE;
}

int insertsort(int* arr, int lenth)
{
    int i = 0 ,j = 0;
	int ret = 0;
	int tmp = 0;
	do_return_val(NULL == arr, ERR_CODE);

	for(i; i < lenth; i++)
	{
		tmp = arr[i];
		for(j = i; j > 0; j--)
		{
			if(tmp < arr[j - 1])
			{
				arr[j] = arr[j - 1];
			}
			else
			{
				break;
			}
		}
		arr[j] = tmp;
	}

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
