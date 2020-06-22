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

	ic_engine::ic_engine(float I, float T, float HM, float HV, float C, float Tnatural, const std::vector<int>& changeV, const std::vector<int>& changeM) :
		I(I), T(T), HM(HM), HV(HV), C(C), Tnatural(Tnatural), changeV(changeV), changeM(changeM){
		
		TE = Tnatural;
		index = 0;
		V = changeV[index];
		M = changeM[index];
		VC = 0.0f;
		VH = 0.0f;
	}

	ic_engine::~ic_engine() {

	}

	void ic_engine::calculateVC()
	{	
		if (TE == 0.0f) {
			TE = Tnatural;
		}

		VC = C * (Tnatural - TE);
	}

	void ic_engine::calculateVH()
	{
		VH = M * HM + V * V * HV;
	}

	void ic_engine::work()
	{
		calculateVC();
		calculateVH();
		float TVE = VH + VC;
		TE += TVE;
		
		if (index == changeV.size()) {
			V = 0.0f;
			M = 0.0f;
			return;
		}

		a = M / I;
		V += a;
		if(V > changeV[index+1])
			index++;
		float up = V - changeV[index];
		float down = changeV[index+1] - changeV[index];
		float factorM = changeM[index+1] - changeM[index];
		M = up / down * factorM + changeM[index];
	}

	bool ic_engine::isNormal()
	{
		return T >= TE;
	}

}