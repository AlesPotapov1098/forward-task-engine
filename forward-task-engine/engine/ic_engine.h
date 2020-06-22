#ifndef INTERNAL_CONCLUSION_ENGINE_H
#define INTERNAL_CONCLUSION_ENGINE_H

#include <vector>

#include "engine.h"

namespace phs{
	class ic_engine : public engine
	{
	private:
		float			 I;			// - ������ ������� ���������
		float			 T;			// - ����������� ���������
		float			 HM;		// - ����������� ����������� �������� ������� �� ��������� �������
		float			 HV;		// - ����������� ����������� �������� ������� �� �������� �������� ���������
		float			 C;			// - ����������� ����������� �������� ���������� �� ����������� ��������� � ���������� �����
		float			 TE;		// - ����������� ��������� (��� ����������� ������, ����� �������� �������� ������)
		float			 Tnatural;	// - ����������� ���������� �����
		std::vector<int> changeV;	// - ��������� ��������
		std::vector<int> changeM;	// - ��������� ������������� �������

		float VC;	// - �������� ���������� ���������
		float VH;	// - �������� ������� ���������
		float V;	// - ������� �������� �������� ���������
		float M;	// - ������� ������������ ������
		float a;	// - ���������

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