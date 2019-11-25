#pragma once

#ifdef JB_PLATFORM_WINDOWS
	#ifdef JB_BUILD_DLL
		#define JUMBO_API __declspec(dllexport)

	#else
		#define JUMBO_API __declspec(dllimport)
#endif 
#else 
#error JumboEngine only supports Windows!
#endif