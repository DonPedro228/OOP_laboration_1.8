#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <bitset>
using namespace std;

class Set
{

public:
	class BitString
	{
	private:
		unsigned long field_1;
		unsigned long field_2;
	public:
		BitString() : field_1(0), field_2(0) {}
		BitString(unsigned long f1, unsigned long f2) : field_1(f1), field_2(f2) {}

		unsigned long getField_1() const { return field_1; }
		unsigned long getField_2() const { return field_2; }

		void setField_1(unsigned long value) { field_1 = value; }
		void setField_2(unsigned long value) { field_2 = value; }

		void Init(unsigned long value1, unsigned long value2);
		void Read();
		void Display() const;
		string toString() const;

		BitString And_Operation(const BitString& other);
		BitString Or_Operation(const BitString& other) const;
		BitString Xor_Operation(const BitString& other);
		BitString Not_Operation(const BitString& other);
		BitString ShiftRight(int bits) const;
		BitString ShiftLeft(int bits) const;
	};

	Set() {};

	void Add_Element(int element);
	Set& Remove_Element(int element);

	Set Union_Set(const Set& other) const;
	Set Interest_Set(const Set& other) const;

	Set difference_Set(const Set& other) const;

	unsigned long getField_1() const { return data.getField_1(); }
	unsigned long getField_2() const { return data.getField_2(); }

	void setField_1(unsigned long value) { data.setField_1(value); }
	void setField_2(unsigned long value) { data.setField_2(value); }
	void Init(unsigned long value1, unsigned long value2);
	void Read();
	void Display() const;
	string toString() const;
	BitString ShiftRight(int bits) {
		return data.ShiftRight(bits);
	}

	BitString ShiftLeft(int bits) {
		return data.ShiftLeft(bits);
	}

	Set& operator=(const BitString& other) {
		data = other;
		return *this;
	}
private:
	BitString data;
};