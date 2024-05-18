#pragma once

struct {
	int CurrentTab = 0;

	struct {
		bool Enable = false;

		int DropDelay = 60;

		struct {
			bool DropStone = false;
			bool DropFlint = false;
			bool DropMetal = false;
			bool DropObsidian = false;
			bool DropCrystal = false;
			bool DropMushrooms = false;
			bool DropFlowers = false;
			bool DropBerries = false;
			bool DropWood = false;
			bool DropThatch = false;
			bool DropFiber = false;
			bool DropSeeds = false;
		} DropMats;
	} FarmBot;
	
	struct {
		bool Enable = false;
		bool FirstRun = true;

		int CropsPerRow = 10;
		int Rows = 5;

		bool NotifyOnFullFridges = false;
		char CropBotWebhook[256] = "";
	} CropBot;
} Settings;