#ifndef INTERNAL_CONCLUSION_ENGINE_H
#define INTERNAL_CONCLUSION_ENGINE_H

#include <vector>

#include "engine.h"

namespace phs{
	class ic_engine : public engine
	{
	private:
		float			 I;			// - момент инерции двигател€
		float			 T;			// - температура перегрева
		float			 HM;		// - коэффициент зависимости скорости нагрева от крут€щего момента
		float			 HV;		// - коэффициент зависимости скорости нагрева от скорости вращени€ коленвала
		float			 C;			// - коэффициент зависимости скорости охлаждени€ от температуры двигател€ и окружающей среды
		float			 TE;		// - температура двигател€ (при объ€вл€ении задаем, после мен€етс€ втечение работы)
		float			 Tnatural;	// - температура окружающей среды
		std::vector<int> changeV;	// - изменение скорости
		std::vector<int> changeM;	// - изменение вращетельного момента

		float VC;	// - скорость охлаждени€ двигател€
		float VH;	// - скорость нагрева двигател€
		float V;	// - текуща€ скорость вращени€ коленвала
		float M;	// - текущий вращательный момент
		float a;	// - ускорение

		int index;

	public:
	
		ic_engine();
		ic_engine(float I, float T, float HM, float HV, float C, float Tnatural, const std::vector<int>& changeV, const std::vector<int>& changeM);
		~ic_engine();
	
		void work() override;
		bool isNormal() override;

	private:
		void calculateVC();
		void calculateVH();
	};
}

#endif