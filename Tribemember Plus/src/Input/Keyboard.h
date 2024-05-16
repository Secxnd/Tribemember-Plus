#pragma once
#include <Windows.h>
#include <thread>

struct {
	inline void PressKey(int KeyCode, int Milliseconds) {
		keybd_event(KeyCode, 0, 0, 0);
		std::this_thread::sleep_for(std::chrono::milliseconds(Milliseconds));
		keybd_event(KeyCode, 0, KEYEVENTF_KEYUP, 0);
	}

	inline void DownKey(int KeyCode) { keybd_event(KeyCode, 0, 0, 0); }
	inline void UpKey(int KeyCode) { keybd_event(KeyCode, 0, KEYEVENTF_KEYUP, 0); }

	inline void Typrewrite(std::string text) {
		for (char c : text) {
			WORD KeyCode = VkKeyScanA(c) & 0xFF;
			if (KeyCode != 0xFF) {
				PressKey(KeyCode, 0);
			}
		}
	}
} Keyboard;