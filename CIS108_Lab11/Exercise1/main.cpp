#include "Xstring.h";

int main()
{
	// testing generation of XString with no parameters
	XString xs1 = XString();

	// testing generation of XString with char*
	XString xs2 = XString("tralala");

	// testing generation of XString with size parameter
	XString xs3 = XString(1);

	string some_string = "some string";
	// testing generation of XString with string
	XString xs4 = XString(some_string);

	// trying to read capacities through the function
	size_t xs1c = xs1.capacity();
	size_t xs2c = xs2.capacity();
	size_t xs3c = xs3.capacity();
	size_t xs4c = xs4.capacity();

	// testing adding string to the XString
	string hm = "hm";
	string some = xs3.str(hm);

	// testing adding char* to the XString
	xs2.append("ojojojo");
	// testing adding XString to the XString
	xs2.append(XString("que?"));

	// testing adding XString to the XString
	xs2.append(string(" pasa!"));

	// testing adding char* to the XString to the default XString
	xs1.append(" _-after 256-_ ");
	xs1c = xs1.capacity();

	return 0;
}