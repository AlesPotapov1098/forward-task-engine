#include "test_ic_engine.h"

namespace phs {

	test_ic_engine::test_ic_engine(phs::engine* eng) : test_engine(eng) {

	}

	void test_ic_engine::test()
	{
		const int MAX_TIME = 1000000;
		for (int time = 0; time < MAX_TIME; time++) {
			engine->work();
			if (!engine->isNormal()) {
				time_stop = time;
				result_test = false;
				break;
			}
		}
	}
}