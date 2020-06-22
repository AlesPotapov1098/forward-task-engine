#ifndef TEST_ENGINE_H
#define TEST_ENGINE_H
#pragma once

#include "..\engine\engine.h"

namespace phs{
	class test_engine
	{
	protected:
		engine * engine;
		int	  time_stop = 0;
		bool  result_test = true;
	public:
		test_engine(phs::engine * eng);

		virtual void test() = 0;
		bool get_result_test();
		int get_time_stop();
	};
}

#endif