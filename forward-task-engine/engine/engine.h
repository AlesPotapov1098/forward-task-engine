#ifndef ENGINE_H
#define ENGINE_H
#pragma once

namespace phs{
	class engine
	{
	public:
		virtual void work() = 0;
		virtual bool isNormal() = 0;
	};
}

#endif