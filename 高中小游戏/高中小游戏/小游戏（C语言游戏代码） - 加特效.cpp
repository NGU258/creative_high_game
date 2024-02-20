/*										           C语言小游戏代码  		    		                 */
#pragma warning(disable:4996)
#include "time.h"
#include<string.h>
#include "stdio.h"//例如我的生日是2004年12月19日
#include "conio.h"//下面的exit函数 
#include "head/system1.h"//导入光伏系统 
#include "head/lyq1.h"//导入猜生日程序 
#include "windows.h"//导入Sleep()函数 
#include "stdlib.h"//导入system()函数 
#define pr printf("恭喜进入探索迷宫，请按任意键进入：\n")
#define NUM 17//控制行数的循环
#define NUM1 17//控制列数的循环
#define LYQ FILE//个人喜好 
#define RW	'6'//控制人物角色
#define RW1 '8'//控制人物角色
#define S system1();//导入system1.h里面的system1()函数。 
#define Visit(a) Sleep(a)//调整速度 数字越大，运行速度越慢 
#define LIFE1 3//英雄人物1的生命值 
#define LIFE2 3//英雄人物2的生命值 
int djs = 0, life1 = LIFE1, life2 = LIFE2, map_end = 0, map2 = 0, cf = 1, x, y, x11, y11, if1 = 0, if2 = 0, v = 0, life_sign1 = 1, life_sign2 = 1;//控制刚开始时的倒计时及生命值、地图线束标志，进入下一地图的标志等 
char c[NUM][NUM1], o, t;//全局二维数组
int move_yz(int* m, int* n, int* m1, int* n1)//先向右移与向左移
{
	static int a = 1, b = 1; //用该两个变量控制*的左右循环 
	if (c[*m][*n + 1] != '#' && a)//第一个*一直往右移 
	{
		if (c[*m][*n + 1] == RW)//判断*的下右边是否是角色1
		{
			if (life1)life1 -= 1; if1 = 1;//当怪兽*碰到该角色时life1即生命值减1，如果到0就不减了，if1为*撞到第一个角色时的标志，为下面的判断作前提 
		}
		if (c[*m][*n + 1] == RW1)//判断*的下右边是否是角色2
		{
			if (life2)life2 -= 1; if2 = 1;//当怪兽*碰到该角色时life2即生命值减1，如果到0就不减了，if2为*撞到第二个角色时的标志，为下面的判断作前提 
		}
		if (life1 > 0 && if1)//当角色1还有生命移与对应位置交换 
		{
			if (map2 == 1) //如果map2的值是2，说明已经进入到第二个地图了 ，将角色1进行相应的位置变换 
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else//如果map2的值不是2，说明还是第一个地图， 将角色1进行相应的位置变换 
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			if1 = 0;//让if1的值为0，到了下次循环来的时候就不会执行这了，只有当*的右边是角色1时才会进入到这来。 
			putchar('\a');//撞到该角色响一下，效果好点。 
		}
		if (life2 > 0 && if2)//当角色2还有生命移到对应位置
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			if2 = 0;//让if2的值为0，到了下次物质循环来的时候就不会执行这了，只有当*的右边是角色2时才会进入到这来。
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)//当角色1的生命值为0时代表死亡，life_sign1是为了让这一条if语句只执行一次，不让后面这种类型的If继续执行。 
		{
			if (c[1][1] == RW1)//如果c[1][1]的位置是角色2，就不能让它与角色2交换，让角色2与c[1][2]交换位置向右移一位后再让角色1与c[1][1]交换位置 
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;//执行完让这个if语句在整个函数中只能执行一次 
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)//当角色2的生命值为0时代表死亡，life_sign2是为了让这一条if语句只执行一次，不让后面这种类型的If继续执行。 
		{
			if (c[15][15] == RW)//如果c[15][15]的位置是角色1，就不能让它与角色1交换，让角色1与c[15][15]交换位置向右移一位后再让角色2与c[15][15]交换位置 
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m][*n + 1];//*的位置向右移动 
		c[*m][*n + 1] = c[*m][*n];
		c[*m][*n] = t;
		*n += 1;
	}
	else //第一个*一直往左移 
	{
		if (c[*m][*n - 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m][*n - 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置	
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//下面的语句作用与上面的类似，我就不一一说明了 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m][*n - 1];
		c[*m][*n - 1] = c[*m][*n];
		c[*m][*n] = t;
		*n -= 1;
	}

	if (c[*m1][*n1 - 1] != '#' && b)//第二个*一直往左移
	{
		if (c[*m1][*n1 - 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m1][*n1 - 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[11][13];
				c[11][13] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m1][*n1 - 1];
		c[*m1][*n1 - 1] = c[*m1][*n1];
		c[*m1][*n1] = t;
		*n1 -= 1;
	}
	else //第二个*一直往右移
	{
		if (c[*m1][*n1 + 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m1][*n1 + 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置	
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[11][13];
				c[11][13] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			if2 = 0;
			life_sign2 = 0;
		}
		t = c[*m1][*n1 + 1];
		c[*m1][*n1 + 1] = c[*m1][*n1];
		c[*m1][*n1] = t;
		*n1 += 1;//此语句若改为*n1++;就出错了 
	}
	if (c[*m][*n + 1] == '#')a = 0;
	if (c[*m][*n - 1] == '#')a = 1;
	if (c[*m1][*n1 + 1] == '#')b = 1;
	if (c[*m1][*n1 - 1] == '#')b = 0;
	return 0;
}
int move_yz1(int* m, int* n, int* m1, int* n1)//先向右移与向左移，这个是为了后面的地图2的* 的左右移动 
{
	static int a = 1, b = 1;
	if (c[*m][*n + 1] != '#' && a)//第一个*一直往右移 
	{
		if (c[*m][*n + 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m][*n + 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m][*n + 1];
		c[*m][*n + 1] = c[*m][*n];
		c[*m][*n] = t;
		*n += 1;
	}
	else//第一个*一直往左移 
	{
		if (c[*m][*n - 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m][*n - 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m][*n - 1];
		c[*m][*n - 1] = c[*m][*n];
		c[*m][*n] = t;
		*n -= 1;
	}

	if (c[*m1][*n1 - 1] != '#' && b)//第二个*一直往左移
	{
		if (c[*m1][*n1 - 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m1][*n1 - 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[11][13];
				c[11][13] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m1][*n1 - 1];
		c[*m1][*n1 - 1] = c[*m1][*n1];
		c[*m1][*n1] = t;
		*n1 -= 1;
	}
	else//第二个*一直往右移
	{
		if (c[*m1][*n1 + 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m1][*n1 + 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置	
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[11][13];
				c[11][13] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
		}
		t = c[*m1][*n1 + 1];
		c[*m1][*n1 + 1] = c[*m1][*n1];
		c[*m1][*n1] = t;
		*n1 += 1;
	}
	if (c[*m][*n + 1] == '#')a = 0;
	if (c[*m][*n - 1] == '#')a = 1;
	if (c[*m1][*n1 + 1] == '#')b = 1;
	if (c[*m1][*n1 - 1] == '#')b = 0;
	return 0;
}
int move_yz2(int* m, int* n, int* m1, int* n1)//先向右移与向左移，这个是为了后面的地图2的* 的左右移动 
{
	static int a = 1, b = 1;
	if (c[*m][*n + 1] != '#' && a)//第一个*一直往右移 
	{
		if (c[*m][*n + 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m][*n + 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m][*n + 1];
		c[*m][*n + 1] = c[*m][*n];
		c[*m][*n] = t;
		*n += 1;
	}
	else//第一个*一直往左移 
	{
		if (c[*m][*n - 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m][*n - 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m][*n - 1];
		c[*m][*n - 1] = c[*m][*n];
		c[*m][*n] = t;
		*n -= 1;
	}

	if (c[*m1][*n1 - 1] != '#' && b)//第二个*一直往左移
	{
		if (c[*m1][*n1 - 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m1][*n1 - 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[11][13];
				c[11][13] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m1][*n1 - 1];
		c[*m1][*n1 - 1] = c[*m1][*n1];
		c[*m1][*n1] = t;
		*n1 -= 1;
	}
	else//第二个*一直往右移
	{
		if (c[*m1][*n1 + 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m1][*n1 + 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置	
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[11][13];
				c[11][13] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
		}
		t = c[*m1][*n1 + 1];
		c[*m1][*n1 + 1] = c[*m1][*n1];
		c[*m1][*n1] = t;
		*n1 += 1;
	}
	if (c[*m][*n + 1] == '#')a = 0;
	if (c[*m][*n - 1] == '#')a = 1;
	if (c[*m1][*n1 + 1] == '#')b = 1;
	if (c[*m1][*n1 - 1] == '#')b = 0;
	return 0;
}
int move_yz3(int* m, int* n, int* m1, int* n1)//先向右移与向左移，这个是为了后面的地图2的* 的左右移动 
{
	static int a = 1, b = 1;
	if (c[*m][*n + 1] != '#' && a)//第一个*一直往右移 
	{
		if (c[*m][*n + 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m][*n + 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m][*n + 1];
		c[*m][*n + 1] = c[*m][*n];
		c[*m][*n] = t;
		*n += 1;
	}
	else//第一个*一直往左移 
	{
		if (c[*m][*n - 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m][*n - 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m][*n - 1];
		c[*m][*n - 1] = c[*m][*n];
		c[*m][*n] = t;
		*n -= 1;
	}

	if (c[*m1][*n1 - 1] != '#' && b)//第二个*一直往左移
	{
		if (c[*m1][*n1 - 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m1][*n1 - 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[11][13];
				c[11][13] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m1][*n1 - 1];
		c[*m1][*n1 - 1] = c[*m1][*n1];
		c[*m1][*n1] = t;
		*n1 -= 1;
	}
	else//第二个*一直往右移
	{
		if (c[*m1][*n1 + 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m1][*n1 + 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置	
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[11][13];
				c[11][13] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
		}
		t = c[*m1][*n1 + 1];
		c[*m1][*n1 + 1] = c[*m1][*n1];
		c[*m1][*n1] = t;
		*n1 += 1;
	}
	if (c[*m][*n + 1] == '#')a = 0;
	if (c[*m][*n - 1] == '#')a = 1;
	if (c[*m1][*n1 + 1] == '#')b = 1;
	if (c[*m1][*n1 - 1] == '#')b = 0;
	return 0;
}
int move_sx(int* mm, int* nn, int* mm1, int* nn1)//先向上移与向下移
{
	static int a1 = 1, b1 = 1;
	if (c[*mm - 1][*nn] != '#' && a1)//第一个*一直向上移
	{
		if (c[*mm - 1][*nn] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*mm - 1][*nn] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置	 
		{
			if (x < 8)//左上角位置 
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[12][3];
				c[12][3] = t;
			}
			if1 = 0;
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置 
		{
			if (x11 < 8)//左上角位置 
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[12][3];
				c[12][3] = t;
			}
			if2 = 0;
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
		}
		t = c[*mm - 1][*nn];
		c[*mm - 1][*nn] = c[*mm][*nn];
		c[*mm][*nn] = t;
		*mm -= 1;
	}
	else //第一个*一直向下移
	{
		if (c[*mm + 1][*nn] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*mm + 1][*nn] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置 
		{
			if (x < 8)//左上角位置 
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[12][3];
				c[12][3] = t;
			}
			if1 = 0;
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置 
		{
			if (x11 < 8)//左上角位置 
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[12][3];
				c[12][3] = t;
			}
			if2 = 0;
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
		}
		t = c[*mm + 1][*nn];
		c[*mm + 1][*nn] = c[*mm][*nn];
		c[*mm][*nn] = t;
		*mm += 1;
	}

	if (c[*mm1 + 1][*nn1] != '#' && b1)//第二个*一直向下移
	{
		if (c[*mm1 + 1][*nn1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*mm1 + 1][*nn1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置	4 13 12 3
		{
			if (x < 8)
			{
				t = c[x][y];
				c[x][y] = c[4][13];
				c[4][13] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置 
		{
			if (x11 < 8)//左上角位置 
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[12][3];
				c[12][3] = t;
			}
			if2 = 0;
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
		}
		t = c[*mm1 + 1][*nn1];
		c[*mm1 + 1][*nn1] = c[*mm1][*nn1];
		c[*mm1][*nn1] = t;
		*mm1 += 1;
	}
	else //第二个*一直向上移
	{
		if (c[*mm1 - 1][*nn1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*mm1 - 1][*nn1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//当还有生命移到对应位置	4 13 12 3
		{
			if (x < 8)
			{
				t = c[x][y];
				c[x][y] = c[4][13];
				c[4][13] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
		}
		if (life2 > 0 && if2)//当还有生命移到对应位置	4 13 12 3
		{
			if (x11 < 8)//左上角位置 
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[12][3];
				c[12][3] = t;
			}
			if2 = 0;
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
		}
		t = c[*mm1 - 1][*nn1];
		c[*mm1 - 1][*nn1] = c[*mm1][*nn1];
		c[*mm1][*nn1] = t;
		*mm1 -= 1;
	}
	if (c[*mm - 1][*nn] == '#')a1 = 0;
	if (c[*mm + 1][*nn] == '#')a1 = 1;
	if (c[*mm1 - 1][*nn1] == '#')b1 = 1;
	if (c[*mm1 + 1][*nn1] == '#')b1 = 0;
	return 0;
}
int weiyi = 0, host = 0;
LYQ* fp;
int  LYQ1()
{
	char hh, Z, Zt, cei = 0, h;
	char name[2], fat[5], c1[20] = "convert ", f1[20] = "format ", c2[10] = ": /fs:";
	char bgc[10] = "color ", bgc_size[4], bgc_d[] = "  ..";
	int m[10], n[10], ja = 0, ja1 = 0, prize = 3, i, j, s = 0, Tgua_sign = 0, die1 = 0, die2 = 0;
	static int speed = 100;
	static int shu = 1, cei_s = 0, a;
	if (map2) a = 8;//用来控制给*存下标的数量 
	else 	 a = 4;
	if (cf--)//下次就不用再打开文件了 
	{
		if (map2)//如果map2的值为1说明要导入地图2了 
		{
			if (!(fp = fopen("地图\\map2.txt", "r")))
			{
				system("cls");
				printf("地图2导入错误，请注意文件路径是否正确");
				exit(1);
			}
			map_end = 1;
		}
		else if (!(fp = fopen("地图\\map1.txt", "r")))
		{
			system("cls");
			printf("地图1导入错误，请注意文件路径是否正确");
			exit(1);
		}
		for (i = 0; i < NUM; i++)
		{
			for (j = 0; j < NUM1; j++)
				c[i][j] = fgetc(fp);
			hh = fgetc(fp);//获取文本后面的换行字符 
		}
		fclose(fp);
	}
	while (1)
	{
		printf("\t     游戏规则(到达终点0即可获胜！)\n英雄角色 %c", RW);
		printf("(方向控制键：w a s d)\t生命值%c", 3);
		printf("：%d  当前位置：%2d %2d  ", life1, x, y);//第一个人物 

		printf("\n英雄角色 %c", RW1);
		printf("(方向控制键：i j k l)\t生命值%c", 3);
		printf("：%d  当前位置：%2d %2d  ", life2, x11, y11);

		printf("\n\n终点(0)\t 墙(#)\t宝藏入口(%%,$)\n吃人的小怪兽(*)\t传送阵(!)\n\n快捷键道具：\nR:复位\tp:暂停\tz或m:移形换位\tv:调整游戏难度\tq:重新游戏     y:查看源代码\nc:格式化U盘\tu返回登陆页面");
		printf("\tb:背景颜色\t\n\n");
		for (i = 0; i < NUM; i++)
		{
			printf("\t         ");
			for (j = 0; j < NUM1; j++)
			{
				printf("%c", c[i][j]);
				if (c[i][j] == RW)
				{
					x = i; y = j;//获取英雄角色RW的坐标x与y 即数组的行与列 
				}
				if (c[i][j] == RW1)
				{
					x11 = i; y11 = j;//获取英雄角色RW1的坐标x与y 即数组的行与列 
				}
				if (c[i][j] == '*' && a)
				{
					m[ja++] = i; n[ja1++] = j;//获取*怪兽的坐标x与y 即数组的行与列 
					a--;
				}
			}
			printf("\n");
		}
		if (die1)printf("(游戏人物%c已死亡,目前无法移动！)\n", RW);
		if (die2)printf("(游戏人物%c已死亡,目前无法移动！)\n", RW1);
		if (life1 == 0 && life2 == 0)
		{
			system("cls");
			printf("真遗憾,游戏闯关失败！\n若想要重新开始%c\n请按空格，否则按任意键结束:\n", 3);
			life1 = LIFE1, life2 = LIFE2;//重新游戏后的初始值 
			life_sign1 = life_sign2 = 1;
			if1 = if2 = 0;
			if (getch() != ' ') exit(0);
			else return 1;
		}
	vi:
		Visit(v);
		if (kbhit())//判断是否按了键盘，若按了返回1，否则返回0
		{
			Z = getch();
			if (life1)
			{
				switch (Z)
				{
				case 'W':
				case 'w':if (c[x - 1][y] == '*' || c[x - 1][y] == '#' || c[x - 1][y] == RW || c[x - 1][y] == RW1 || c[x - 1][y] == '%' || c[x - 1][y] == '$')
				{
					if (c[x - 1][y] == '%')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); lyq258b(); getch(); system("color a9"); break;
					}
					break;
				}
						if (c[x - 1][y] == '$')
						{
							system("cls"); system("color 0b"); pr; getch(); system("cls"); S getch(); system("color a9"); break;
						}
						if (c[x - 1][y] == '0')
						{
							s = 1; Tgua_sign = 1; break;
						}
						if (c[x - 1][y] == '!')
						{
							if (x == 1 || x == 2)
							{
								if (c[15][15] == RW1)
								{
									t = c[14][15]; c[14][15] = c[x][y]; c[x][y] = t; break;
								}
								t = c[15][15]; c[15][15] = c[x][y]; c[x][y] = t; break;
							}
							t = c[1][1]; c[1][1] = c[x][y]; c[x][y] = t; break;
						}
						t = c[x - 1][y]; c[x - 1][y] = c[x][y]; c[x][y] = t; break;
				case 'A':
				case 'a':if (c[x][y - 1] == '*' || c[x][y - 1] == '#' || c[x][y - 1] == RW || c[x][y - 1] == RW1 || c[x][y - 1] == '%' || c[x][y - 1] == '$')
				{
					if (c[x][y - 1] == '%')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); lyq258b(); getch(); system("color a9"); break;
					}
					if (c[x][y - 1] == '$')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); S getch(); system("color a9"); break;
					}
					break;
				}
						if (c[x][y - 1] == '0')
						{
							s = 1; Tgua_sign = 1; break;
						}
						if (c[x][y - 1] == '!')
						{
							if (x == 1 || x == 2)
							{
								if (c[15][15] == RW1)
								{
									t = c[14][15]; c[14][15] = c[x][y]; c[x][y] = t; break;
								}
								t = c[15][15]; c[15][15] = c[x][y]; c[x][y] = t; break;
							}
							t = c[1][1]; c[1][1] = c[x][y]; c[x][y] = t; break;
						}
						t = c[x][y - 1]; c[x][y - 1] = c[x][y]; c[x][y] = t; break;

				case 'S':
				case 's':if (c[x + 1][y] == '*' || c[x + 1][y] == '#' || c[x + 1][y] == RW || c[x + 1][y] == RW1 || c[x + 1][y] == '%' || c[x + 1][y] == '$')
				{
					if (c[x + 1][y] == '%')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); lyq258b(); getch(); system("color a9"); break;
					}
					if (c[x + 1][y] == '$')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); S getch(); system("color a9"); break;
					}
					break;
				}
						if (c[x + 1][y] == '0')
						{
							s = 1; Tgua_sign = 1; break;
						}
						if (c[x + 1][y] == '!')
						{
							if (x == 1 || x == 2)
							{
								if (c[15][15] == RW1)
								{
									t = c[14][15]; c[14][15] = c[x][y]; c[x][y] = t; break;
								}
								t = c[15][15]; c[15][15] = c[x][y]; c[x][y] = t; break;
							}
							t = c[1][1]; c[1][1] = c[x][y]; c[x][y] = t; break;
						}
						t = c[x + 1][y]; c[x + 1][y] = c[x][y]; c[x][y] = t; break;
				case 'D':
				case 'd':if (c[x][y + 1] == '*' || c[x][y + 1] == '#' || c[x][y + 1] == RW || c[x][y + 1] == RW1 || c[x][y + 1] == '%' || c[x][y + 1] == '$')
				{
					if (c[x][y + 1] == '%')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); lyq258b(); getch(); system("color a9"); break;
					}
					if (c[x][y + 1] == '$')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); S getch(); system("color a9"); break;
					}
					break;
				}
						if (c[x][y + 1] == '0')
						{
							s = 1; Tgua_sign = 1; break;
						}
						if (c[x][y + 1] == '!')
						{
							if (x == 1 || x == 2)
							{
								if (c[15][15] == RW1)
								{
									t = c[14][15]; c[14][15] = c[x][y]; c[x][y] = t; break;
								}
								t = c[15][15]; c[15][15] = c[x][y]; c[x][y] = t; break;
							}
							t = c[1][1]; c[1][1] = c[x][y]; c[x][y] = t; break;
						}
						t = c[x][y + 1]; c[x][y + 1] = c[x][y]; c[x][y] = t; break;
				}
			}
			else die1 = 1;//死亡标志 
			if (life2)
			{
				switch (Z)
				{
				case 'I':
				case '8':
				case 'i':if (c[x11 - 1][y11] == '*' || c[x11 - 1][y11] == '#' || c[x11 - 1][y11] == RW || c[x11 - 1][y11] == RW1 || c[x11 - 1][y11] == '%' || c[x11 - 1][y11] == '$')
				{
					if (c[x11 - 1][y11] == '%')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); lyq258b(); getch(); system("color a9"); break;
					}
					if (c[x11 - 1][y11] == '$')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); S getch(); system("color a9"); break;
					}
					break;
				}
						if (c[x11 - 1][y11] == '0')
						{
							s = 1; Tgua_sign = 2; break;
						}
						if (c[x11 - 1][y11] == '!')
						{
							if (x11 == 1 || x11 == 2)
							{
								if (c[15][15] == RW)
								{
									t = c[14][15]; c[14][15] = c[x11][y11]; c[x11][y11] = t; break;
								}
								t = c[15][15]; c[15][15] = c[x11][y11]; c[x11][y11] = t; break;
							}
							if (c[1][1] == RW)
							{
								t = c[1][2]; c[1][2] = c[x11][y11]; c[x11][y11] = t; break;
							}
							t = c[1][1]; c[1][1] = c[x11][y11]; c[x11][y11] = t; break;
						}
						t = c[x11 - 1][y11]; c[x11 - 1][y11] = c[x11][y11]; c[x11][y11] = t; break;

				case 'J':
				case '4':
				case 'j':if (c[x11][y11 - 1] == '*' || c[x11][y11 - 1] == '#' || c[x11][y11 - 1] == RW || c[x11][y11 - 1] == RW1 || c[x11][y11 - 1] == '%' || c[x11][y11 - 1] == '$')
				{
					if (c[x11][y11 - 1] == '%')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); lyq258b(); getch(); system("color a9"); break;
					}
					if (c[x11][y11 - 1] == '$')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); S getch(); system("color a9"); break;
					}
					break;
				}
						if (c[x11][y11 - 1] == '0')
						{
							s = 1; Tgua_sign = 2; break;
						}
						if (c[x11][y11 - 1] == '!')
						{
							if (x11 == 1 || x11 == 2)
							{
								if (c[15][15] == RW)
								{
									t = c[14][15]; c[14][15] = c[x11][y11]; c[x11][y11] = t; break;
								}
								t = c[15][15]; c[15][15] = c[x11][y11]; c[x11][y11] = t; break;
							}
							if (c[1][1] == RW)
							{
								t = c[1][2]; c[1][2] = c[x11][y11]; c[x11][y11] = t; break;
							}
							t = c[1][1]; c[1][1] = c[x11][y11]; c[x11][y11] = t; break; t = c[1][1]; c[1][1] = c[x11][y11]; c[x11][y11] = t; break;
						}
						t = c[x11][y11 - 1]; c[x11][y11 - 1] = c[x11][y11]; c[x11][y11] = t; break;
				case 'K':
				case '5':
				case 'k':if (c[x11 + 1][y11] == '*' || c[x11 + 1][y11] == '#' || c[x11 + 1][y11] == RW || c[x11 + 1][y11] == RW1 || c[x11 + 1][y11] == '%' || c[x11 + 1][y11] == '$')
				{
					if (c[x11 + 1][y11] == '%')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); lyq258b(); getch(); system("color a9"); break;
					}
					if (c[x11 + 1][y11] == '$')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); S getch(); system("color a9"); break;
					}
					break;
				}
						if (c[x11 + 1][y11] == '0')
						{
							s = 1; Tgua_sign = 2; break;
						}
						if (c[x11 + 1][y11] == '!')
						{
							if (x11 == 1 || x11 == 2)
							{
								if (c[15][15] == RW)
								{
									t = c[14][15]; c[14][15] = c[x11][y11]; c[x11][y11] = t; break;
								}
								t = c[15][15]; c[15][15] = c[x11][y11]; c[x11][y11] = t; break;
							}
							if (c[1][1] == RW)
							{
								t = c[1][2]; c[1][2] = c[x11][y11]; c[x11][y11] = t; break;
							}
							t = c[1][1]; c[1][1] = c[x11][y11]; c[x11][y11] = t; break; t = c[1][1]; c[1][1] = c[x11][y11]; c[x11][y11] = t; break;
						}
						t = c[x11 + 1][y11]; c[x11 + 1][y11] = c[x11][y11]; c[x11][y11] = t; break;
				case 'L':
				case '6':
				case 'l':if (c[x11][y11 + 1] == '*' || c[x11][y11 + 1] == '#' || c[x11][y11 + 1] == RW || c[x11][y11 + 1] == RW1 || c[x11][y11 + 1] == '%' || c[x11][y11 + 1] == '$')
				{
					if (c[x11][y11 + 1] == '%')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); lyq258b(); getch(); system("color a9"); break;
					}
					if (c[x11][y11 + 1] == '$')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); S getch(); system("color a9"); break;
					}
					break;
				}
						if (c[x11][y11 + 1] == '0')
						{
							s = 1; Tgua_sign = 2; break;
						}
						if (c[x11][y11 + 1] == '!')
						{
							if (x11 == 1 || x11 == 2)
							{
								if (c[15][15] == RW)
								{
									t = c[14][15]; c[14][15] = c[x11][y11]; c[x11][y11] = t; break;
								}
								t = c[15][15]; c[15][15] = c[x11][y11]; c[x11][y11] = t; break;
							}
							if (c[1][1] == RW)
							{
								t = c[1][2]; c[1][2] = c[x11][y11]; c[x11][y11] = t; break;
							}
							t = c[1][1]; c[1][1] = c[x11][y11]; c[x11][y11] = t; break; t = c[1][1]; c[1][1] = c[x11][y11]; c[x11][y11] = t; break;
						}
						t = c[x11][y11 + 1]; c[x11][y11 + 1] = c[x11][y11]; c[x11][y11] = t; break;
				}
			}
			else die2 = 1;
			switch (Z)
			{
			case 'R':
			case 'r':weiyi = 1; return 1; break;
			case 'M':
			case 'm':
			case 'Z':
			case 'z':t = c[x][y]; c[x][y] = c[x11][y11]; c[x11][y11] = t; break;
			case 'P':
			case 'p':while (1)
			{
				Zt = getch();
				if (Zt == 'p' || Zt == 'P')break;
				else printf("请按P键继续。\n");
			}
					break;
			case 'v':
			case 'V':
				system("cls");
				system("color 16");
				printf("请输入一个数（正整数），该数用来改变循环的速度（值越大，速度越慢,默认值：0）：   ");
				scanf("%d", &v);
				system("color a9");
				goto vi;
				break;
			case 'Q':
			case 'q':life_sign1 = life_sign2 = 1; life1 = LIFE1, life2 = LIFE2; x = y = 1; x11 = y11 = 15; if1 = if2 = 0; return 1;
			case 'y':
			case 'Y':
				system("cls");
				system("color 0a");
				srand(time(NULL));
				printf("中途暂停请按空格键,调整浏览速度请按数字键（数字越大速度越慢,按S可随机调整速度哦）%c：\n", 2);
				system("pause");
				system("cls");
				if (!(fp = fopen("小游戏（C语言游戏代码） - 加特效.c", "r")))
				{
					printf("该文件位置有误，请确定是否用Dev软件打开！\n");
					exit(0);
				}
				t = fgetc(fp);
				while (!feof(fp))//文件打开成功返回1，反之0 
				{
					if (t == '\n') Sleep(speed);
					if (kbhit())
					{
						switch (getch())
						{
						case '9':speed = 850; break;
						case '8':speed = 750; break;
						case '7':speed = 650; break;
						case '6':speed = 550; break;
						case '5':speed = 450; break;
						case '4':speed = 350; break;
						case '3':speed = 250; break;
						case '2':speed = 150; break;
						case '1':speed = 50; break;
						case '0':speed = 0; break;
						case 'S':
						case 's':speed = rand() % 1000; printf("\n当前速度：%d", speed); break;
						case ' ':getch(); break;
						default:break;
						}
					}
					putchar(t);
					t = fgetc(fp);
				}
				fclose(fp);
				printf("\n\a程序打开完毕！\n");
				getch();
				system("color a9");
				break;
			case 'c':
			case 'C':
			c:
				system("cls");
				system("color 0a");
				printf("请输入数字键进入相应的功能：\n");
				printf("输入数字（1）,功能：用format命令格式化U盘(该功能会把U盘内的内容删除,请注意备份)\n");
				printf("输入数字（2）,功能：用该convert命令格式化U盘(若你的U盘不是NTFS格式,使用该命令可以不会\t\t    删除你的U盘内容,直接变成ntfs格式)\n\n");
				printf("输入数字（3），功能：进入手动格式化U盘！\n");
				h = getch();
				if (h == '1')
				{
					system("cls");
					printf("请输入你要选择的盘符及要选择的文件系统,注意用空格隔开（例:c ntfs）：\n");
					scanf("%s%s", name, fat);
					strcat(f1, name);
					strcat(c2, fat);
					getch();
					strcat(f1, c2);
					printf("你已输入格式：");
					puts(f1);
					system(f1);
					f1[7] = c2[6] = '\0';
					getch();
					system("color a9");
				}
				else if (h == '2')
				{
					system("cls");
					printf("请输入你要选择的盘符及要选择的文件系统,注意用空格隔开（例:c ntfs）：\n");
					scanf("%s%s", name, fat);
					strcat(c1, name);
					strcat(c2, fat);
					strcat(c1, c2);
					printf("你已输入格式：");
					puts(c1);
					system(c1);
					c1[8] = c2[6] = '\0';
					getch();
					system("color a9");
				}
				else if (h == '3')
				{
					system("cls");
					system("diskpart");
				}
				else
				{
					system("cls");
					printf("你的输入有误，请重新输入！\n");
					goto c;
				}
				break;
			case 'b':
			case 'B':
				system("cls");
			qm:
				printf("请输入你的背景色(该值由两个十六进制的数组成)\n例：0A 0代表背景色,Ａ代表字体色，若想查看更多，请输入1\n");
				gets_s(bgc_size);
				if (bgc_size[0] == '1')
				{
					strcat(bgc, bgc_d);
					system(bgc);
					bgc[6] = '\0';//将bgc新获得的值去掉 
					getch();
					if (1) goto qm;
				}
				else
				{
					strcat(bgc, bgc_size);
					system(bgc);
					bgc[6] = '\0';//将bgc新获得的值去掉 
				}

				break;
			case 'U':
			case 'u':
				host = 1;
				return 1;
				break;
			}//switch endx
			if (s == 1)goto loop1;
		}//kbhit end
		if (map2 == 1)
		{
			if (move_yz(&m[1], &n[1], &m[0], &n[0]))  return 1;//把要移动的*地址传过去 
			if (move_yz1(&m[3], &n[3], &m[2], &n[2])) return 1;//防止第一次a,b的值不确定，用了多个一样的函数 
			if (move_yz2(&m[5], &n[5], &m[4], &n[4])) return 1;
			if (move_yz3(&m[7], &n[7], &m[6], &n[6])) return 1;
		}
		else
		{
			if (move_yz(&m[0], &n[0], &m[3], &n[3])) return 1;//把要移动的*地址传过去 
			if (move_sx(&m[2], &n[2], &m[1], &n[1])) return 1;//把要移动的*地址传过去
		}
		system("cls");
	}//while循环到此结束 
loop1:
	system("cls");
	printf("游戏通关成功\n\n");
	if (Tgua_sign == 1)
	{
		printf("恭喜我们的英雄  %c\t获胜!%c\n", RW, 1);
		printf("请按任意键领取奖品：\n");
		getch();
		while (prize)
		{
			system("cls");
			if (map2 == 1)
			{
				printf("最终奖品：奇异特效!\n奖品正在发送中 %d\a\n\n游戏小贴示：打开浏览器观赏完后记得把浏览器关闭再来本界面哦！\n\n在浏览器中按功能键(F11)可进入全屏可获得最佳效果呢。", prize, 14);
				Sleep(1000);
			}
			else
			{
				printf("奖品：星空粒子!\n奖品正在发送中 %d\a\n\n游戏小贴示：打开浏览器观赏完后记得把浏览器关闭再来本界面哦！\n\n在浏览器中按功能键(F11)可进入全屏可获得最佳效果呢。", prize, 14);
				Sleep(1000);
			}
			prize--;
		}
		if (map2 == 1)
		{
			system("网页文件\\奇异特效.html");
			system("cls");
			printf("领取完毕！\n");
			while (shu)
			{
				printf("请按任意键进入下一关。\n");
				getch();
				shu--;
				return 0;
			}
		}
		else
		{
			system("网页文件\\星空粒子.html");
			system("cls");
			printf("领取完毕！\n");
			while (shu)
			{
				printf("请按任意键进入下一关。\n");
				getch();
				shu--;
				return 0;
			}
		}
	}
	else if (Tgua_sign == 2)
	{
		printf("恭喜我们的英雄  %c\t获胜!%c \n", RW1, 1);
		printf("请按任意键领取奖品：\n");
		getch();
		while (prize)
		{
			system("cls");
			if (map2 == 1)
			{
				printf("最终奖品：奇异特效!\n奖品正在发送中 %d\a\n\n游戏小贴示：打开浏览器观赏完后记得把浏览器关闭再来本界面哦！\n在浏览器中按功能键(F11)可进入全屏可获得最佳效果呢。", prize, 14);
				Sleep(1000);
			}
			else
			{
				printf("奖品：代码雨!\n奖品正在发送中 %d\a\n\n游戏小贴示：打开浏览器观赏完后记得把浏览器关闭再来本界面哦！\n在浏览器中按功能键(F11)可进入全屏可获得最佳效果呢。", prize, 14);
				Sleep(1000);
			}
			prize--;
		}
		if (map2 == 1)
		{
			system("网页文件\\奇异特效.html");
			system("cls");
			printf("领取完毕！\n");
			while (shu)
			{
				printf("请按任意键进入下一关。\n");
				getch();
				shu--;
				return 0;
			}
		}
		else
		{
			system("网页文件\\代码雨.html");
			system("cls");
			printf("领取完毕！\n");
			while (shu)
			{
				printf("请按任意键进入下一关。\n");
				getch();
				shu--;
				return 0;
			}
		}
	}
	else printf("Game over！");
	system("pause");
	return 0;//返回0代表整个程序线束！ 
}
#define CD 20
struct user
{
	char name_zh[CD], name_pw[CD];
}stu, * p = &stu;
void C_game()
{
	int s = 1, a = 1, djs1 = 3, kg = 0, i = 0, j = 0, x = 0, y = 0, weiz = 0, m, across = 0, v = 0, s_r = 0;
	char name[50] = "title 游戏开始(玩家: 罗永庆)", ch, zhangH[CD], password[CD];
star:
	system("color 0C");
	system("Mode con cols=42 lines=6"); //控制窗口大小，注cols的最小值是16，不能低于该值 
	system("title C语言小游戏（258班）");//修改窗口的名称 
	printf("欢迎来到吾的游戏世界%c\n\n", 11);
	system("pause");
	system("cls");
	printf("游戏已开启\n\n不过请先登陆你的账号,否则无法进入游戏\n\n按数字键1进入登陆页面。\n");
log_on:
	if (getch() == '1')
	{
	host1:
	log_zh:
	fail:
	log:
		system("cls");
	qian:
		system("cls");
		system("Mode con cols=42 lines=9");
		printf("退出游戏请输入0\n\n");
		printf("新建账号请输入1\n\n");
		printf("登陆账号请输入2\n\n");
		if (s_r && ch != '0' && ch != '1' && ch != '2')	printf("\n输入有误，请重新输入！\n");
		ch = getch();
		if (ch == '1')//新建账号
		{
			system("cls");
			printf("请输入你的账号：\n");
			gets_s(stu.name_zh);
			printf("请输入你的密码：\n");
			gets_s(stu.name_pw);
			name[21] = '\0';
			strcat(name, stu.name_zh);
			strcat(name, ")");
			if (!(fp = fopen("地图\\user.txt", "r+")))
			{
				printf("文件打开失败，请注意是否用Dev软件打开!");
				exit(0);
			}
			ch = fgetc(fp);
			if (ch == EOF)//判断当前文档是否为空 如果为空走下面 
			{
				fputs("角色账号与密码: ", fp);
				fputs(stu.name_zh, fp);//从struct结构体里面取8个给fp指向的文件 
				fputc(' ', fp);//传空格给fp指向的文件做标志 
				fputs(stu.name_pw, fp);
				fputc('\n', fp);
				fclose(fp);
			}
			else
			{
				fseek(fp, -0L, 2);// 如果前文档是不是空 ，则指向指针指向末尾
				fputs("角色账号与密码: ", fp);
				fputs(stu.name_zh, fp);//从struct结构体里面取8个给fp指向的文件 
				fputc(' ', fp);//传空格给fp指向的文件做标志 
				fputs(stu.name_pw, fp);
				fputc('\n', fp);
				fclose(fp);
			}
			printf("\n您的用户已创建成功，\n请前往登陆用户登陆你的账户,谢谢合作%c。\n", 2);
			system("pause");
			s_r = 0;
			goto log_zh;
		}
		else if (ch == '2')//登陆账号 
		{
			system("cls");
			printf("请输入你的账号：\n");
			gets_s(zhangH);
			printf("请输入你的账号密码：\n");
			gets_s(password);
			if (!(fp = fopen("地图\\user.txt", "r+")))
			{
				printf("文件打开失败，请注意是否用Dev软件打开!");
				exit(0);
			}
			ch = fgetc(fp);
			if (ch == EOF)//说明文件为空，无账户登陆 
			{
				system("Mode con cols=50 lines=6");
				system("cls");
				printf("你还未创建用户，请创建后再来此登陆，谢谢合作！%c\n按任意键返回。", 2);
				getch();
				goto log;
			}
			while (!feof(fp))//当文件打开成功则结束循环 
			{
				if (ch == ' ')//遇到空格 
				{
					if (weiz == 0) x = ftell(fp);//记录第一个空格的位置 
					else y = ftell(fp);//记录第二个空格的位置 
					weiz++;
					if (y)
					{
						fseek(fp, x, 0);//让指针从文档开头移到前一个空格后的位置 
						for (i = 0; i < y - x - 1; i++)//记录账号 
							stu.name_zh[i] = fgetc(fp);
						stu.name_zh[i] = '\0';//让最后面的为结束符 
						i = 0;
						ch = fgetc(fp);//将后面的第二个空格接收 指针移向第二个空格后 
						while ((stu.name_pw[i] = fgetc(fp)) != '\n')i++;//记录密码 
						stu.name_pw[i] = '\0';//将获取的换行符去掉
						weiz = 0;
						y = 0;
						if (!strcmp(zhangH, stu.name_zh) && !strcmp(password, stu.name_pw))
						{
							across = 1;//账号符合的标志
							break;// 
						}
					}
				}
				ch = fgetc(fp);
			}
			fclose(fp);
			if (across) //判断是否已有账号符号登陆条件 
			{
				system("cls");
				printf("登陆成功，祝你游戏愉快！%c\n", 2);
				name[21] = '\0';
				strcat(name, stu.name_zh);
				strcat(name, ")");
				Sleep(900);
				system("color 0b");
			}
			else //否则就返回登录页面 
			{
				system("cls");
				printf("登陆失败！\n\n请注意你的账户密码是否输入正确\n或者还未创建此用户\n\n");
				system("pause");
				goto fail;
			}
			s_r = 0;
		}
		else if (ch == '0')
		{
			system("cls");
			printf("游戏结束，欢迎下次光临！\n");
			exit(0);
		}
		else
		{
			s_r = 1;
			goto qian;
		}
	}
	else
	{
		system("cls");
		printf("你还没有登陆你的账户，请输入1进入！\n");
		goto log_on;
	}
	while (1)
	{
		if (host == 1)
		{
			host = 0;
			goto host1;
		}
		if ((weiyi--) == 1)goto weiyi1;// 用来刷新 
		if (djs) system("title 小游戏已启动");
		while (djs)//倒计时 
		{
			system("cls");
			printf("游戏启动倒计时%c：\a", 12);
			printf("%d", djs--);
			Sleep(1000);//执行挂起一段时间,延迟一秒 ，单位是毫秒 ，注：sleep(小写)函数的单位是秒 
		}
		if (s--)
		{
			system("Mode con cols=36 lines=1");
			system("cls");
			printf("游戏开始!%c", 15);
			Sleep(1000);
			system(name);
			system("cls");
			printf("第一关：镜像旋转关！%c", 21);
			Sleep(1000);
		}
		system("color 0b");
	map2:
		system("Mode con cols=85 lines=30");
	weiyi1:
		if (!LYQ1())break;
	}
	while (djs1)
	{
		system("cls");
		printf("正在进入下一关%d %c\a", djs1, 1);
		map2 = 1;//加载地图2的标志 
		cf = 1;//加载文件的次数 
		Sleep(1000);
		djs1--;
	}
	if (map_end == 1) goto map2break;
	system("cls");
	printf("第二关：山海关！%c", 22);
	Sleep(1000);
	system("cls");
	djs1 = 0;
	goto map2;
map2break:
	system("cls");
	printf("游戏通关，Game over!%c\n欢迎下次光临！", 1);
}
int main()
{
	C_game();
	system("pause");
	return 666;
}