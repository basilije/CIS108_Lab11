#pragma once
#include <iostream>

using namespace std;

class XString
{
	protected:
		char* raw_string;
		size_t total_capacity;

	public:

		XString();
		XString(const char*);
		XString(const XString&);
		XString(const string&);
		XString(size_t);
		~XString();

		void assign(const char*);
		void assign(const XString&);
		void assign(const string&);
		void append(const char*);
		void append(const XString&);
		void append(const string&);
		size_t capacity();
		void clear();
		size_t length();
		string str(string&);
		

};