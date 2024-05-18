#include "Settings.h"

#include "Ark/FarmBot.h"
#include "Ark/CropBot.h"

#include "UI/UI.h"

#include <Windows.h>
#include <thread>


void KeyHandler() {
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(25));
		if (GetAsyncKeyState(VK_F1) & 1) {
			if (!Settings.CurrentTab) Settings.FarmBot.Enable = true;
			else if (Settings.CurrentTab == 1) Settings.CropBot.Enable = true;
		}
		else if (GetAsyncKeyState(VK_F2) & 1) {
			if (!Settings.CurrentTab) Settings.FarmBot.Enable = false;
			else if (Settings.CurrentTab == 1) Settings.CropBot.Enable = false;
		}
		/*
		if (GetAsyncKeyState(VK_F1) & 1 && !Settings.CurrentTab) Settings.FarmBot.Enable = true;
		if (GetAsyncKeyState(VK_F1) & 1 && Settings.CurrentTab == 1) Settings.CropBot.Enable = true;
		if (GetAsyncKeyState(VK_F2) & 1 && !Settings.CurrentTab) Settings.FarmBot.Enable = false;
		if (GetAsyncKeyState(VK_F2) & 1 && Settings.CurrentTab == 1) Settings.CropBot.Enable = false;
		*/
	}
}

void FeatureHandle() {
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(25));
		if (Settings.FarmBot.Enable) FarmBot();
		//if (Settings.CropBot.Enable) CropBot();
	}
}


int main() {
#ifdef FHD
	if (Vector2D(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)) != Vector2D(1920, 1080)) {
		MessageBoxA(0, "Your resolution does not match the configuration for this build.\nConfigured Resolution: FHD (1920x1080)", "Wrong Resolution", MB_OK);
		return 0;
	}
#elif defined(UWFHD)
	if (Vector2D(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)) != Vector2D(2540, 1080)) {
		MessageBoxA(0, "Your resolution does not match the configuration for this build.\nConfigured Resolution: UWFHD (2540x1080)", "Wrong Resolution", MB_OK);
		return 0;
	}
#elif defined(WQHD)
	if (Vector2D(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)) != Vector2D(2540, 1440)) {
		MessageBoxA(0, "Your resolution does not match the configuration for this build.\nConfigured Resolution: WQHD (2540x1440)", "Wrong Resolution", MB_OK);
		return 0;
	}
#elif defined(UWQHD)
	if (Vector2D(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)) != Vector2D(3440, 1440)) {
		MessageBoxA(0, "Your resolution does not match the configuration for this build.\nConfigured Resolution: UWQHD (3440x1440)", "Wrong Resolution", MB_OK);
		return 0;
	}
#elif defined(UHD)
	if (Vector2D(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)) != Vector2D(3840, 2160)) {
		MessageBoxA(0, "Your resolution does not match the configuration for this build.\nConfigured Resolution: UHD (3840x2160)", "Wrong Resolution", MB_OK);
		return 0;
	}
#endif

	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)KeyHandler, 0, 0, 0));
	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)FeatureHandle, 0, 0, 0));
	DoUI();
}