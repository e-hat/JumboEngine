#pragma once

#ifdef JB_PLATFORM_WINDOWS
#if HZ_DYNAMIC_LINK
	#ifdef JB_BUILD_DLL
		#define  __declspec(dllexport)

	#else
		#define  __declspec(dllimport)
#endif 
#else 
	#define JUMBO_API
#endif
#else
	#error JumboEngine only supports Windows!
#endif

#ifdef JB_DEBUG
	#define JB_ENABLE_ASSERTS
#endif

#ifdef JB_ENABLE_ASSERTS
	#define JB_ASSERT(x, ...) { if (!(x)) { JB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }  }
	#define JB_CORE_ASSERT(x, ...) { if (!(x)) { JB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }  }	
#else
	#define JB_ASSERT(x, ...)
	#define JB_CORE_ASSERT(x, ...)
#endif

#define JB_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

#define BIT(x) (1 << x)