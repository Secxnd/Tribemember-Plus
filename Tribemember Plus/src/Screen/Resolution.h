#pragma once
#include "Structs.h"

/*
*
* If you happen to be here and see that your Resolution hasnt been set up yet you can take a look in the Tribemember Plus Discord.
* I made a small program with which you can get the Position and Color of the pixel that your mouse is on.
* 
* If you dont know what one of the Icons is supposed to represent just ask in the Discord or DM me(Secxnd).
* If you do update the namespace corresponding to your Resolution make sure that the Icons have the same name.
* 
* If you have set up your Resolution I would greatly appreciate it if you could send me(Secxnd) your Resolution namespace so that I can update the Source and Release.
* 
* I will eventually set up the missing namespaces myself when I have time.
* 
*/

//                          DEFINE YOUR SCREEN RESOLUTION HERE!!!
#define FHD // FHD = 1920x1080 | UWFHD = 2540x1080 | WQHD = 2540x1440 | UWQHD = 3440x1440 | UHD = 3840x2160
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace N_FHD {
	Icon ActiveInventoryBag(Vector2D(818, 71), rgb(78, 148, 182));
	Icon InactiveInventoryBag(Vector2D(818, 71), rgb(225, 241, 248));

	Icon ActiveRemoteINVENTORY(Vector2D(1210, 129), rgb(223, 250, 255));

	Icon ActiveRemoteDropAll(Vector2D(1426, 204), rgb(14, 196, 214));

	Icon ActiveRemoteAutoStack(Vector2D(1561, 196), rgb(14, 196, 214));

	Vector2D RemoteSearchbar(1277, 198);
}

namespace N_UWFHD {

}

namespace N_WQHD {

}

namespace N_UWQHD {
	Icon ActiveInventoryBag(Vector2D(1530, 94), rgb(78, 148, 182));
	Icon InactiveInventoryBag(Vector2D(1530, 94), rgb(225, 241, 248));

	Icon ActiveRemoteINVENTORY(Vector2D(2055, 182), rgb(223, 250, 255));

	Icon ActiveRemoteDropAll(Vector2D(2342, 263), rgb(14, 196, 214));

	Icon ActiveRemoteAutoStack(Vector2D(2530, 261), rgb(14, 196, 214));

	Vector2D RemoteSearchbar(2139, 265);
}

namespace N_UHD {

}