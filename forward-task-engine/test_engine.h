#ifndef TEST_ENGINE_H
#define TEST_ENGINE_H
#pragma once

#include "ic_engine.h"

namespace phs{
	class test_engine
	{
	protected:
		ic_engine engine;
		float V;
		float M;
		float Tnatural;
		int	  time_stop;
		bool  result_test = true;
	public:
		test_engine(ic_engine& engine);

		void test();
		bool get_result_test();
		int get_time_stop();

		virtual void calculate_conditions() = 0;

	};
}

#endif