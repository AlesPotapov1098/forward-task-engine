#ifndef ENGINE_H
#define ENGINE_H
#pragma once

namespace phs{
	class engine
	{
	public:
		virtual void work() = 0;
		virtual void calculateVC(float Tnatural) = 0;
		virtual void calculateVH(float M, float V) = 0;
		virtual bool isNormal() = 0;
	};
}

#endif