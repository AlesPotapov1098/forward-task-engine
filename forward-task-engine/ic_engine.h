#ifndef INTERNAL_CONCLUSION_ENGINE_H
#define INTERNAL_CONCLUSION_ENGINE_H

#include <vector>

#include "engine.h"

namespace phs{
	class ic_engine : public engine
	{
	private:
		float I;   // - момент инерции двигателя
		float T;   // - температура перегрева
		float HM;  // - коэффициент зависимости скорости нагрева от крутящего момента
		float HV;  // - коэффициент зависимости скорости нагрева от скорости вращения коленвала
		float C;   // - коэффициент зависимости скорости охлаждения от температуры двигателя и окружающей среды
		float TE;  // - температура двигателя (при объявляении задаем, после меняется втечение работы)

		float VC;  // - скорость охлаждения двигателя
		float VH;  // - скорость нагрева двигателя

	public:
	
		ic_engine();
		ic_engine(float I, float T, float HM, float HV, float C, float TE);
		~ic_engine();

		void calculateVC(float Tnatural) override;
		void calculateVH(float M, float V) override;
		
		void work() override;

		bool isNormal() override;

	};
}

#endif