#include <iostream>
#include <vector>

#include "..\forward-task-engine\engine\ic_engine.h"
#include "..\forward-task-engine\test-engine\test_ic_engine.h"

int main() {


	setlocale(LC_ALL,"RUS");

	float Tnatural = 13.0f;
	std::cout << "Введите температуру окружающей среды Tnatural = ";
	std::cin >> Tnatural;
	
	std::vector<int> startV = {0,75,150,200,250,300};
	std::vector<int> startM = {20,75,100,105,75,0};

	phs::engine * eng = new phs::ic_engine(10,110,0.01,0.0001,0.1,Tnatural,startV,startM);
	phs::test_engine * tester = new phs::test_ic_engine(eng);
	tester->test();

	if (tester->get_result_test()) {
		std::cout << "Тест прошел отличной!" << std::endl;
	}
	else {
		std::cout << "Тетс провалился, двигатель престал работать в момент времени t = " << tester->get_time_stop() << std::endl;
	}

	return 0;
}