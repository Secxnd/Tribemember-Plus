#pragma once
#include "../Screen/Resolution.h"
#include "../Settings.h"

#include "../Input/Mouse.h"
#include "../Input/Keyboard.h"
#include "../Other/Time.h"

#include <thread>
#include <chrono>

#ifdef FHD
using namespace N_FHD;
#elif defined(UWFHD)
using namespace N_UWFHD;
#elif defined(WQHD)
using namespace N_WQHD;
#elif defined(UWQHD)
using namespace N_UWQHD;
#elif defined(UHD)
using namespace N_UHD;
#endif
/*
inline void CropBot() {
	Settings.CropBot.FirstRun = true;
	while (Settings.CropBot.Enable) {
		for (int Crop = 0; Crop < Settings.CropBot.CropsPerRow; Crop++) {
			while (SpawnScreenFirstBed.IsIconActive() && Settings.CropBot.Enable) {
				Mouse.DClickAt(SpawnScreenSearchBar);
				Time.Sleep(200);
				Keyboard.Typrewrite("CropBed" + std::to_string(Crop));
				Time.Sleep(200);
				Mouse.ClickAt(SpawnScreenFirstBed.Position);
				Mouse.ClickAt(SpawnScreenSpawnAt);
			}
			while (!ActiveInventoryBag.IsIconActive() && Settings.CropBot.Enable) {
				Keyboard.PressKey(0x49, 10);
				Time.Sleep(500);
			}
			Keyboard.PressKey(0x49, 10);
			Time.Sleep(1000);
			if (Settings.CropBot.FirstRun && Settings.CropBot.Enable) {
				Keyboard.PressKey(VK_TAB, 10);
				Time.Sleep(10);
				Keyboard.Typrewrite("t.maxfps 10");
				Keyboard.PressKey(VK_RETURN, 10);
				Settings.CropBot.FirstRun = false;
			}
			Keyboard.PressKey(VK_DOWN, 5000);
			Keyboard.DownKey(0x45);
			Time.Sleep(1000);
			Mouse.Move(LayOnBed);
			Time.Sleep(200);
			Keyboard.UpKey(0x45);
			Time.Sleep(1000);
			Keyboard.PressKey(0x45, 10);
			Time.Sleep(1000);
			Keyboard.PressKey(VK_RIGHT, 1120);
			Keyboard.PressKey(VK_DOWN, 590);
			for (int i = 0; i < 7; i++) {
				if (Settings.CropBot.Enable) {
					Time.Sleep(3500);
					Keyboard.PressKey(VK_UP, 170);
				}
			}
			Time.Sleep(100000);
		}
	}
}
*/
