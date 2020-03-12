#pragma once

#ifdef PTH_PLATFORM_WINDOWS
	#ifdef PTH_BUILD_DLL
		#define PTH_API __declspec(dllexport)
	#else
		#define PTH_API __declspec(dllimport)
	#endif
#else
	#error Panther only support windows!
#endif