#include <iostream>
#include <chrono>  // std::chrono kullanmak için
#include <thread>  // std::this_thread kullanmak için
#include <cstdlib>
#include <ctime>

using namespace std;

//**********************************************************

void systemWait(int x) {
	this_thread::sleep_for(chrono::seconds(x));
	//Sistemi ekranda bekletmek i�in fonksiyon... ��ine al�nan int de�eri kadar bekliyor.
}

//***************************************************************

void systemClear() {
	system("cls");

	//Ekran� Windows i�in temizleyen fonksiyon....
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

	// Fonksiyon ile bardak say�s�n� al�yoruz.
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
	// Kullan�c� ile kar��la��lan ilk yer... Men� mant��� i�erisinde ... 
}

//***************************************************************

void printArray(int** array, int size) {
	// S�tun numaralar�n� yazd�rma
	cout << "   ";
	for (int j = 0; j < size; j++) {
		cout << "  " << j + 1 << "  ";
	}
	cout << endl;

	// Sat�r numaralar� ve dizinin elemanlar�n� yazd�rma
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << "  ";
		for (int j = 0; j < size; j++) {
			cout << "| " << array[i][j] << " |";
		}
		cout << "\n";
	}
	// Ekrana Basma G�revi..... Fonksiyon �eklinde matriksi ekrana bast�rma
}

//**************************************************************

void fillArray(int** array, int size) {
	// numbers dizisi tan�mlan�yor ve ba�lang�� de�erleri atan�yor...
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

	// array dizisi s�f�rlan�yor...
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < size - 2; j++) {
			array[i][j] = 0;
		}
	}

	// rasgele say�lar kullan�larak array dizisi dolduruluyor...
	srand(time(NULL));
	int control = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < size - 2; j++) {
			// rasgele bir sat�r ve s�tun se�ilir...
			int row = rand() % 4;
			int col = rand() % (size - 2);
			// numbers dizisindeki bu h�crede 0 olmad��� s�rece rasgele bir h�cre se�ilmeye devam edilir...
			while (numbers[row][col] == 0) {
				row = rand() % 4;
				col = rand() % (size - 2);
			}
			// numbers dizisindeki say�, array dizisine atan�r ve numbers dizisindeki h�cre s�f�rlan�r...
			array[i][j] = numbers[row][col];
			numbers[row][col] = 0;
			control++;
			// Kontrol edilen h�cre say�s� 4 * (size - 2) oldu�unda, t�m say�lar zaten array dizisine atanm�� demektir...
			if (control == 4 * (size - 2)) {
				break;
			}
		}
		// son iki h�cre s�f�rlan�r...
		array[i][size - 2] = 0;
		array[i][size - 1] = 0;
	}

	// numbers dizisi serbest b�rak�l�r...
	for (int i = 0; i < 4; i++) {
		delete[] numbers[i];
	}
	delete[] numbers;

	// Say�lar� d�rder d�rder doldurma...
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
	// Kullan�c�dan al�nan bardak say�lar� structure ile tutulur...
}

//**************************************************************

int main() {
	

	int size;
	startingScreen();
	size = findGlassNumber();





	return 0;
}