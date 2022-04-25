#include <iostream>
#include<ctime>
using namespace std;

class Stack
{
private:
	int size;
	int* data;
	int* data2;
public:
	Stack(int valuesize)
	{
		size = valuesize;
		data = new int[size];
		data2 = new int[size + 1];
		for (int i = 0; i < size; i++)
		{
			data[i] = rand() % 20;
		}
	}
	void PrintStack()
	{
		for (int i = 0; i < size; i++)
		{
			cout << data + i << "\t";
			cout << data[i] << endl;
		}
	}
	void push_back(int value)
	{
		for (int i = 0; i < size; i++)
		{
			data2[i] = data[i];
		}
		data2[size] = value;
		size++;
		data = data2;
		cout << "Добавляю введенное значение в конец массива!" << endl;
	}
	~Stack()
	{
		delete[] data;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int a;
	cout << "Введите размер массива: ";
	cin >> a;
	cout << endl;

	Stack Massiv(a);
	Massiv.PrintStack();

	int b;
	cout << "Введите число для добавления в конец массива: ";
	cin >> b;
	cout << endl;

	Massiv.push_back(b);
	Massiv.PrintStack();

	return 0;
}