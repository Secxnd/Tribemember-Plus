#pragma once
#include "../Screen/Resolution.h"
#include "../Settings.h"

#include "../Input/Mouse.h"
#include "../Input/Keyboard.h"

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

inline void DropMaterial(std::string Name) {
	Mouse.ClickAt(RemoteSearchbar);
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	Keyboard.Typrewrite(Name);
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	Mouse.ClickAt(ActiveRemoteDropAll.Position);
}

void FarmBot() {
	while (Settings.FarmBot.Enable) {
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
		auto StartTime = std::chrono::steady_clock::now();
		while (Settings.FarmBot.Enable) {
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
			auto CurrentTime = std::chrono::steady_clock::now();
			auto ElapsedTime = std::chrono::duration_cast<std::chrono::seconds>(CurrentTime - StartTime);

			Mouse.LClick();

			if (ElapsedTime.count() >= Settings.FarmBot.DropDelay && Settings.FarmBot.Enable) {
				Keyboard.PressKey(0x46, 1);

				while (!ActiveInventoryBag.IsIconActive() || !ActiveRemoteINVENTORY.IsIconActive()) {
					std::this_thread::sleep_for(std::chrono::milliseconds(5));
					if (!Settings.FarmBot.Enable) return;
				}

				if (Settings.FarmBot.DropMats.DropStone) DropMaterial("Stone");
				if (Settings.FarmBot.DropMats.DropFlint) DropMaterial("Flint");
				if (Settings.FarmBot.DropMats.DropMetal) DropMaterial("Metal");
				if (Settings.FarmBot.DropMats.DropObsidian) DropMaterial("Obsidian");
				if (Settings.FarmBot.DropMats.DropCrystal) DropMaterial("Crystal");
				if (Settings.FarmBot.DropMats.DropMushrooms) DropMaterial("Mushroom");
				if (Settings.FarmBot.DropMats.DropFlowers) DropMaterial("Flower");
				if (Settings.FarmBot.DropMats.DropBerries) DropMaterial("Berry");
				if (Settings.FarmBot.DropMats.DropWood) DropMaterial("Wood");
				if (Settings.FarmBot.DropMats.DropThatch) DropMaterial("Thatch");
				if (Settings.FarmBot.DropMats.DropFiber) DropMaterial("Fiber");
				if (Settings.FarmBot.DropMats.DropFiber) DropMaterial("Seed");

				Keyboard.PressKey(VK_ESCAPE, 1);

				break;
			}
		}
	}
}