#include <stdio.h>
void calculate(double, double);
int main(void)
{
	double download_speed = .0;
	double file_size = .0;
	char ch;

	printf("Please enter the download speed(Mb/s) and file size(MB) respectively:\n");
	while (scanf("%lf %lf", &download_speed, &file_size) != 2)
	{
		if (ch = getchar() == EOF)
		{
			while (ch == EOF)
				ch = getchar();
			break;
		}
		while (ch != '\n' && ch != EOF)
			ch = getchar();
	}
	calculate(download_speed, file_size);
	return 0;
}

void calculate(double ds, double fs)
{
	printf("\nAt %.2lf megabits per second, a file of %.2lf megabytes down in %.2lf seconds.\n", ds, fs, fs / (ds / 8));
}
