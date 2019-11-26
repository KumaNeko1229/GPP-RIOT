
#ifndef _CONSTANTS_H            // prevent multiple definitions if this 
#define _CONSTANTS_H            // ..file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

//-----------------------------------------------
// Useful macros
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
// Safely call onLostDevice
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) { ptr->onLostDevice(); } }
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) { ptr->onResetDevice(); } }
#define TRANSCOLOR  SETCOLOR_ARGB(0,255,0,255)  // transparent color (magenta)
// mapped as VKs and not Char to prevent confusion later on
#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44

//-----------------------------------------------
//                  Constants
//-----------------------------------------------
// graphic images
const char PLAYER_IMAGE[] = "player.png";
const char ENEMY_IMAGE[] = "enemy.png";

// window
const char CLASS_NAME[] = "Riot";
const char GAME_TITLE[] = "Riot";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH = 1366;               // width of game in pixels
const UINT GAME_HEIGHT = 768;               // height of game in pixels

// game
const double PI = 3.14159265;
const float FRAME_RATE = 200.0f;               // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f / FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f / MIN_FRAME_RATE; // maximum time used in calculations

// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY = VK_ESCAPE;   // escape key
const UCHAR ALT_KEY = VK_MENU;     // Alt key
const UCHAR ENTER_KEY = VK_RETURN;   // Enter key
const UCHAR LEFT_KEY = VK_A;
const UCHAR RIGHT_KEY = VK_D;
const UCHAR UP_KEY = VK_W;
const UCHAR DOWN_KEY = VK_S;

#endif
