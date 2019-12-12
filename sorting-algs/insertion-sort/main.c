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

void InsertionSort(int numbers[], int numbersSize) {

	int i = 0;
	int j = 0;
	int temp = 0;
   
    for (i = 1; i < numbersSize; ++i) {
		j = i;
        
        while (j > 0 && numbers[j] < numbers[j - 1]) {
         
			temp = numbers[j];
			numbers[j] = numbers[j - 1];
			numbers[j - 1] = temp;
			--j;
        }
    }

}

int main() {
	// clock_t Start = clock();
	//call sort function here
	// clock_t End = clock();
	// int elapsedTime = (End - Start) / CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
	return 1;
}
