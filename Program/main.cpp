#include <iostream>
#include <iomanip>
using namespace std;

void draw_line(int size, const char& c = '-') {
	for (--size; size >= 0; size--)
		cout << c;
	cout << endl;
}

// 1 funcs

int myrand(const int& min, const int& max) {
	return min > 0 ?
		rand() % (max - min + 1) + min :
		rand() % (abs(min) + max + 1) + min;
}

void full_mass(int* mass, int size, const int* dia) {
	for (--size; size >= 0; size--)
		mass[size] = myrand(dia[0], dia[1]);
}

void draw_mass(const int* mass, const int& size, const int& c_space) {
	draw_line(size * c_space + 2);
	for (int i = 0; i < size; i++)
		cout << "|" << setw(c_space - 1) << mass[i];
	cout << " |" << endl;
	draw_line(size * c_space + 2);
}

int max_(int* mass, int size) {
	int max_i = 0;
	for (--size; size > 0; --size)
		if (mass[max_i] < mass[size])
			max_i = size;
	return mass[max_i];
}

// 2 tmpl func

template <typename T>
T myrand_(const T& min, const T& max) {
	return (T)(min > 0 ?
		rand() % (max - min + 1) + min :
		rand() % (abs(min) + max + 1) + min);
}

template <typename T>
void full_mass_(T* mass, int size, const T* dia) {
	for (--size; size >= 0; size--)
		mass[size] = myrand_(dia[0], dia[1]);
}

template <typename T>
void draw_mass_(const T* mass, const int& size, const int& c_space) {
	draw_line(size * c_space + 2);
	for (int i = 0; i < size; i++)
		cout << "|" << setw(c_space - 1) << mass[i];
	cout << " |" << endl;
	draw_line(size * c_space + 2);
}

template < typename T >
T max__(T* mass, int size) {
	int max_i = 0;
	for (--size; size > 0; --size)
		if (mass[max_i] < mass[size])
			max_i = size;
	return mass[max_i];
}

void main() {
	srand(time(NULL));
	const int c_space = 4; // кількість містя яке виділяєьбся на одну комірку массиву, при виводі в консоль
	int dia[2], n; // діапазон, n

	cout << "n = "; cin >> n;
	cout << "dia start = "; cin >> dia[0];
	cout << "dia end = "; cin >> dia[1];

	int* mass = new int[n];

	cout << "1 // funcs" << endl;
	full_mass(mass, n, dia);
	draw_mass(mass, n, c_space);
	cout << "max: " << max_(mass, n) << endl;

	cout << "2 // tmpl funcs" << endl;
	full_mass_(mass, n, dia);
	draw_mass_(mass, n, c_space);
	cout << "max tmpl: " << max__<int>(mass, n) << endl;

	delete[] mass;
}