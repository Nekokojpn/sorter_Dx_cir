#include "DxLib.h"
#include "main.h"

ARRS ARR[ARR_LENGTH];
static int comparison;
static int arrayaccess;
static int step;
char buf[100];
int access[ARR_LENGTH]; //アクセスした番号を格納しておきます
int success[ARR_LENGTH];//ソート済みの番号を格納しておきます
int ac = 0;//アクセスのスタックカウンタ
int sc = 0;
int updateframe;
int c = 0;

bool dis = false;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	ChangeWindowMode(TRUE);
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 16, 60);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetAlwaysRunFlag(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
	
	shuffle();
	WaitTimer(1000);
	bubble_sort();
	WaitTimer(1000);
	
	shuffle();
	WaitTimer(1000);
	quicksort(ARR, 0, ARR_LENGTH);
	WaitTimer(1000);
	
	
	shuffle();
	WaitTimer(1000);
	merge_sort_call(ARR, 0, ARR_LENGTH);
	WaitTimer(1000);

	shuffle();
	WaitTimer(1000);
	bitonicsort_call(ARR, ARR_LENGTH, 1);
	WaitTimer(1000);

	shuffle();
	WaitTimer(1000);
	heapsort_call(ARR, ARR_LENGTH);
	WaitTimer(1000);
	
	draw_accesses();
	ScreenFlip();
	WaitKey();
	DxLib_End();
	return 0;
}

void bubble_sort()
{
	initialize_sort(150);
	int i, j;
	ARRS temp;
	for (i = 0; i < ARR_LENGTH - 1; i++)
	{
		for (j = ARR_LENGTH - 1; j > i; j--)
		{
			add_step();
			addToAccess(j);
			add_comp();
			add_arrac();
			add_arrac();
			if (ARR[j - 1].v > ARR[j].v)
			{
				temp = ARR[j - 1];
				ARR[j - 1] = ARR[j];
				ARR[j] = temp;
			}
			if (c == updateframe)//更新フレーム間
			{
				Display_index_red_fromaccess();
				c = 0;
			}
			c++;
		}
		addToSuccess(i);
	}
	Display();
	clearAccess();
	clearSuccess();
}
void add_step()
{
	step++;
}
void add_comp()
{
	comparison++;
}
void add_arrac()
{
	arrayaccess++;
}
int Display()
{
	ClearDrawScreen();
	draw_accesses();
	for (int i = 0; i < ARR_LENGTH; i++)
	{
		DrawCircle(R, R, R - i, GetColor(ARR[i].r,ARR[i].g,ARR[i].b), 0, 1);
	}
	ScreenFlip();
	return 0;
}
int Display_index_red_fromaccess()
{
	ClearDrawScreen();
	
	for (int i = 0; i < ARR_LENGTH; i++)
	{
		DrawCircle(R, R, R - i, GetColor(ARR[i].r, ARR[i].g, ARR[i].b), 0, 1);
		for (int j = 0; j < ARR_LENGTH; j++)
		{
			if (access[j] == i)
			{
				DrawCircle(R, R, R - i, GetColor(0,0,0), 0, 1);
				break;
			}
		}

	}
	draw_accesses();
	clearAccess();
	ScreenFlip();
	return 0;
}
void draw_accesses()
{
	DrawFormatString(0, 0, GetColor(255, 255, 0), "Array accesses: %d Comparisons: %d Update frame: %d %d", arrayaccess, comparison, updateframe, ARR[0]);
}
int addToAccess(int arr_index)
{
	access[ac] = arr_index;
	ac++;
	return 0;
}
int clearAccess()
{
	ac = 0;
	for (int i = 0; i < ARR_LENGTH; i++)
	{
		access[i] = -1;
	}
	return 0;
}
int addToSuccess(int arr_index)
{
	success[sc] = arr_index;
	sc++;
	return 0;
}
int clearSuccess()
{
	sc = 0;
	for (int i = 0; i < ARR_LENGTH; i++)
	{
		success[i] = -1;
	}
	return 0;
}
void initialize_sort(int updframe)
{
	updateframe = updframe;
	comparison = 0;
	arrayaccess = 0;
	step = 0;
	clearAccess();
	clearSuccess();
}
void shuffle()
{
	initialize_sort(0);
	int r, g, b,count=0;
	r = 255;
	g = 120;
	b = 0;
	for (int i = 0; i < ARR_LENGTH; i++)
	{
		addToAccess(i);
		ARR[i].v = (i + 1); 
		
		if (count==0)
		{
			ARR[i].r = r;
			ARR[i].g = g+=3;
			ARR[i].b = b;
			if (g == 255)
			{
				count++;
			}
		}
		else if (count == 1)
		{
			ARR[i].r = r-=3;
			ARR[i].g = g;
			ARR[i].b = b;
			if (r == 0)
				count++;
		}
		else if (count == 2)
		{
			ARR[i].r = r;
			ARR[i].g = g;
			ARR[i].b = b += 3;
			if (b == 255)
				count++;
		}
		else if (count == 3)
		{
			ARR[i].r = r;
			ARR[i].g = g-=3;
			ARR[i].b = b;
			if (g == 0)
				count++;
		}
		else if (count == 4)
		{
			ARR[i].r = r+=3;
			ARR[i].g = g;
			ARR[i].b = b;
			if (r == 255)
				count++;
		}
		else if (count == 5)
		{
			ARR[i].r = r;
			ARR[i].g = g;
			ARR[i].b = b-=3;
			if (b == 0)
				count++;
		}
		else
		{
			ARR[i].r = r;
			ARR[i].g = g += 3;
			ARR[i].b = b += 3;
			if (g == 255)
				count++;
		}
		if (c == 2)
		{
			Display_index_red_fromaccess();
			c = 0;
		}
		c++;
	}
	shuffle_Arr(ARR, ARR_LENGTH);
	Display();
}
void sort_destruct()
{
	clearAccess();
	clearSuccess();
}
void shuffle_Arr(ARRS* ary, int size)
{
	c = 0;
	WaitTimer(1000);
	for (int i = 0; i < size; i++)
	{
		ARRS temp;
		int j = rand() % size;
		temp = ary[i];
		ary[i] = ary[j];
		ary[j] = temp;
		addToAccess(i);
		addToAccess(j);
		if (c == 2)
		{
			Display_index_red_fromaccess();
			c = 0;
		}
		c++;
	}
}
