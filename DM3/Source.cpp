#include <iostream>
#include <algorithm>

using namespace std;

void Input(int* &result, int &length) {

	cout << "Input array length?>";
	cin >> length;
	if (length < 0)
		length = 0;
	result = new int[length];
	int min, max;
	cout << "Min value?>";
	cin >> min;
	cout << "Max value?>";
	cin >> max;

	for (int i = 0; i < length; i++) {
		result[i] = rand() % (max - min + 1) + min;
	}
}

void Output(const int* arr, const int length) {

	cout << "[";
	for (int i = 0; i < length; i++) {
		cout << arr[i];
		if (i != length - 1)
			cout << ", ";
	}
	cout << "]" << endl;
}

bool HasElement(int target, const int* arr, int length) {

	for (int i = 0; i < length; i++) {
		if (arr[i] > target)
			return false;
		if (arr[i] == target)
			return true;
	}
	return false;
}

void Intersection(int* &intersection, int &intLength, int* arr1, const int length1, int* arr2, const int length2) {

	sort(arr1, arr1 + length1);
	sort(arr2, arr2 + length2);

	const int* bigger = (length1 > length2) ? arr1 : arr2;
	const int* smaller = (bigger == arr1) ? arr2 : arr1;
	const int biggerLength = max(length1, length2);
	const int smallerLength = min(length1, length2);
	intersection = new int[smallerLength];
	intLength = 0;

	for (int i = 0; i < smallerLength; i++) {

		if (HasElement(smaller[i], intersection, intLength))
			continue;
		if (HasElement(smaller[i], bigger, biggerLength))
		{
			intersection[intLength] = smaller[i];
			intLength++;
		}
	}
}

void main() {

	int* arr1 = NULL, *arr2 = NULL;
	int length1 = 0, length2 = 0;

	cout << "Array1:" << endl;
	Input(arr1, length1);
	Output(arr1, length1);

	cout << "Array2:" << endl;
	Input(arr2, length2);
	Output(arr2, length2);

	int* intersection, intLength;
	Intersection(intersection, intLength, arr1, length1, arr2, length2);
	cout << "Intersection:";
	Output(intersection, intLength);

	delete[] arr1;
	delete[] arr2;
	delete[] intersection;
}