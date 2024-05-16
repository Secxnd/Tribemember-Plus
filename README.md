# Tribemember Plus - ASA Multi Tool

## Tribemember Plus is a Multi Tool for ARK: Survival Ascended which will help with alot of PvE related Tasks and maybe I will add some PvP Features.

### What do I need to compile it myself?

Currently you only need GLFW (https://www.glfw.org/download) and the Windows 10 SDK 10.0.20348.0 (Visual Studio Installer) to compile it. 
After installing the Windows pre-compiled binaries from the GLFW Downloads you will need to update the Include and Library path in the Project Settings. (Configuration Properties -> General -> Include Directories/Library Directories)

You will most likely have to compile it yourself due to the release being a build compiled for the UWQHD resolution. If your Monitor resolution doesn't correspond to UWQHD (3440x1440) you will need to change the resolution preset in Screen/Resolution.h. Your needed Resolution namespace will most likely not be set up so you will have to set it up yourself. I will try to set up every namespace in the future tho.

This is a complete recode of an older version of Tribemember Plus so it doesn't have many Features at the moment but I will continuesly work on adding more Features.