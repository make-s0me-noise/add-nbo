#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc,char* argv[])
{
	FILE* p = fopen(argv[1],"r");
	char buf[4];

	fread(buf,sizeof(char),4,p);
	uint32_t *t = (uint32_t*)buf;
	uint32_t a1 = htonl(*t);
	pclose(p);

	FILE* f = fopen(argv[2],"r");
	char buf2[4];

	fread(buf2,sizeof(char),4,f);
	uint32_t *t2 = (uint32_t*)buf2;
	uint32_t a2 = htonl(*t2);
	pclose(p);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",a1,a1,a2,a2,a1+a2,a1+a2);
	
	return 0;
}