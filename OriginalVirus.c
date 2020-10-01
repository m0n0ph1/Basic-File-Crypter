#include <Windows.h>

int main() //we can use "void" also
{	

	char* title = "Virus....";
	char* message = "I am an Evil Virus!!!";

	MessageBox(NULL, message, title, MB_OK | MB_ICONEXCLAMATION );
	return 0;
}
