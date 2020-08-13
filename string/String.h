#ifndef __STRING_H__
#define __STRING_H__

#ifndef NDEBUG
/*debug�汾*/
#define DEBUG 1
#else
/*release�汾*/

#ifdef _WIN32
/*����Windows����ʾ�Ķ��లȫ����*/
#define _CRT_SECURE_NO_WARNINGS
#endif //!_WIN32

#define DEBUG 0
#endif // !NDEBUG

#include <iostream>
#include <cstring>
#include <cstdlib>

/*���뻺������С*/
#define BUFFSIZE 4096

class String
{
private:
	/*�������*/
	static size_t string_total;
	/*�ַ���������*/
	mutable char* buffer;
	/*�ַ�����ʵ����'\0'��������*/
	mutable size_t real_len;
	/*�ַ�������*/
	mutable size_t capacity;

	/*�Զ�����buffer������*/
	char* auto_alloc(const char* str1, const char* str2 = nullptr, bool is_free = true) const;
	char* auto_alloc(const int strlen1, const int strlen2 = 0, bool is_free = true) const;

	/*String���������ú���*/
	String& string_subtraction(const char* str);
public:
	/*has-a��ϵ*/
	class iterator {
	public:
		iterator();
		iterator(const iterator& iter);
		iterator(char* pointer);
		iterator(iterator&& right);
		~iterator();
		char& operator*() const;
		iterator& operator=(const iterator& iter);
		bool operator!=(const iterator& iter);
		/*������*/
		const iterator operator++(int);
		/*ǰ����*/
		iterator& operator++();
		const iterator operator--(int);
		iterator& operator--();
		iterator operator+(int i) const;
		iterator operator-(int i) const;
		char* get_pointer() const;
	private:
		char* pointer;
	};
	using const_iterator = const iterator;
	/*has-a��ϵ*/
	class reverse_iterator {
	public:
		reverse_iterator();
		reverse_iterator(const reverse_iterator& riter);
		reverse_iterator(char* pointer);
		reverse_iterator(reverse_iterator&& right);
		~reverse_iterator();
		char& operator*() const;
		reverse_iterator& operator=(const reverse_iterator& iter);
		bool operator!=(const reverse_iterator& iter);
		const reverse_iterator operator++(int);
		reverse_iterator& operator++();
		const reverse_iterator operator--(int);
		reverse_iterator& operator--();
		reverse_iterator operator+(int i) const;
		reverse_iterator operator-(int i) const;
		char* get_pointer() const;
	private:
		char* pointer;
	};
	using const_reverse_iterator = const reverse_iterator;

	constexpr static size_t npos = ~0U;

	String::iterator begin();
	String::iterator end();

	String::reverse_iterator rbegin();
	String::reverse_iterator rend();

	static const size_t get_string_total();

	String();
	~String();
	/*�˴��ǵ�ʹ��size_tǿ������ת��*/
	explicit String(const size_t capacity);
	String(const char ch);
	String(const char* str);
	String(const String& str);
	/*�ƶ�����*/
	String(String&& right);

	String& append(const char* str);
	String& append(const char* str, size_t count);
	String& append(const char ch);
	String& append(size_t count, const char ch);
	String& append(const String& str);
	String& append(const String& str, size_t count);

	String& assign(const char* str);
	String& assign(const size_t count, const char ch);
	String& assign(const char* str, const size_t count);
	String& assign(const String& str, const size_t offset, const size_t count);
	String& assign(const String& str);
	String& assign(const String&& str);

	/*����Ҫ��һ������*/
	String& replace(const String::iterator first, const String::iterator last, const char* str);
	String& replace(const String::iterator first, const String::iterator last, const char* str, const size_t count);
	String& replace(const String::iterator first, const String::iterator last, size_t count, const char ch);

	int compare(const size_t off, const size_t on, const char* str);
	int compare(const size_t off, const size_t on, const char* str, const size_t count);
	int compare(const char* str) const;
	int compare(const String& str) const;
	int compare(const size_t off, const size_t on, const String& str) const;
	int compare(const size_t off, const size_t on, const String& str, const size_t roff, const size_t ron) const;

	size_t find(const char ch, const size_t start = 0U) const;
	size_t find(const char* str, const size_t start = 0U) const;
	size_t find(const String& str, const size_t start = 0U) const;
	/*string::find 3��������û������ʲô��˼����������Լ����д��*/
	size_t find(const char* str, const size_t start, const size_t str_start);

	/*���̫����⵽���Ǹ�ʲô�ģ�û��ʵ�ֺ�����*/
	size_t find_first_not_of(const char ch, const size_t start = 0U) const;
	size_t find_first_not_of(const char* str, const size_t start = 0U) const;
	size_t find_first_not_of(const String& str, const size_t start = 0U) const;
	size_t find_first_not_of(const char* str, const size_t start, const size_t str_start);

	void pop_back();
	void push_back(const char ch);
	const char& at(const size_t size) const;
	String substr(const size_t off = 0U, const size_t count = ~0U);
	char& back();
	char& back() const;
	char& front();
	char& front() const;
	size_t max_size() const;
	void clear();
	void swap(String& str);
	size_t copy(char* buffer, size_t count, size_t off = 0U);

	const char* data() const;
	const char* c_str() const;

	bool empty() const;

	String::iterator erase(String::const_iterator first, String::const_iterator last);

	const size_t get_capacity() const;
	const size_t get_length() const;

	void reserve(size_t new_size = 0U);

	String& operator=(const String& str);
	String& operator=(const char* str);
	String& operator=(const char ch);

	String& operator+=(const String& str);
	String& operator+=(const char* str);
	String& operator+=(const char ch);

	String operator+(const String& str);
	String operator+(const char* str);
	String operator+(const char ch);

	String operator-(const String& str);
	String operator-(const char* str);
	String operator-(const char ch);

	String& operator-=(const String& str);
	String& operator-=(const char* str);
	String& operator-=(const char ch);

	String operator*(const size_t count) const;
	String& operator*=(const size_t count);

	bool operator==(const String& str);
	bool operator==(const char* str);

	bool operator>(const String& str);
	bool operator>(const char* str);
	bool operator<(const char* str);
	bool operator<(const String& str);

	/*explicit�ر���ʽת������ǿ������ת��Ϊ(wchar_t *)�ǵ��Զ��ֶ��ͷ��ڴ�*/
	explicit operator wchar_t* () const;
	/*����string���ȣ�ͬ��*/
	explicit operator size_t() const;
	explicit operator int() const;

	char& operator[](const size_t count);
	const char& operator[](const size_t count) const;

	friend std::ostream& operator<<(std::ostream& out, const String& str);
	friend std::istream& operator>>(std::istream& in, String& str);

	friend String operator+(const char* ch, const String& str);
	friend String operator+(const char ch, const String& str);

	friend String operator-(const char* ch, const String& str);
	friend bool operator==(const String& str1, const String& str2);
};
/*ֱ�ӵ���String * size_t */
String operator*(const size_t count, const String& str);

#endif // !__STRING_H__