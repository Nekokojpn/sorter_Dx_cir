#include "main.h"

int updateframeq;
int qc = 0;
void q_sort(ARRS numbers[], int left, int right)
{
	int l_hold, r_hold;
	ARRS pivot;
	l_hold = left;
	r_hold = right;
	pivot = numbers[left];
	addToAccess(left);
	if (qc == updateframeq)
	{
		Display_index_red_fromaccess();
		qc = 0;
	}
	qc++;
	while (left < right)
	{
		add_arrac();
		add_comp();

		while ((numbers[right].v >= pivot.v) && (left < right))
		{
			addToAccess(right);
			if (qc == updateframeq)
			{
				Display_index_red_fromaccess();
				qc = 0;
			}
			qc++;
			right--;
		}
		if (qc == updateframeq)
		{
			Display_index_red_fromaccess();
			qc = 0;
		}
		qc++;
		if (left != right)
		{
			add_arrac();
			add_arrac();
			addToAccess(left);
			addToAccess(right);
			numbers[left] = numbers[right];
			left++;
		}
		if (qc == updateframeq)
		{
			Display_index_red_fromaccess();
			qc = 0;
		}
		qc++;
		add_arrac();
		add_comp();
		addToAccess(left);
		while ((numbers[left].v <= pivot.v) && (left < right))
		{
			addToAccess(left);
			if (qc == updateframeq)
			{
				Display_index_red_fromaccess();
				qc = 0;
			}
			qc++;
			left++;
		}
		if (left != right)
		{
			add_arrac();
			add_arrac();
			numbers[right] = numbers[left];
			right--;
		}
		if (qc == updateframeq)
		{
			Display_index_red_fromaccess();
			qc = 0;
		}
		qc++;
	}
	add_arrac();
	numbers[left] = pivot;
	pivot.v = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot.v)
		q_sort(numbers, left, pivot.v - 1);
	if (right > pivot.v)
		q_sort(numbers, pivot.v + 1, right);
}
void quicksort(ARRS arr[], int left, int right)
{
	initialize_sort(5);
	updateframeq = 5;
	q_sort(arr, left, right);
	Display();
	sort_destruct();
}