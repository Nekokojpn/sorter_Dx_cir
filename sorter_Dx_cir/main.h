#pragma once
#include "DxLib.h"
#include <stdlib.h>
#include <random>
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include <thread>
#include <cassert>
#include <math.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")


#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024
#define ARR_LENGTH 512
#define ARR_MAXVALUE 700
#define RADIX 100
#define ARR_WIDTH (SCREEN_WIDTH / ARR_LENGTH)
#define R 512

typedef struct AS {
	int v;
	int r;
	int g;
	int b;
}ARRS;

int Display();
int Display_index_red_fromaccess();
int addToAccess(int arr_index);
int clearAccess();
int addToSuccess(int arr_index);
int clearSuccess();
void sort_destruct();
void shuffle();
void shuffle_Arr(ARRS* ary, int size);

void draw_accesses();
void add_arrac();
void add_comp();
void add_step();
void initialize_sort(int updframe);
void bubble_sort();

void quicksort(ARRS arr[], int left, int right);
void q_sort(ARRS numbers[], int left, int right);

void bitonicsort_call(ARRS a[], int N, int up);
void bitonicSort(ARRS a[], int low, int cnt, int dir);
void bitonicMerge(ARRS a[], int low, int cnt, int dir);
void compAndSwap(ARRS a[], int i, int j, int dir);

void merge_sort_call(ARRS arr[], int l, int r);
void mergeSort(ARRS arr[], int l, int r);
void merge(ARRS arr[], int start, int mid, int end);

void heapsort_call(ARRS arr[], int N);
static void downheap(ARRS arr[], int n);
static void upheap(ARRS arr[], int n);
void heapsort(ARRS arr[], int n_elems);
static inline void swap(ARRS arr[], int a, int b);