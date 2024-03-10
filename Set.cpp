#include "Set.h"
#include <iostream>
#include <bitset>
#include <sstream>
#include <string>
#include <intrin.h>
using namespace std;

void Set::BitString::Init(unsigned long value1, unsigned long value2)
{
	setField_1(value1);
	setField_2(value2);
}

void Set::BitString::Read()
{
	unsigned long number1, number2;

	cout << "Enter first number: ";
	cin >> number1;

	cout << "Enter second number: ";
	cin >> number2;

	if (number1 > 31) {
		field_2 = 1UL << (number1 - 32);
		field_1 = 0;
	}
	else {
		field_1 = 1UL << number1;
		field_2 = 0;
	}

	if (number2 > 31) {
		field_2 |= 1UL << (number2 - 32);
	}
	else {
		field_1 |= 1UL << number2;
	}

	Init(field_1, field_2);
}

void Set::BitString::Display() const
{
	cout << "Field_1: " << bitset<64>(field_1) << endl;
	cout << "Field_2: " << bitset<64>(field_2) << endl;
}

string Set::BitString::toString() const
{
	return bitset<64>(field_1).to_string() + " " + bitset<64>(field_2).to_string();
}

string Set::toString() const
{
    return data.toString();
}

void Set::Init(unsigned long value1, unsigned long value2)
{

    data.Init(value1, value2);
}

void Set::Display() const
{
    data.Display();
}

void Set::Read()
{
    data.Read();
}

Set::BitString Set::BitString::And_Operation(const BitString& other)
{
	BitString r;
	r.field_1 = field_1 & other.field_1;
	r.field_2 = field_2 & other.field_2;
	return r;
}

Set::BitString Set::BitString::Or_Operation(const BitString& other) const
{
	BitString r;
	r.field_1 = field_1 | other.field_1;
	r.field_2 = field_2 | other.field_2;
	return r;
}

Set::BitString Set::BitString::Xor_Operation(const BitString& other)
{
	BitString r;
	r.field_1 = field_1 ^ other.field_1;
	r.field_2 = field_1 ^ other.field_2;
	return r;
}

Set::BitString Set::BitString::Not_Operation(const BitString& other)
{
	BitString r;
	r.field_1 = ~other.field_1;
	r.field_2 = ~other.field_2;
	return r;
}


Set::BitString Set::BitString::ShiftRight(int bits) const {
	unsigned long new_field_1, new_field_2;

	if (bits >= 64) {
		return BitString();
	}
	else if (bits >= 32) {
		new_field_1 = 0;
		new_field_2 = field_1 >> (bits - 32);
	}
	else {
		new_field_2 = (field_2 >> bits) | (field_1 << (32 - bits));
		new_field_1 = field_1 >> bits;
	}

	return BitString(new_field_1, new_field_2);
}

Set::BitString Set::BitString::ShiftLeft(int bits) const {
	unsigned long new_field_1, new_field_2;

	if (bits >= 64) {
		return BitString();
	}
	else if (bits >= 32) {
		new_field_1 = field_2 << (bits - 32);
		new_field_2 = 0;
	}
	else {
		new_field_1 = (field_1 << bits) | (field_2 >> (32 - bits));
		new_field_2 = field_2 << bits;
	}

	return BitString(new_field_1, new_field_2);
}

void Set::Add_Element(int element) {
	if (element >= 0 && element < 32)
		data = data.Or_Operation(BitString(1UL << element, 0));
	else if (element >= 0 && element < 64)
		data = data.Or_Operation(BitString(0, 1UL << (element - 64)));
	else
		cout << "Element out of range" << endl;
}

Set& Set::Remove_Element(int element)
{
	if (element >= 0 && element < 32) {
		data.setField_1(data.getField_1() & ~(1UL << element));
	}
	else if (element >= 0 && element < 64) {
		data.setField_2(data.getField_2() & ~(1UL << (element - 64)));
	}
	else {
		cout << "Element out of range" << endl;
	}

	return *this;
}

Set Set::Union_Set(const Set& other) const
{
	Set result;
	result.data = data.Or_Operation(other.data);
	return result;
}

Set Set::Interest_Set(const Set& other) const
{
	Set result;
	BitString intersection_field(data.getField_1(), data.getField_2());
	intersection_field.And_Operation(other.data);
	result.Init(intersection_field.getField_1(), intersection_field.getField_2());
	return result;
}

Set Set::difference_Set(const Set& other) const
{
	Set result;
	result.Init(data.getField_1() & ~other.data.getField_1(), data.getField_2() & BitString().Not_Operation(other.data).getField_2());
	return result;
}