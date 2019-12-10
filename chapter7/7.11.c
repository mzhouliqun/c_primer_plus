#include <stdio.h>
#include <ctype.h>
#define thistle 1.25
#define beet 0.65
#define carrots 0.89
#define basevalue 100
#define discount 0.05
#define weight1 5
#define weight2 20
#define weight_fee1 3.50
#define weight_fee2 10.00
#define over_weight_fee 8
#define over_weight_rate 0.1
void menu(void);
int main(void)
{

	char a, b, c, q, selection;
	double pounda = 0, poundb = 0, poundc = 0, dis_value, v_sum, t_sum, sum;

	while (1)
	{
		menu();
		while ((selection = getchar()) == '\n') continue;
		switch (selection)
		{
			case 'a': printf("Please enter the thistle weight:\n");
				scanf("%lf", &pounda); continue;
			case 'b': printf("Please enter the beet weight:\n");
				scanf("%lf", &poundb); continue;
			case 'c': printf("Please enter the carrots weight:\n");
				scanf("%lf", &poundc); continue;
			case 'e': printf("Done\n"); break;
			case 'q': printf("quit\n"); return 0;
			default : printf("Input error, please input again!\n"); continue;	
		}
		v_sum = pounda * thistle + poundb * beet + poundc * carrots;
		if (v_sum >= 100)
			dis_value = discount;
		else
			dis_value = 0;
		if (pounda + poundb + poundc == 0)
			t_sum = 0;
		else if (pounda + poundb + poundc <= weight1)
			t_sum = weight_fee1;
		else if (pounda + poundb + poundc > weight1 && pounda + poundb <= weight2)
			t_sum = weight_fee2;
		else
			t_sum = (pounda + poundb + poundc - weight2) * over_weight_rate + over_weight_fee;
		sum = v_sum * (1 - dis_value) + t_sum;
		printf("Information for your purchases:\n");
		printf("Cost per pound:\n");
		printf("thistle:	1.25 dollar/poud\n");
		printf("beet:		0.65 dollar/poud\n");
		printf("carrots:	0.89 dollar/poud\n");
		printf("thistle:	%.2lf pound\n", pounda);
		printf("beet:		%.2lf pound\n", poundb);
		printf("carrots:	%.2lf pound\n", poundc);
		printf("The cost of the thistle is %.2lf dollars\n", pounda * thistle);
		printf("The cost of the beet is %.2lf dollars\n", poundb * beet);
		printf("The cost of the carrots is %.2lf dollars\n", poundc * carrots);
		printf("The order of vegetable cost is %.2lf dollars\n", v_sum);
		printf("discount is %.2lf\n", dis_value);
		printf("freight is %.2lf\n", t_sum);
		printf("The order of total cost is %.2lf dollars\n", sum);
	}
	return 0;
}	
void menu(void)
{
	printf("Please input your selection of vegetable: a,b,c,q\n");
	printf("a)thistle\n");
	printf("b)beet\n");
	printf("c)carrots\n");
	printf("e)End Of Input\n");
	printf("q)quit\n");
}
