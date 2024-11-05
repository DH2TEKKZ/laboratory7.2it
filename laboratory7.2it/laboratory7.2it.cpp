#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int low, const int high);
void Print(int** a, const int rowCount, const int colCount);
int minElement(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));

	int low = -42;
	int high = 51;

	int rowCount = 7;
	int colCount = 6;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, low, high);
	Print(a, rowCount, colCount);
	cout << endl;

	int s = minElement(a, rowCount, colCount);
	
	cout << "sum= " << s;
	
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int low, const int high)
{
	for (int i = 0; i < rowCount; i++) 
		for(int j = 0; j < colCount; j++)
			a[i][j] = low + rand() % (high - low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
int minElement(int** a, const int rowCount, const int colCount)
{
	int minSum = 0;
	for (int i = 0; i < rowCount; i++) {
		int minElement = a[i][0];
		for (int j = 1; j < colCount; j++) {
			if (a[i][j] < minElement) {
				minElement = a[i][j];
			}
		}
		minSum += minElement;
	}
	return minSum;
}