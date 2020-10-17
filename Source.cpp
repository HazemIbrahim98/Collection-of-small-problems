/*
if (scanf_s("%d", &stage) != 1) {
	printf("Invalid Input");
	scanf_s("%c");
	goto start;
}*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>
#include<math.h>
#include<cstdio>
#include<time.h>

//Structs
struct point {
	float x;
	float y;
};

struct dateOfBirth {
	int day;
	int month;
	int year;
};

struct Employee {
	char name[30];
	dateOfBirth dob;
	float salary;
};

//Function Declaration
int start();

void arrays();
void arraysMatrix();
void arraysSum();

void strings();
void stringPalindrome();
void stringRotate();
void rotateLeft();
void rotateRight();

void recursion();
int sumOfDigits(int input);
float maxElement(float arr[], int i);

void structs();
void structPoints(point point1);
void structPointsSum(point point1, point point2);
void structEmployee();
void structEmployeeRead(Employee staff[]);
void structEmployeeReadFromFile(Employee staff[]);
void structEmployeeMaxSalary(Employee staff[]);
void structEmployeeYoungest(Employee staff[]);
void structEmployeePrint(Employee staff[], int i);
void sarayoung(Employee CO[], int size);

void game();
void gameStart(char word[][50]);
void gamePrint(char word[][50]);
void gameGuess(char word[][50], int *guess);
int gameFull(char word[][50]);
void gameHangMan(int tries);

void simonsays();

void main() {
	//Main Function Acts As A Distributor
	int stage;
start:

	stage = start();

	switch (stage) {

	case 1:
		arrays();
		break;

	case 2:
		strings();
		break;

	case 3:
		recursion();
		break;

	case 4:
		structs();
		break;

	case 5:
		game();
		break;

	case 6:
		simonsays();
		break;

	case 7:
		//Exits
		system("cls");
		printf("GoodBye.");
		Sleep(600);
		exit(0);

	default:
		//Deals With Invalid Inputs
		printf("Invalid input");
		Sleep(600);
		goto start;
	}
	//Restarts Application
	goto start;
}

int start() {
	//Prints Initial Main Menu	
	int stage;

start:

	system("cls");
	printf("-- Select A Group:-\n\n1) Programs With 2D Arrays\n\n2) Programs With Strings");
	printf("\n\n3) Programs With Recursion\n\n4) Programs With Structs\n\n5) HangMan\n\n6) Simon Says\n\n7)Exit\n\n");

	if (scanf_s("%d", &stage) != 1) {
		printf("Invalid Input");
		Sleep(600);
		scanf_s("%c");
		goto start;
	}

	return stage;
}

 void arrays() {
	//Prints the 2D array options

	int stage;
start:
	system("cls");

	printf("-- Select Program :-\n\n1) Square Matrix\n\n2) Sum Of Row And Column\n\n3) Main Menu\n\n");
	if (scanf_s("%d", &stage) != 1) {
		printf("Invalid Input");
		scanf_s("%c");
		Sleep(500);
		goto start;
	}

	switch (stage) {

	case 1:
		arraysMatrix();
		break;

	case 2:
		arraysSum();
		break;

	case 3:
		return;

	default:
		//Deals With Invalid inputs
		printf("Invalid input");
		Sleep(600);
		goto start;
	}
	//Deals With Finished Functions
	goto start;
}

void arraysMatrix() {
	//Function To Calculate Non Zero Elements & Diagonal Multplication

	int n, count = 0;
	float mult = 1;

start:
	system("cls");

	printf("Entrer Dimension Of 2D Array :");

	if (scanf_s("%d", &n) != 1) {
		printf("Invalid Input");
		Sleep(500);
		scanf_s("%c");
		goto start;
	}
	if (n < 1) {
		printf("Invalid Input");
		Sleep(500);
		goto start;
	}

	//Dynamically allocating 2D array
	float **arr = (float **)malloc(sizeof(float *) * n);
	for (int i = 0; i < n; i++)
		arr[i] = (float *)malloc(sizeof(float) * n);

	//Input
	printf("\nEnter The 2D Array Of Size %d X %d\n", n, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (scanf_s("%f", &arr[i][j]) != 1) {
				printf("Invalid Input Re-Enter A Float: ");
				scanf_s("%c");
				j--;
			}

	system("cls");

	printf("\nEntered Array Is :\n\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%f  ", arr[i][j]);
		printf("\n");
	}
	//Calculate Non Zero Elements
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] != 0)
				count++;

	printf("\nNumber Of Non Zero Elements : %d\n", count);

	//Calculate Diagonal Multplication
	for (int i = 0; i < n; i++)
		mult *= arr[i][i];

	printf("\nDiagonal Multplication is : %f\n", mult);

	//Freeing 2d array
	for (int i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
	_getch();
}

void arraysSum() {
	//Functio To Print Sum Of Rows And columns

	float arr[3][6];
	float sum = 0;
	system("cls");

	printf("Enter the array (10 Terms) : ");

	//Input
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 5; j++)
			if (scanf_s("%f", &arr[i][j]) != 1) {
				printf("Invalid Input Re-Enter A Float: ");
				scanf_s("%c");
				j--;
			}

	//Calculates Sum
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++)
			sum += arr[i][j];
		arr[i][5] = sum;
		sum = 0;
	}

	for (int j = 0, sum = 0; j < 5; j++) {
		for (int i = 0; i < 2; i++)
			sum += arr[i][j];
		arr[2][j] = sum;
		sum = 0;
	}
	system("cls");
	//Output
	arr[2][5] = 0;
	printf("\n                                                        SUM\n");
	for (int i = 0; i < 3; i++) {
		printf("\t");
		for (int j = 0; j < 6; j++)
			printf("%f ", arr[i][j]);

		printf("\n");

		if (i == 1) {
			printf("SUM\t");

			for (int j = 0; j < 5; j++)
				printf("%f ", arr[i + 1][j]);
			break;
		}
	}

	_getch();
}

void strings() {
	//Prints the string options

	int stage;
start:
	system("cls");

	printf("-- Select Program\n\n1) Palindrome\n\n2) Rotate\n\n3) Main Menu\n\n");

	if (scanf_s("%d", &stage) != 1) {
		printf("Invalid Input");
		scanf_s("%c");
		Sleep(500);
		goto start;
	}

	switch (stage) {

	case 1:
		stringPalindrome();
		break;

	case 2:
		stringRotate();
		break;

	case 3:
		//Returns To Main
		return;

	default:
		//Deals With Invalid inputs
		printf("Invalid input");
		Sleep(600);
		goto start;
	}
	//Deals With Finished Functions
	goto start;
}

void stringPalindrome() {
	//Function To Tell If Palindrome

	char arr1[100], arr2[100];

	while (1) {
		system("cls");

		//Input
		printf("Enter 0 To Exit.\n\nEnter The Word : ");
		scanf_s("\n");
		gets_s(arr1);

		for (int i = 0; i < sizeof(arr1); i++)
			arr1[i] = tolower(arr1[i]);

		//Exit Condition
		if (arr1[0] == '0') {
			printf("\nReturning To Main");
			Sleep(600);
			break;
		}

		strcpy_s(arr2, arr1);
		_strrev(arr2);

		//OutPut
		if (strcmp(arr1, arr2) == 0)
			printf("\nWord Is Palindrome\n");
		else
			printf("\nWord Is Not Palindrome\n");
		_getch();
	}
}

void stringRotate() {
	//Function To Rotate A String

	int stage;
start:

	system("cls");

	printf("-- Select Mode\n\n1) Rotate Left\n\n2) Rotate Right\n\n3) Main Functions\n\n");

	if (scanf_s("%d", &stage) != 1) {
		printf("Invalid Input");
		Sleep(500);
		scanf_s("%c");
		goto start;
	}


	switch (stage) {

	case 1:
		rotateLeft();
		break;

	case 2:
		rotateRight();
		break;

	case 3:
		//Returns To Main Function
		return;

	default:
		//Deals With Invalid inputs
		printf("Invalid input");
		Sleep(600);
		goto start;
	}
	//Deals With Finished Functions
	goto start;
}

void rotateLeft() {
	// abcdef to bcdefa

	char arr[100], temp;
	int n;

	start:
	system("cls");

	//Input
	printf("Enter The Array To Rotate : ");
	
	scanf_s("\n");
	gets_s(arr);

	printf("\nEnter The Number Of Rotations : ");

	if (scanf_s("%d", &n) != 1) {
		printf("Invalid Input");
		scanf_s("%c");
		Sleep(500);
		goto start;
	}
	if (n < 0) {
		printf("Invalid Input");
		Sleep(500);
		goto start;
	}
	
	//Rotating N Times
	while (n != 0) {
		temp = arr[0];

		for (int i = 0; i < (strlen(arr) - 1); i++)
			arr[i] = arr[i + 1];

		arr[(strlen(arr) - 1)] = temp;

		n--;
	}

	//Output
	printf("\nArray After Rotation : ");
	puts(arr);

	_getch();
}

void rotateRight() {
	// abcdef to fabcde

	char arr[100], temp;
	int n;
	start :
	system("cls");

	//Input
	printf("Enter The Array To Rotate : ");

	scanf_s("\n");
	gets_s(arr);

	printf("\nEnter The Number Of Rotations : ");
	
	if (scanf_s("%d", &n) != 1) {
		printf("Invalid Input");
		scanf_s("%c");
		Sleep(500);
		goto start;
	}
	if (n < 0) {
		printf("Invalid Input");
		Sleep(500);
		goto start;
	}

	//Rotating N Times
	while (n != 0) {
		temp = arr[(strlen(arr) - 1)];

		for (int i = (strlen(arr) - 1); i > 0; i--)
			arr[i] = arr[i - 1];

		arr[0] = temp;

		n--;
	}

	//Output
	printf("\nArray After Rotation : ");
	puts(arr);

	_getch();
}

void recursion() {
	//Prints the recursion options

	int stage;
	float arrayForMaxElement[50];

start:
	system("cls");

	printf("-- Select Program\n\n1) Sum Of Digits\n\n2) Max Element\n\n3) Main Menu\n\n");

	if (scanf_s("%d", &stage) != 1) {
		printf("Invalid Input");
		scanf_s("%c");
		Sleep(500);
		goto start;
	}
	switch (stage) {

	case 1:
		stage1:
			system("cls");
			printf("Enter The Positive Integer : ");

			if (scanf_s("%d", &stage) != 1) {
				printf("Invalid Input");
				scanf_s("%c");
				Sleep(500);
				goto stage1;
			}
			if (stage < 0) {
				printf("Invalid Input");
				Sleep(500);
				goto stage1;
			}

			printf("\nSum Is : %d", sumOfDigits(stage));
			_getch();
			break;

	case 2:
		stage2:
			system("cls");

			printf("Enter The Size Of Array (Max 50) : ");

			if (scanf_s("%d", &stage) != 1) {
				printf("Invalid Input");
				Sleep(500);
				scanf_s("%c");
				goto stage2;
			}
			if (stage > 50 || stage < 1) {
				printf("Invalid Input");
				Sleep(500);
				goto stage2;
			}

			printf("\nEnter The Flaot Digits : ");

			for (int i = 1; i < stage + 1; i++)
				if (scanf_s("%f", &arrayForMaxElement[i]) != 1) {
					printf("Invalid Input\n Re-Enter The Element : ");
					scanf_s("%c");
					i--;
				}
			
			arrayForMaxElement[0] = arrayForMaxElement[1];

			printf("\nMax Element Is : %f", maxElement(arrayForMaxElement, stage));
			_getch();
			break;

	case 3:
		//Returns To Main
		return;

	default:
		//Deals With Invalid inputs
		printf("Invalid input");
		Sleep(600);
		goto start;
	}
	//Deals With Finished Functions
	goto start;
}

int sumOfDigits(int input) {
	//Recursive Function To Print The Sum Of Degits In A Big String

	if (input == 0)
		return 0;
	else
		return (input % 10 + sumOfDigits(input / 10));
}

float maxElement(float arr[], int i) {
	//Recursive Function To Print Max Element

	if (i == 0)
		return arr[0];
	if (arr[i] > arr[0])
		arr[0] = arr[i];

	return maxElement(arr, i - 1);
}

void structs() {
	//Prints the struct options

	int stage;
	point point1, point2;
start:
	system("cls");

	printf("-- Select Program\n\n1) Points\n\n2) Employees\n\n3) Main Menu\n\n");
	if (scanf_s("%d", &stage) != 1) {
		printf("Invalid Input");
		Sleep(500);
		scanf_s("%c");
		goto start;
	}

	switch (stage) {

	case 1:
		read1:
		system("cls");

		//Input
		printf("Enter Point 1's X , Y Coordinates : ");
		if (scanf_s("%f%f", &point1.x, &point1.y) != 2) {
			printf("Invalid Input\n");
			Sleep(500);
			scanf_s("%c");
			goto read1;
		}
		read2:
		printf("\nEnter Point 2's X , Y Coordinates : ");
		if (scanf_s("%f%f", &point2.x, &point2.y) != 2) {
			printf("Invalid Input\n");
			scanf_s("%c");
			Sleep(500);
			goto read2;
		}
		
		system("cls");

		structPoints(point1);
		structPoints(point2);

		structPointsSum(point1, point2);

		break;

	case 2:
		structEmployee();
		break;

	case 3:
		//Returns To Main
		return;

	default:
		//Deals With Invalid inputs
		printf("Invalid input");
		Sleep(600);
		goto start;
	}
	goto start;
}

void structPoints(point point) {
	//Function To Print Point And Norm

	printf("X is : %f , Y is : %f\n", point.x, point.y);
	printf("Norm is : %f\n\n", pow((pow(point.x, 2) + pow(point.y, 2)), 0.5));
}

void structPointsSum(point point1, point point2) {
	//Function To Print Sum Of Two Points

	point1.x += point2.x;
	point1.y += point2.y;

	printf("Sum Is :- X : %f , Y : %f\n", point1.x, point1.y);

	_getch();
}

void structEmployee() {
	//Function As A Hub For Other Employee Functions
	
	Employee staff[10];
	system("cls");

//	structEmployeeRead(staff);
	structEmployeeReadFromFile(staff);

//	structEmployeeMaxSalary(staff);

//	structEmployeeYoungest(staff);
	sarayoung(staff, 10);

	_getch();
}

void structEmployeeRead(Employee staff[]) {
	//Function To Read 10 Employees

	system("cls");
	
	//Input
	for (int i = 0; i < 10; i++) {

		printf("Employee %d\n", i + 1);

		printf("Enter Name : ");
		scanf_s("%s", &staff[i].name, 10);

		printf("Enter Salary : ");
		if (scanf_s("%f", &staff[i].salary) != 1) {
			printf("Invalid Input\nRe-Enter Staff Info\n");
			scanf_s("%c");
			i--;
			Sleep(500);
			continue;
		}
		if (staff[i].salary < 1) {
			printf("Invalid Input\nRe-Enter Staff Info\n");
			i--;
			Sleep(500);
			continue;
		}

		printf("Enter Date Of Birth (DD-MM-YYYY) : ");
		if (scanf_s("%d%d%d", &staff[i].dob.day, &staff[i].dob.month, &staff[i].dob.year) != 3) {
			printf("Invalid Input\nRe-Enter Staff Info\n");
			scanf_s("%c");
			i--;
			Sleep(500);
			continue;
		}
		if (staff[i].dob.year < 1 || staff[i].dob.month < 1 || staff[i].dob.day < 1 || staff[i].dob.day > 31 || staff[i].dob.month > 12) {
			printf("Invalid Input\nRe-Enter Staff Info\n");
			i--;
			Sleep(500);
			continue;
		}

		system("cls");
	}
}

void structEmployeeReadFromFile(Employee staff[]) {
	//Function To Read 10 Employees from files to debug

	system("cls");

	FILE *in;
	fopen_s(&in, "Employee.txt", "r");

	if (in == NULL){
		printf("Error File Not Found");
		return;
	}

	//Input
	for (int i = 0; i < 10; i++) {
		fscanf_s(in, "%s", &staff[i].name, 10);
		fscanf_s(in, "%f", &staff[i].salary);
		fscanf_s(in, "%d%d%d", &staff[i].dob.day, &staff[i].dob.month, &staff[i].dob.year);
	}
}

void structEmployeeMaxSalary(Employee staff[]) {
	//Function To Print Employee With Max Salary

	int employeeI = 0;
	float highest = staff[0].salary;
	
	for (int i = 1; i < 10; i++)
		if (staff[i].salary > highest) {
			highest = staff[i].salary;
			employeeI = i;
		}
	printf("Employee With Highest Salary Is Employee Number %d\n", employeeI + 1);
	structEmployeePrint(staff, employeeI);
}

void structEmployeeYoungest(Employee staff[]) {
	//Function To Find The Youngest Employee

	int lowest, lowestI, count = 0;

	//Find Lowest Year
	lowest = staff[0].dob.year;

	for (int i = 0; i < 10; i++)
		if (lowest < staff[i].dob.year) {
			lowest = staff[i].dob.year;
			lowestI = i;
		}
	//Find Repeats Of Lowest Year
	for (int i = 0; i < 10; i++)
		if (lowest == staff[i].dob.year)
			count++;
	
	if (count == 1) {
		printf("\nYoungest Employee :-\n");
		structEmployeePrint(staff, lowestI);
		return;
	}
	else {
		//Compares Months Within Lowest Years
		Employee months[10];
		int sizeOfMonths = 0;
		count = 0;

		for (int i = 0; i < 10; i++)
			if (lowest == staff[i].dob.year) {
				months[sizeOfMonths] = staff[i];
				sizeOfMonths++;
			}

		//Find Lowest Months
		lowest = months[0].dob.month;

		for (int i = 0; i < sizeOfMonths; i++)
			if (lowest <= months[i].dob.month) {
				lowest = months[i].dob.month;
				lowestI = i;
			}

		//Finds Repeats Of Lowest Months
		for (int i = 0; i < sizeOfMonths; i++)
			if (lowest == months[i].dob.month)
				count++;

		if (count == 1) {
			printf("\nYoungest Employee :-\n");
			structEmployeePrint(months, lowestI);
			return;
		}
		
		else {
			//Compares Days Within Lowest Months
			
			Employee days[10];
			int sizeOfDays = 0;
			count = 0;

			for (int i = 0; i < 10; i++)
				if (lowest == months[i].dob.month) {
					days[sizeOfDays] = months[i];
					sizeOfDays++;
				}

			//Find Lowest Day
			lowest = months[0].dob.day;

			for (int i = 0; i < sizeOfDays; i++)
				if (lowest <= days[i].dob.day) {
					lowest = days[i].dob.day;
					lowestI = i;
				}

			//Finds Repeats Of Lowest Day
			for (int i = 0; i < sizeOfDays; i++)
				if (lowest == days[i].dob.day)
					count++;
	
			if (count == 1) {
				printf("\nYoungest Employee :-\n");
				structEmployeePrint(days, lowestI);
				return;
			}
			else {
				//Prints The Youngest Employees With Exact Ages

				printf("\nYoungest Employee :-\n");
				for (int i = 0; i < sizeOfDays; i++)
					if (lowest == days[i].dob.day) {
						structEmployeePrint(days, i);
						printf("\n");
					}

			}
		}
	}
}

void sarayoung(Employee CO[], int size) {

	int y = 0, pm[10], m = 0, pd[10], d = 0;
	for (int i = 0; i<size; i++)
		if (y<CO[i].dob.year)
			y = CO[i].dob.year;
	int j = 0;
	for (int i = 0; i<size; i++)
		if (y == CO[i].dob.year)
		{
			pm[j] = i;
			j++;
		}
	for (int i = 0; i<j; i++)
		if (m<CO[pm[i]].dob.month)
			m = CO[pm[i]].dob.month;
	int k = 0;
	for (int i = 0; i<size; i++)
	{
		if (y == CO[i].dob.year && m == CO[i].dob.month)
		{
			pd[k] = i;
			k++;
		}
	}
	for (int i = 0; i<k; i++)
		if (d<CO[pd[i]].dob.day)
			d = CO[pd[i]].dob.day;
	for (int i = 0; i<size; i++)
	{
		if (d == CO[i].dob.day && m == CO[i].dob.month && y == CO[i].dob.year)
		{
			printf("Youngest Employee:-\n");
			printf("Name:");
			puts(CO[i].name);
			printf("Date Of Birth: %d/%d/%d\n", CO[i].dob.day, CO[i].dob.month, CO[i].dob.year);
			printf("Salary: %f\n\n", CO[i].salary);
		}
	}

}
void structEmployeePrint(Employee staff[], int i) {
	//Function To Print The Employee

	printf("Name Is : ");
	puts(staff[i].name);
	printf("Date Of Birth Is (%d-%d-%d)\n", staff[i].dob.day, staff[i].dob.month, staff[i].dob.year);
	printf("Salary Is %f\n", staff[i].salary);

}

void game() {
	//Function Containing The Game
	int tries = 5;
	char word[2][50];

	gameStart(word);

	//Main Game Loop
	while (tries != 0) {
		system("cls");

		gameHangMan(tries);

		printf("Tries left : %d\n", tries);

		gamePrint(word);
		gameGuess(word, &tries);
		if (gameFull(word) == 1) {
			system("cls");
			gameHangMan(tries);
			gamePrint(word);
			printf("\n\nYou Win!");
			_getch();
			return;
		}
	}
	system("cls");
	gameHangMan(tries);
	gamePrint(word);
	printf("\n\nYou Lose!");
	_getch();
	return;
}

void gameStart(char word[][50]) {
	//Initializes The Game

	int wordN, input;

	memset(word, '0', sizeof(char) * 50 * 2);

	FILE *in;

	fopen_s(&in, "Game.txt", "r");

	if (in == NULL) {
		printf("Error File Not Found");
		Sleep(500);
		exit(0);
	}

	if (fscanf_s(in, "%d", &wordN) != 1) {
		printf("Error Intiger Not Found In The Start Of The File");
		Sleep(1500);
		exit(0);
	}
start:
	system("cls");

	printf("Welcome To HangMan\n");

	printf("Select Word N (1 - %d) : ", wordN);
	
	if (scanf_s("%d", &input) != 1) {
		printf("Invalid Input");
		scanf_s("%c");
		goto start;
	}

	if (input <= 0 || input > wordN) {
		printf("Invalid Input");
		Sleep(500);
		goto start;
	}

	for (int i = 0; i < input; i++)
		fscanf_s(in, "%s", &word[0], 50);
}

void gamePrint(char word[][50]) {

	int i = 0;
	printf("Game Board Is :-\n\n");

	while (word[0][i] != NULL) {

		if (word[1][i] == '1') {
			printf("%c ", toupper(word[0][i]));
		}
		else
			printf("_ ");

		i++;
	}
}

void gameGuess(char word[][50], int *tries) {
	//Finds The Guess In The Game Array

	int i = 0, count = 0;
	char guess;

	printf("\n\nEnter Your Guess : ");

	scanf_s("\n%c", &guess);

	while (word[0][i] != NULL) {
		if (word[0][i] == tolower(guess)) {
			word[1][i] = '1';
			count++;
		}
		i++;
	}

	if (count == 0) {
		printf("Wrong Guess");
		*tries -= 1;
		Sleep(1000);
		return;
	}
}

int gameFull(char word[][50]) {
	//Returns 1 If The Word Is Complete

	int i = 0;

	while (word[0][i] != NULL) {
		if (word[1][i] == '0')
			return 0;
		i++;
	}
	return 1;
}

void gameHangMan(int tries) {
	//Prints Hangman
	switch (tries) {

	case 5:
		printf("   ____\n  |    |\n  |    O\n  |   /|\\\n  |    |\n  |   / \\\n _|_\n|   |______\n|          |\n|__________|\n");
		break;

	case 4:
		printf("   ____\n  |    |\n  |    O\n  |   /|\\\n  |    |\n  |   /\n _|_\n|   |______\n|          |\n|__________|\n");
		break;

	case 3:
		printf("   ____\n  |    |\n  |    O\n  |   /|\\\n  |    |\n  |\n _|_\n|   |______\n|          |\n|__________|\n");
		break;


	case 2:
		printf("   ____\n  |    |\n  |    O\n  |   /|\\\n  |\n  |\n _|_\n|   |______\n|          |\n|__________|\n");
		break;

	case 1:
		printf("   ____\n  |    |\n  |    O\n  |   /|\n  |\n  |\n _|_\n|   |______\n|          |\n|__________|\n");
		break;

	case 0:
		printf("   ____\n  |    |\n  |    O \n  |\n  |\n  |\n _|_\n|   |______\n|          |\n|__________|\n");
		break;
	}

	printf("\n\n");
}

void simonsays() {
	int rounds = 4, rng;
	char play;
	int arrRNG[10], arrPlayer[10];

	FILE *p;

start:

	 p = fopen("Simon Says.txt", "w");

	if (p == NULL) {
		printf("Error File Not Found");
		return;
	}


	system("cls");
	rounds = 4;

	printf("              Welcome TO Simon Says\n\n\n\n");
	printf("Play?(Y / N) : ");
	scanf_s("\n");
	scanf_s("%c", &play);

	if (toupper(play) == 'N') {
		printf("GoodBye");
		Sleep(1000);
		return;
	}
	else if (toupper(play) != 'Y') {
		printf("Invalid Input");
		Sleep(500);
		goto start;

	}

	while (1) {

		for (int i = 0; i < rounds; i++) {
			system("cls");

			srand(time(NULL));
			rng = (rand() % 4) + 1;
			arrRNG[i] = rng;

			switch (rng) {
			case 1:
				printf("              Welcome TO Simon Says\n\n\n\n\n\n");
				printf("          1          2          3          4\n");
				printf("          O\n\n\n");

				break;
			case 2:
				printf("              Welcome TO Simon Says\n\n\n\n\n\n");
				printf("          1          2          3          4\n");
				printf("                     O\n\n\n");

				break;
			case 3:
				printf("              Welcome TO Simon Says\n\n\n\n\n\n");
				printf("          1          2          3          4\n");
				printf("                                O\n\n\n");

				break;
			case 4:
				printf("              Welcome TO Simon Says\n\n\n\n\n\n");
				printf("          1          2          3          4\n");
				printf("                                           O\n\n\n");

				break;
			}
			Sleep(500);

			system("cls");
			printf("              Welcome TO Simon Says\n\n\n\n\n\n");
			printf("          1          2          3          4\n\n\n\n");
			Sleep(100);
		}

		printf("Enter The Game Input : ");

		for (int i = 0; i < rounds; i++)
		if (scanf_s("%d", &arrPlayer[i]) != 1) {
			printf("Invalid Input :- Re-Enter The Int : ");
			scanf_s("%c");
			i--;
			continue;
		}

		fprintf(p, "\nRNG input : ");
		for (int i = 0; i < rounds; i++)
			fprintf(p, "%d", arrRNG[i]);

		fprintf(p, "\nPlayer input : ");

		for (int i = 0; i < rounds; i++)
			fprintf(p, "%d", arrPlayer[i]);


		for (int i = 0; i < rounds; i++)
			if (arrRNG[i] != arrPlayer[i]) {
				printf("You Lose");
				fclose(p);
				Sleep(500);
				return;
			}

		if (rounds == 9) {
			printf("You Win");
			fclose(p);
			Sleep(500);
			return;
		}

		rounds++;
	}
	_getch();
}
