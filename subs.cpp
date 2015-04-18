#include <cstdio>
#include <algorithm>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
const int MAXN = 1000005;

int N, index, index2=1, best;
char maxChar, S[MAXN];
bool control;

//CLASSE CREATA DA EDOARDO MORASSUTTO :)
class FileReader {
	private:
	FileReader(const FileReader& fr) {}
	
	int maxBufferSize, bufferSize, bufferPointer;
	int fileNo;
	char* buffer;
	
	/** 
	 * Load the buffer and replace the old one
	 */
	void loadBuffer() {
		bufferSize = read(fileNo, buffer, maxBufferSize);
		// reset the pointer to the begin
		bufferPointer = 0;
	}
	/**
	 * Get the next char from the buffer, if the buffer finish reload it
	 */ 
	inline char nextChar() {
		// reload the buffer if needed
		if (bufferPointer >= bufferSize) 
			loadBuffer();
		
		return buffer[bufferPointer++];
	}
	/**
	 * Skip all spaces (spaces, end line, tabulation). If the file finish
	 * return false
	 */ 
	bool skipSpaces() {
		char c;
		while (((c = nextChar()) == ' ' || c == '\n' || c == '\t') && c != '\0') 
			;
		if (c == '\0')
			return 0;
		// un-get the last chat
		bufferPointer--;
		return 1;
	}
	
	public:
	/**
	 * Load the file and the buffer
	 * _name is the file name
	 * _bufferSize is the maximum amuount of memory used for the buffer
	 */ 
	FileReader(const char* _name, int _bufferSize = 150000) {
		buffer = (char*)malloc(_bufferSize);
		fileNo = open(_name, O_RDONLY);
		maxBufferSize = _bufferSize;
		
		loadBuffer();
	}
	/**
	 * Load from a file descriptor
	 * _fileNo is the file descriptor (must be opened in read mode! try STDIN_FILENO ;)
	 * _bufferSize is the maximum amount of memory used for the buffer
	 */ 
	FileReader(int _fileNo, int _bufferSize = 150000) {
		buffer = (char*)malloc(_bufferSize);
		fileNo = _fileNo;
		maxBufferSize = _bufferSize;
		
		loadBuffer();
	}
	/**
	 * Release the buffer
	 */ 
	~FileReader() {
		free(buffer);
		close(fileNo);
	}
	
	/**
	 * Read the next integer from the buffer. Negative numbers are allowed
	 */ 
	int readInt() {
		int n = 0, mul = 1;
		char c;
		
		// if the file ends there isn't a number. So yeah
		if (!skipSpaces()) abort();
		
		// try to parse the sign
		c = nextChar();
		if (c == '+' || c == '-')
			mul = (c == '+') ? 1 : -1;
		else // if the sign is not present, un-get the read char
			bufferPointer--;
		
		do {
			c = nextChar();
			if (c >= '0' && c <= '9')
				n = n*10 + (c-'0');
		} while (c >= '0' && c <= '9');
		return n * mul;
	}
	
	/**
	 * Read a long long from the buffer. Negative #s are ok!
	 */ 
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
	
	/**
	 * Read a double from the buffer. Formats allowed are:
	 *  0.1
	 *  1
	 *  -1
	 *  -1.0
	 *  .0
	 *  -.0
	 */ 
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
		
		// if there is the dot
		if (dotpos > 0) 
			for (; dotpos < i-1; dotpos++)
				n /= 10.0;
		
		return n * mul;
	}
	
	/**
	 * Read a string from the buffer. Spaces, tabs, endlines, EOF 
	 * terminate the string
	 */ 
	int readString(char* str) {
		// no string, no party
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
	
	/**
	 * Read a single char (skipping spaces before)
	 */ 
	char readChar() {
		if (!skipSpaces())
			return '\0';
		return nextChar();
	}
};

int main()
{
    freopen("output.txt","w",stdout);
    
    FileReader fr("input.txt");
    
    N=fr.readInt();
    maxChar=S[0]=fr.readChar();
    
    for(int i=1; i<N; i++){
    	S[i]=fr.readChar();
    	S[++index]=S[i];
    	if(S[i]>maxChar){
    		best=i;
    		index=0;
    		index2=1;
    		S[index]=maxChar=S[i];
    		control=false;
    	}
    	if(control){
    		if(S[i]<S[index2]){
    			index2=1;
    			control=false;
    		}
    		else{
    			if(S[i]==S[index2]) index2++;
    			else{
    				S[index2]=S[i];
    				best=i-index2;
    				index=index2;
    				index2=1;
    				control=false;
    			}
    		}
    		
    	}
    	if(S[i]==maxChar && best != i) control=true;
    }
    
    printf("%d\n",best);
    
    return 0;
}
