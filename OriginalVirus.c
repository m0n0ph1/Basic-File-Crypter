#include <Windows.h>

int main()
{	
	HANDLE WINAPI CreateThread(
	LPSECURITY_ATTRIBUTES  lpThreadAttributes,    
	SIZE_T dwStackSize,        
	LPTHREAD_START_ROUTINE lpStartAddress,    
	LPVOID                 lpParameter,
    DWORD                  dwCreationFlags,
	LPDWORD                lpThreadId){}

	char* title = "Virus....";
	char* message = "I am an Evil Virus!!!";

	MessageBox(NULL, message, title, MB_OK | MB_ICONEXCLAMATION );
	return 0;
}