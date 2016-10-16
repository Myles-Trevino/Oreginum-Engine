#pragma once
#include <Windows.h>

namespace Oreginum
{
	enum Key
	{
		LEFT_MOUSE = VK_LBUTTON, RIGHT_MOUSE = VK_RBUTTON, MIDDLE_MOUSE = VK_MBUTTON,
		BACKSPACE = VK_BACK, TAB = VK_TAB, ENTER = VK_RETURN, PAUSE = VK_PAUSE,
		CAPS_LOCK = VK_CAPITAL, ESC = VK_ESCAPE, SPACEBAR = VK_SPACE, PAGE_UP = VK_PRIOR,
		PAGE_DOWN = VK_NEXT, END = VK_END, HOME = VK_HOME, LEFT = VK_LEFT, UP = VK_UP,
		RIGHT = VK_RIGHT, DOWN = VK_DOWN, PRINT_SCREEN = VK_SNAPSHOT, INS = VK_INSERT,
		DEL = VK_DELETE, ZERO = '0', ONE = '1', TWO = '2', THREE = '3', FOUR = '4',
		FIVE = '5', SIX = '6', SEVEN = '7', EIGHT = '8', NINE = '9', A = 'A', B = 'B',
		C = 'C', D = 'D', E = 'E', F = 'F', G = 'G', H = 'H', I = 'I', J = 'J', K = 'K',
		L = 'L', M = 'M', N = 'N', O = 'O', P = 'P', Q = 'Q', R = 'R', S = 'S', T = 'T',
		U = 'U', V = 'V', W = 'W', X = 'X', Y = 'Y', Z = 'Z', LEFT_WINDOWS = VK_LWIN,
		RIGHT_WINDOWS = VK_RWIN, APPLICATIONS = VK_APPS, NUMPAD_ZERO = VK_NUMPAD0,
		NUMPAD_ONE = VK_NUMPAD1, NUMPAD_TWO = VK_NUMPAD2, NUMPAD_THREE = VK_NUMPAD3,
		NUMPAD_FOUR = VK_NUMPAD4, NUMPAD_FIVE = VK_NUMPAD5, NUMPAD_SIX = VK_NUMPAD6,
		NUMPAD_SEVEN = VK_NUMPAD7, NUMPAD_EIGHT = VK_NUMPAD8, NUMPAD_NINE = VK_NUMPAD9,
		NUMPAD_MULTIPLY = VK_MULTIPLY, NUMPAD_ADD = VK_ADD,
		NUMPAD_SUBTRACT = VK_SUBTRACT, NUMPAD_DECIMAL = VK_DECIMAL, NUMPAD_DIVIDE = VK_DIVIDE,
		F1 = VK_F1, F2 = VK_F2, F3 = VK_F3, F4 = VK_F4, F5 = VK_F5, F6 = VK_F6, F7 = VK_F7,
		F8 = VK_F8, F9 = VK_F9, F10 = VK_F10, F11 = VK_F11, F12 = VK_F12,
		NUM_LOCK = VK_NUMLOCK, SCROLL_LOCK = VK_SCROLL, LEFT_SHIFT = VK_LSHIFT,
		RIGHT_SHIFT = VK_RSHIFT, LEFT_CONTROL = VK_LCONTROL, RIGHT_CONTROL = VK_RCONTROL,
		LEFT_ALT = VK_LMENU, RIGHT_ALT = VK_RMENU, MUTE = VK_VOLUME_MUTE,
		VOLUME_DOWN = VK_VOLUME_DOWN, VOLUME_UP = VK_VOLUME_UP,
		NEXT_TRACK = VK_MEDIA_NEXT_TRACK, PREVIOUS_TRACK = VK_MEDIA_PREV_TRACK,
		STOP_TRACK = VK_MEDIA_STOP, PAUSE_TRACK = VK_MEDIA_PLAY_PAUSE, SEMICOLON = VK_OEM_1,
		PLUS = VK_OEM_PLUS, COMMA = VK_OEM_COMMA, MINUS = VK_OEM_MINUS, PERIOD = VK_OEM_PERIOD,
		SLASH = VK_OEM_2, TILDE = VK_OEM_3, LEFT_BRACKET = VK_OEM_4, BACKSLASH = VK_OEM_5,
		RIGHT_BRACKET = VK_OEM_6, QUOTE = VK_OEM_7
	};

	namespace Keyboard
	{
		void update();

		bool was_pressed(Key key);
		bool is_held(Key key);
	};
}