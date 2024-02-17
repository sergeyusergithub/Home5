// main.cpp

#include "String.hpp"
#include <iostream>



int main() {

	// создание объекта строка пустого, размером 80 символов
	String str;

	// выводим размер пустой строки, проверяем, что строки имеет размер 80
	std::cout << "Empty string has size: " << str.get_size() << std::endl;

	// заполняем пустую строку константной строкой
	str = "Hello new string!";

	// выводим содержимое строки размер строки не уменьшился
	std::cout << "Const string is: " << str << ". String size is: " << str.get_size();
	std::cout << "\n\n";

	// заполняем пустую строку константной строкой более допустимого размера
	str = "Hello new string! 1.ha-ha-ha! 2.ha-ha-ha! 3.ha-ha-ha! 4.ha-ha-ha! 5.ha-ha-ha! 6.ha-ha-ha!  \
		7.ha-ha-ha! 8.ha-ha-ha! 9.ha-ha-ha! 10.ha-ha-ha!";

	// выводим содержимое строки
	std::cout << "Const string is: " << str << " \nThis string has new size: " << str.get_size();
	std::cout << "\n\n";

	// создание объекта строки заданного размера
	String str1(70);

	// выводим размер созданного объекта строки
	std::cout << "Size new empty string is: " << str1.get_size() << "\n\n";

	// копируем содержимое одной строки в другую строку
	str1 = str;


	// выводим содержимое новой строки
	std::cout << "Conten of copy string is: " << str1 << " \nSize this string is: " << str1.get_size() << "\n\n";

	// изменим размер строки
	str1.put_size(130);

	// заполняем строку нового размера
	str1 = "Hello new string! 1.ha-ha-ha! 2.ha-ha-ha! 3.ha-ha-ha! 4.ha-ha-ha! 5.ha-ha-ha! 6.ha-ha-ha! 7.ha-ha-ha! 8.ha-ha-ha! 9.ha-ha-ha! 10.ha-ha-ha!";

	// выводим содержимое строки и его размер
	std::cout << "Conten of copy string is:\n" << str1 <<  " \nSize this string is: " << str1.get_size() << "\n\n";



	return 0;
}

