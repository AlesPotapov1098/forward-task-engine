#include "test_engine.h"

phs::test_engine::test_engine(phs::engine * engine)
{
	this->engine = engine;
}

bool phs::test_engine::get_result_test()
{
	return this->result_test;
}

int phs::test_engine::get_time_stop()
{
	return this->time_stop;
}
