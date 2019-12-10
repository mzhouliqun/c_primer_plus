#include <stdio.h>
#include <string.h>

typedef struct lens {
	float foclen;
	float fstop;
	char brand[30];
} LENS;

int main(void)
{
//各个成员赋值
	LENS ar[10];
	ar[2].foclen = 500.0;
	ar[2].fstop = 2.0;
	strcpy(ar[2].brand, "Remarkatar");

//指定初始化项目列表
//LENS ar[10] = {[2] = { 500.0, 2.0, "Remarkatar"}};

	printf("%s %.2f %.2f\n", ar[2].brand, ar[2].foclen, ar[2].fstop);
	return 0;
}
