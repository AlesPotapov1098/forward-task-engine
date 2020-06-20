#include "test_engine.h"

phs::test_engine::test_engine(ic_engine& engine)
{
	this->engine = engine;
}

void phs::test_engine::test()
{
	const int MAX_TIME = 1000000;

	for(int time = 0;time < MAX_TIME;time++){
		calculate_conditions();
		engine.calculateVC(this->Tnatural);
		engine.calculateVH(this->M, this->V);
		engine.work();

		if(!engine.isNormal()){
			this->time_stop = time;
			this->result_test = false;
			break;
		}
	} 
}

bool phs::test_engine::get_result_test()
{
	return this->result_test;
}

int phs::test_engine::get_time_stop()
{
	return this->time_stop;
}
