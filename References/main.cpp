#include <iostream>
// Кодировка UTF-8

template <typename T> // 1-я ф-ция не работает
void my_swap(T a, T b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> // 2-я уже работает, через разыменование указателей
void p_swap(T* a, T* b) {
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

template <typename T> // 3-я - копия std::swap()
void ref_swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

int MX[10][2];
int& func(int index) {
	return MX[index][1];
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	
	std::cout << "Ввод в массив.\n";
	for (int i{}; i < 10; i++) {
		std::cout << "Введите " << i + 1 << "-й элемент -> ";
		std::cin >> MX[i][0];
		func(i) = MX[i][0];
	}

	std::cout << "Итоговый массив:\n";
	for (int i{}; i < 10; i++)
		std::cout << MX[i][0] << "\t" << func(i) << "\n";



	// Ссылки - параметры функций
	/*
	n = 10; m = 15;
	
	
	std::cout << n << " " << m << std::endl;
	//p_swap(&n, &m); // работает, но неудобно, т.к. нужно передавать адреса
	ref_swap(n, m); // передаем переменную
	std::cout << n << " " << m << std::endl;
	*/
	
	
	// Cсылки 
	/*
	// & - амперсант

	// Ссылка не может быть объявлена без инициализации.

	n = 10; m = 20;
	int& refn = n; // Ссылка, ассоциирующаяся с переменной n
	std::cout << "refn = " << refn << std::endl;
	refn = m;
	std::cout << "refn = " << refn << std::endl;
	std::cout << "n = " << n << std::endl;

	// Примечания:
	//	1) Ссылки всегда обязательно инициализируются. Нет аналога нейтрального указателя.
	//	2) Не существует операторов для работы над ссылкой. Все операции проводятся над объектом, с которым ссылка ассоциируется.
	//	3) Ссылка это обращение напрямую к памяти (разыменование указателя). Т.е. ссылка - псевдоним переменной. 
	*/










	return 0;
}