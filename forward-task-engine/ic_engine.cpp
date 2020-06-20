#include "ic_engine.h"

namespace phs {

	ic_engine::ic_engine() {
		I = 10.0f;
		T = 110.0f;
		HM = 0.01f;
		HV = 0.0001f;
		C = 0.1f;
		TE = 0.0f;
	}

	ic_engine::ic_engine(float I, float T, float HM, float HV, float C, float TE) :
		I(I), T(T), HM(HM), HV(HV), C(C), TE(TE){

	}

	ic_engine::~ic_engine() {

	}

	void ic_engine::calculateVC(float Tnatural)
	{	
		if (TE == 0.0f) {
			TE = Tnatural;
		}

		VC = C * (Tnatural - TE);
	}

	void ic_engine::calculateVH(float M, float V)
	{
		VH = M * HM + V * V * HV;
	}

	void ic_engine::work()
	{
		float VTE = VH + VC;
		TE += VTE;
	}

	bool ic_engine::isNormal()
	{
		return T >= TE;
	}

}