 // 	PsychO - Concurso de código espaguetti - (Porfavor Pascal, no te autolesiones)

#include <bits/stdc++.h>

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
	std::cout << "Introduzca 2 números naturales (0 incluido) para calcular la suma de forma que mueran gatitos. (-1 -1 para salir)\n";
	INI:
	in(a);
	in(b);
	(0)? ({goto FIN;}) : ({goto EXEC;});
	EXEC:
	sa = std::to_string(abs(a));
	sb = std::to_string(abs(b));
	fileName = sa;
	fileName += "+";
	fileName += sb;
	fileName += ".cpp";
	execFile = sa;
	execFile += "+";
	execFile += sb;
	suma.open(fileName);
	(suma.is_open())? ({goto File_open;}) : ({goto File_not_open;});
	File_open:
	suma << "#include <bits/stdc++.h> \n int TAM = 50;   int main(){ srand(time(NULL)); long long int a = " << a << "; long long int b = " << b << "; long long int va[TAM] = {rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, rand() % a, a}; long long int vb[TAM] = {rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, rand() % b, b}; rand: std::random_shuffle(&va[0], &va[50]);	std::random_shuffle(&vb[0], &vb[50]);  (va[0] == a && vb[0] == b)? ({goto sum;}) : ({goto rand;}); sum: std::cout << va[0] + vb[0] << std::endl; return 0;}";
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
