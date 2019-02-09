#pragma once
#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <chrono>
using namespace std;

#define CARFIRSTLANE 185
constexpr auto CARSECONDLANE = 220;
#define CARTHIRDLANE 270

constexpr auto FIRSTLANE = 195;
#define SECONDLANE 240
constexpr auto THIRDLANE = 285;



#define MINIVANHEIGHT 60
#define MINIVANWIDTH 70

#define COPCARWIDTH 60
#define COPCARHEIGHT 50

#define BOMBHEIGHT 20
#define BOMBWIDTH 20

#define EXPLOSIONWIDTH 40
#define EXPLOSIONHEIGHT 40

#define TAXIHEIGHT 40
#define TAXIWIDTH 50

#define AUDIWIDTH 50
#define AUDIHEIGHT 40

#define MINITRUCKWIDTH 60
#define MINITRUCKHEIGHT 50

#define SCREENHEIGHT 400
#define SCREENWIDTH 400

#define ACTUAL_AUDI_X audi_dest.x+6
#define ACTUAL_AUDI_Y audi_dest.y+4

#define ACTUAL_AUDI_WIDTH  28
#define ACTUAL_AUDI_HEIGHT 30

#define ACTUAL_MINIVAN_X minivan_dest.x+22
#define ACTUAL_MINIVAN_Y minivan_dest.y+5

#define ACTUAL_MINIVAN_WIDTH 10
#define ACTUAL_MINIVAN_HEIGHT 47

#define ACTUAL_TAXI_WIDTH 20
#define ACTUAL_TAXI_HEIGHT 35

#define ACTUAL_TAXI_X taxi_dest.x + 14
#define ACTUAL_TAXI_Y taxi_dest.y + 3


#define ACTUAL_COP_WIDTH 24
#define ACTUAL_COP_HEIGHT 42

#define ACTUAL_COP_X policecar_dest.x + 18
#define ACTUAL_COP_Y policecar_dest.y + 5

#define ACTUAL_COP2_X policecar_dest_2.x + 18
#define ACTUAL_COP2_Y policecar_dest_2.y + 5

#define ROAD_ONE_BORDER_EAST 320
#define ROAD_ONE_BORDER_WEST 172

#define ACTUAL_MINITRUCK_WIDTH 22
#define ACTUAL_MINITRUCK_HEIGHT 40

#define ACTUAL_MINITRUCK_X minitruck_position.x + 17
#define ACTUAL_MINITRUCK_Y minitruck_position.y + 7

#define ACTUAL_LIMO_X limo_position.x + 21
#define ACTUAL_LIMO_Y limo_position.y + 6

#define ACTUAL_LIMO_WIDTH 22
#define ACTUAL_LIMO_HEIGHT 77

#define ACTUAL_TRUCK_X truck_position.x + 28
#define ACTUAL_TRUCK_Y truck_position.y + 10

#define ACTUAL_TRUCK_WIDTH 28
#define ACTUAL_TRUCK_HEIGHT 83
enum class isRingrendered {ABSENT,PRESENT};
