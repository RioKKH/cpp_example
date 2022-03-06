#include <iostream>

int* local()
{
	int i = 42; // ローカル変数
	return &i; // 警告！団グリングポインター
}

int* dyn_alloc()
{

