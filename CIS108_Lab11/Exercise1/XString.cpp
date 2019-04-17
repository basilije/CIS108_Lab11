#include "Xstring.h"

// initial capacity of XString
#define INITIAL_CAPACITY 256

// value that should be added to the total_capacity variable when there is a known length of the char array, string or Xstring
// also this value shoud be subtracted from the size operand of memset function
#define DELTA_INITIAL_CAPACITY 1

// variable for storing the current XString before the operation
XString old_raw_xString = XString();

// variable to calculate how much chars need to be appended
size_t no_of_chars_to_append;

// the default constructor
XString::XString()
{
	total_capacity = INITIAL_CAPACITY; // default capacity of Xstring
	raw_string = new char[total_capacity];
	memset(raw_string, 0, total_capacity);
}

// the constructor with char* (uses assign method for the same kind of the parameter)
XString::XString(const char* some_char)
{
		XString::assign(some_char);
}

// the constructor with XString& (uses assign method for the same kind of the parameter)
XString::XString(const XString& some_Xstring)
{
		XString::assign(some_Xstring);
}

// the constructor with string& (uses assign method for the same kind of the parameter)
XString::XString(const string& some_string)
{
		XString::assign(some_string);
}

// the constructor with parameter how much charaters should have new XString
XString::XString(size_t xSize)
{
	total_capacity = xSize;
	raw_string = new char[xSize];
	memset(raw_string, 0, xSize);
}

// the constructor
XString::~XString()
{
	free(raw_string); // free the memory used with XString
}

// assign char array to the XString
void XString::assign(const char* char_to_assign)
{
	total_capacity = strlen(char_to_assign) + DELTA_INITIAL_CAPACITY; // total_capacity is larger for DELTA_INITIAL_CAPACITY, then input char* (char with value of str(0) should be at the end)
	raw_string = new char[total_capacity]; // new char array size is size of whole char array with value of str(0) at the end
	memset(raw_string, 0, total_capacity); // set the new char memory range to 0
	memcpy(raw_string, char_to_assign, total_capacity - DELTA_INITIAL_CAPACITY); // copy just the input char array, str(0) is already be at the end
}

void XString::assign(const XString& xString_to_assign)
{
	total_capacity = xString_to_assign.total_capacity; // total_capacity is equal to total_capacity of input XString
	raw_string = new char[total_capacity]; // new char array size is size of whole char array with value of str(0) at the end
	memset(raw_string, 0, total_capacity); // set the new char memory range to 0
	memcpy(raw_string, xString_to_assign.raw_string, total_capacity - DELTA_INITIAL_CAPACITY); // copy just the input char array, str(0) is already be at the end
}

void XString::assign(const string& string_to_assign)
{
	total_capacity = string_to_assign.size() + DELTA_INITIAL_CAPACITY; // total_capacity is larger for DELTA_INITIAL_CAPACITY, then size of input string (char with value of str(0) should be at the end)
	raw_string = new char[total_capacity]; // new char array size is size of whole char array with value of str(0) at the end
	memset(raw_string, 0, total_capacity); // set the new char memory range to 0
	memcpy(raw_string, string_to_assign.data(), total_capacity - DELTA_INITIAL_CAPACITY);  // copy just the data of input string, str(0) is already be at the end
}

// appending the char* to the end of the current XString
void XString::append(const char* char_to_append)
{
	old_raw_xString = XString(raw_string);
	no_of_chars_to_append = strlen(char_to_append);
	total_capacity += no_of_chars_to_append;
	raw_string = new char[total_capacity];
	memset(raw_string, 0, total_capacity);
	memcpy(raw_string, old_raw_xString.raw_string, old_raw_xString.capacity() - DELTA_INITIAL_CAPACITY);
	memcpy(raw_string + old_raw_xString.capacity() - DELTA_INITIAL_CAPACITY, char_to_append, no_of_chars_to_append);
}

// appending the XString to the end of the current XString
void XString::append(const XString& xString_to_append)
{
	old_raw_xString = XString(raw_string);
	no_of_chars_to_append = xString_to_append.total_capacity;
	total_capacity += no_of_chars_to_append;
	raw_string = new char[total_capacity];
	memset(raw_string, 0, total_capacity);
	memcpy(raw_string, old_raw_xString.raw_string, old_raw_xString.capacity() - DELTA_INITIAL_CAPACITY);
	memcpy(raw_string + old_raw_xString.capacity() - DELTA_INITIAL_CAPACITY, xString_to_append.raw_string, no_of_chars_to_append);
}

// appending the string to the end of the current XString
void XString::append(const string& string_to_append)
{
	old_raw_xString = XString(raw_string);
	no_of_chars_to_append = string_to_append.size();
	total_capacity += no_of_chars_to_append;
	raw_string = new char[total_capacity];
	memset(raw_string, 0, total_capacity);
	memcpy(raw_string, old_raw_xString.raw_string, old_raw_xString.capacity() - DELTA_INITIAL_CAPACITY);
	memcpy(raw_string + old_raw_xString.capacity() - DELTA_INITIAL_CAPACITY, string_to_append.data(), no_of_chars_to_append);
}

// returning the total_capacity value through the function
size_t XString::capacity()
{
	return total_capacity;
}

void XString::clear()
{
	total_capacity = 1; // default capacity of empty Xstring
	raw_string = new char[total_capacity];
	memset(raw_string, 0, total_capacity);
}

// return the length of the raw_string variable of current XString
size_t XString::length()
{
	return strlen(raw_string);
}

string XString::str(string& someXstring)
{
	return string(someXstring);
}

