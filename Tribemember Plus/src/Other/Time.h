#pragma once
#include <Windows.h>
#include <thread>
#include <chrono>

struct {
	inline void Sleep(int Milliseconds) { std::this_thread::sleep_for(std::chrono::milliseconds(Milliseconds)); }
} Time;