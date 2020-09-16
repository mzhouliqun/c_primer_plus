#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define NUMBER_GROUP_LENGTH		18
#define RADIX					1000000000000000000l;

void usage(int argc, char *argv[]);
void displayUsage( char *programName );
void initBuffer( long **buffer0, long **buffer1, long **buffer2, unsigned maxSize);
void freeBuffer( long **buffer0, long **buffer1, long **buffer2 );
void displayBuffer( long *buffer, int resultLen );

long *fibonacci( unsigned which, long *buffer0, long *buffer1, long *buffer2, unsigned int bufferSize, int *pResultLen );
int addBuffer( long *buffer1, long *buffer2, long *buffer0, unsigned int resultLen, unsigned int bufferSize );

void displayBuffer( long *buffer, int resultLen );

int main(int argc, char *argv[])
{
		int resultLen = 1;

		unsigned int which;
		unsigned int maxSize;

		long *buffer;
		long *buffer0;
		long *buffer1;
		long *buffer2;

		struct timeval beginTime, endTime;

		usage(argc,argv);

		maxSize = atoi(argv[1])/NUMBER_GROUP_LENGTH + 1;
		which = atoi(argv[2]);

		gettimeofday(&beginTime, NULL);
		initBuffer( &buffer0, &buffer1, &buffer2, maxSize);

		buffer = fibonacci( which, buffer0, buffer1, buffer2, maxSize, &resultLen );
		gettimeofday(&endTime, NULL);

		displayBuffer(buffer, resultLen);

		freeBuffer( &buffer0, &buffer1, &buffer2 );

		printf("maxSize = %d, resultLen=%d, deltaTime=%ld(微秒).\n", maxSize, resultLen, endTime.tv_usec - beginTime.tv_usec);

		return 0;
}

void usage(int argc, char *argv[])
{
		if ( argc < 3 )
		{
				displayUsage( argv[0]);
				exit(-1);
		}

		if ( atoi(argv[1]) < 1 ) displayUsage( argv[0]);
}

void displayUsage( char *programName )
{
		printf( "Usage: %s [numberMaxLength] [max]\n", programName );
		printf( "\t[numberMaxLength] and [max] must be larger than 2.\n" );
}

void initBuffer( long **buffer0, long **buffer1, long **buffer2, unsigned maxSize)
{
		unsigned int bufferSize = sizeof(long) * maxSize;

		*buffer0 = (long *) malloc( bufferSize );
		*buffer1 = (long *) malloc( bufferSize );
		*buffer2 = (long *) malloc( bufferSize );

		memset( *buffer0, 0, bufferSize );
		memset( *buffer1, 0, bufferSize );
		memset( *buffer2, 0, bufferSize );

		**buffer1 = 1l;
		**buffer2 = 1l;

		if ( *buffer0 == NULL || *buffer1 == NULL || *buffer2 == NULL )
		{
				printf("initBuffer: Out of memory! bufferSize=%d, buffer0=%p, buffer1=%p, buffer2=%p.\n", bufferSize, *buffer0, *buffer1, *buffer2);
				exit(-2);
		}
}

void freeBuffer( long **buffer0, long **buffer1, long **buffer2 )
{
		free(*buffer0);
		free(*buffer1);
		free(*buffer2);
}

long *fibonacci( unsigned which, long *buffer0, long *buffer1, long *buffer2, unsigned int bufferSize, int *pResultLen )
{
		int i, j=0, mode, resultLen=1;

		for ( i = 3; i <=which; ++i )
		{
				mode = (j++) % 3;
				switch(mode)
				{
						case  0:
								resultLen = addBuffer( buffer1, buffer2, buffer0, resultLen, bufferSize );
								break;
						case  1:
								resultLen = addBuffer( buffer2, buffer0, buffer1, resultLen, bufferSize );
								break;
						default:
								resultLen = addBuffer( buffer0, buffer1, buffer2, resultLen, bufferSize );
				}
		}

		*pResultLen = resultLen;

		switch(mode)
		{
				case  0: return buffer0;
				case  1: return buffer1;
				default: return buffer2;
		}
}

// MaxLong: 922,3372,0368,5377,5807
// buffer = buffer1 + buffer2
int addBuffer( long *buffer1, long *buffer2, long *buffer, unsigned int resultLen, unsigned int bufferSize  )
{
		long result;

		int index, carryCount = 0;
		unsigned int len;

		len = resultLen;
		for ( index = 0; index < len; ++index )
		{
				result = *(buffer1+index) + *(buffer2+index) + carryCount;
				*(buffer+index) = result % RADIX;
				carryCount = result / RADIX;
		}

		if ( carryCount > 0 )
		{
				if ( ++len < bufferSize )
				{
						*(buffer+len-1) = carryCount;
				}
				else
				{
						printf(" result len > bufferSize!!!\n");
						exit(-3);
				}
		}

		return len;
}

void displayBuffer( long *buffer, int resultLen )
{
		int i;

		for ( i = resultLen - 1; i >= 0; --i )
		{
				printf("%018ld", buffer[i]);
		}	

		printf("\n");
		return;
}

