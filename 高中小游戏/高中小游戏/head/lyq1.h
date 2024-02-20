#include "stdlib.h"
int cheng(int a,int b)
{
	int sum=1,i;
	for(i=1;i<=b;i++)
	 sum*=a;
	return sum;
}
void hua()
{
	int a; 
	printf("\t\t\t中级占卜术——《获取生日之法》\n",1);
    printf("    该程序的算法是将你的出生日期算出来,请按照要求进行操作,谢谢配合");
    printf("%c。\n\t\t\t若想要打开计算器请按数字键 1\n",3);
    printf("\t        请输入你的年龄(即用2022减去你出生的那一年的值)\n\t\t\t\t    ");
}
void huaa()
{
	printf("\t\t\t中级占卜术——《获取生日之法》\n",1);
    printf("    该程序的算法是将你的出生日期算出来,请按照要求进行操作,谢谢配合");
    printf("%c。\n",3);
}
void hua1()
{
	printf("\t\t\t好的");
    printf("%c",3);
    printf("现在请看下面五组数据%c:\n\n",1);
}
int by(int month[])
{
	int i,x=0,sum=0;
	for(i=4;i>=0;i--)
    {
    	sum+=month[i]*cheng(2,x);
    	x++;
    }
    return sum;
}
void hua2(int y,int s,int s1)
{
	 int i;
	 printf("\n\t   我已知晓你的生日,若想查看你的生日信息,请输入数字666");
     printf("%c\n",1);
     loop:printf("\t\t\t\t       ");
     scanf("%d",&i);
     if(i==666)
     {
     printf("\n\t \t\t您的出生日期: %d年%d月%d日",y,s,s1);
     printf("\n\n\t    本程序到此执行结束,谢谢您的使用,欢迎下次再来！");
     printf("%c\a\a",1);
     }
      else 
     {
     	printf("\t\t\t 请输入数字666，谢谢配合！");
     	printf("%c\n",3);
     	goto loop;
     }
}

void lyq258b()
{
    int A[5][16]={16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,
    			  8,9,10,11,12,13,14,15,24,25,26,27,28,29,30,31,
    			  4,5,6,7,12,13,14,15,20,21,22,23,28,29,30,31,
    			  2,3,6,7,10,11,14,15,18,19,22,23,26,27,30,31,
    			  1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31};
    int c=1,yr,i,j,sum=0,sum1=0,num,month[5],day[5],*x=month,*y=day,m=0,yy;
    y:
    system("cls");
    hua();
    scanf("%d",&yy);
    if(yy==1) 
	{	 
	 system("calc.exe");
	 goto y; 
	}
    else 
	{
	 yr=2022-yy; 
	}	
    hua1();
    for(i=0;i<5;i++)
    {   system("cls");
    	huaa();
    	//hua1();  	
    	printf("若下面数字中若出现你的月份数,请输入1,若没有出现,请输入0。\n    第%d组\n",c++);
    		for(j=1;j<17;j++)
    	{
    	
    		printf("%3d",A[i][j-1]);
    		if(j%4==0&&j!=0)printf("\n");
    		
    	}
    	printf("\n");
    	scanf("%d",&num);
    	month[m++]=num;
    }
    
    c=1,m=0;
    for(i=0;i<5;i++)
   	 	{   system("cls");
   	 		huaa();
   	 		printf("\n\t\t\t  注意，请看下面数字:\n");  	
   	 		printf("\n若下面数字中若出现你的日份数,请输入1,若没有出现,请输入0。\n    第%d组\n",c++);
    		for(j=1;j<17;j++)
    		{
    			printf("%3d",A[i][j-1]);
    			if(j%4==0&&j!=0)printf("\n");
    		}
    		printf("\n");
    		scanf("%d",&num);
    		day[m++]=num;
   		}	
  	    sum=by(x);
    	sum1=by(y);
   		hua2(yr,sum,sum1);
}
