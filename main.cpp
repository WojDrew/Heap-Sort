
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define SIZE 100

void heapSort(int *vect, int n);
void bulidMaxHeap(int *vect, int n);
void maxHeapify(int *vect, int i, int n);
int parent(int i);
int left(int i);
int right(int i);

int main()
{
	srand(time(NULL));
	int vect[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		vect[i] = rand() % 100;
	}

	for (int i = 0; i < SIZE; i++)
		cout << vect[i] << " ";
	cout << endl << "--------------------" << endl;
	heapSort(vect, SIZE);
	for (int i = 0; i < SIZE; i++)
		cout << vect[i] << " ";

	return 0;
}

void heapSort(int *vect, int n)
{
	int heapLength = n;
	bulidMaxHeap(vect, n);
	for (int i = 0; i < n - 1; i++)
	{
		int temp = vect[0];
		vect[0] = vect[heapLength - 1];
		vect[heapLength - 1] = temp;
		heapLength--;
		maxHeapify(vect, 0, heapLength);
		
	}
}

void bulidMaxHeap(int *vect, int n)
{
	for (int i = (n-1)/2; i >= 0 ; i--)
	{
		maxHeapify(vect, i, n);
	}
}

void maxHeapify(int *vect, int i, int n)
{
	int l = left(i);
	int r = right(i);
	int largest = i;

	if (l < n && vect[l] > vect[largest])
		largest = l;
	if (r < n && vect[r] > vect[largest])
		largest = r;

	if (largest == i)
		return;
	else
	{
		int temp = vect[largest];
		vect[largest] = vect[i];
		vect[i] = temp;
		maxHeapify(vect,largest,n);
	}
}

int parent(int i)
{
	return i / 2;
}

int left(int i)
{
	return 2 * i + 1;
}

int right(int i)
{
	return 2 * i + 2;
}