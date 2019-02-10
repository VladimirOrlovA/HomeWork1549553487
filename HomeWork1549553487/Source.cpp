#include<iostream>
#include<locale.h>
#include<time.h>
#include<Windows.h>


using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void FillArrayOrder(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = i;
}


void FillArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = 0 + rand() % 9;
}

void FillArray(float arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = float(1 + rand() % 5) / (2 + rand() % 3);
		arr[i] = float(int(arr[i] * 100) % 100) / 100;
	}
}

void FillArray(char arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 256;
}


void PrintArray(int arr[], int n)
{
	cout << "\nIndex ->\t";
	for (int i = 0; i < n; i++)
		cout << i << "  ";

	cout << "\nElements ->\t";
	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";

	cout << endl << endl;
}

void PrintArray(float arr[], int n)
{
	cout << "\nIndex ->\t";
	for (int i = 0; i < n; i++)
		cout << i << "  ";

	cout << "\nElements ->\t";
	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";

	cout << endl << endl;
}

void PrintArray(char arr[], int n)
{
	cout << "\nIndex ->\t";
	for (int i = 0; i < n; i++)
		cout << i << "  ";

	cout << "\nElements ->\t";
	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";

	cout << endl << endl;
}

template<typename T>
void SearchMax(T arr[], int n, T x)
{
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > x) count++;
	}

	cout << "Кол-во элементов больше " << x << " =>  " << count << endl << endl;
}

template<typename T>
void SearchMaxArrPosition(T arr[], int &n)
{
	
	int max = 0, ind, i = 0;

	for (i; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			ind = i;
		}
	}

	cout << "Максимальный элемент массива A[" << ind <<"]="<< arr[ind]<< endl << endl;
}

template<typename T>
void SearchNullArrPosition(T arr[], int &n)
{

	int ind, i = 0;

	cout << "\nНулевые элементы массива -> \n";

	for (i; i < n; i++)
	{
		if (arr[i] == 0)
		{
			ind = i;
			cout << "\n A[" << ind << "]= " << arr[ind]<<endl;
		}
	}


	cout << endl << endl;
}

template<typename T>
void ReorderingArray(T arr[], int n)
{
	T c;
	for (int i = 0; i < n / 2; i++)
	{
		c = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = c;
	}
}

void InvertDigits(int& k)
{
	int buf, i = 0, s = 0;

	buf = k;

	// Определяем разрядность числа для последующего перевода цифр в обратном порядке

	while (buf > 0)
	{
		buf /= 10;
		i++;
	}

	// Переводим введенное число в обратном порядке

	while (i >= 0)
	{
		if (k % 10 == 0) k *= 10;
		s += k % 10 * pow(10, i - 1);
		k /= 10;
		i--;
	}

	cout << "Invert number \t\t" << s << endl;

}

void AddRightDigit(int& k, int d)
{

	// Добавляем к введенному числу k справа число d

	k = k * 10 + d;

	cout << "\nAdded digit to the number \t" << k << endl;

}

void AddLeftDigit(int& k, int d)
{
	// Определяем разрядность числа для последующего подстановки цифры слева

	int b, i = 0;

	b = k;
	while (b > 0)
	{
		b /= 10;
		i++;
	}

	// Добавляем к введенному числу k слева число d

	k += (pow(10, i) * d);

	cout << "\nAdded digit to the number \t" << k << endl;

}

void XexpY(int x, int y)
{
	int b = 1, i = 0;

	while (y > i)
	{
		if (y == 0) b = 1;
		else b *= x;
		i++;
	}
	cout << "\nРезультат возведения в степень -> \t"<<b;
}


void Task1()
{
	/*1.	**Напишите шаблон функции, которая осуществляет поиск максимального элемента в массиве.Функция возвращает позицию 
		элемента и его значение.Рекомендации: Воспользуйтесь передачей параметров по ссылке.*/

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);
		
	int n;
	cout << "\nВведите размерность массива -> ";
	cin >> n;
	int *arr = new int[n];

	FillArray(arr, n);
	PrintArray(arr, n);
	SearchMaxArrPosition(arr, n);
	
}

void Task2()
{
	/*2.	**Напишите шаблон функции, которая принимает массив, и выводит на экран позиции нулевых элементов массива.*/

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	int n;
	cout << "\nВведите размерность массива -> ";
	cin >> n;
	int *arr = new int[n];

	FillArray(arr, n);
	PrintArray(arr, n);
	SearchNullArrPosition(arr, n);
	

}

void Task3()
{
	/*3.	**Напишите шаблон функции, которая принимает x и y и вычисляет x в степени y.Y – целое число.*/

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask3\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	int x, y;
	char flag = 'n';

	do
	{
		int check = 1;
		cout << "\nВведите возводимое число в степень -> \t";
		cin >> x;
		do
		{
			cout << "\nВведите степень -> \t\t\t";
			cin >> y;

			if (y >= 0) check = 0;
			else cout << "\nВы ввели отрицательное число степени. Попробуйте еще раз... \n" << endl;

		} while (check);

	
		XexpY(x, y);

		cout << "\n\nВы хотите повторить? (y/n) -> ";
		cin >> flag;

	} while (flag == 'y');

}


int main()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n  07_02_2019  1549553487 \n\n";
	SetConsoleTextAttribute(hConsole, 7);
	

	setlocale(LC_ALL, "");
	srand(time(NULL));

	int number;
	char flag;

	do
	{
		cout << endl << "Enter number of Task (1) to (3) => ";
		cin >> number;

		switch (number)
		{
		case 1: {Task1(); } break;
		case 2: {Task2(); } break;
		case 3: {Task3(); } break;

		default: cout << "\nEntered number of Task does not exist...\n\n";

		}

		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n--------------------------------------------------------------------------\n\n";
		SetConsoleTextAttribute(hConsole, 7);

		cout << "Do you want to continue? \n\nIf YES press (y) if NO any keys => ";
		cin >> flag;

	} while (flag == 'y');
}
