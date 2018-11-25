#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

inline void in(long long int &n) {
	n = 0;
	int ch = getchar_unlocked(); int sign = 1;
	while (ch < '0' || ch > '9') { if (ch == '-')sign = -1; ch = getchar_unlocked(); }

	while (ch >= '0' && ch <= '9')
		n = (n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked();
	n = n * sign;
}

int main(){
	long long int a ,b;
	std::string sa, sb;
	std::string fileName;
	std::string execFile;
	std::string compile;
	std::string execute;
	std::ofstream suma;
	std::ofstream comp;
	std::ofstream exec;
	INI:
	in(a);
	in(b);
	(a+b)? ({goto EXEC;}) : ({goto FIN;});
	EXEC:
	sa = std::to_string(a);
	sb = std::to_string(b);
	fileName = sa + '0';
	fileName += "+";
	fileName += sb + '0';
	fileName += ".cpp";
	execFile = sa + '0';
	execFile += "+";
	execFile += sb + '0';
	suma.open(fileName);
	(suma.is_open())? ({goto File_open;}) : ({goto File_not_open;});
	File_open:
	suma << "#include <iostream>\n inline void out(int n) {int N = n, rev, count = 0; rev = N; if (N == 0) { putchar_unlocked('0'); return; } while ((rev % 10) == 0) { count++; rev /= 10; } rev = 0; while (N != 0) { rev = (rev << 3) + (rev << 1) + N % 10; N /= 10; } while (rev != 0) { putchar_unlocked(rev % 10 + '0'); rev /= 10; } while (count--) putchar_unlocked('0');}\n int main(){int a = " << a << ";  int b = " << b << "; int res = a + b; out(res); std::cout << std::endl; return 0;}";
	suma.close();
	compile = "g++ -Wall -O ";
	compile += fileName;
	compile += " -o ";
	compile += execFile;
	comp.open("compile.cpp");
	(comp.is_open())? ({goto Compile_open;}) : ({goto File_not_open;});
	Compile_open:
	comp << "#include <stdlib.h>\nint main(){system(";
	comp << '"';
	comp << compile;
	comp << '"';
	comp << ");return 0;}";
	comp.close();
	system("g++ -Wall -O compile.cpp -o compile");
	system("./compile");
	execute = "./";
	execute += execFile;
	exec.open("execute.cpp");
	(exec.is_open())? ({goto Exec_open;}) : ({goto File_not_open;});
	Exec_open:
	exec << "#include <stdlib.h>\nint main(){system(";
	exec << '"';
	exec << execute;
	exec << '"';
	exec << ");return 0;}";
	exec.close();
	system("g++ -Wall -O execute.cpp -o execute");
	system("./execute");
	goto INI;
	File_not_open:
	putchar_unlocked('C');
	putchar_unlocked('o');
	putchar_unlocked('u');
	putchar_unlocked('l');
	putchar_unlocked('d');
	putchar_unlocked(' ');
	putchar_unlocked('n');
	putchar_unlocked('o');
	putchar_unlocked('t');
	putchar_unlocked(' ');
	putchar_unlocked('c');
	putchar_unlocked('r');
	putchar_unlocked('e');
	putchar_unlocked('a');
	putchar_unlocked('t');
	putchar_unlocked('e');
	putchar_unlocked(' ');
	putchar_unlocked('f');
	putchar_unlocked('i');
	putchar_unlocked('l');
	putchar_unlocked('e');
	putchar_unlocked('.');
	putchar_unlocked('\n');
	goto INI;
	FIN:
	return 0;
}
