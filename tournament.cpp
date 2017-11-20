/*
 * hw5.cpp
 *
 *  Created on: Oct 14, 2017
 *      Author: andrewratz
 */

#include <iostream>
#include "hw5.h"

using namespace std;
using namespace cop3530;

int main() {
	cout << "---Succeeds---" << endl;
	cout << "Array: ";
	int scores[] = {1,2,3,4};
	for (int i = 0; i < 4; i++)
		cout << scores[i];
	cout << endl;
	int* start = &scores[0];
	int* end = &scores[3];
	int* array = makeTT(start, end);
	cout << "Packed Array: ";
	//Since the array's size is 4 (even), 2*n - 1 = 7 so the packed array will have 7 elements
	for (int i = 0; i < 7; i++) {
		cout << *array;
		array++;
	}
	cout << endl;

	cout << "Array: ";
	int scores2[] = {1,2};
	for (int i = 0; i < 2; i++)
		cout << scores2[i];
	cout << endl;
	start = &scores2[0];
	end = &scores2[1];
	array = makeTT(start, end);
	cout << "Packed Array: ";
	//Since the array's size is 2 (even), 2*n - 1 = 3 so the packed array will have 3 elements
	for (int i = 0; i < 3; i++) {
		cout << *array;
		array++;
	}
	cout << endl;

	cout << "Array: ";
	int scores3[] = {1,2,3};
	for (int i = 0; i < 3; i++)
		cout << scores3[i];
	cout << endl;
	start = &scores3[0];
	end = &scores3[2];
	array = makeTT(start, end);
	cout << "Packed Array: ";
	//Since the array's size is 3 (odd), 2*n = 6 so the packed array will have 6 elements
	for (int i = 0; i < 6; i++) {
		cout << *array;
		array++;
	}
	cout << endl;

	cout << "---Fails---" << endl;
	cout << "Array: ";
	int scores4[] = {1,2,3,4,5};
	for (int i = 0; i < 5; i++)
		cout << scores4[i];
	cout << endl;
	start = &scores4[0];
	end = &scores4[4];
	array = makeTT(start, end);
	cout << "Packed Array: ";
	//Since the array's size is 5 (odd), 2*n = 10 so the packed array will have 10 elements
	for (int i = 0; i < 10; i++) {
		cout << *array;
		array++;
	}
	cout << endl;

	cout << "Array: ";
	int scores5[] = {1,2,3,4,5,6};
	for (int i = 0; i < 6; i++)
		cout << scores5[i];
	cout << endl;
	start = &scores5[0];
	end = &scores5[5];
	array = makeTT(start, end);
	cout << "Packed Array: ";
	//Since the array's size is 6 (even), 2*n - 1 = 11 so the packed array will have 11 elements
	for (int i = 0; i < 11; i++) {
		cout << *array;
		array++;
	}
	cout << endl;
}




















