#pragma once
#include "Includes.h"


#define CAMH 200
#define CAMW 500
class myGame
{
public:
	myGame();
	~myGame();
	void Init();
	int Create();

	int LoadRoad();

	int mainEvent();
	void Close();
private:
	SDL_Window* win;
	SDL_Renderer* ren;

	SDL_Surface* first_road_surface, *bomb_surface, *optsurf, *taxi_surface, *audi_surface, *dispenser_surface,
		*minivan_surface, *policecar_surface, *screen_surface, *ring_surface, *Minitruck_surface, *optsurf2, *fuelbar_surface,
		*fuel_surface, *limo_surface, *truck_surface, *audi_menu, *blackviper_menu, *audi_text, *blackviper_text, *select_surface,
		*square_surface, *gameover_surface,*retrybutton_surface,*exitbutton_surface,*ambulance_surface,*longvehicle_surface,
		*yellowBobcat_surface,*greentruck_surface,*familycar_surface,*firstbullet_surface,*smallbobcat_surface,*pause_surface,
		*pausebutton_surface,*resumebutton_surface;
		
	


	SDL_Texture* first_road_texture, *bomb_texture, *taxi_texture, *audi_texture, *minivan_texture, *dispenser_texture,
		*policecar_texture, *ring_texture, *Minitruck_texture, *fuelbar_texture, *fuel_texture, *limo_texture,
		*truck_texture, *audi_menu_texture, *Blackviper_menu_texture, *audi_text_texture, *blackviper_text_texture, *select_texture,
		*square_texture,*gameover_texture,*retrybutton_texture,*exitbutton_texture,*ambulance_texture,*longvehicle_texture,
		*yellowBobcat_texture,*greentruck_texture,*familycar_texture,*firstbullet_texture[21],*smallbobcat_texture,*pause_texture,
		*pausebutton_texture,*resumebutton_texture;
		
	
	
	
	chrono::steady_clock::time_point time_one;
	chrono::steady_clock::time_point time_two;
	int when_to_stop_render_ring = 0;

	chrono::steady_clock::time_point time_one_when_screen_move_false;
	chrono::steady_clock::time_point time_two_when_screen_move_false;



	SDL_Rect first_Road_dest, bomb_dest, bomb_dest2, bomb_dest3, taxi_dest, audi_dest, minivan_dest, policecar_dest, policecar_dest_2,
		policecar_source[3], viewport_left, viewport_right, audi_text_viewport,blackviper_text_viewport,select_viewport,
		square_position,retrybutton_position, exitbutton_position,retrybutton_source[2], exitbutton_source[2],pause_position;

	SDL_Rect first_road_campos, explosion_position, ring_position, minitruck_position, dispenser_position, fuelbar_position,
		fuel_position, limo_position, truck_position, gameover_position, ambulance_source[3], ambulance_position, longvehicle_position,
		yellowBobcat_position, greentruck_position, familycar_position, firstbullet_position[21], smallbobcat_position,
		pausebutton_source[2], pausebutton_position;

	SDL_Point* center;
	SDL_RendererFlip flip;

	int LoadTaxi();
	int TaxiTexture();
	void RenderTaxi();

	void LoadAudi();
	void AudiTexture();
	void RenderAudi();

	void LoadBlackviper();
	int which_car_to_load = 0;

	int fuel_appear_once = 0;

	void RenderAudiOffScreen();
	void CreateAudi();
	void LoadPoliceCar();
	void PoliceCarTexture();
	void RenderPoliceCar(int& frame);
	void RenderpoliceCar2(int& frame);



	void LoadMiniVan();
	void MiniVanTexture();
	void RenderMiniVan();
	
	bool DetectCollisionWithVan();
	bool DectectCollsionWithBomb_one();
	bool DetectCollisionWithBomb_two();
	bool DetectCollisionWithBomb_three();

	bool DetectCollisionWithTaxi_one();
	bool DetectCollisionWithCop_one();
	bool DetectCollisionWithCop_two();
	bool DetectEastboundaryCollision();
	bool DetectWestboudaryCollision();
	bool DetectCollisionWithMinitruck();
	bool DetectCollisionWithAmbulance();
	bool DeTectCollisionWithLongvehicle();
	bool DetectCollisionWithYellowBobcat();
	bool DetectCollisionWithGreeenTruck();
	bool DetectCollisionWithFamilyCar();
	bool DetectCollisionWithSmallBobcat();


	void ResetRoad_one();
	void AccelerateScreen();
	
	void RenderExplosion();

	int LoadBomb();
	int BombTexture();
	int RenderBomb();
	int RenderBomb_2();
	int RenderBomb_3();

	bool Running;
	bool Selection;
	bool pause;
	bool Movescreen;
	bool Gameover;
	double angle;

	int LoadRing();
	int RingTexture();
	isRingrendered RenderRing(int&);

	void CheckAllCollision(isRingrendered&);
	void HoldCollision(bool);

	int LoadMinitruck();
	int MinitruckTexture();
	void RenderMinitruck();

	int LoadDispenser();
	int DispenserTexture();
	void RenderDispenser();

	int LoadFuelBar();
	int FuelBarTexture();
	void RenderFuelBar();

	int LoadFuel();
	int FuelTexture();
	void RenderFuel(chrono::steady_clock::duration&);
	bool DetectCollisionWithFuel();

	int LoadCar();
	int CarTexture();
	void RenderCar();
	bool DetectCollisionWithLimo();

	void DestroyAllPastTextures();
	void ResetAllPositions();

	int LoadTruck();
	int TruckTexture();
	void RenderTruck();
	bool DetectCollisionWithTruck();

	void LoadMenuItems();
	
	int LoadGameover();
	int TextureGameover();
	void RenderGameover();

	int LoadRetrybutton();
	int TextureRetryButton();
	void RenderRetryButton(int&);

	int LoadExitbutton();
	int TextureExitButton();
	void RenderExitButton(int&);

	int LoadAmbulance();
	int TextureAmbulance();
	void RenderAmbulance(int&);

	int LoadLongVehicle();
	int TextureLongVehicle();
	void RenderLoadVehicle();

	int LoadYellowBobcat();
	int TextureYellowBobcat();
	void RenderYellowBobcat();

	int LoadGreenTruck();
	int TextureGreenTruck();
	void RenderGreenTruck();

	int LoadFamilyCar();
	int TextureFamilyCar();
	void RenderFamilyCar();

	int LoadFirstBullet();
	void TextureFirstBullet();
	void RenderFirstBullet_zero();
	void RenderFirstBullet_one();
	void RenderFirstBullet_two();
	void RenderFirstBullet_three();
	void RenderFirstBullet_four();
	void RenderFirstBullet_five();
	void RenderFirstBullet_six();
	void RenderFirstBullet_seven();
	void RenderFirstBullet_eight();
	void RenderFirstBullet_nine();
	void RenderFirstBullet_ten();
	void RenderFirstBullet_eleven();
	void RenderFirstBullet_twelve();
	void RenderFirstBullet_thirteen();
	void RenderFirstBullet_fourteen();
	void RenderFirstBullet_fifteen();
	void RenderFirstBullet_sixteen();
	void RenderFirstBullet_seventeen();
	void RenderFirstBullet_eighteen();
	void RenderFirstBullet_nineteen();
	void RenderFirstBullet_twenty();

	int LoadSmallBobcat();
	int TextureSmallBobcat();
	void RenderSmallBobcat();


	void LoadPause();
	void TexturePause();
	void RenderPause(Uint8&);

	void LoadPauseButton();
	void RenderPauseButton(int&);

	void LoadResumeButton();
	void RenderResumeButton(int&);


	int theWholeGame();
	void thePauseLoop();
	int theGameOverLoop();
	int theSelectionLoop();

	int wait = 0;
	const Uint8* keystate = 0;
	int counter = 500;
	isRingrendered ringpresent = isRingrendered::ABSENT;
	int frame = 0;
	int frame_for_ambulance = 0;
	long long when_to_decrease_fuel = 0;
	int bulletnumber = 0;
	bool pause_loop_entered = false;
	chrono::steady_clock::duration time_spent_during_pause = chrono::steady_clock::duration::zero();
	chrono::steady_clock::duration time_passed = chrono::steady_clock::duration::zero();

	chrono::steady_clock::duration time_spent_when_screen_move_is_false = chrono::steady_clock::duration::zero();

	int which_of_the_source_to_render = 0;
	SDL_Event evt;

	int which_button_source_to_render = 0;
	int which_button_source_to_render_2 = 0;
};