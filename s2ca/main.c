#include <stdio.h>
#include <locale.h>

int wmain(int argc, wchar_t* argv[])
{
	setlocale(LC_ALL, "chs");
	wchar_t *p = argv[1];
	if (p != NULL) {
		while (1) {
			wprintf_s(L"L'%c'", *p);
			if (*++p != 0) {
				printf(",");
			}
			else {
				break;
			}
		}
	}
	return 0;
}