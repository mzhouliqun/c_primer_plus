/* data example:
0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 5 2 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 1 9 8 5 4 5 2 0 0 0 0 0 0 0 0 0
0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 0 4 5 2 0 0 0 0 0 0 0 0
0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 4 5 2 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 1 8 5 0 0 0 4 5 2 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 4 5 2 0 0 0 0 0
5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
9 9 9 9 0 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 3 9 9 9 9 9 9 9
8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
0 0 0 0 2 2 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
0 0 0 0 3 3 0 0 0 0 0 0 5 8 9 9 8 5 0 5 6 1 1 1 1 6 5 0 0 0
0 0 0 0 4 4 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
0 0 0 0 5 5 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ROW 20  //数组行数
#define CLO 30  //数组列数

char itoc(int s); //将s转换为指定的字符
void xiao(int row, int clo, int image[row][clo]);
int y4(int n, int tt[n]); //如果所有元素都大于等于1，如果大于则返回1，否则返回0
int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	int num = 0;
	int image[ROW][CLO] = {0};
	char imagechar[ROW][CLO + 1] = {0};
	FILE *fp = fopen("1.txt", "r");
	FILE *fp1 = fopen("2.txt", "w");
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < CLO; j++)
		{
			fscanf(fp, "%d", &num);
			image[i][j] = num;
			imagechar[i][j] = itoc(num);
			printf("%c", imagechar[i][j]);
		}
		imagechar[i][CLO] = '\n';
		fprintf(fp1, "%s", &imagechar[i]);
		printf("\n");
	}
	fclose(fp);
	fclose(fp1);
	printf("\n\n-----图像尖峰处理------\n\n");
	FILE *fp4 = fopen("3.txt", "w"); //对图像进行尖峰处理
	xiao(ROW, CLO, image);
	memset (imagechar, 0, sizeof(imagechar));
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < CLO; j++)
		{
			imagechar[i][j] = itoc(image[i][j]);
		}
		imagechar[i][CLO] = '\n';
		fprintf(fp4, "%s", &imagechar[i]);
		printf("%s",imagechar[i]);
	}
	fclose(fp4);
	return 0;
}
  
char itoc(int s)
{
	char chs[10] = " .':~*=7%#";
	return chs[s];
}

void xiao(int row, int clo, int image[row][clo])
{
	int i = 0;
	int j = 0;
	int temp[4] = {0}; //存放与上下左右相减的绝对值
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < clo; j++)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					temp[0] = abs(image[i][j] - image[i + 1][j]); //下值
					temp[1] = abs(image[i][j] - image[i][j + 1]); //右值
					if (y4(2, temp))
						image[i][j] = (image[i+1][j] + image[i][j + 1]) / 2; //矩阵的左上角
				}
				else if (j == clo - 1)
				{
					temp [0] = abs(image[i][j] - image[i][j - 1]); //左值
					temp [1] = abs(image[i][j] - image[i + 1][j]); //下值
					if (y4(2, temp))
						image[i][j] = (image[i][j - 1] + image[i + 1][j]) / 2; //矩阵的右上角
				}
				else
				{
					//矩阵上边
					temp[0] = abs(image[i][j] - image[i][j - 1]); //左值
					temp[1] =  abs(image[i][j] - image[i][j + 1]); //右值
					temp[2] =  abs(image[i][j] - image[i + 1][j]); //下值
					if (y4(3, temp))
					image[i][j] = (image[i][j - 1] + image[i][j + 1] + image[i + 1][j]) / 3; //矩阵的上条边
				}
			}
			else if (i == row - 1)
			{
				if (j == 0)
				{
					temp[0] = abs(image[i][j] - image[i - 1][j]); //上值
					temp[1] = abs(image[i][j] - image[i][j + 1]); //右值
					if (y4(2, temp))
						image[i][j] = (image[i - 1][j] + image[i][j + 1]) / 2; //矩阵的左下角
				}
				else if (j == clo - 1)
				{
					temp[0] = abs(image[i][j] - image[i][j - 1]); //左值
					temp[1] =  abs(image[i][j] - image[i - 1][j]); //上值
					if (y4(2,temp)) image[i][j] = (image[i][j - 1] + image[i - 1][j]) / 2; //矩阵的右下角
				}
				else
				{
					//矩阵下边
					temp[0] = abs(image[i][j] - image[i][j - 1]); //左值
					temp[1] = abs(image[i][j] - image[i][j + 1]); //右值
					temp[2] = abs(image[i][j] - image[i - 1][j]); //上值
					if (y4(3, temp))
						image[i][j] = (image[i][j - 1] + image[i][j + 1] + image[i - 1][j]) / 3; //矩阵的下条边
				}
			}
			else if (j == 0)
			{
				temp[0] = abs(image[i][j] - image[i - 1][j]); //上值
				temp[1] = abs(image[i][j] - image[i + 1][j]); //下值
				temp[2] = abs(image[i][j] - image[i][j + 1]); //右值
				if (y4(3, temp))
					image[i][j] = (image[i - 1][j] + image[i + 1][j] + image[i][j + 1]) / 3; //矩阵的左条边
			}
			else if (j == clo - 1)
			{
				temp[0] = abs(image[i][j] - image[i - 1][j]); //上值
				temp[1] = abs(image[i][j] - image[i + 1][j]); //下值
				temp[2] =  abs(image[i][j] - image[i][j - 1]); //左值
				if (y4 (3, temp))
				image[i][j] = (image[i - 1][j] + image[i + 1][j] + image[i][j - 1]) / 3; //矩阵的右条边
			}
			else
			{
				temp[0] = abs(image[i][j] - image[i - 1][j]); //上值
				temp[1] = abs(image[i][j] - image[i + 1][j]); //下值
				temp[2] = abs(image[i][j] - image[i][j - 1]); //左值
				temp[3] = abs(image[i][j] - image[i][j + 1]); //右值
				if (y4 (4, temp))
				image[i][j] = (image[i - 1][j] + image[i + 1][j] + image[i][j - 1] + image[i][j + 1]) / 4; //矩阵内部 
			}
		}
	}
}

int y4(int n, int tt[n])
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (tt[i] <= 1)
		return 0;
	}
	return 1;
}

