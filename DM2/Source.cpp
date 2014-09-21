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

bool HasElement(int target, const int* arr, int length, int cutLength = 20) {

	int cuts = length / cutLength + 1;
	int i = 0;
	for (i = 0; i < cuts; i++) {
		if ((i + 1) * cutLength >= length)
			break;
		if (arr[(i + 1) * cutLength] > target)
			break;
	}

	int from = (i + 1) * cutLength - 1;
	int to = i * cutLength;
	if (from >= length) {
		if (arr[length - 1] < target)
			return false; //если даже последний элемент меньше нужного, то внутри массива и подавна
		from = length - 1;
	}

	for (int j = from; j >= to; j--) {

		if (arr[j] == target)
			return true;
	}
	return false;
}

void AddToArray(const int* source, const int sourceLength, int* target, int& targetLength) {
	
	for (int i = 0; i < sourceLength; i++) {
		target[targetLength] = source[i];
		targetLength++;
	}
}

void Union(int* &arrUnion, int &unionLength, int* arr1, const int length1, int* arr2, const int length2, int cutLength) {

	int* temp = new int[length1 + length2]; // что бы хватило

	int tempLength = 0;
	AddToArray(arr1, length1, temp, tempLength);
	AddToArray(arr2, length2, temp, tempLength);

	arrUnion = new int[length1 + length2];
	unionLength = 0;

	sort(temp, temp + length1 + length2);

	for (int i = 0; i < length1 + length2; i++) {
		if (!HasElement(temp[i], arrUnion, unionLength, cutLength)) {
			arrUnion[unionLength] = temp[i];
			unionLength++;
		}
	}
	delete[] temp;
}

void main() {

	int* arr1 = NULL, *arr2 = NULL;
	int length1 = 0, length2 = 0;
	int cutLength = 0;
	cout << "Cut length?>";
	cin >> cutLength;

	cout << "Array1:" << endl;
	Input(arr1, length1);
	Output(arr1, length1);

	cout << "Array2:" << endl;
	Input(arr2, length2);
	Output(arr2, length2);

	int* unionArr, unionLength;
	Union(unionArr, unionLength, arr1, length1, arr2, length2, cutLength);
	cout << "Union:";
	Output(unionArr, unionLength);

	delete[] arr1;
	delete[] arr2;
	delete[] unionArr;
}