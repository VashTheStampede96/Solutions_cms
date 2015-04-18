#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <list>
#define pb(x) push_back(x)
#define FOR(i,n) for(;i<n;++i)
#define mod(x) (x<0)? -x:x
#define f first
#define s second
#define INF 1e9
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int n, e[100005], p[100005];


// Grazie Edo per la classe <3

class FileReader {
	private:
	FileReader(const FileReader& fr) {}

	int maxBufferSize, bufferSize, bufferPointer;
	int fileNo;
	char* buffer;

	void loadBuffer() {
		bufferSize = read(fileNo, buffer, maxBufferSize);
		bufferPointer = 0;
	}
	inline char nextChar() {
		if (bufferPointer >= bufferSize)
			loadBuffer();

		return buffer[bufferPointer++];
	}
	bool skipSpaces() {
		char c;
		while (((c = nextChar()) == ' ' || c == '\n' || c == '\t') && c != '\0')
			;
		if (c == '\0')
			return 0;
		bufferPointer--;
		return 1;
	}

	public:
	FileReader(const char* _name, int _bufferSize = 150000) {
		buffer = (char*)malloc(_bufferSize);
		fileNo = open(_name, O_RDONLY);
		maxBufferSize = _bufferSize;

		loadBuffer();
	}
	FileReader(int _fileNo, int _bufferSize = 150000) {
		buffer = (char*)malloc(_bufferSize);
		fileNo = _fileNo;
		maxBufferSize = _bufferSize;

		loadBuffer();
	}
	~FileReader() {
		free(buffer);
		close(fileNo);
	}
	int readInt() {
		int n = 0, mul = 1;
		char c;

		if (!skipSpaces()) abort();

		c = nextChar();
		if (c == '+' || c == '-')
			mul = (c == '+') ? 1 : -1;
		else
			bufferPointer--;

		do {
			c = nextChar();
			if (c >= '0' && c <= '9')
				n = n*10 + (c-'0');
		} while (c >= '0' && c <= '9');
		return n * mul;
	}
	long long readLongLong() {
		long long n = 0;
		int mul = 1;
		char c;

		if (!skipSpaces()) abort();

		c = nextChar();
		if (c == '+' || c == '-')
			mul = (c == '+') ? 1 : -1;
		else
			bufferPointer--;

		do {
			c = nextChar();
			if (c >= '0' && c <= '9')
				n = n*10 + (c-'0');
		} while (c >= '0' && c <= '9');
		return n * mul;
	}
	double readDouble() {
		double n = 0;
		int mul = 1, i = 0;
		int dotpos = 0;
		char c;

		if (!skipSpaces()) abort();

		c = nextChar();
		if (c == '+' || c == '-')
			mul = (c == '+') ? 1 : -1;
		else
			bufferPointer--;

		do {
			i++;
			c = nextChar();
			if (c >= '0' && c <= '9')
				n = n*10.0 + (c-'0');
			if (c == '.')
				dotpos = i;
		} while ((c >= '0' && c <= '9') || c == '.');

		if (dotpos > 0)
			for (; dotpos < i-1; dotpos++)
				n /= 10.0;

		return n * mul;
	}
	int readString(char* str) {
		if (!skipSpaces())
			return str[0] = 0;

		char c;
		int l = 0;

		do {
			c = nextChar();
			str[l++] = c;
		} while (c != ' ' && c != '\n' && c != '\t' && c != '\0');
		str[--l] = '\0';
		return l;
	}
	char readChar() {
		if (!skipSpaces())
			return '\0';
		return nextChar();
	}
};

int main()
{
    FileReader fr("input.txt");

	n = fr.readInt();
	for( int i=0; i<n; ++i )
        e[i] = fr.readInt() + i;
	e[n] = n;

	for( int i=0, l=1; i<n+1; ++i )
        while( l<=e[i] ) p[l++] = i;

    int ans = 0, t = n;
    while( t>0 ){
        ++ans;
        t = p[t];
    }

    ofstream out("output.txt");

    out << ans << "\n";

	return 0;
}
