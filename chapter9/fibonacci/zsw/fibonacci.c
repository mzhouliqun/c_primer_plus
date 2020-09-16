#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void displayResult(char *buffer, unsigned bufferSize);
void initBuffer( char *buffer, unsigned size );
void resultReverse( char *from, char *to, int size);

int addBuffer( char *bufferA, char *bufferB, char *bufferC, int resultLength, int bufferSize);
int addInteger( int a, int b, int carry, char *buffer);
int fetchResult( char *buffer0, char *buffer1, char *buffer2, char *buffer3, unsigned bufferSize, int mode);

int main(int argc, char *argv[])
{
		unsigned int bufferSize;
		unsigned int maxCount;
		char *buffer0;
		char *buffer1;
		char *buffer2;
		char *buffer3;

		if ( argc < 3 )
		{
				printf("Usage: %s [bufferSize] [count]\n", argv[0]);
				exit(-1);
		}

		bufferSize = atoi(argv[1]);
		maxCount = atoi(argv[2]);
		if  ( maxCount < 3 || bufferSize < 3 )
		{
				printf("The count(%s) and bufferSize must be larger than 2.\n", argv[1]);
				printf("Usage: %s [bufferSize] [count]\n", argv[0]);
				exit(-1);
		}

		buffer0 = malloc(sizeof(char)*(1+maxCount));
		buffer1 = malloc(sizeof(char)*(1+maxCount));
		buffer2 = malloc(sizeof(char)*(1+maxCount));
		buffer3 = malloc(sizeof(char)*(1+maxCount));

		initBuffer(buffer1, maxCount+1);
		initBuffer(buffer2, maxCount+1);
		initBuffer(buffer0, maxCount+1);

		int i,j=0;
		int mode = 0;
		int resultLength = 1;

		for ( i = 2; i < maxCount; ++i )
		{
				mode = (j++) % 3;
				switch(mode)
				{
						case 0:
								resultLength = addBuffer(buffer1, buffer2, buffer0, resultLength, maxCount); break;
						case 1:
								resultLength = addBuffer(buffer2, buffer0, buffer1, resultLength, maxCount); break;
						default:
								resultLength = addBuffer(buffer0, buffer1, buffer2, resultLength, maxCount);
				}
		}

		fetchResult( buffer0, buffer1, buffer2, buffer3, resultLength, mode);
		displayResult( buffer3, resultLength );

		printf("resultLength = %d\n", resultLength);

		free(buffer1);
		free(buffer2);
		free(buffer0);
		exit(0);
}

/* fetch buffer0 -> bufferTo */
void displayResult(char *buffer, unsigned bufferSize)
{
		printf("%s\n", buffer);
}

int fetchResult( char *buffer0, char *buffer1, char *buffer2, char *buffer3, unsigned resultSize, int mode)
{
		switch(mode)
		{
				case 0:
						resultReverse(buffer0, buffer3, resultSize);
						break;
				case 1:
						resultReverse(buffer1, buffer3, resultSize);
						break;
				default:
						resultReverse(buffer2, buffer3, resultSize);
		}

		return resultSize;
}

void resultReverse( char *from, char *to, int size)
{
		int i;
		int j = size - 1;
		for ( i = 0; i < size; ++i )
		{
				to[i] = 48 + from[j--]; /* '0' = 48 */
		}
}

/* init buffer */
void initBuffer( char *buffer, unsigned size )
{
		memset(buffer, 0, size);	
		*buffer = 1;
		return;
}

/* C = A+B, result = length of result */
int addBuffer( char *bufferA, char *bufferB, char *bufferC, int resultLength, int bufferSize)
{
		int len;
		int index;
		int carryCount = 0;
		for ( index = 0; index < resultLength; ++index )
		{
				carryCount = addInteger( *(bufferA+index), *(bufferB+index), carryCount, bufferC+index );
		}

		len = resultLength;
		if ( carryCount > 0 ) 
		{
				if ( ++len < bufferSize )
				{
						*(bufferC+len-1) = carryCount;
						/* printf( "addBuffer, bufferLen = %d, %d.\n", len, *(bufferC+len) ); */
						return len;
				}
				printf(" len > bufferSize !!!");
				exit(-1);
		}
		return len;
}

/* *buffer = a + b, return carryCount */
int addInteger( int a, int b, int carry, char *buffer)
{
		int result = a+b+carry;
		*buffer = ( result%10 ) & 0x000000ff;
		result/=10;	
		/* printf("addInteger: %d + %d = %d, carry = %d, newCarry = %d\n", a, b, *buffer, carry, result);*/
		return result;
}


/* End of file */

