#pragma once

enum States
{
	OVERWORLD = 0,
	BATTLE = 1,
	SAFARIBATTLE = 2
};

//how the menu functions
enum MenuFlags
{
	NONE =			0,
	FOCUSABLE =		1,
	WRAPS =			2,
	HOLD_INPUT =	4, //whether or not a button can be held to cycle through items
	SWITCHABLE =	8,
	A_TO_SWITCH =	16 //whether or not A can be pressed to finish a switch
};

//the state the cursor is in (flags because of moving items with both visible)
enum ArrowStates
{
	HIDDEN =	0,
	ACTIVE =	1,
	INACTIVE =	2
};

#define STARTING_MAP	0
#define STARTING_X		5
#define STARTING_Y		6

#define VIEWPORT_WIDTH	10
#define VIEWPORT_HEIGHT	9

#define CONNECTION_NORTH	0
#define CONNECTION_SOUTH	1
#define CONNECTION_WEST		2
#define CONNECTION_EAST		3
#define OUTSIDE_MAP			36
#define DUNGEON_FOREST		3

//warp stuff
#define WARP_TILE			0
#define WARP_TO_OUTSIDE		1
#define ELEVATOR_MAP		237
#define WARP_TYPE_NORMAL	0
#define WARP_TYPE_SET		1

#define WATER_TILE 20
#define FLOWER_TILE 3
#define ANIMATION_TIMER 22

#define ENTITY_LIMIT		60
#define ENTITY_WALKSTART	12
#define ENTITY_DOWN			0
#define ENTITY_UP			1
#define ENTITY_LEFT			2
#define ENTITY_RIGHT		3
#define ISNPC(n) (n <= ENTITY_LIMIT)
#define STEP_TIMER			64.0f / 60.0f
#define DELTAX(n) (n == ENTITY_LEFT ? -1 : n == ENTITY_RIGHT ? 1 : 0)
#define DELTAY(n) (n == ENTITY_UP ? -1 : n == ENTITY_DOWN ? 1 : 0)
#define MOVEMENT_NORMAL		0
#define MOVEMENT_WALL		1
#define MOVEMENT_JUMP		2
#define MOVEMENT_NONE		255
#define JUMP_STEPS			16

//movement types
#define MTYPE_DIRECTIONAL	255
#define MTYPE_WALK			254
#define RANDOM_WALK			2
#define MDIR_ANY			0
#define MDIR_NONE			255
#define MDIR_DOWN			208
#define MDIR_UP				209
#define MDIR_LEFT			210
#define MDIR_RIGHT			211
#define MDIR_VERTICAL		1
#define MDIR_HORIZONTAL		2

#define MENU_BLANK			31
#define MENU_CORNER_UL		25
#define MENU_H				26
#define MENU_CORNER_UR		27
#define MENU_V				28
#define MENU_CORNER_DL		29
#define MENU_CORNER_DR		30
#define MENU_DELAY_TIME		20
#define CURSOR_ACTIVE		109
#define CURSOR_INACTIVE 	108
#define CURSOR_MORE			110
#define CURSOR_MORE_TIME	60
#define CURSOR_VIS_TIME		4
#define TEXT_SPEED_SLOW		1
#define TEXT_SPEED_MEDIUM	1
#define TEXT_SPEED_FAST		3
#define TEXT_TIMER_SLOW		6
#define TEXT_TIMER_MEDIUM	3
#define	TEXT_TIMER_FAST		3
#define TEXT_TIMER_BLANK	20
#define TEXT_TIMER_PAUSE	35
#define TEXT_AUTOCLOSE_MAX	80

#define MESSAGE_AUTOCLOSE	0x4E
#define MESSAGE_LINE		0x4F
#define MESSAGE_ENDNAME		0x50
#define MESSAGE_PARA		0x51
#define MESSAGE_POKE		0x54
#define MESSAGE_SCROLL		0x55
#define MESSAGE_END			0x57
#define MESSAGE_PROMPT		0x58
#define MESSAGE_PAUSE		0x5A
#define MESSAGE_SOUND		0x5B

#define MAX_ITEMS			20

//#define DEFAULT_PALETTE { sf::Color(255, 255, 255, 255), sf::Color(168, 168, 168, 255), sf::Color(96, 96, 96, 255), sf::Color(0, 0, 0, 255)}
#define DEFAULT_PALETTE_0 sf::Color(255, 255, 255, 255)
#define DEFAULT_PALETTE_1 sf::Color(168, 168, 168, 255)
#define DEFAULT_PALETTE_2 sf::Color(96, 96, 96, 255)
#define DEFAULT_PALETTE_3 sf::Color(0, 0, 0, 255)
#define PAL_0_RGBA	4177066239
#define PAL_1_RGBA	2829625599
#define PAL_2_RGBA	1616929023
#define PAL_3_RGBA	255
#define POKE_DEFAULT_PAL	16

//temporary input
#define INPUT_UP		sf::Keyboard::Key::Up
#define INPUT_DOWN		sf::Keyboard::Key::Down
#define INPUT_LEFT		sf::Keyboard::Key::Left
#define INPUT_RIGHT		sf::Keyboard::Key::Right
#define INPUT_A			sf::Keyboard::Key::X
#define INPUT_B			sf::Keyboard::Key::Z
#define INPUT_START		sf::Keyboard::Key::Enter
#define INPUT_SELECT	sf::Keyboard::Key::RShift

//evolutions
#define EVOLUTION_NONE		0
#define EVOLUTION_LEVEL		1
#define EVOLUTION_ITEM		2
#define EVOLUTION_TRADE		3

#define EV_MAXVITAMIN		25600

#define TRAINER_MUSIC_BASE 141
