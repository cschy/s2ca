#include <stdio.h>
#include <locale.h>

int wmain(int argc, wchar_t* argv[])
{
	setlocale(LC_ALL, "chs");
	wchar_t *p = argv[1];
	if (p != NULL) {
		printf("{");
		while (*p) {
			wprintf_s(L"L'%c',", *p++);
		}
		printf("0}");
	}
	return 0;
}