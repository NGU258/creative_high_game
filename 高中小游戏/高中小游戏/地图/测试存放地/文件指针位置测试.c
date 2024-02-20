#include "stdio.h"
int main()
{
	FILE *fp;
	char a;
	if(!(fp=fopen("1.txt","r")))
		    {
		    	system("cls");
		    	printf("地图2导入错误，请注意文件路径是否正确");
		    	exit(1);
		    }
	fseek(fp,2L,0);
	printf("%d\n",ftell(fp));
	printf("%c\n",fgetc(fp));
	printf("%d\n",ftell(fp));
	fseek(fp,2L,1);
	printf("%d\n",ftell(fp));
	printf("%c",fgetc(fp));
	fclose(fp);
	return 666;
}
