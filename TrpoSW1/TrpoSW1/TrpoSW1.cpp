﻿#include <iostream>
using namespace std;

void splittingNumbers() {
	int number;
	cout << "enter the number, each digit of this number must be printed on a new line: ";
	cin >> number;
	while (number) {
		cout << number % 10 << endl;
		number /= 10;
	}
}

void dayOfWeek() {
	int day;
	cout << "day of the week that you want: ";
	cin >> day;
	switch (day) {
	case 1:
		cout << "Monday";
		break;
	case 2:
		cout << "Tuesday";
		break;
	case 3:
		cout << "Wendnesday";
		break;
	case 4:
		cout << "Thursday";
		break;
	case 5:
		cout << "Friday";
		break;
	case 6:
		cout << "Saturday";
		break;
	case 7:
		cout << "Sunday";
		break;
	default:
		cout << "you must enter the day of the week";
		break;
	}
}

void firstNumbers() {
	int number, amountOfNum;
	cout << "enter two integers number and amount of number and ";
	cout << "returns a number containing the first k digits of n" << endl;
	cout << "number ";  cin >> number;
	cout << "amount of number "; cin >> amountOfNum;
	if (number < amountOfNum) {
		cout << "Error";
	}
	else {
		int i = 0, kk = number;
		while (kk) {
			kk /= 10;
			i++;
		}
		cout << number / int(pow(10, (i - amountOfNum)));
	}

}

int main() {
	splittingNumbers();
	dayOfWeek();
	firstNumbers();
	return 0;
}