
// can recognize -23, 5, etc

#include <iostream>
#include <climits>

using namespace std;

class Solution {
	public:
		bool isDigit(char c) {
			return ( c>='0' && c<='9' );
		}

		int atoi(const char *str) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function

			long long ret = 0;
			char c;
			int i = 0;
			int sign = 1;

			// first char, - or digit
			c = str[i];

			// skip white spaces
			while (c == ' ') {
				c = str[++i];
			} 

			//check if there is a sign
			if (c == '-') {
				sign = -1;
				i++;
			} else if (c== '+') {
				i++; 
			} else if ( !isDigit(c) ) {
				return 0;
			}

			//cout<<"sign="<<sign<<endl;

			while (true) {
				c = str[i++];
				//cout<<"c="<<c<<"("<<(int)c<<")"<<endl;

				if (c==0 || !isDigit(c)) { 
					//cout<<"in"<<endl;
					break; 
				} else if (!isDigit(c)) {
					return 0;
				} else {
					ret = ret*10 + c - '0';
				}
				//cout<<"ret="<<ret<<endl;
			}


			//cout<<"sign="<<sign<<endl;
			//cout<<"ret="<<ret<<endl;

			if (sign==1 && ret>(long long)INT_MAX) {
					return INT_MAX;
			} else if (sign==-1 && ret>(long long)INT_MAX+1) {
					return INT_MIN;
			}

			//cout<<"sign*ret="<<sign*ret<<endl;
			return sign*ret;
		}
};

int main(int argc, char** argv) {
	////cout<<"max int = "<<INT_MAX<<endl;
	Solution s;
	//unsigned int r = s.atoi(argv[1]); 
	////cout<<"main: r="<<r<<endl;
	//cout<<"main: "<<s.atoi(argv[1])<<endl;
	return 0;
}




