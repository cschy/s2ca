#include <Windows.h>
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"wmainCRTStartup\"")

int wmain(int argc, wchar_t* argv[])
{
	wchar_t* arg = argv[1];
	if (arg == NULL) {
		return;
	}
	const size_t size = (wcslen(arg) + 1) * 5 * sizeof(wchar_t);

	if (OpenClipboard(NULL))
	{
		EmptyClipboard();
		HGLOBAL buffer = GlobalAlloc(GMEM_FIXED, size);
		wchar_t* p = (wchar_t*)GlobalLock(buffer);
		*p++ = L'{';
		while(*arg) {
			*p++ = L'L'; 
			*p++ = L'\'';
			*p++ = *arg;
			*p++ = L'\'';
			*p++ = L',';
			arg++;
		}
		*p++ = L'0';
		*p++ = L'}';
		*p = 0;
		GlobalUnlock(buffer);
		SetClipboardData(CF_UNICODETEXT, buffer);
		CloseClipboard();
	}

	keybd_event(0x11, 0, 0, 0);//press ctrl
	keybd_event(0x56, 0, 0, 0);//press v
	keybd_event(0x56, 0, 2, 0);//release v
	keybd_event(0x11, 0, 2, 0);//release ctrl
	
	return 0;
}