#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Jumbo
{
	class  Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return sCoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return sClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> sCoreLogger;
		static std::shared_ptr<spdlog::logger> sClientLogger;
	};
}

// Core log macros
#define JB_CORE_FATAL(...)		::Jumbo::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define JB_CORE_ERROR(...)		::Jumbo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JB_CORE_WARN(...)		::Jumbo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JB_CORE_INFO(...)		::Jumbo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JB_CORE_TRACE(...)		::Jumbo::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define JB_FATAL(...)		::Jumbo::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define JB_ERROR(...)		::Jumbo::Log::GetClientLogger()->error(__VA_ARGS__)
#define JB_WARN(...)		::Jumbo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JB_INFO(...)		::Jumbo::Log::GetClientLogger()->info(__VA_ARGS__)
#define JB_TRACE(...)		::Jumbo::Log::GetClientLogger()->trace(__VA_ARGS__)


