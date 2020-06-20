#ifndef TEST_IC_ENGINE_H
#define TEST_IC_ENGINE_H
#pragma once

#include <vector>

#include "test_engine.h"

namespace phs{
	class test_ic_engine : test_engine
	{
	private:
		const int SIZE = 5;
		int * startV;
		int * startM;
		int position;
		float a;
	public:
		void calculate_conditions() override;
		void set_tnatural(float Tnatural);
	};
}
#endif