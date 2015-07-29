#include <Windows.h>

int main()
{	

	char* title = "Virus....";
	char* message = "I am an Evil Virus!!!";

	MessageBox(NULL, message, title, MB_OK | MB_ICONEXCLAMATION );
	return 0;
}