// String.cpp

#include "String.hpp"


//=============================================================
String::String(int n) {
	if (n < 0) {
		throw -1;
	}
	if (n == 0) {
		str_ = nullptr;
		size_ = n;
		return;
	}
	size_ = n + 1;
	str_ = new char[size_] {};
	str_[size_ - 1] = '\0';
}

//==============================================================

String::String(const String& str) {
	size_ = str.size_;
	str_ = new char[size_] {};

	for (int i = 0; i < size_; ++i) {
		str_[i] = str.str_[i];
	}
}

//================================================================

String::String(const char* str)
{
	if (str == nullptr) {
		str_ = nullptr;
		size_ = {};
		return;
	}

	str_ = new char[size_] {};
	
	int length{}; // хранит длину переданной строки
	// определяем длину переданной строки
	while (str[length] != '\0') {
		++length;
	}
	
	size_ = length + 1; // увеличиваем размер чтобы хранить символ конца строки
	str_ = new char[size_] {};
	
	for (int i = 0; i < length; ++i) {
	
	}
	str_[size_ - 1] = '\0';
}

//========================================================================

String& String::operator=(const String& other)
{
	clear();

	if (size_ >= other.size_) {
		for (int i = 0; i < other.size_; ++i) {
			str_[i] = other.str_[i];
		}
		return *this;
	}
	for (int i = 0; i < size_; ++i) {
		str_[i] = other.str_[i];
	}
		return *this;
	// TODO: insert return statement here
}


//========================================================================
String& String::operator=(const char* str)
{
	if (str == nullptr) {
		str_ = nullptr;
		size_ = {};
		return *this;
	}

	clear();

	int index{};
	while (str[index] != '\0' && index < size_ - 1) {
		str_[index] = str[index];
		++index;
	}
	str_[size_ - 1] = '\0';

	return *this;
}


//========================================================================

std::ostream& operator<<(std::ostream& out,const String& str)
{
	for (int i = 0; i < str.get_size(); ++i) {
		out << str.str_[i];
	}
	return out;
}


//=========================================================================
std::istream& operator>>(std::istream& in,String& str)
{
	
	int count{};
	char sym{};
	// с помощью данного цикла сохраняем пользовательский ввод в наш объект строки
	// если пользователь ввел возврат строки раньше чем размер строки, то сохраняется вся строка
	// если пользовательь ввел больше символов, чем размер строки, то сохраняется часть символов раваная 
	// размеру строки
	while (sym != '\n') {
		in.get(sym);
		if (count < str.size_ - 1) {
			str.str_[count] = sym;
			count += 1;
		}		
	}
	
	str.str_[str.size_ - 1] = '\0';

	
	
	return in;
}


// =========================================================================

int String::get_size() const
{
	return size_ - 1;
}

void String::put_size(int size)
{
	char* tmp = new char[size+1] {};
	if (size >= size_) {
		for (int i = 0; i < size_; ++i) {
			tmp[i] = str_[i];
		}
		delete[] str_;
		str_ = tmp;
		size_ = size + 1;
		return;
	}

	for (int i = 0; i < size; ++i) {
		tmp[i] = str_[i];
	}
	delete[] str_;
	str_ = tmp;
	size_ = size + 1;

}


//============================================================================
void String::clear()
{
	for (int i = 0; i < size_ - 1; ++i) {
		str_[i] = {};
	}
}
