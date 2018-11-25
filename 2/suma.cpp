#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

int main(){

	int a ,b;
	std::string fileName;
	std::string execFile;
	std::string compile;
	std::string execute;
	std::ofstream suma;
	std::ofstream comp;
	std::ofstream exec;

	while(std::cin >> a >> b && a+b){

	fileName = a + '0';
	fileName += "+";
	fileName += b + '0';
	fileName += ".cpp";

	execFile = a + '0';
	execFile += "+";
	execFile += b + '0';

	suma.open(fileName);
	if (suma.is_open()){

	    suma << "#include <iostream>\n int main(){int a = " << a << ";  int b = " << b << "; int res = a + b; std::cout << res << std::endl; return 0;}";
		suma.close();

		compile = "g++ -Wall -O ";
		compile += fileName;
		compile += " -o ";
		compile += execFile;

		comp.open("compile.cpp");
		if(comp.is_open()){

			comp << "#include <stdlib.h>\nint main(){system(";
			comp << '"';
			comp << compile;
			comp << '"';
			comp << ");return 0;}";
			comp.close();

		}

		system("g++ -Wall -O compile.cpp -o compile");
		system("./compile");

		execute = "./";
		execute += execFile;

		exec.open("execute.cpp");
		if(exec.is_open()){

			exec << "#include <stdlib.h>\nint main(){system(";
			exec << '"';
			exec << execute;
			exec << '"';
			exec << ");return 0;}";
			exec.close();

		}

		system("g++ -Wall -O execute.cpp -o execute");
		system("./execute");

	}
	else {
		std::cout << "no se pudo crear el archivo.\n";
	}

    }

    return 0;
}
