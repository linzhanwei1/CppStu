#include <stdio.h>
#include <string.h>


char* strcpy(char* buf, const char* str, size_t n) {
	return strncpy(buf, str, n);
}
int main(int argc, char* argv[]) {
	const char* s = "D.T.Software";
	char buf[16] = { 0 };

	strcpy(buf, s, sizeof(buf)-1);
	printf("%s\n", buf);

	return 0;
}