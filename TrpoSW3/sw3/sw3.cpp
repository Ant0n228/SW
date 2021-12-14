#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct text
{
	string str;
	int first_number = 0;
	double second_number = 0;
	int third_number = 0;
};

text* resizeArray(int& oldSize, int newSize, text* work);
text* readTextFromFile(string fileName, int& size);
void writeTextInFile(string fileName, text* work, int size);
void readWrite();
int getSize(string fileName);
void sizeOfFile();
void newFile(string from, string to, char letter);
void letter();


int main() {
	readWrite();
	sizeOfFile();
	letter();
}

text* readTextFromFile(string fileName, int& size) {
	ifstream file(fileName.c_str());
	if (!file.is_open()) {
		return nullptr;
	}
	size = 1;
	text* work = new text[size];
	int numberOfLines = 0;
	while (!file.eof())
	{
		if (numberOfLines == size)
		{
			work = resizeArray(size, size * 2, work);
		}
		file >> work[numberOfLines].str;
		file >> work[numberOfLines].first_number;
		file >> work[numberOfLines].second_number;
		file >> work[numberOfLines].third_number;
		numberOfLines++;
	}
	file.close();
	return work;
}

text* resizeArray(int& old_size, int new_size, text* work) {
	if (old_size == new_size)
	{
		return work;
	}
	text* newArray = new text[new_size];
	old_size = new_size < old_size ? new_size : old_size;
	for (int i = 0; i < old_size; i++)
	{
		newArray[i] = work[i];
	}
	old_size = new_size;
	delete[] work;
	return newArray;
}

void writeTextInFile(string fileName, text* work, int size) {
	ofstream file(fileName, iostream::app);
	if (!file.is_open()) {
		return;
	}
	for (int i = 0; i < size; i++)
	{
		file << endl << work[i].str << " " << work[i].first_number << " " << work[i].second_number << " " << work[i].third_number;
	}
	file.close();
}

void readWrite() {
	int size;
	const string filename = "myfile.txt";
	text* file = readTextFromFile(filename, size);
	writeTextInFile(filename, file, size);
}

int getSize(string fileName) {
	ifstream file(fileName, ios_base::binary | ios_base::ate);
	int size = file.tellg();
	file.close();
	return size;
}

void sizeOfFile() {
	const string fileName = "myfile.txt";
	cout << getSize(fileName) << endl;
}

void newFile(string from, string to, char letter) {
	ifstream fin(from);
	ofstream fout(to);
	if (!fin.is_open() || !fout.is_open()) {
		return;
	}
	string buf_str;
	while (!fin.eof()) {
		getline(fin, buf_str);
		if (buf_str.find(letter) != string::npos) {
			fout << buf_str << endl;
		}
	}
	fin.close();
	fout.close();
}

void letter() {
	const string fromFile = "myfile.txt",
		toFile = "myfile2.txt";
	char let;
	cout << "Enter letter to find them: ";
	cin >> let;
	newFile(fromFile, toFile, let);
}
