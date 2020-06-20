#ifndef INTERNAL_CONCLUSION_ENGINE_H
#define INTERNAL_CONCLUSION_ENGINE_H

#include <vector>

#include "engine.h"

namespace phs{
	class ic_engine : public engine
	{
	private:
		float I;   // - ������ ������� ���������
		float T;   // - ����������� ���������
		float HM;  // - ����������� ����������� �������� ������� �� ��������� �������
		float HV;  // - ����������� ����������� �������� ������� �� �������� �������� ���������
		float C;   // - ����������� ����������� �������� ���������� �� ����������� ��������� � ���������� �����
		float TE;  // - ����������� ��������� (��� ����������� ������, ����� �������� �������� ������)

		float VC;  // - �������� ���������� ���������
		float VH;  // - �������� ������� ���������

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