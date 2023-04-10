#include <iostream>
#include <chrono>  // std::chrono kullanmak iÃ§in
#include <thread>  // std::this_thread kullanmak iÃ§in
#include <cstdlib>
#include <ctime>

using namespace std;

//**********************************************************

void systemWait(int x) {
	this_thread::sleep_for(chrono::seconds(x));
	//Sistemi ekranda bekletmek için fonksiyon... Ýçine alýnan int deðeri kadar bekliyor.
}

//***************************************************************

void systemClear() {
	system("cls");

	//Ekraný Windows için temizleyen fonksiyon....
}

//***************************************************************

int findGlassNumber() {
	int size;
	bool valid_size = false;
	while (!valid_size) {
		cout << "Could You Please Enter Number Of Glasses:";
		cin >> size;
		if (size < 4) {
			cout << "Could You Please Enter The Number Of Glasses Again, This Time Making Sure It Is Greater Than Four (4)!! ";
			systemWait(2);
			systemClear();
			valid_size = false;
		}
		else {
			cout << "Your Glass Number Is:" << size << endl;
			cout << "Your Colour Number Is:" << size - 2 << endl;
			valid_size = true;
		}
	}
	return size;

	// Fonksiyon ile bardak sayýsýný alýyoruz.
}

//***************************************************************

void startingScreen() {
	cout << "      ___          ___" << endl;
	cout << "|  | |    |   |   |   |" << endl;
	cout << "|--| |--  |   |   |   |" << endl;
	cout << "|  | |___ |__ |__ |___|" << endl;
	systemWait(2);
	systemClear();
	cout << "               __  ___  ___  __   " << endl;
	cout << "\\\    /\\\    /  |  |  |  |    |  |  " << endl;
	cout << " \\\  /  \\\  /   |__|  |  |--  |--   " << endl;
	cout << "  \\\/    \\\/    |  |  |  |___ |  \\\  " << endl;

	cout << "   ___   ___    ____    _______" << endl;
	cout << "  |     |   |  |    |      | " << endl;
	cout << "  |___  |   |  |----       | " << endl;
	cout << "      | |   |  |    \\\      | " << endl;
	cout << "   ___| |___|  |     \\\     | " << endl;

	cout << "		Prepared By: Baturhan Cagatay" << endl;
	systemWait(2);
	systemClear();
	int controller;
	cout << "Please Enter The Number Of The Task You Want To Do?\n1)Start A New Game...\n2)Continue The Old Game...\n";
	cin >> controller;
	switch (controller) {
	case 1:
		cout << "Game Is Starting....";
		systemWait(2);
		systemClear();
		break;

	case 2:
		cout << "Game Is Loading....";
		systemWait(2);
		systemClear();
		break;
	default:
		cout << "Please Enter A Valid Value!!";
		break;
	}
	// Kullanýcý ile karþýlaþýlan ilk yer... Menü mantýðý içerisinde ... 
}

//***************************************************************

void printArray(int** array, int size) {
	// Sütun numaralarýný yazdýrma
	cout << "   ";
	for (int j = 0; j < size; j++) {
		cout << "  " << j + 1 << "  ";
	}
	cout << endl;

	// Satýr numaralarý ve dizinin elemanlarýný yazdýrma
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << "  ";
		for (int j = 0; j < size; j++) {
			cout << "| " << array[i][j] << " |";
		}
		cout << "\n";
	}
	// Ekrana Basma Görevi..... Fonksiyon þeklinde matriksi ekrana bastýrma
}

//**************************************************************

void fillArray(int** array, int size) {
	// numbers dizisi tanýmlanýyor ve baþlangýç deðerleri atanýyor...
	int num = 1;
	int constant = 0;
	int** numbers = new int* [4];
	for (int i = 0; i < 4; i++) {
		numbers[i] = new int[size - 2];
		for (int j = 0; j < size - 2; j++) {
			numbers[i][j] = num;
			constant += 1;
			if (constant == 4) {
				num += 1;
				constant = 0;
			}
		}
	}

	// array dizisi sýfýrlanýyor...
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < size - 2; j++) {
			array[i][j] = 0;
		}
	}

	// rasgele sayýlar kullanýlarak array dizisi dolduruluyor...
	srand(time(NULL));
	int control = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < size - 2; j++) {
			// rasgele bir satýr ve sütun seçilir...
			int row = rand() % 4;
			int col = rand() % (size - 2);
			// numbers dizisindeki bu hücrede 0 olmadýðý sürece rasgele bir hücre seçilmeye devam edilir...
			while (numbers[row][col] == 0) {
				row = rand() % 4;
				col = rand() % (size - 2);
			}
			// numbers dizisindeki sayý, array dizisine atanýr ve numbers dizisindeki hücre sýfýrlanýr...
			array[i][j] = numbers[row][col];
			numbers[row][col] = 0;
			control++;
			// Kontrol edilen hücre sayýsý 4 * (size - 2) olduðunda, tüm sayýlar zaten array dizisine atanmýþ demektir...
			if (control == 4 * (size - 2)) {
				break;
			}
		}
		// son iki hücre sýfýrlanýr...
		array[i][size - 2] = 0;
		array[i][size - 1] = 0;
	}

	// numbers dizisi serbest býrakýlýr...
	for (int i = 0; i < 4; i++) {
		delete[] numbers[i];
	}
	delete[] numbers;

	// Sayýlarý dörder dörder doldurma...
}

//**************************************************************

struct glasses {
	int glass1;
	int glass2;
};

glasses glassControl(int size) {
	int glassA, glassB;
	bool glass_control = false;

	while (!glass_control) {
		cout << "Please enter the number of your first glass: ";
		cin >> glassA;
		cout << "Please enter the number of your second glass: ";
		cin >> glassB;

		if (glassA < 0 || glassA > size) {
			cout << "Please enter a valid number for the first glass!" << endl;
			glass_control = false;
		}
		else if (glassB < 0 || glassB > size) {
			cout << "Please enter a valid number for the second glass!" << endl;
			glass_control = false;
		}
		else {
			glass_control = true;
		}
	}

	glasses result;
	result.glass1 = glassA;
	result.glass2 = glassB;
	return result;
	// Kullanýcýdan alýnan bardak sayýlarý structure ile tutulur...
}

//**************************************************************

int main() {
	

	int size;
	startingScreen();
	size = findGlassNumber();





	return 0;
}