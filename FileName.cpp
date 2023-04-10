#include <iostream>
#include <chrono>  // std::chrono kullanmak iÃ§in
#include <thread>  // std::this_thread kullanmak iÃ§in
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <string>
#include <algorithm>
constexpr auto startX = 40;
constexpr auto startY = 13;

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
			systemWait(1);
			systemClear();
		}
	}
	return size;

	// Fonksiyon ile bardak sayýsýný alýyoruz.
}

//***************************************************************

// Giriþ Ekraný 
void hideCursor(void)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void screenClear(void) {
	system("cls");
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void printBottles(void)
{
	const string reset("\033[0m");
	string bottle[4] = { "|     |","|     |","|     |","|_____|" };
	cout << reset;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			gotoxy(startX + (i * 10), startY + j);
			cout << bottle[j];
		}
	}
}
void printFullBottles(int num)
{
	string fullBottle[4] = { "|     |","|||||||","|||||||","|||||||" };
	const string reset("\033[0m");

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			gotoxy(startX + (i * 10), startY + j);
			cout << fullBottle[j];
		}
	}
}


void intro(void) {

	string bottleHorizontal[3] = { " __________","|||||||||\\\\\\  ","|||||||||||\\\\" };
	string water[1] = { "           ||" };
	string bottleDiagonal[4] = { "   /     / " ,"  ///////  "," ///////   ","///////   " };
	string bottle[4] = { "|     |","|||||||","|||||||","|||||||" };
	const string reset("\033[0m");
	int num = 0;

	for (int i = 0; i < 34; i++)
	{
		screenClear();
		for (int j = 0; j < 4; j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			gotoxy(20 + i, 6 + j);
			cout << bottle[j];
			printBottles();
			printFullBottles(num);
		}
		if ((i == 12) || (i == 22) || (i == 32))
		{
			Sleep(200);
			screenClear();
			printBottles();
			printFullBottles(num);
			for (int k = 0; k < 4; k++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				gotoxy(20 + i, 6 + k);
				cout << bottleDiagonal[k];
			}
			Sleep(200);
			screenClear();
			printBottles();
			printFullBottles(num);
			for (int k = 0; k < 3; k++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				gotoxy(18 + i, 6 + k);
				cout << bottleHorizontal[k];
			}
			num++;
			for (int k = 0; k < 4; k++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				Sleep(300);
				gotoxy(18 + i, 9 + k);
				cout << water[0];
			}
			printFullBottles(num);
		}
		Sleep(200);
	}
	cout << reset;
}
void printFullBottlesWin(int num)
{
	string fullBottle[4] = { "|     |","|||W|||","|||I|||","|||N|||" };
	const string reset("\033[0m");

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			gotoxy(startX + (i * 10), startY + j);
			cout << fullBottle[j];
		}
	}
}

void outrun(void) {

	string bottleHorizontal[3] = { " __________","|||||||||\\\\\\  ","|||||||||||\\\\" };
	string water[1] = { "           ||" };
	string bottleDiagonal[4] = { "   /     / " ,"  ///////  "," ///////   ","///////   " };
	string bottle[4] = { "|     |","|||||||","|||||||","|||||||" };
	const string reset("\033[0m");
	int num = 0;

	for (int i = 0; i < 34; i++)
	{
		screenClear();
		for (int j = 0; j < 4; j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			gotoxy(20 + i, 6 + j);
			cout << bottle[j];
			printBottles();
			printFullBottlesWin(num);
		}
		if ((i == 12) || (i == 22) || (i == 32))
		{
			Sleep(200);
			screenClear();
			printBottles();
			printFullBottlesWin(num);
			for (int k = 0; k < 4; k++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				gotoxy(20 + i, 6 + k);
				cout << bottleDiagonal[k];
			}
			Sleep(200);
			screenClear();
			printBottles();
			printFullBottlesWin(num);
			for (int k = 0; k < 3; k++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				gotoxy(18 + i, 6 + k);
				cout << bottleHorizontal[k];
			}
			num++;
			for (int k = 0; k < 4; k++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				Sleep(300);
				gotoxy(18 + i, 9 + k);
				cout << water[0];
			}
			printFullBottles(num);
		}
		Sleep(200);
	}
	cout << reset;
}
void rulePage() {
	cout << "Welcome To Water Sorting Game\n";
	cout << "Rules" << endl;
	cout << "1)Enter the number of cups you want to play with to start our game. /At least 4 cups \n2) To make a move during the game, perform the assignment operation from a full cup to an empty cup. \n3) To exit the game, press 0 and 0 anywhere in the game and type 'E' on the screen that appears. \n4) To restart the game, press 0 and 0 anywhere in the game and type 'R' on the screen that appears.";
	systemWait(2);
	systemClear();
}


//***************************************************************

int menu() {
	int controller;
	do {
		cout << "Please Enter The Number Of The Task You Want To Do?\n1)Start A New Game...\n2)Continue The Old Game...\n3)Exit The Game...\n";
		cin >> controller;
		switch (controller) {
		case 1:
			cout << "Game Is Starting....";
			systemWait(2);
			systemClear();
			return 1;
			break;

		case 2:
			cout << "Game Is Loading....";
			systemWait(2);
			systemClear();
			return 2;
			break;
		case 3:
			cout << "Game Is Closing...";
			systemWait(2);
			systemClear();
			return 3;
			break;
		default:
			cout << "Please Enter A Valid Value!!\n";
			systemWait(2);
			systemClear();
			break;
		}
	} while (true);
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
	hideCursor();
	intro();
	
	systemClear();
	rulePage();
	//Giriþ Ekranýný Bastýrdým...
	cout << "\n";
	int menu_controller = 0;

	jumptomenu:

	//Menüye Dönüþ Ýçin Jump Kullanýlabilir.

	menu_controller = menu();
	if (menu_controller == 1) {
		size = findGlassNumber();
	}
	 
	else if (menu_controller == 2) {
		cout << "Please Enter A Correct Value";
	}
	else if (menu_controller == 3) {
		
		systemWait(1);
		systemClear();
		exit(0);
	}
	
	int movement_number = 0;

	//Dinamik Bellek Ýle Arrayimizi Oluþturmak...
	int** screen = new int* [4];
	for (int i = 0; i < 4; i++) {
		screen[i] = new int[size];
	}

	bool glass_control = false;
	fillArray(screen, size);
	//printArray(screen, size);
	int control = 0;

	while (1) {

		int finish_control = 0;
		int controllerA, controllerB;

		for (int i = 0; i < size; i++) {
			for (int j = 1; j < 4; j++) {
				controllerA = screen[j - 1][i];
				controllerB = screen[j][i];
				if (controllerA == controllerB) {
					finish_control++;
				}
					
			}
		}

		if (finish_control == (3 * size)) {
			hideCursor();
			outrun();
			systemWait(2);
			systemClear();
			goto jumptomenu;
		}
		/*else {
			cout << "Game Continues\n";
			cout << " " << finish_control << endl;
		  }*/

		printArray(screen, size);

		glasses selectedGlasses = glassControl(size);

		

		cout << "Number Of Displacement:"<<movement_number<<endl;
		cout << "First glass: " << selectedGlasses.glass1 << endl;
		cout << "Second glass: " << selectedGlasses.glass2 << endl;
		movement_number++;

		
		char character_control;
		if (selectedGlasses.glass1 == 0 && selectedGlasses.glass2 == 0) {
			cout << "Please Choose You Want To Do... \n";
			cin >> character_control;
			
			if (character_control == 'R') {
				cout << "Returning To The Menu...." << endl;
				systemWait(2);
				systemClear();
				goto jumptomenu;
			}
			if (character_control == 'E') {
				cout << "Exit The Game" << endl;
				systemWait(2);
				systemClear();
				exit(0);
			}


		}

		else {

			int countOfNumber = 1;
			int row1 = 0;
			int row2 = 3;
			int i = 0;

			while (i < 3) {
				if (screen[i][selectedGlasses.glass1 - 1] != 0) {
					if ((screen[i][selectedGlasses.glass1 - 1] == screen[i + 1][selectedGlasses.glass1 - 1])){
						countOfNumber += 1;
					}
					else {
						break;
					}	

				}

				i++;
			}
			cout << "Count: " << countOfNumber << endl;

			int receivedValue = 0;
			int changedZero = 0;
			int zero = 0;

			int flagCount = countOfNumber;
			while (countOfNumber > 0 && row2>-1) {
				if (screen[row1][selectedGlasses.glass1 - 1] != 0) {
					receivedValue = screen[row1][selectedGlasses.glass1 - 1];
					screen[row1][selectedGlasses.glass1 - 1] = zero;


					while (flagCount > 0) {
						if (screen[row2][selectedGlasses.glass2 - 1] == 0) {
							screen[row2][selectedGlasses.glass2 - 1] = receivedValue;
							flagCount--;
						}
						if (screen[row2][selectedGlasses.glass2 - 1] == receivedValue) {
							for (int i = 3; i >= 0; i--) {
								if (screen[i][selectedGlasses.glass2 - 1] == 0)
								{
									for (int j = flagCount; j > 0; j--)
									{
										screen[i][selectedGlasses.glass2 - 1] = receivedValue;
									}
									flagCount--;
								}
							}
							break;
						}
						int row_controller=0;
						if (screen[row2][selectedGlasses.glass2 - 1] != receivedValue) {
							for (int i = 3; i >= 0; i--) {
								if (screen[i][selectedGlasses.glass2 - 1] != receivedValue) {
									row_controller++;
								}
							}
							if (row_controller == 4) {
								cout << "Transfer Can Not Be Performed\n";
								screen[row1][selectedGlasses.glass1 - 1]=receivedValue;
								break;
							}
							else {
								for (int i = row_controller; i > 0; i--) {
									if (screen[i - 1][selectedGlasses.glass2 - 1] == 0) {
										screen[i - 1][selectedGlasses.glass2 - 1] = receivedValue;
										//screen[row1][selectedGlasses.glass1 - 1] = 0;
									}
								}
							}
						}
						row2--;
					}
					countOfNumber--;
				}
				row1++;
			}
			
			systemWait(2);
			systemClear();
		}

	}

	
	//Dinamik Bellekten Ayrýlýyor *********************

	for (int i = 0; i < size; i++) {
		delete[] screen[i];
	}
	delete[] screen;


	return 0;
}


