#pragma once

namespace Astro
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define AS_KEY_SPACE           ::Astro::Key::Space
#define AS_KEY_APOSTROPHE      ::Astro::Key::Apostrophe    /* ' */
#define AS_KEY_COMMA           ::Astro::Key::Comma         /* , */
#define AS_KEY_MINUS           ::Astro::Key::Minus         /* - */
#define AS_KEY_PERIOD          ::Astro::Key::Period        /* . */
#define AS_KEY_SLASH           ::Astro::Key::Slash         /* / */
#define AS_KEY_0               ::Astro::Key::D0
#define AS_KEY_1               ::Astro::Key::D1
#define AS_KEY_2               ::Astro::Key::D2
#define AS_KEY_3               ::Astro::Key::D3
#define AS_KEY_4               ::Astro::Key::D4
#define AS_KEY_5               ::Astro::Key::D5
#define AS_KEY_6               ::Astro::Key::D6
#define AS_KEY_7               ::Astro::Key::D7
#define AS_KEY_8               ::Astro::Key::D8
#define AS_KEY_9               ::Astro::Key::D9
#define AS_KEY_SEMICOLON       ::Astro::Key::Semicolon     /* ; */
#define AS_KEY_EQUAL           ::Astro::Key::Equal         /* = */
#define AS_KEY_A               ::Astro::Key::A
#define AS_KEY_B               ::Astro::Key::B
#define AS_KEY_C               ::Astro::Key::C
#define AS_KEY_D               ::Astro::Key::D
#define AS_KEY_E               ::Astro::Key::E
#define AS_KEY_F               ::Astro::Key::F
#define AS_KEY_G               ::Astro::Key::G
#define AS_KEY_H               ::Astro::Key::H
#define AS_KEY_I               ::Astro::Key::I
#define AS_KEY_J               ::Astro::Key::J
#define AS_KEY_K               ::Astro::Key::K
#define AS_KEY_L               ::Astro::Key::L
#define AS_KEY_M               ::Astro::Key::M
#define AS_KEY_N               ::Astro::Key::N
#define AS_KEY_O               ::Astro::Key::O
#define AS_KEY_P               ::Astro::Key::P
#define AS_KEY_Q               ::Astro::Key::Q
#define AS_KEY_R               ::Astro::Key::R
#define AS_KEY_S               ::Astro::Key::S
#define AS_KEY_T               ::Astro::Key::T
#define AS_KEY_U               ::Astro::Key::U
#define AS_KEY_V               ::Astro::Key::V
#define AS_KEY_W               ::Astro::Key::W
#define AS_KEY_X               ::Astro::Key::X
#define AS_KEY_Y               ::Astro::Key::Y
#define AS_KEY_Z               ::Astro::Key::Z
#define AS_KEY_LEFT_BRACKET    ::Astro::Key::LeftBracket   /* [ */
#define AS_KEY_BACKSLASH       ::Astro::Key::Backslash     /* \ */
#define AS_KEY_RIGHT_BRACKET   ::Astro::Key::RightBracket  /* ] */
#define AS_KEY_GRAVE_ACCENT    ::Astro::Key::GraveAccent   /* ` */
#define AS_KEY_WORLD_1         ::Astro::Key::World1        /* non-US #1 */
#define AS_KEY_WORLD_2         ::Astro::Key::World2        /* non-US #2 */

/* Function keys */
#define AS_KEY_ESCAPE          ::Astro::Key::Escape
#define AS_KEY_ENTER           ::Astro::Key::Enter
#define AS_KEY_TAB             ::Astro::Key::Tab
#define AS_KEY_BACKSPACE       ::Astro::Key::Backspace
#define AS_KEY_INSERT          ::Astro::Key::Insert
#define AS_KEY_DELETE          ::Astro::Key::Delete
#define AS_KEY_RIGHT           ::Astro::Key::Right
#define AS_KEY_LEFT            ::Astro::Key::Left
#define AS_KEY_DOWN            ::Astro::Key::Down
#define AS_KEY_UP              ::Astro::Key::Up
#define AS_KEY_PAGE_UP         ::Astro::Key::PageUp
#define AS_KEY_PAGE_DOWN       ::Astro::Key::PageDown
#define AS_KEY_HOME            ::Astro::Key::Home
#define AS_KEY_END             ::Astro::Key::End
#define AS_KEY_CAPS_LOCK       ::Astro::Key::CapsLock
#define AS_KEY_SCROLL_LOCK     ::Astro::Key::ScrollLock
#define AS_KEY_NUM_LOCK        ::Astro::Key::NumLock
#define AS_KEY_PRINT_SCREEN    ::Astro::Key::PrintScreen
#define AS_KEY_PAUSE           ::Astro::Key::Pause
#define AS_KEY_F1              ::Astro::Key::F1
#define AS_KEY_F2              ::Astro::Key::F2
#define AS_KEY_F3              ::Astro::Key::F3
#define AS_KEY_F4              ::Astro::Key::F4
#define AS_KEY_F5              ::Astro::Key::F5
#define AS_KEY_F6              ::Astro::Key::F6
#define AS_KEY_F7              ::Astro::Key::F7
#define AS_KEY_F8              ::Astro::Key::F8
#define AS_KEY_F9              ::Astro::Key::F9
#define AS_KEY_F10             ::Astro::Key::F10
#define AS_KEY_F11             ::Astro::Key::F11
#define AS_KEY_F12             ::Astro::Key::F12
#define AS_KEY_F13             ::Astro::Key::F13
#define AS_KEY_F14             ::Astro::Key::F14
#define AS_KEY_F15             ::Astro::Key::F15
#define AS_KEY_F16             ::Astro::Key::F16
#define AS_KEY_F17             ::Astro::Key::F17
#define AS_KEY_F18             ::Astro::Key::F18
#define AS_KEY_F19             ::Astro::Key::F19
#define AS_KEY_F20             ::Astro::Key::F20
#define AS_KEY_F21             ::Astro::Key::F21
#define AS_KEY_F22             ::Astro::Key::F22
#define AS_KEY_F23             ::Astro::Key::F23
#define AS_KEY_F24             ::Astro::Key::F24
#define AS_KEY_F25             ::Astro::Key::F25

/* Keypad */
#define AS_KEY_KP_0            ::Astro::Key::KP0
#define AS_KEY_KP_1            ::Astro::Key::KP1
#define AS_KEY_KP_2            ::Astro::Key::KP2
#define AS_KEY_KP_3            ::Astro::Key::KP3
#define AS_KEY_KP_4            ::Astro::Key::KP4
#define AS_KEY_KP_5            ::Astro::Key::KP5
#define AS_KEY_KP_6            ::Astro::Key::KP6
#define AS_KEY_KP_7            ::Astro::Key::KP7
#define AS_KEY_KP_8            ::Astro::Key::KP8
#define AS_KEY_KP_9            ::Astro::Key::KP9
#define AS_KEY_KP_DECIMAL      ::Astro::Key::KPDecimal
#define AS_KEY_KP_DIVIDE       ::Astro::Key::KPDivide
#define AS_KEY_KP_MULTIPLY     ::Astro::Key::KPMultiply
#define AS_KEY_KP_SUBTRACT     ::Astro::Key::KPSubtract
#define AS_KEY_KP_ADD          ::Astro::Key::KPAdd
#define AS_KEY_KP_ENTER        ::Astro::Key::KPEnter
#define AS_KEY_KP_EQUAL        ::Astro::Key::KPEqual

#define AS_KEY_LEFT_SHIFT      ::Astro::Key::LeftShift
#define AS_KEY_LEFT_CONTROL    ::Astro::Key::LeftControl
#define AS_KEY_LEFT_ALT        ::Astro::Key::LeftAlt
#define AS_KEY_LEFT_SUPER      ::Astro::Key::LeftSuper
#define AS_KEY_RIGHT_SHIFT     ::Astro::Key::RightShift
#define AS_KEY_RIGHT_CONTROL   ::Astro::Key::RightControl
#define AS_KEY_RIGHT_ALT       ::Astro::Key::RightAlt
#define AS_KEY_RIGHT_SUPER     ::Astro::Key::RightSuper
#define AS_KEY_MENU            ::Astro::Key::Menu