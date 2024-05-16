#pragma once
#include <Windows.h>
#include <thread>
#include "../Screen/Structs.h"

struct {
	Vector2D GetMousePos() {
		POINT p;
		GetCursorPos(&p);
		return Vector2D(p.x, p.y);
	}

	inline void LClick() {
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	}

	inline void RLClick() {
		mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
	}

	inline void DClick() {
		LClick();
		LClick();
	}

	inline void ClickAt(Vector2D Position) {
		SetCursorPos(Position.X, Position.Y);
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		LClick();
	}

	inline void DClickAt(Vector2D Position) {
		SetCursorPos(Position.X, Position.Y);
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		DClick();
	}
} Mouse;