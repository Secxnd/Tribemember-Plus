#include "Settings.h"

#include "Ark/FarmBot.h"

#include "UI/UI.h"

#include <Windows.h>
#include <thread>


void KeyHandler() {
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(25));
		if (GetAsyncKeyState(VK_F1) & 1 && !Settings.CurrentTab) Settings.FarmBot.Enable = true;
		else if (GetAsyncKeyState(VK_F2) & 1 && !Settings.CurrentTab) Settings.FarmBot.Enable = false;
	}
}

void FeatureHandle() {
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(25));
		if (Settings.FarmBot.Enable) FarmBot();
	}
}


int main() {
	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)KeyHandler, 0, 0, 0));
	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)FeatureHandle, 0, 0, 0));
	DoUI();
	return 0;
}