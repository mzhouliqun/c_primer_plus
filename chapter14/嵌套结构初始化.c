#include <stdio.h>
int main(void)
{
	union u {
		int u_n;
		char u_c;
	};
//	union u data = {.u_n = 2};
	struct s {
		int s_n;
		union u data;
		double s_d;
	};
	struct s kk = {.data.u_n = 1001};
	printf("%d\n", kk.data.u_n);
	return 0;
}
