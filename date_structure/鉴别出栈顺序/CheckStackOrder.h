#ifndef __CheckStack_h_
#define __CheckStack_h_

#include"Stack.h"

int CheckStackOrser(int* in,int insize,int* out,int outsize);

#endif

int CheckStackOrder(int* in, int insize, int* out, int outsize)
{
	assert(in && out);
	Stack st;
	InitStack(&st);
	int i, j = 0;
	for (i = 0; i < insize; i++)
	{
		if (in[i] != out[j])
		{
			PushbackStack(&st, in[i]);
			continue;
		}
		j++;
	}
	for (i = j; i < 5; i++)
	{
		if (out[i] == StackTop(&st))
			PopbackStack(&st);
		else return 0;
	}

	return 1;
}