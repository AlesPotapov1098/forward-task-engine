#ifndef TEST_IC_ENGINE_H
#define TEST_IC_ENGINE_H
#pragma once

#include <vector>

#include "test_engine.h"
#include "..\engine\engine.h"

namespace phs{
	class test_ic_engine : public test_engine
	{
	private:
	public:
		test_ic_engine(phs::engine * eng);
		void test() override;
	};
}
#endif