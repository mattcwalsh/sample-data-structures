#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

const int NUMBERS_SIZE = 50000;
const int CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000;

int genRandInt(int low, int high) {
	return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[], int arr3[]) {
	for (int i = 0; i < NUMBERS_SIZE; ++i) {
		arr1[i] = genRandInt(0, NUMBERS_SIZE);
		arr2[i] = arr1[i];
		arr3[i] = arr1[i];
	}
}

int partition_midpoint(int numbers[], int i, int k) {

	int midpoint = i + (k - i) / 2;
	int pivot = numbers[midpoint];

	int temp;
	int l = i;
	int h = k;

	bool done = false;

	while (!done) {

		while (numbers[l] < pivot) {
			++l;
		}

		while (pivot < numbers[h]) {
			--h;
		}

		if (l >= h) {
			done = true;
		}

		else {
			temp = numbers[l];
			numbers[l] = numbers[h];
			numbers[h] = temp;
			++l;
			--h;
		}
	}

	return h;
}

void Quicksort_midpoint(int numbers[], int i, int k) {
	int j = 0;

	if (i >= k) {
		return;
	}

	j = partition_midpoint(numbers, i, k);
	Quicksort_midpoint(numbers, i, j);
	Quicksort_midpoint(numbers, j + 1, k);
}

int partition_medianOfThree(int numbers[], int i, int k) {

	int midpoint = i + (k - i) / 2;
	int pivot = (numbers[i] + numbers[midpoint] + numbers[k])/3;

	int temp;
	int l = i;
	int h = k;

	bool done = false;

	while (!done) {

		while (numbers[l] < pivot) {
			++l;
		}

		while (pivot < numbers[h]) {
			--h;
		}

		if (l >= h) {
			done = true;
		}
		
		else {
			temp = numbers[l];
			numbers[l] = numbers[h];
			numbers[h] = temp;
			++l;
			--h;
		}
	}

	return h;
}

void Quicksort_medianOfThree(int numbers[], int i, int k) {
	int j = 0;

	if (i >= k) {
		return;
	}

	j = partition_medianOfThree(numbers, i, k);
	Quicksort_medianOfThree(numbers, i, j);
	Quicksort_medianOfThree(numbers, j + 1, k);
}

int main() {
	// clock_t Start = clock();
	//call sort function here
	// clock_t End = clock();
	// int elapsedTime = (End - Start) / CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
	return 1;
}
