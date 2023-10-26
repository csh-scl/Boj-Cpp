#include <bits/stdc++.h>
using namespace std;
// arr 배열은 해당 당일의 할 수 있는 일 1. 당일일은 하거나 2. 하루 미루기
int arr[20];
int work[20];
int value[20];
int main(void){
	int num;
	cin >> num;
	
	for (int i = 1; i <= num; i++) {
		cin >> work[i] >> value[i];
	}
	
	for (int i = num; i >= 1; i--) {
		if (i + work[i] <= num+1) {
			arr[i] = max(arr[i + 1], arr[i + work[i]] + value[i]);
		}
		else
			arr[i] = arr[i+1];
	}

	cout << *max_element(arr, arr+num+1);
} 