#include <string.h>

class string {
	char* str;
	int len;
	
public:
	string(char c, int n);
	string(const char* s);
	string(const string& s);
	~string();

	void add_string(const string& s);
	void copy_string(const string& s);
	int strlen();
};

string::string(char c, int n) {
	str = new char[n + 1];
	
	for (int i = 0; i < n; i++) {
		str[i] = c;
	}
	str[n] = '\n';
	len = n;
}

string::string(const char* s) {
	str = new char[sizeof s + 1];
	strcpy_s(str, sizeof s + 1, s);
	len = sizeof str;
}

string::string(const string& s) {
	str = new char[s.len + 1];
	strcpy_s(str, s.len, s.str);
	len = s.len;
}

string::~string() {
	delete[] str;
}

void string::add_string(const string& s) {
	char* new_str = new char[len + s.len + 1];

	for (int i = 0; i < len; i++) {
		new_str[i] = str[i];
	}
	for (int i = len; i < len + s.len; i++) {
		new_str[i] = s.str[i];
	}
	new_str[len + s.len] = '\n';
	delete[] str;
	str = new_str;
	len += s.len;
}

void string::copy_string(const string& s) {
	delete[] str;
	str = new char[s.len + 1];

	for (int i = 0; i < s.len + 1; i++) {
		str[i] = s.str[i];
	}
	str[s.len] = '\n';
	len = s.len;
}

int string::strlen() {
	return len;
}
