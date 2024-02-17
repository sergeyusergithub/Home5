// String.hpp

#pragma once

#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>


class String {
public:
	// конструктор по умолчанию, создает строку длинной 80
	String() :String(80) {	}

	// конструктор с параметром, задающим размер создаваемой строки
	String(int n);

	// конструктор копирования
	String(const String& str);

	// конструктор принимающий строку от пользователя
	String(const char* str);

	// деструктор
	~String() {
		delete[] str_;
		size_ = {};
	}

	// оператор присваивания копированием
	String& operator=(const String& other); 

	// оператор присваивания копирование константой строки
	String& operator=(const char* str);


	// оператор потокового вывода строки
	friend std::ostream& operator << (std::ostream& out,const String& str);

	// оператор потокового ввода строки, длина строки определяется, длиной при создании объекта строки
	friend std::istream& operator >> (std::istream& in, String& str);


	// метод возвращающий размер строки
	int get_size() const;

	// метод получающий размер строки
	void put_size(int size);

private:
	char* str_;
	int size_;
	// метод очистки строки
	void clear();
};


#endif // #ifndef STRING_HPP
 
