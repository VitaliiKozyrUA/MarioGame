#include<string>
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<thread>
#include<stdlib.h>
#include <vector>
using namespace std;

//vars
int frame_rate = 40;
int velocity = 40;
int jumpvelocity = 50;
int jump_plus = 20;
int move_x = 25;
int move_y = 15;
int start = 0;
int absolute_x = 25;
int incremate = 1;
int jump_height = 6;
int losses = 0;
int legs_pos = 0;
std::string check_1; //LEGS
std::string check_2; //HEAD
std::string check_above;
std::string check_below;

//3600 spaces
std::string fresh = "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                ";

bool isJUMP = false;
bool stop_x_ = false;
bool stop_x = false;
bool stop_jump = false;
bool stop_jump_below = false;
bool needtorefresh = true;
bool need_sound = false;
bool game_over = false;
bool stop = false;
bool main_stop = false;
bool start_game = false;
bool defeat_stop = false;
bool developer_mode = false;
bool victory = false;

//CHARACTER
std::string character_head_left = "(. )";
std::string character_head_right = "( .)";
std::string character_head_bottom = " {}";
std::string character_legs_forward_1 = " ||";
std::string character_legs_forward_2 = " |\\";
std::string character_legs_forward_3 = " /\\";
std::string character_legs_forward_4 = " /|";
std::string character_legs_forward_jump = " ][";
std::string head = character_head_right;
std::string legs = character_legs_forward_1;

//CHARACTER

//MAP
std::string slice_1 =   "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ";
std::string slice_2 =   "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ";
std::string slice_3 =   "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ";
std::string slice_4 =   "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ";
std::string slice_5 =   "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ";
std::string slice_6 =   "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ";
std::string slice_7 =   "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ";
std::string slice_8 =   "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ";
std::string slice_9 =   "                                                                                                                          |''''|     |''''|     |''''|                                                                                                                                                                                                                                                                                                                                                                                             ";
std::string slice_10 =  "                                                                                                                          |....|     |....|     |....|                                                                                                                                                                                                                                                                                                                                                                                             ";
std::string slice_11 =  "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ";
std::string slice_12 =  "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ";
std::string slice_13 =  "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ";
std::string slice_14 =  "                                                                                   o|o                                                                                                   o|o                                                                                                                                                                                                                                                                                                                                ";
std::string slice_15 =  "                                                                                  o|||o                                                                                                 o|||o                                                                                                                                                                                                                                                                                                                                    ";
std::string slice_16 =  "                                                                         |:::::::::::::::::::::|              |''''|      |''''|     |''''|     |''''|      |''''|              |:::::::::::::::::::::|              |'''     '''|                                                                                                                                                                                                                                                                                                                                                                                      ";
std::string slice_17 =  "                                                                                                              |....|      |....|     |....|     |....|      |....|                                                   |           |                                                                                                                                                                                                                                                                                                             ";
std::string slice_18 =  "                                                                                                              |....|                                        |....|                                                   |           |                                                                                                                                                                                                                                                                                    ";
std::string slice_19 =  "                                                                                                              |....|                                        |....|                                                   |           |                                       |::|                                                                  |::|''III''|::|                                                                                                                                                                             ";
std::string slice_20 =  "                                                                                                              |....|                                        |....|                                                   |           |                           |::|        |  |                                                       |::|       |  |NOT BAD|  |                                                                                                                                                     ";
std::string slice_21 =  "                                                             |''''|                                           |....|                                        |....|                                                   |           |               |::|        |  |        |  |                                      |::|                        |  |..III..|  |                                                                                                                                                                               ";
std::string slice_22 =  "                                                             |....|                                           |....|                                        |....|                                                   |                           |  |        |  |        |  |                |::|                                              |  |       |  |                                                                                                                                                                              ";
std::string slice_23 =  "                                           |''''|                                                             |....|                                        |....|                                                   |                           |  |        |  |        |  |      |::|                   |::|                                 |  |       |  |                                                                                                                                                                                    ";
std::string slice_24 =  "                                           |    |                                                             |....|                                        |....|                                                   |                           |  |        |  |        |  |                                                                  |  |       |  |                                                                                                                                                                                                 ";
std::string slice_25 =  "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ|                        |ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZoooooZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               ";
std::string slice_26 =  "|   |   |   |   |   |   |   |   |   |   |   |   |                        |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ";
std::string slice_27 =  "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZooooooooooooooooooooooooZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       ";
std::string slice_28 =  "|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ";
std::string slice_29 =  "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
std::string _slice_1;
std::string _slice_2;
std::string _slice_3;
std::string _slice_4;
std::string _slice_5;
std::string _slice_6;
std::string _slice_7;
std::string _slice_8;
std::string _slice_9;
std::string _slice_10;
std::string _slice_11;
std::string _slice_12;
std::string _slice_13;
std::string _slice_14;
std::string _slice_15;
std::string _slice_16;
std::string _slice_17;
std::string _slice_18;
std::string _slice_19;
std::string _slice_20;
std::string _slice_21;
std::string _slice_22;
std::string _slice_23;
std::string _slice_24;
std::string _slice_25;
std::string _slice_26;
std::string _slice_27;
std::string _slice_28;
std::string _slice_29;
//MAP

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};

void start_page() {
	while (start_game == false) {
		gotoxy(0, 0);
		cout << fresh;
		gotoxy(2, 6);
		cout << "  ___                           ___     _         ";
		gotoxy(2, 7);
		cout << " | _ \\  _ _   ___   ___  ___   | __|   | |_   ___ ";
		gotoxy(2, 8);
		cout << " |  _/ | '_| / -_) (_-< (_-<   | _|    |  _| / _ \\";
		gotoxy(2, 9);
		cout << " |_|   |_|   \\___| /__/ /__/   |_|      \\__| \\___/";

		//-----------------
		gotoxy(15, 12);
		cout << "   _____   _______              _____    _______      _____              __  __   ______ ";
		gotoxy(15, 13);
		cout << "  / ____| |__   __|     /\\     |  __ \\  |__   __|    / ____|     /\\     |  \\/  | |  ____|";
		gotoxy(15, 14);
		cout << " | (___      | |       /  \\    | |__) |    | |      | |  __     /  \\    | \\  / | | |__   ";
		gotoxy(15, 15);
		cout << "  \\___ \\     | |      / /\\ \\   |  _  /     | |      | | |_ |   / /\\ \\   | |\\/| | |  __|  ";
		gotoxy(15, 16);
		cout << "  ____) |    | |     / ____ \\  | | \\ \\     | |      | |__| |  / ____ \\  | |  | | | |____ ";
		gotoxy(15, 17);
		cout << " |_____/     |_|    /_/    \\_\\ |_|  \\_\\    |_|       \\_____| /_/    \\_\\ |_|  |_| |______|";
		
		gotoxy(3, 25);
		cout << "Use A, D and Space to control the charecter.  |";
		gotoxy(3, 26);
		cout << "Beware of these objects - o.                  |";
		gotoxy(3, 27);
		cout << "Use R to restart the game.                    |";
		gotoxy(3, 28);
		cout << "Use X to exit the game.                       |";
		gotoxy(52, 25);
		cout << "Customize the screen refresh rate(D + | A - ).";
		gotoxy(52, 27);
		cout << "One frame per " << frame_rate << " ms";
		gotoxy(101, 28);
		cout << "Creator: Vitalya";

		gotoxy(0, 0);
		cout << "";
		
		if (GetAsyncKeyState('D') & 0x8000 && frame_rate != 100) {
			frame_rate += 1;
		}

		if (GetAsyncKeyState('A') & 0x8000 && frame_rate != 0) {
			frame_rate -= 1;
		}
		if (GetAsyncKeyState('X') & 0x8000) {
			gotoxy(0, 0);
			cout << fresh;
			exit(1);
		}
		Sleep(50);
		if (GetAsyncKeyState('F') & 0x8000) { start_game = true; }
	}
}

void victory_page() {
	while (true){
		gotoxy(25, 12);
		cout << " __      __  _____    _____   _______    ____    _____   __     __  _ ";
		gotoxy(25, 13);
		cout << " \\ \\    / / |_   _|  / ____| |__   __|  / __ \\  |  __ \\  \\ \\   / / | |";
		gotoxy(25, 14);
		cout << "  \\ \\  / /    | |   | |         | |    | |  | | | |__) |  \\ \\_/ /  | |";
		gotoxy(25, 15);
		cout << "   \\ \\/ /     | |   | |         | |    | |  | | |  _  /    \\   /   | |";
		gotoxy(25, 16);
		cout << "    \\  /     _| |_  | |____     | |    | |__| | | | \\ \\     | |    |_|";
		gotoxy(25, 17);
		cout << "     \\/     |_____|  \\_____|    |_|     \\____/  |_|  \\_\\    |_|    (_)";
		gotoxy(0, 0);
		Sleep(5000);
		exit(1);
	}
}

void sounds() {
	while (true) {
		if (victory == true) {
			return;
		}
		if (stop == false) {
			if (need_sound == true) {
				Beep(200, 200);
			}
		}
		else { }
	}
}

void defeat_func() {
	losses += 1;

	stop = true;

	//vars
	move_x = 25;
	move_y = 15;
	start = 0;
	absolute_x = 25;
	incremate = 1;
	legs_pos = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       

	isJUMP = false;
	stop_x_ = false;
	stop_x = false;
	stop_jump = false;
	stop_jump_below = false;
	needtorefresh = true;
	need_sound = false;
	game_over = false;
	main_stop = false;
	start_game = false;
	defeat_stop = true;
	head = character_head_right;
}

void jumpfunc() {
	while (true) {
		if (victory == true) {
			return;
		}
		if (stop == false) {
			//COLISSION
			switch (move_y) {
			case 23: check_below = slice_29; break;
			case 22: check_below = slice_28; break;
			case 21: check_below = slice_27; break;
			case 20: check_below = slice_26; break;
			case 19: check_below = slice_25; break;
			case 18: check_below = slice_24; break;
			case 17: check_below = slice_23; break;
			case 16: check_below = slice_22; break;
			case 15: check_below = slice_21; break;
			case 14: check_below = slice_20; break;
			case 13: check_below = slice_19; break;
			case 12: check_below = slice_18; break;
			case 11: check_below = slice_17; break;
			case 10: check_below = slice_16; break;
			case 9: check_below = slice_15; break;
			case 8: check_below = slice_14; break;
			case 7: check_below = slice_13; break;
			case 6: check_below = slice_12; break;
			case 5: check_below = slice_11; break;
			case 4: check_below = slice_10; break;
			case 3: check_below = slice_9; break;
			case 2: check_below = slice_8; break;
			case 1: check_below = slice_7; break;
			}

			if (check_below[absolute_x] == 'o' || check_below[absolute_x + 3] == 'o') {
				defeat_func();
			}
			if (check_below[absolute_x + 1] == 'I') {
				victory = true;
			}
			if (check_below[absolute_x] != ' ' || check_below[absolute_x + 3] != ' ') {
				stop_jump_below = true;
				isJUMP = false;
				incremate = 0;
			}
			else {
				stop_jump_below = false;
				isJUMP = true;
				move_y += 1;
				legs = character_legs_forward_1;
				Sleep(jumpvelocity - jump_plus);
			}
			//COLISSION
			check_above = ' ';
			check_below = ' ';
			Sleep(10);
			need_sound = false;
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 && isJUMP == false) {
				stop_jump = false;
				stop_jump_below = false;
				isJUMP = true;
				legs = character_legs_forward_jump;
				while (stop_jump == false) {
					//COLISSION
					switch (move_y) {
					case 25: check_above = slice_26; break;
					case 24: check_above = slice_25; break;
					case 23: check_above = slice_24; break;
					case 22: check_above = slice_23; break;
					case 21: check_above = slice_22; break;
					case 20: check_above = slice_21; break;
					case 19: check_above = slice_20; break;
					case 18: check_above = slice_19; break;
					case 17: check_above = slice_18; break;
					case 16: check_above = slice_17; break;
					case 15: check_above = slice_16; break;
					case 14: check_above = slice_15; break;
					case 13: check_above = slice_14; break;
					case 12: check_above = slice_13; break;
					case 11: check_above = slice_12; break;
					case 10: check_above = slice_11; break;
					case 9: check_above = slice_10; break;
					case 8: check_above = slice_9; break;
					case 7: check_above = slice_8; break;
					case 6: check_above = slice_7; break;
					case 5: check_above = slice_6; break;
					case 4: check_above = slice_5; break;
					case 3: check_above = slice_4; break;
					case 2: check_above = slice_3; break;
					case 1: check_above = slice_2; break;
					}

					if (check_above[absolute_x] != ' ' || check_above[absolute_x + 3] != ' ' || check_above[absolute_x + 1] != ' ' || check_above[absolute_x + 2] != ' ') {
						stop_jump = true;
					}
					else {
						stop_jump = false;
						Sleep(jumpvelocity);
						incremate += 1;
					}
					if (incremate == jump_height) {
						incremate = 0;
						stop_jump = true;
					}
					move_y -= 1;
				}
				//COLISSION	

				while (stop_jump_below == false) {
					Sleep(jumpvelocity - jump_plus);
					move_y += 1;

					//COLISSION
					switch (move_y) {
					case 23: check_below = slice_29; break;
					case 22: check_below = slice_28; break;
					case 21: check_below = slice_27; break;
					case 20: check_below = slice_26; break;
					case 19: check_below = slice_25; break;
					case 18: check_below = slice_24; break;
					case 17: check_below = slice_23; break;
					case 16: check_below = slice_22; break;
					case 15: check_below = slice_21; break;
					case 14: check_below = slice_20; break;
					case 13: check_below = slice_19; break;
					case 12: check_below = slice_18; break;
					case 11: check_below = slice_17; break;
					case 10: check_below = slice_16; break;
					case 9: check_below = slice_15; break;
					case 8: check_below = slice_14; break;
					case 7: check_below = slice_13; break;
					case 6: check_below = slice_12; break;
					case 5: check_below = slice_11; break;
					case 4: check_below = slice_10; break;
					case 3: check_below = slice_9; break;
					case 2: check_below = slice_8; break;
					case 1: check_below = slice_7; break;
					}
					if (check_below[absolute_x] != ' ' || check_below[absolute_x + 3] != ' ') {
						stop_jump_below = true;
					}
					else {
						stop_jump_below = false;
					}
					//COLISSION
				}


				need_sound = true;
				Sleep(jumpvelocity);

				isJUMP = false;
				legs = character_legs_forward_1;
			}
		}
		else {}
	}
}

void moveX() {
	while (true) {
		if (victory == true) {
			return;
		}
		if (stop == false) {
			//COLISSION
			switch (move_y) {
			case 23: check_1 = slice_28; check_2 = slice_26; break;
			case 22: check_1 = slice_27; check_2 = slice_25; break;
			case 21: check_1 = slice_26; check_2 = slice_24; break;
			case 20: check_1 = slice_25; check_2 = slice_23; break;
			case 19: check_1 = slice_24; check_2 = slice_22; break;
			case 18: check_1 = slice_23; check_2 = slice_21; break;
			case 17: check_1 = slice_22; check_2 = slice_20; break;
			case 16: check_1 = slice_21; check_2 = slice_19; break;
			case 15: check_1 = slice_20; check_2 = slice_18; break;
			case 14: check_1 = slice_19; check_2 = slice_17; break;
			case 13: check_1 = slice_18; check_2 = slice_16; break;
			case 12: check_1 = slice_17; check_2 = slice_15; break;
			case 11: check_1 = slice_16; check_2 = slice_14; break;
			case 10: check_1 = slice_15; check_2 = slice_13; break;
			case 9: check_1 = slice_14; check_2 = slice_12; break;
			case 8: check_1 = slice_13; check_2 = slice_11; break;
			case 7: check_1 = slice_12; check_2 = slice_10; break;
			case 6: check_1 = slice_11; check_2 = slice_9; break;
			case 5: check_1 = slice_10; check_2 = slice_8; break;
			case 4: check_1 = slice_9; check_2 = slice_7; break;
			case 3: check_1 = slice_8; check_2 = slice_6; break;
			case 2: check_1 = slice_7; check_2 = slice_5; break;
			case 1: check_1 = slice_6; check_2 = slice_4; break;
			}
			if (check_1[absolute_x + 4] == 'o' || check_2[absolute_x + 4] == 'o') {
				defeat_func();
			}
			else if (check_1[absolute_x - 1] == 'o' || check_2[absolute_x - 1] == 'o') {
				defeat_func();
			}
			if (check_1[absolute_x + 4] != ' ' || check_2[absolute_x + 4] != ' ') { stop_x = true; }
			else if (check_1[absolute_x - 1] != ' ' || check_2[absolute_x - 1] != ' ') { stop_x_ = true; }
			else { stop_x = false; stop_x_ = false; }
			//COLISSION


			if (GetAsyncKeyState('D') & 0x8000) {
				stop_x_ = false;
				if (stop_x == false || developer_mode == true) {
					if (legs_pos == 3) { legs_pos = 0; legs = character_legs_forward_4; }
					if (legs_pos == 2) { legs_pos += 1; legs = character_legs_forward_3; }
					if (legs_pos == 1) { legs_pos += 1; legs = character_legs_forward_2; }
					if (legs_pos == 0) { legs_pos += 1; legs = character_legs_forward_1; }

					if (isJUMP == true) { legs = character_legs_forward_jump; }
					if (move_x == 57) { start += 1; absolute_x += 1; }
					else { move_x += 1; absolute_x += 1; }
					head = character_head_right;
					Sleep(velocity);
				}
				if (stop_x == true) { legs = character_legs_forward_1; }
			}
			else if (GetAsyncKeyState('A') & 0x8000) {
				stop_x = false;
				if (stop_x_ == false || developer_mode == true) {
					if (legs_pos == 3) { legs_pos = 0; legs = character_legs_forward_4; }
					if (legs_pos == 2) { legs_pos += 1; legs = character_legs_forward_3; }
					if (legs_pos == 1) { legs_pos += 1; legs = character_legs_forward_2; }
					if (legs_pos == 0) { legs_pos += 1; legs = character_legs_forward_1; }
					if (isJUMP == true) { legs = character_legs_forward_jump; }
					if (move_x < 58 && move_x != 21) { move_x -= 1; absolute_x -= 1; }
					if (move_x <= 22 && start >= 1) { start -= 1; absolute_x -= 1; }
					head = character_head_left;
					Sleep(velocity);
				}
				if (stop_x == true) { legs = character_legs_forward_1; }
			}
		}
		else { }
	}
}

void control () {
	int pause_count = 0;
	while (true) {
		if (victory == true) {
			return;
		}
		if (true == true) {
			if (GetAsyncKeyState('N') & 0x8000 && GetAsyncKeyState('M') & 0x8000) {
				if (developer_mode == false) {
					developer_mode = true;
					Sleep(30);
				}
				else if (developer_mode == true) {
					developer_mode = false;
					Sleep(30);
				}
			}
			if (GetAsyncKeyState('W') & 0x8000 && developer_mode == true) {
				move_y -= 1;
				Sleep(30);
			}
			if (GetAsyncKeyState('R') & 0x8000) {
				move_x = 25;
				move_y = 15;
				start = 0;
				absolute_x = 25;
				isJUMP = false;
				stop_x_ = false;
				stop_x = false;
				stop_jump = false;
				stop_jump_below = false;
				needtorefresh = true;
				need_sound = false;
				game_over = false;
				main_stop = false;
				start_game = false;
				head = character_head_right;
			}

			if (GetAsyncKeyState('X') & 0x8000) {
				gotoxy(0, 0);
				cout << fresh;
				exit(1);
			}

			if (GetAsyncKeyState('P') & 0x8000) {
				main_stop = true;
				Sleep(100);
			}

			if (GetAsyncKeyState('L') & 0x8000) {
				main_stop = false;
				Sleep(100);
			}
		}
		else { }
	}
}

void refreshmap() {
	while (true) {
		if (victory == true) {
			gotoxy(0, 0);
			cout << fresh;
			return;
		}
		if (GetAsyncKeyState('X') & 0x8000) {
			gotoxy(0, 0);
			cout << fresh;
			exit(1);
		}
		gotoxy(0, 0);
		cout << fresh;
		if (defeat_stop == false) {
			//REFRESH
			_slice_29 = "";
			_slice_28 = "";
			_slice_27 = "";
			_slice_26 = "";
			_slice_25 = "";
			_slice_24 = "";
			_slice_23 = "";
			_slice_22 = "";
			_slice_21 = "";
			_slice_20 = "";
			_slice_19 = "";
			_slice_18 = "";
			_slice_17 = "";
			_slice_16 = "";
			_slice_15 = "";
			_slice_14 = "";
			_slice_13 = "";
			_slice_12 = "";
			_slice_11 = "";
			_slice_10 = "";
			_slice_9 = "";
			_slice_8 = "";
			_slice_7 = "";
			_slice_6 = "";
			_slice_5 = "";
			_slice_4 = "";
			_slice_3 = "";
			_slice_2 = "";
			_slice_1 = "";
			//REFRESH

			//MAP
			for (int i = start; i < start + 120; ++i) {
				_slice_29.operator+=(slice_29[i]);
				_slice_28.operator+=(slice_28[i]);
				_slice_27.operator+=(slice_27[i]);
				_slice_26.operator+=(slice_26[i]);
				_slice_25.operator+=(slice_25[i]);
				_slice_24.operator+=(slice_24[i]);
				_slice_23.operator+=(slice_23[i]);
				_slice_22.operator+=(slice_22[i]);
				_slice_21.operator+=(slice_21[i]);
				_slice_20.operator+=(slice_20[i]);
				_slice_19.operator+=(slice_19[i]);
				_slice_18.operator+=(slice_18[i]);
				_slice_17.operator+=(slice_17[i]);
				_slice_16.operator+=(slice_16[i]);
				_slice_15.operator+=(slice_15[i]);
				_slice_14.operator+=(slice_14[i]);
				_slice_13.operator+=(slice_13[i]);
				_slice_12.operator+=(slice_12[i]);
				_slice_11.operator+=(slice_11[i]);
				_slice_10.operator+=(slice_10[i]);
				_slice_9.operator+=(slice_9[i]);
				_slice_8.operator+=(slice_8[i]);
				_slice_7.operator+=(slice_7[i]);
				_slice_6.operator+=(slice_6[i]);
				_slice_5.operator+=(slice_5[i]);
				_slice_4.operator+=(slice_4[i]);
				_slice_3.operator+=(slice_3[i]);
				_slice_2.operator+=(slice_2[i]);
				_slice_1.operator+=(slice_1[i]);
			}
			gotoxy(0, 29);
			cout << _slice_29;
			gotoxy(0, 28);
			cout << _slice_28;
			gotoxy(0, 27);
			cout << _slice_27;
			gotoxy(0, 26);
			cout << _slice_26;
			gotoxy(0, 25);
			cout << _slice_25;
			gotoxy(0, 24);
			cout << _slice_24;
			gotoxy(0, 23);
			cout << _slice_23;
			gotoxy(0, 22);
			cout << _slice_22;
			gotoxy(0, 21);
			cout << _slice_21;
			gotoxy(0, 20);
			cout << _slice_20;
			gotoxy(0, 19);
			cout << _slice_19;
			gotoxy(0, 18);
			cout << _slice_18;
			gotoxy(0, 17);
			cout << _slice_17;
			gotoxy(0, 16);
			cout << _slice_16;
			gotoxy(0, 15);
			cout << _slice_15;
			gotoxy(0, 14);
			cout << _slice_14;
			gotoxy(0, 13);
			cout << _slice_13;
			gotoxy(0, 12);
			cout << _slice_12;
			gotoxy(0, 11);
			cout << _slice_11;
			gotoxy(0, 10);
			cout << _slice_10;
			gotoxy(0, 9);
			cout << _slice_9;
			gotoxy(0, 8);
			cout << _slice_8;
			gotoxy(0, 7);
			cout << _slice_7;
			gotoxy(0, 6);
			cout << _slice_6;
			gotoxy(0, 5);
			cout << _slice_5;
			gotoxy(0, 4);
			cout << _slice_4;
			gotoxy(0, 3);
			cout << _slice_3;
			gotoxy(0, 2);
			cout << _slice_2;
			gotoxy(0, 1);
			cout << _slice_1;
			//MAP

			//CHARACTER
			gotoxy(move_x, move_y + 3);
			cout << head;
			gotoxy(move_x, move_y + 4);
			cout << character_head_bottom;
			gotoxy(move_x, move_y + 5);
			cout << legs;
			//CHARACTER
			gotoxy(3, 1);
			cout << "Losses: " << losses;
			gotoxy(0, 0);
		}
	else{
		gotoxy(30, 12);
		cout << "  _____    ______   ______   ______              _______ ";
		gotoxy(30, 13);
		cout << " |  __ \\  |  ____| |  ____| |  ____|     /\\     |__   __|";
		gotoxy(30, 14);
		cout << " | |  | | | |__    | |__    | |__       /  \\       | |   ";
		gotoxy(30, 15);
		cout << " | |  | | |  __|   |  __|   |  __|     / /\\ \\      | |   ";
		gotoxy(30, 16);
		cout << " | |__| | | |____  | |      | |____   / ____ \\     | |   ";
		gotoxy(30, 17);
		cout << " |_____/  |______| |_|      |______| /_/    \\_\\    |_|  ";
		gotoxy(0, 0);
		Sleep(1000);
		defeat_stop = false;
		stop = false;
		}
		Sleep(frame_rate);
	}
}

void start_threads() {
	thread t1(jumpfunc);
	thread t2(refreshmap);
	thread t3(moveX);
	thread t4(sounds);
	thread t5(control);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
}

int main()
{
	system("mode con cols=120 lines=30");
	system("color 70");
	start_page();
	start_threads();
	victory_page();
}