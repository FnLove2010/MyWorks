#include <stdio.h>

typedef void(__stdcall * APE_PROGRESS_CALLBACK) (int);

void Verify(int n, APE_PROGRESS_CALLBACK ProgressCallback)
{
	if (!ProgressCallback)
		return;
	for (int i = 0; i < n;++i)
	{
		ProgressCallback(i);
	}
}

void __stdcall  call(int n)
{
	printf("%d ", n);
}
#define DLLEXPORT

DLLEXPORT void  __stdcall  call2(int n)
{
	printf("%d ", n);
}

int main(int argc, char** argv)
{
	Verify(5, (APE_PROGRESS_CALLBACK)call);
	Verify(6, (APE_PROGRESS_CALLBACK)call2);
	getchar();
	return 0;
}