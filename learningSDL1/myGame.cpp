#include "myGame.h"

myGame::myGame()
{
	win = nullptr;
	ren = nullptr;
	Running = true;
	Movescreen = true;
	Selection = true;
	Gameover = true;
	pause = true;
	
	ring_surface = nullptr;
	square_surface = nullptr;
	optsurf = nullptr;
	for (int i = 0; i < 21; ++i)
	{
		firstbullet_texture[i] = nullptr;
	}
	first_road_surface = nullptr;
	square_texture = nullptr;


	first_Road_dest = { 100,0,SCREENWIDTH - 100,SCREENHEIGHT };
	first_road_campos = {0,5000-SCREENHEIGHT,300, SCREENHEIGHT};
	bomb_dest = {FIRSTLANE,-5,20,20};
	bomb_dest2 = { SECONDLANE,-100,BOMBWIDTH,BOMBHEIGHT };
	bomb_dest3 = { THIRDLANE,-200,BOMBWIDTH,BOMBHEIGHT };
	explosion_position = { 0,0,EXPLOSIONWIDTH ,EXPLOSIONHEIGHT };
	taxi_dest = { CARFIRSTLANE,-500,TAXIWIDTH,TAXIHEIGHT};
	audi_dest = {220, 300,AUDIWIDTH,AUDIHEIGHT};
	minivan_dest = {CARSECONDLANE, -550, MINIVANWIDTH, MINIVANHEIGHT};
	policecar_dest = { CARTHIRDLANE,400,COPCARWIDTH,COPCARHEIGHT};
	policecar_dest_2 = { CARSECONDLANE,400,COPCARWIDTH,COPCARHEIGHT };
	policecar_source[0] = { 0,0,256,256 };
	policecar_source[1] = { 256,0,256,256 };
	policecar_source[2] = { 512,0,256,256 };
	minitruck_position = { CARTHIRDLANE,-100,MINITRUCKWIDTH,MINITRUCKHEIGHT };
	ring_position = { audi_dest.x,audi_dest.y,AUDIWIDTH,AUDIHEIGHT };
	dispenser_position = { 30,210,40,40 };
	bomb_surface = nullptr;
	bomb_texture = nullptr;
	first_road_texture = nullptr;
	taxi_surface = nullptr;
	taxi_texture = nullptr;
	audi_surface = nullptr;
	audi_texture = nullptr;
	minivan_surface = nullptr;
	minivan_texture = nullptr;
	policecar_surface = nullptr;
	policecar_texture = nullptr;
	screen_surface = nullptr;
	ring_texture = nullptr;
	Minitruck_texture = nullptr;
	Minitruck_surface = nullptr;
	optsurf2 = nullptr;
	dispenser_surface = nullptr;
	dispenser_texture = nullptr;

	fuelbar_surface = nullptr;
	fuelbar_texture = nullptr;
	limo_position = { CARSECONDLANE,-100,70,90 };
	fuelbar_position = { 34,250,20,150 };
	fuel_position = { 0,-100,20,20 };
	fuel_surface = nullptr;
	fuel_texture = nullptr;
	limo_surface = nullptr;
	limo_texture = nullptr;
	audi_menu = nullptr;
	blackviper_menu = nullptr;
	truck_surface = nullptr;
	truck_texture = nullptr;
	truck_position = { 160,-150,90,100 };
	audi_menu_texture = nullptr;
	Blackviper_menu_texture = nullptr;

	viewport_left = {100,120,100,100};
	viewport_right = { 200,125,100,100 };
	audi_text = nullptr;
	blackviper_text = nullptr;
	audi_text_texture = nullptr;
	blackviper_text_texture = nullptr;
	audi_text_viewport = { 100,85,100,40 };
	blackviper_text_viewport = { 200,85,100,40 };
	select_surface = nullptr;
	select_texture = nullptr;
	select_viewport = { 150,210,100,40 };
	
	gameover_surface = nullptr;
	gameover_texture = nullptr;
	gameover_position = { FIRSTLANE,100,100,100 };

	angle = 0.0;
	flip = SDL_FLIP_NONE;
	center = NULL;

	retrybutton_surface = nullptr;
	retrybutton_texture = nullptr;
	retrybutton_position = {20,100,60,20};
	retrybutton_source[0] = {0,0,144,40};
	retrybutton_source[1] = { 144,0,292,40 };

	exitbutton_surface = nullptr;
	exitbutton_texture = nullptr;
	exitbutton_position = { 20,130,60,20 };
	exitbutton_source[0] = { 0,0,144,40 };
	exitbutton_source[1] = { 144,0,292,40 };

	ambulance_surface = nullptr;
	ambulance_texture = nullptr;
	ambulance_position = { (THIRDLANE-5),-100,30,70 };
	ambulance_source[0] = {72,31,105,205};
	ambulance_source[1] = {245,31,105,205};
	ambulance_source[2] = {422,31,105,205};

	longvehicle_surface = nullptr;
	longvehicle_texture = nullptr;
	longvehicle_position = { (CARSECONDLANE+5),-180,50,180};

	yellowBobcat_surface = nullptr;
	yellowBobcat_texture = nullptr;
	yellowBobcat_position = {CARFIRSTLANE,-150,40,80};

	greentruck_surface = nullptr;
	greentruck_texture = nullptr;
	greentruck_position = { CARTHIRDLANE+5,-70,40,60 };

	familycar_surface = nullptr;
	familycar_texture = nullptr;
	familycar_position = { CARSECONDLANE+10,-80,35,70 };

	firstbullet_surface = nullptr;
	for (int i = 0; i < 21; ++i)
	{
		firstbullet_texture[i] = nullptr;
	}
	for (int u = 0; u < 21; ++u)
	{
		firstbullet_position[u] = { 0,0,5,3 };
	}

	smallbobcat_surface = nullptr;
	smallbobcat_texture = nullptr;
	smallbobcat_position = { CARFIRSTLANE,-180,40,70 };

	pause_surface = nullptr;
	pause_texture = nullptr;
	pause_position = { FIRSTLANE-60,100,200,50 };

	pausebutton_surface = nullptr;
	pausebutton_texture = nullptr;
	pausebutton_source[0] = {2,2,145,34};
	pausebutton_source[1] = {148,2,150,34};
	pausebutton_position = {20,100,60,20};

	resumebutton_surface = nullptr;
	resumebutton_texture = nullptr;
}
//===============================================================================================
//===============================================================================================

myGame::~myGame()
{
	Close();
	
}
//===============================================================================================
//===============================================================================================
void myGame::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL_Wasn't INITIALIZED, " << SDL_GetError() << endl;
	}
	if (IMG_Init((IMG_INIT_PNG)& IMG_INIT_PNG) < 0)
	{
		cout << "PNG wasn't INItialized, " << IMG_GetError() << endl;
	}
	if (IMG_Init((IMG_INIT_JPG)& IMG_INIT_JPG) < 0)
	{
		cout << "JPG wasn't INItialized, " << IMG_GetError() << endl;
	}
}
int myGame::Create()
{
	win = SDL_CreateWindow("RACEER", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREENWIDTH, SCREENHEIGHT, SDL_WINDOW_SHOWN);
	if (win == nullptr)
	{
		cout << "Window was not created, " << SDL_GetError() << endl;
		return -1;
	}
	else
	{
		ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (ren == nullptr)
		{
			cout << "Renderer wasn't created, " << SDL_GetError() << endl;
			return -1;
		}
	}
	//screen_surface = SDL_GetWindowSurface(win);
	screen_surface = IMG_Load("resources/Audi.png");
	SDL_SetWindowIcon(win, screen_surface);
	return 0;
}
//===============================================================================================
//===============================================================================================
int myGame::mainEvent()
{
	Init();  
	Create();

	LoadMenuItems();
	LoadBomb();
	BombTexture();
	LoadRoad();

	LoadTaxi();
	TaxiTexture();
	
	SDL_RenderCopy(ren, select_texture, NULL, &select_viewport);

	SDL_RenderCopy(ren, blackviper_text_texture, NULL, &blackviper_text_viewport);

	SDL_RenderCopy(ren, audi_text_texture, NULL, &audi_text_viewport);

	SDL_RenderCopy(ren, Blackviper_menu_texture, NULL, &viewport_right);

	SDL_RenderCopy(ren, audi_menu_texture, NULL, &viewport_left);
	
	

	//selection loop
	theSelectionLoop();
	
	
	AudiTexture();

	LoadMiniVan();
	MiniVanTexture();

	LoadPoliceCar();
	PoliceCarTexture();

	LoadRing();
	RingTexture();

	LoadMinitruck();
	MinitruckTexture();

	LoadDispenser();
	DispenserTexture();

	LoadFuelBar();
	FuelBarTexture();

	LoadFuel();
	FuelTexture();
	
	LoadCar();
	CarTexture();
	
	LoadTruck();
	TruckTexture();

	LoadAmbulance();
	TextureAmbulance();

	LoadLongVehicle();
	TextureLongVehicle();
	
	LoadYellowBobcat();
	TextureYellowBobcat();
	RenderYellowBobcat();
	
	LoadGreenTruck();
	TextureGreenTruck();

	LoadFamilyCar();
	TextureFamilyCar();
	
	LoadFirstBullet();
	TextureFirstBullet();
	
	LoadSmallBobcat();
	TextureSmallBobcat();

	LoadPause();
	TexturePause();
	
	LoadPauseButton();
	LoadResumeButton();

	LoadGameover();
	TextureGameover();

	LoadRetrybutton();
	TextureRetryButton();

	LoadExitbutton();
	TextureExitButton();



	///---------------------------///
	theWholeGame();
	//---------------------------//	
	return 0;
}




void myGame::Close()
{
	SDL_DestroyRenderer(ren);
	ren = nullptr;
	SDL_DestroyWindow(win);
	win = nullptr;
	SDL_DestroyTexture(first_road_texture);
	first_road_texture = nullptr;
	SDL_DestroyTexture(bomb_texture);
	bomb_texture = nullptr;
			SDL_DestroyTexture(first_road_texture);
			first_road_texture = nullptr;
		SDL_DestroyTexture(taxi_texture);
		taxi_texture = nullptr;
		SDL_DestroyTexture(audi_texture);
		audi_texture = nullptr;
		SDL_DestroyTexture(minivan_texture);
		minivan_texture = nullptr;
		SDL_DestroyTexture(policecar_texture);
		policecar_texture = nullptr;
		SDL_DestroyTexture(ring_texture);
		ring_texture = nullptr;
		
	IMG_Quit();
	SDL_Quit();
}
//===============================================================================================
//===============================================================================================
int myGame::LoadRoad()
{
	
	first_road_surface = IMG_Load("resources/road_one.png");
	if (first_road_surface == nullptr)
	{
		cout << "First road load error, " << IMG_GetError() << endl;
		return -1;
	}
	else
	{
		optsurf = SDL_ConvertSurface(first_road_surface, screen_surface->format, NULL);
		SDL_SetColorKey(optsurf, SDL_TRUE, SDL_MapRGB(optsurf->format, 255, 255, 255));
		first_road_texture = SDL_CreateTextureFromSurface(ren, optsurf);
		if (first_road_surface == nullptr)
		{
			cout << "First road textured wasn't created, " << SDL_GetError() << endl;
			return -1;
		}
	}
	SDL_FreeSurface(optsurf);
	optsurf = nullptr;

	SDL_FreeSurface(first_road_surface);
	first_road_surface = nullptr;
	return 0;
}
//===============================================================================================
//===============================================================================================
void myGame::ResetRoad_one()
{
	if (first_road_campos.y < 0)
	{
		first_road_campos.y = 4312 - SCREENHEIGHT;
	}
}
//===============================================================================================
//===============================================================================================
void myGame::AccelerateScreen()
{
	first_road_campos.y -= 5;
}
//===============================================================================================
//===============================================================================================
int myGame::LoadBomb()
{
	bomb_surface = IMG_Load("resources/explosion.png");
	if (bomb_surface == nullptr)
	{
		cout << "Dynamite not loaded, " << SDL_GetError() << endl;
	}
	else
	{
		optsurf = SDL_ConvertSurface(bomb_surface, bomb_surface->format, NULL);
		SDL_SetColorKey(optsurf, SDL_TRUE, SDL_MapRGB(optsurf->format, 255, 255, 255));
	}

	SDL_FreeSurface(bomb_surface);
	bomb_surface = nullptr;
	return 0;
}
//================================================================================================
//================================================================================================
int myGame::BombTexture()
{
	bomb_texture = SDL_CreateTextureFromSurface(ren, optsurf);
	if (bomb_texture == nullptr)
	{
		cout << "Bomb texture not created, " << SDL_GetError()<<endl;
	}
	SDL_FreeSurface(optsurf);
	optsurf = nullptr;
	return 0;
}
//=================================================================================================
//=================================================================================================
int myGame::RenderBomb()
{
	SDL_RenderCopy(ren, bomb_texture, NULL, &bomb_dest);
	return 0;
}
//=================================================================================================
//=================================================================================================
int myGame::RenderBomb_2()
{
	SDL_RenderCopy(ren, bomb_texture, NULL, &bomb_dest2);
	return 0;
}
//=================================================================================================
//=================================================================================================
int myGame::RenderBomb_3()
{
	SDL_RenderCopy(ren, bomb_texture, NULL, &bomb_dest3);
	return 0;
}
//=================================================================================================
//=================================================================================================
int myGame::LoadTaxi()
{
	taxi_surface = IMG_Load("resources/taxi.png");
	if (taxi_surface == nullptr)
	{
		cout << "Taxi wasn't loaded, " << IMG_GetError() << endl;
		return -1;
	}
	else
	{
		SDL_SetColorKey(taxi_surface, SDL_TRUE, SDL_MapRGB(taxi_surface->format, 255, 255, 255));
		optsurf = SDL_ConvertSurface(taxi_surface, taxi_surface->format, NULL);
		if (optsurf == nullptr)
		{
			cout << "Taxi not optimized, " << SDL_GetError() << endl;
			return -1;
		}
	}
	SDL_FreeSurface(taxi_surface);
	taxi_surface = nullptr;
	return 0;
}
//=================================================================================================
//=================================================================================================
int myGame::TaxiTexture()
{
	taxi_texture = SDL_CreateTextureFromSurface(ren, optsurf);
	if (taxi_texture == nullptr)
	{
		cout << "Taxi texture not created, " << SDL_GetError() << endl;
		return -1;
	}
	SDL_FreeSurface(optsurf);
	optsurf = nullptr;
	return 0;
}
//=================================================================================================
//=================================================================================================
void myGame::RenderTaxi()
{
	SDL_RenderCopy(ren, taxi_texture, NULL, &taxi_dest);
}
//=================================================================================================
//=================================================================================================
void myGame::LoadAudi()
{
	audi_surface = IMG_Load("resources/Audi.png");
	if (audi_surface == nullptr)
	{
		cout << "audi not loaded, " << IMG_GetError() << endl;
	}
	else
	{
		optsurf = SDL_ConvertSurface(audi_surface, audi_surface->format, NULL);
		SDL_SetColorKey(optsurf, SDL_TRUE, SDL_MapRGB(optsurf->format, 255, 255, 255));
	}
	
	SDL_FreeSurface(audi_surface);
	audi_surface = nullptr;
}
//=================================================================================================
//=================================================================================================
void myGame::AudiTexture()
{
	audi_texture = SDL_CreateTextureFromSurface(ren, optsurf);
	if (audi_texture == nullptr)
	{
		cout << "audi texture not created, " << SDL_GetError() << endl;
	}
	SDL_FreeSurface(optsurf);
	optsurf = nullptr;
}
//=================================================================================================
//=================================================================================================
void myGame::RenderAudi()
{
	SDL_RenderCopyEx(ren, audi_texture, NULL, &audi_dest, angle, center, flip);
}
//==================================================================================================
void myGame::RenderAudiOffScreen()
{
	RenderExplosion();
	SDL_DestroyTexture(audi_texture);
	audi_texture = nullptr;
	/*audi_dest.y = 1000;
	audi_dest.x = 5000;*/
	
}
//=================================================================================================
//=================================================================================================
void myGame::LoadMiniVan()
{
	minivan_surface = IMG_Load("resources/Mini_van.png");
	SDL_SetColorKey(minivan_surface, SDL_TRUE, SDL_MapRGB(minivan_surface->format, 255, 255, 255));
	optsurf = SDL_ConvertSurface(minivan_surface, minivan_surface->format, NULL);


	SDL_FreeSurface(minivan_surface);
	minivan_surface = nullptr;
}
//=================================================================================================
//=================================================================================================
void myGame::MiniVanTexture()
{
	minivan_texture = SDL_CreateTextureFromSurface(ren, optsurf);
	SDL_FreeSurface(optsurf);
	optsurf = nullptr;
}
//=================================================================================================
//=================================================================================================
void myGame::RenderMiniVan()
{
	SDL_RenderCopy(ren, minivan_texture, NULL, &minivan_dest);
}
//=================================================================================================
//=================================================================================================
void myGame::LoadPoliceCar()
{
	policecar_surface = IMG_Load("resources/1.png");
	SDL_SetColorKey(policecar_surface, SDL_TRUE, SDL_MapRGB(policecar_surface->format, 255, 255, 255));
	optsurf = SDL_ConvertSurface(policecar_surface, policecar_surface->format, NULL);

	SDL_FreeSurface(policecar_surface);
	policecar_surface = nullptr;
}
//=================================================================================================
//=================================================================================================
void myGame::PoliceCarTexture()
{
	policecar_texture = SDL_CreateTextureFromSurface(ren, optsurf);
	SDL_FreeSurface(optsurf);
	optsurf = nullptr;
}
//=================================================================================================
//=================================================================================================
void myGame::RenderPoliceCar(int& frame)
{
	SDL_RenderCopy(ren, policecar_texture, &policecar_source[frame/4], &policecar_dest);
}
//=================================================================================================
//=================================================================================================
void myGame::RenderpoliceCar2(int& frame)
{
		SDL_RenderCopy(ren, policecar_texture, &policecar_source[frame/4], &policecar_dest_2);
	
}
//======================================================================================
//======================================================================================
//======================================================================================
//======================================================================================
bool myGame::DetectCollisionWithVan()
{
	if ((ACTUAL_AUDI_X > (ACTUAL_MINIVAN_X + ACTUAL_MINIVAN_WIDTH)) || ((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH) < ACTUAL_MINIVAN_X) || (ACTUAL_AUDI_Y > (ACTUAL_MINIVAN_Y + ACTUAL_MINIVAN_HEIGHT)) || ((ACTUAL_AUDI_Y + ACTUAL_AUDI_HEIGHT) < ACTUAL_MINIVAN_Y))
	{
		return false;
	}
	else
	{
		return true;
	}
	
}
//========================================================================================
//=======================================================================================
bool myGame::DectectCollsionWithBomb_one()
{
	auto y = pow((ACTUAL_AUDI_Y+ACTUAL_AUDI_HEIGHT/2)-(bomb_dest.y + BOMBHEIGHT/2), 2);
	auto x = pow((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH / 2) - (bomb_dest.x + BOMBWIDTH / 2), 2);
	auto distance = sqrt(y + x);
	if (distance < 16)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
//============================================================================================
//============================================================================================
bool myGame::DetectCollisionWithBomb_two()
{
	auto y = pow((ACTUAL_AUDI_Y + ACTUAL_AUDI_HEIGHT / 2) - (bomb_dest2.y + BOMBHEIGHT / 2), 2);
	auto x = pow((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH / 2) - (bomb_dest2.x + BOMBWIDTH / 2), 2);
	auto distance = sqrt(y + x);
	if (distance < 16)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//===============================================================================================
//===============================================================================================
bool myGame::DetectCollisionWithBomb_three()
{
	auto y = pow((ACTUAL_AUDI_Y + ACTUAL_AUDI_HEIGHT / 2) - (bomb_dest3.y + BOMBHEIGHT / 2), 2);
	auto x = pow((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH / 2) - (bomb_dest3.x + BOMBWIDTH / 2), 2);
	auto distance = sqrt(y + x);
	if (distance < 16)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//===============================================================================================
//===============================================================================================
void myGame::RenderExplosion()
{

	explosion_position.x = audi_dest.x;
	explosion_position.y = audi_dest.y;
	
		SDL_RenderCopy(ren, bomb_texture, NULL, &explosion_position);
	
	
}
//===============================================================================================
//===============================================================================================
void myGame::HoldCollision(bool collision)
{
	if (collision == true)
	{
		Movescreen = false;
		time_one_when_screen_move_false = chrono::steady_clock::now();
	}
}
//=================================================================================
//=================================================================================
void myGame::CreateAudi()
{
	if (which_car_to_load == 2)
	{
		LoadBlackviper();
	}
	if (which_car_to_load == 1)
	{
		LoadAudi();
	}
	 
	 AudiTexture();
	
	 audi_dest.x = CARSECONDLANE;
	 audi_dest.y = 350;
	 RenderAudi();	 
}
//==================================================================================
//==================================================================================
int myGame::LoadRing()
{
	ring_surface = IMG_Load("resources/ring.png");
	if (ring_surface == NULL)
	{
		cout << "Ring.png not loaded, " << IMG_GetError() << endl;
	}
	else
	{
		
		optsurf = SDL_ConvertSurface(ring_surface, ring_surface->format, NULL);
		if (optsurf == nullptr)
		{
			cout << "Ring conversion failed, " << SDL_GetError() << endl;
		}
		SDL_SetColorKey(optsurf, SDL_TRUE, SDL_MapRGB(optsurf->format, 0, 0, 0));
	}
	SDL_FreeSurface(ring_surface);
		ring_surface = nullptr;
	return 0;
}
//=========================================================================================
//=========================================================================================
int myGame::RingTexture()
{
	ring_texture = SDL_CreateTextureFromSurface(ren, optsurf);
	if (ring_texture == nullptr)
	{
		cout << "No ring texture, " << SDL_GetError() << endl;

	}
	return 0;
}
//=========================================================================================
//=========================================================================================
isRingrendered myGame::RenderRing(int& counter)
{
	ring_position.x = audi_dest.x;
	ring_position.y = audi_dest.y;
	if(counter < 100)
	{
		SDL_RenderCopy(ren, ring_texture, NULL, &ring_position);
		++counter;
		return isRingrendered::PRESENT;
	}
	else
	{
		return isRingrendered::ABSENT;
	}
	
	
}
//=======================================================================================
//=======================================================================================
void myGame::CheckAllCollision(isRingrendered& ringpresent)
{
	if (ringpresent == isRingrendered::ABSENT)
	{
		//detect collision with small bobcat
		auto smallbobcat_collision = DetectCollisionWithSmallBobcat();
		if (smallbobcat_collision == true)
		{
			RenderAudiOffScreen();
		}
		//detect collision with familycar
		auto familycar_collision = DetectCollisionWithFamilyCar();
		if (familycar_collision == true)
		{
			RenderAudiOffScreen();
		}
		//detect collision with green truck
		auto greentruck_collision = DetectCollisionWithGreeenTruck();
		if (greentruck_collision == true)
		{
			RenderAudiOffScreen();
		}
		//detect collision with yellow bobcat
		auto yellowbobcat_collision = DetectCollisionWithYellowBobcat();
		if (yellowbobcat_collision == true)
		{
			RenderAudiOffScreen();
		}
		//detect collision with long vehicle
		auto longvehicle_collision = DeTectCollisionWithLongvehicle();
		if (longvehicle_collision == true)
		{
			RenderAudiOffScreen();
		}
		//detect collision with ambulance
		auto ambulance_collision = DetectCollisionWithAmbulance();
		if (ambulance_collision == true)
		{
			RenderAudiOffScreen();
		}
		//detect collision with truck
		auto truck_collision = DetectCollisionWithTruck();
		if (truck_collision == true)
		{
			RenderAudiOffScreen();
		}
		//detect collision with limo
		auto limo_collision = DetectCollisionWithLimo();
		if (limo_collision == true)
		{
			RenderAudiOffScreen();
		}
		//detect collision with minitruck
		auto minitruck_collision = DetectCollisionWithMinitruck();
		if (minitruck_collision == true)
		{
			RenderAudiOffScreen();
		}
		//Detect collision with borders
		auto west_border_collision = DetectWestboudaryCollision();
		if (west_border_collision == true)
		{
			RenderAudiOffScreen();
		}
		auto east_border_collision = DetectEastboundaryCollision();
		if (east_border_collision)
		{
			RenderAudiOffScreen();
		}
		//Detect Collision with cop
		auto cop_collision = DetectCollisionWithCop_one();
		if (cop_collision == true)
		{
			RenderAudiOffScreen();
		}
		auto cop2_collision = DetectCollisionWithCop_two();
		if (cop2_collision == true)
		{
			RenderAudiOffScreen();
			
		}
		//Detect Collision with taxi
		auto taxi_collision = DetectCollisionWithTaxi_one();
		if (taxi_collision == true)
		{
			RenderAudiOffScreen();
		}
		//Detect Collision with van
		auto minnvan_collision = DetectCollisionWithVan();

		if (minnvan_collision == true)
		{
			RenderAudiOffScreen();
		}

		//Detect collision with bomb


		auto bomb_one_collision = DectectCollsionWithBomb_one();
		if (bomb_one_collision == true)
		{
			RenderAudiOffScreen();
			
		}

		auto bomb_two_collision = DetectCollisionWithBomb_two();
		if (bomb_two_collision == true)
		{
			RenderAudiOffScreen();
		}


		auto bomb_three_collision = DetectCollisionWithBomb_three();
		if (bomb_three_collision == true)
		{
			RenderAudiOffScreen();
		}
		HoldCollision(minnvan_collision);
		HoldCollision(bomb_one_collision);
		HoldCollision(bomb_two_collision);
		HoldCollision(bomb_three_collision);
		HoldCollision(taxi_collision);
		HoldCollision(cop_collision);
		HoldCollision(cop2_collision);
		HoldCollision(west_border_collision);
		HoldCollision(east_border_collision);
		HoldCollision(minitruck_collision);
		HoldCollision(limo_collision);
		HoldCollision(truck_collision);
		HoldCollision(ambulance_collision);
		HoldCollision(longvehicle_collision);
		HoldCollision(yellowbobcat_collision);
		HoldCollision(greentruck_collision);
		HoldCollision(familycar_collision);
		HoldCollision(smallbobcat_collision);
	}
}
//=======================================================================================
//=======================================================================================
bool myGame::DetectCollisionWithTaxi_one()
{
	if ((ACTUAL_AUDI_X > (ACTUAL_TAXI_X + ACTUAL_TAXI_WIDTH)) || ((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH) < ACTUAL_TAXI_X) || (ACTUAL_AUDI_Y > (ACTUAL_TAXI_Y + ACTUAL_TAXI_HEIGHT)) || ((ACTUAL_AUDI_Y + ACTUAL_AUDI_HEIGHT) < ACTUAL_TAXI_Y))
	{
		return false;
	}
	else
	{
		return true;
	}
}
//=========================================================================================
//=========================================================================================
bool myGame::DetectCollisionWithCop_one()
{
	if ((ACTUAL_AUDI_X > (ACTUAL_COP_X + ACTUAL_COP_WIDTH)) || ((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH) < ACTUAL_COP_X) || (ACTUAL_AUDI_Y > (ACTUAL_COP_Y + ACTUAL_COP_HEIGHT)) || ((ACTUAL_AUDI_Y + ACTUAL_AUDI_HEIGHT) < ACTUAL_COP_Y))
	{
		return false;
	}
	else
	{
		return true;
	}
}
//========================================================================================
//========================================================================================
bool myGame::DetectCollisionWithCop_two()
{

	if ((ACTUAL_AUDI_X > (ACTUAL_COP2_X + ACTUAL_COP_WIDTH-15)) || ((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH-15) < ACTUAL_COP2_X) || (ACTUAL_AUDI_Y > (ACTUAL_COP2_Y + ACTUAL_COP_HEIGHT)) || ((ACTUAL_AUDI_Y + ACTUAL_AUDI_HEIGHT) < ACTUAL_COP2_Y))
	{
		return false;
	}
	else
	{
		return true;
	}
}
//=============================================================================
//=============================================================================
bool myGame::DetectWestboudaryCollision()
{
	if (ACTUAL_AUDI_X < ROAD_ONE_BORDER_WEST )
	{
		return true;
	}
	else
	{
		return false;
	}
}
//-=================================================================
bool myGame::DetectEastboundaryCollision()
{
	if ( (ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH) > ROAD_ONE_BORDER_EAST)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//=================================================================================
//=================================================================================
int myGame::LoadMinitruck()
{
	Minitruck_surface = IMG_Load("resources/Mini_truck.png");
	if (Minitruck_surface == nullptr)
	{
		cout << "Couldn't load mini truck " << IMG_GetError() << endl;
		return 1;
	}
	else
	{
		optsurf2 = SDL_ConvertSurface(Minitruck_surface, Minitruck_surface->format, NULL);
		if (optsurf2 == nullptr)
		{
			cout << "optsurf2 error, " << endl;
		}
	}
	SDL_FreeSurface(Minitruck_surface);
		Minitruck_surface = nullptr;
}
//====================================================================================
//=====================================================================================
int myGame::MinitruckTexture()
{
	Minitruck_texture = SDL_CreateTextureFromSurface(ren, optsurf2);
	if (Minitruck_texture == nullptr)
	{
		cout << "Minitruck texture was not created, " << SDL_GetError() << endl;
		return 1;
	}
	else
	{
		SDL_FreeSurface(optsurf2);
		optsurf = nullptr;
	}
	return 0;
}
//================================================================================
//=================================================================================
void myGame::RenderMinitruck()
{
	
	SDL_RenderCopy(ren, Minitruck_texture, NULL, &minitruck_position);
}
//================================================================================
//================================================================================
bool myGame::DetectCollisionWithMinitruck()
{

	if ((ACTUAL_AUDI_X > (ACTUAL_MINITRUCK_X + ACTUAL_MINITRUCK_WIDTH)) || ((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH) < ACTUAL_MINITRUCK_X) || (ACTUAL_AUDI_Y > (ACTUAL_MINITRUCK_Y + ACTUAL_MINITRUCK_HEIGHT)) || ((ACTUAL_AUDI_Y + ACTUAL_AUDI_HEIGHT) < ACTUAL_MINITRUCK_Y))
	{
		return false;
	}
	else
	{
		return true;
	}
}
//=================================================================================
//==================================================================================
int myGame::LoadDispenser()
{
	dispenser_surface = IMG_Load("resources/dispenser.png");
	if (dispenser_surface == nullptr)
	{
		cout << "dispenser surface not loader, " << IMG_GetError() << endl;
		return 1;
	}
	else
	{
		optsurf2 = SDL_ConvertSurface(dispenser_surface, dispenser_surface->format, NULL);
	}
	SDL_FreeSurface(dispenser_surface);
	dispenser_surface = nullptr;
	return 0;
}
//===========================================================================
//==========================================================================
int myGame::DispenserTexture()
{
	dispenser_texture = SDL_CreateTextureFromSurface(ren, optsurf2);
	if (dispenser_texture == nullptr)
	{
		cout << "Dispenser texture not created, " << SDL_GetError() << endl;
		return 1;
	}
	else
	{
		SDL_FreeSurface(optsurf2);
		optsurf2 = nullptr;
	}
	return 0;
}
//=========================================================================
//==========================================================================
void myGame::RenderDispenser()
{
	SDL_RenderCopy(ren, dispenser_texture, NULL, &dispenser_position);
}
//=====================================================================
//=====================================================================
int myGame::LoadFuelBar()
{
	fuelbar_surface = IMG_Load("resources/fuel_1.png");
	return 0;
}
//===================================================================
int myGame::FuelBarTexture()
{
	fuelbar_texture = SDL_CreateTextureFromSurface(ren, fuelbar_surface);
		SDL_FreeSurface(fuelbar_surface);
		fuelbar_surface = nullptr;
	return 0;
}
//===================================================================
void myGame::RenderFuelBar()
{
	SDL_RenderCopy(ren, fuelbar_texture, NULL, &fuelbar_position);
}
//=====================================================================
//======================================================================
int myGame::LoadFuel()
{
	fuel_surface = IMG_Load("resources/dispenser.png");
	if (fuel_surface == nullptr)
	{
		cout << "fuel surface not loaded, " << IMG_GetError() << endl;
		return 1;
	}
	return 0;
}
//=====================================================================
//======================================================================
int myGame::FuelTexture()
{
	fuel_texture = SDL_CreateTextureFromSurface(ren, fuel_surface);
	if (fuel_texture == nullptr)
	{
		cout << "Fuel texture not created " << SDL_GetError() << endl;
		return 1;
	}
	else
	{
		SDL_FreeSurface(fuel_surface);
			fuel_surface = nullptr;
			return 1;
	}
	return 0;
}
//=====================================================================
//======================================================================
void myGame::RenderFuel(chrono::steady_clock::duration& time_passed)
{
	auto fuel_collision = DetectCollisionWithFuel();
	if (fuel_collision == true)
	{	
		SDL_DestroyTexture(fuel_texture);
		fuel_texture = nullptr;
		fuel_position.x = -1000;
		fuelbar_position.h += 20;
	}
	
	
	
		if (time_passed > chrono::seconds(10) && time_passed < chrono::seconds(15) && fuel_collision == false && fuel_appear_once == 0)
		{
			fuel_position.x = SECONDLANE;
			fuel_position.y = 100;
			fuel_appear_once = 1;
			
		}
		else if (time_passed > chrono::seconds(15) && time_passed < chrono::seconds(17))
		{
			fuel_position.y = 10000;
		}

		if (time_passed > chrono::seconds(20) && time_passed < chrono::seconds(25) && fuel_collision == false && fuel_appear_once == 1)
		{
			if (fuel_texture == nullptr)
			{
				LoadFuel();
				FuelTexture();
			}
			fuel_position.x = FIRSTLANE;
			fuel_position.y = 50;
			fuel_appear_once = 2;
		}
		else if (time_passed > chrono::seconds(25) && time_passed < chrono::seconds(27))
		{
			fuel_position.y = 10000;
		}
			
		if (time_passed > chrono::seconds(30) && time_passed < chrono::seconds(45) && fuel_collision == false && fuel_appear_once == 2)
		{
			if (fuel_texture == nullptr)
			{
				LoadFuel();
				FuelTexture();
			}
			fuel_position.x = THIRDLANE;
			fuel_position.y = 200;
			fuel_appear_once = 3;
		}
		else if (time_passed > chrono::seconds(45) && time_passed < chrono::seconds(47))
		{
			fuel_position.y = 10000;
		}

		if (time_passed > chrono::seconds(50) && time_passed < chrono::seconds(58) && fuel_collision == false && fuel_appear_once == 3)
		{
			if (fuel_texture == nullptr)
			{
				LoadFuel();
				FuelTexture();
			}
			fuel_position.x = THIRDLANE;
			fuel_position.y = 60;
			fuel_appear_once = 4;
		}
		else if (time_passed > chrono::seconds(58) && time_passed < chrono::seconds(60))
		{
			fuel_position.y = 10000;
		}

		if (time_passed > chrono::seconds(65) && time_passed < chrono::seconds(67) && fuel_collision == false && fuel_appear_once == 4)
		{
			if (fuel_texture == nullptr)
			{
				LoadFuel();
				FuelTexture();
			}
			fuel_position.x = FIRSTLANE;
			fuel_position.y = 150;
			fuel_appear_once = 5;
		}
		else if (time_passed > chrono::seconds(67) && time_passed < chrono::seconds(70))
		{
			fuel_position.y = 10000;
		}

		if (time_passed > chrono::seconds(75) && time_passed < chrono::seconds(80) && fuel_collision == false && fuel_appear_once == 5)
		{
			if (fuel_texture == nullptr)
			{
				LoadFuel();
				FuelTexture();
			}
			fuel_position.x = SECONDLANE;
			fuel_position.y = 300;
			fuel_appear_once = 6;
		}
		else if (time_passed > chrono::seconds(80) && time_passed < chrono::seconds(82))
		{
			fuel_position.y = 10000;
		}

		if (time_passed > chrono::seconds(85) && time_passed < chrono::seconds(90) && fuel_collision == false && fuel_appear_once == 6)
		{
			if (fuel_texture == nullptr)
			{
				LoadFuel();
				FuelTexture();
			}
			fuel_position.x = THIRDLANE;
			fuel_position.y = 10;
			fuel_appear_once = 7;
		}
		else if (time_passed > chrono::seconds(95) && time_passed < chrono::seconds(97))
		{
			fuel_position.y = 10000;
		}

		if (time_passed > chrono::seconds(100) && time_passed < chrono::seconds(105) && fuel_collision == false && fuel_appear_once == 6)
		{
			if (fuel_texture == nullptr)
			{
				LoadFuel();
				FuelTexture();
			}
			fuel_position.x = THIRDLANE;
			fuel_position.y = 10;
			fuel_appear_once = 7;
		}
		else if (time_passed > chrono::seconds(105) && time_passed < chrono::seconds(107))
		{
			fuel_position.y = 10000;
		}

		if (time_passed > chrono::seconds(112) && time_passed < chrono::seconds(120) && fuel_collision == false && fuel_appear_once == 6)
		{
			if (fuel_texture == nullptr)
			{
				LoadFuel();
				FuelTexture();
			}
			fuel_position.x = THIRDLANE;
			fuel_position.y = 10;
			fuel_appear_once = 7;
		}
		else if (time_passed > chrono::seconds(120) && time_passed < chrono::seconds(122))
		{
			fuel_position.y = 10000;
		}

		if (time_passed > chrono::seconds(125) && time_passed < chrono::seconds(130) && fuel_collision == false && fuel_appear_once == 6)
		{
			if (fuel_texture == nullptr)
			{
				LoadFuel();
				FuelTexture();
			}
			fuel_position.x = THIRDLANE;
			fuel_position.y = 10;
			fuel_appear_once = 7;
		}
		else if (time_passed > chrono::seconds(130) && time_passed < chrono::seconds(133))
		{
			fuel_position.y = 10000;
		}
		SDL_RenderCopy(ren, fuel_texture, NULL, &fuel_position);
}
//=====================================================================
//======================================================================
bool myGame::DetectCollisionWithFuel()
{

	if ((ACTUAL_AUDI_X > (fuel_position.x + fuel_position.w)) || ((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH) < fuel_position.x) || (ACTUAL_AUDI_Y > (fuel_position.y + fuel_position.h)) || ((ACTUAL_AUDI_Y + ACTUAL_AUDI_HEIGHT) < fuel_position.y))
	{
		return false;
	}
	else
	{
		return true;
	}
}
//=====================================================================
//======================================================================
int myGame::LoadCar()
{
	limo_surface = IMG_Load("resources/car.png");
	if (limo_surface == nullptr)
	{
		cout << "car surface not loaded, " << IMG_GetError() << endl;
		return 1;
	}
	return 0;
}
//=====================================================================
//=====================================================================
int myGame::CarTexture()
{
	limo_texture = SDL_CreateTextureFromSurface(ren, limo_surface);
	if (limo_texture == nullptr)
	{
		cout << "car texture eerror " << SDL_GetError() << endl;
		return 1;
	}
	else
	{
		SDL_FreeSurface(limo_surface);
		limo_surface = nullptr;
	}
	return 0;
}
//=====================================================================
//=====================================================================
void myGame::RenderCar()
{
	SDL_RenderCopy(ren, limo_texture, NULL, &limo_position);
}
//=====================================================================
//=====================================================================
bool myGame::DetectCollisionWithLimo()
{
	if ((ACTUAL_AUDI_X > (ACTUAL_LIMO_X + ACTUAL_LIMO_WIDTH)) || ((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH) < ACTUAL_LIMO_X) || (ACTUAL_AUDI_Y > (ACTUAL_LIMO_Y + ACTUAL_LIMO_HEIGHT)) || ((ACTUAL_AUDI_Y + ACTUAL_AUDI_HEIGHT) < ACTUAL_LIMO_Y))
	{
		return false;
	}
	else
	{
		return true;
	}
}
//=====================================================================
//=====================================================================
void myGame::DestroyAllPastTextures()
{

	if (taxi_dest.y > (SCREENHEIGHT + 100))
	{
		SDL_DestroyTexture(taxi_texture);
		taxi_texture = nullptr;
	}
	if (minivan_dest.y > (SCREENHEIGHT + 100))
	{
		SDL_DestroyTexture(minivan_texture);
		minivan_texture = nullptr;
	}

	if (minitruck_position.y > (SCREENHEIGHT + 100))
	{
		SDL_DestroyTexture(Minitruck_texture);
		Minitruck_texture = nullptr;
	}

	if (limo_position.y > (SCREENHEIGHT + 100))
	{
		SDL_DestroyTexture(limo_texture);
		limo_texture = nullptr;
	}
}
//=====================================================================
//=====================================================================
int myGame::LoadTruck()
{
	truck_surface = IMG_Load("resources/truck.png");
	if (truck_surface == nullptr)
	{
		cout << "truck not loaded, " << IMG_GetError() << endl;
		return 1;
	}
	return 0;
}
//=====================================================================
//=====================================================================
int myGame::TruckTexture()
{
	truck_texture = SDL_CreateTextureFromSurface(ren, truck_surface);
	if (truck_texture == nullptr)
	{
		cout << "no truck texture, " << SDL_GetError() << endl;
		return 1;
	}
	else
	{
		SDL_FreeSurface(truck_surface);
		truck_surface = nullptr;
	}
	return 0;
}
//=====================================================================
//=====================================================================
void myGame::RenderTruck()
{
	SDL_RenderCopy(ren, truck_texture, NULL, &truck_position);
}
//=====================================================================
//=====================================================================
bool myGame::DetectCollisionWithTruck()
{
	if ((ACTUAL_AUDI_X > (ACTUAL_TRUCK_X + ACTUAL_TRUCK_WIDTH)) || ((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH) < ACTUAL_TRUCK_X) || (ACTUAL_AUDI_Y > (ACTUAL_TRUCK_Y + ACTUAL_TRUCK_HEIGHT)) || ((ACTUAL_AUDI_Y + ACTUAL_AUDI_HEIGHT) < ACTUAL_TRUCK_Y))
	{
		return false;
	}
	else
	{
		return true;
	}
}
//=====================================================================
//=====================================================================
void myGame::LoadBlackviper()
{
	audi_surface = IMG_Load("resources/Black_viper.png");
	if (audi_surface == nullptr)
	{
		cout << "audi not loaded, " << IMG_GetError() << endl;

	}
	else
	{
		optsurf = SDL_ConvertSurface(audi_surface, audi_surface->format, NULL);
		SDL_SetColorKey(optsurf, SDL_TRUE, SDL_MapRGB(optsurf->format, 255, 255, 255));
	}

	SDL_FreeSurface(audi_surface);
	audi_surface = nullptr;
}
//=====================================================================
//=====================================================================
void myGame::LoadMenuItems()
{
	//square_surface = IMG_Load("resources/square.png");
	//square_texture = SDL_CreateTextureFromSurface(ren, square_surface);

	select_surface = IMG_Load("resources/select.png");
	select_texture = SDL_CreateTextureFromSurface(ren, select_surface);

	audi_text = IMG_Load("resources/Audi_text.png");
	blackviper_text = IMG_Load("resources/Black_viper_text.png");

	audi_text_texture = SDL_CreateTextureFromSurface(ren, audi_text);
	blackviper_text_texture = SDL_CreateTextureFromSurface(ren, blackviper_text);

	audi_menu = IMG_Load("resources/Audi.png");
	blackviper_menu = IMG_Load("resources/Black_viper.png");

	audi_menu_texture = SDL_CreateTextureFromSurface(ren, audi_menu);
	Blackviper_menu_texture = SDL_CreateTextureFromSurface(ren, blackviper_menu);
}
//=====================================================================
//=====================================================================
int myGame::LoadGameover()
{
	gameover_surface = IMG_Load("resources/gameover.jpg");
	if (gameover_surface == nullptr)
	{
		cout << "Gameover was not loaded," << IMG_GetError() << endl;
		return 1;
	}
}
//=====================================================================
//=====================================================================
int myGame::TextureGameover()
{
	gameover_texture = SDL_CreateTextureFromSurface(ren, gameover_surface);
	if (gameover_texture == nullptr)
	{
		cout << "gameover texture not created, " << SDL_GetError() << endl;
		return 1;
	}
	else
	{
		SDL_FreeSurface(gameover_surface);
			gameover_surface = nullptr;
			return 0;
	}
}
//=====================================================================
//=====================================================================
void myGame::RenderGameover()
{
	SDL_RenderCopy(ren, gameover_texture, NULL, &gameover_position);
}
//=====================================================================
//=====================================================================
int myGame::LoadRetrybutton()
{
	retrybutton_surface = IMG_Load("resources/Retry.png");
	if (retrybutton_surface == nullptr)
	{
		cout << "Retry but not loaded, " << IMG_GetError() << endl;
		return 1;
	}
	else
	{
		SDL_SetColorKey(retrybutton_surface, SDL_TRUE, SDL_MapRGB(retrybutton_surface->format, 255,255, 255));
		return 0;
	}
}
//=====================================================================
//=====================================================================
int myGame::TextureRetryButton()
{
	retrybutton_texture = SDL_CreateTextureFromSurface(ren, retrybutton_surface);
	if (retrybutton_texture == nullptr)
	{
		cout << "retry but texture not created, " << SDL_GetError() << endl;
		return 1;
	}
	else
	{
		SDL_FreeSurface(retrybutton_surface);
		retrybutton_surface = nullptr;
	}
	return 0;
}
//=====================================================================
//=====================================================================
void myGame::RenderRetryButton(int& which_button_source_to_render)
{
	SDL_RenderCopy(ren, retrybutton_texture, &retrybutton_source[which_button_source_to_render], &retrybutton_position);
}
//=====================================================================
//=====================================================================
int myGame::LoadExitbutton()
{
	exitbutton_surface = IMG_Load("resources/Exit.png");
	if (exitbutton_surface == nullptr)
	{
		cout << "exit button not loaded, " << IMG_GetError() << endl;
		return 1;
	}
	else
	{
		SDL_SetColorKey(exitbutton_surface, SDL_TRUE, SDL_MapRGB(exitbutton_surface->format, 255, 255, 255));
		return 0;
	}
}
//=====================================================================
//=====================================================================
int myGame::TextureExitButton()
{
	exitbutton_texture = SDL_CreateTextureFromSurface(ren, exitbutton_surface);
	if (retrybutton_texture == nullptr)
	{
		cout << "exit button texture not created, " << SDL_GetError() << endl;
		return 1;
	}
	else
	{
		SDL_FreeSurface(exitbutton_surface);
		exitbutton_surface = nullptr;
	}
	return 0;
}
//=====================================================================
//=====================================================================
void myGame::RenderExitButton(int& which_button_source_to_render)
{
	SDL_RenderCopy(ren, exitbutton_texture, &exitbutton_source[which_button_source_to_render], &exitbutton_position);
}
//=====================================================================
//=====================================================================
void myGame::ResetAllPositions()
{
	bomb_dest = { FIRSTLANE,-5,20,20 };
	bomb_dest2 = { SECONDLANE,-100,BOMBWIDTH,BOMBHEIGHT };
	bomb_dest3 = { THIRDLANE,-200,BOMBWIDTH,BOMBHEIGHT };
	taxi_dest = { CARFIRSTLANE,-500,TAXIWIDTH,TAXIHEIGHT };
	minivan_dest = { CARSECONDLANE, -550, MINIVANWIDTH, MINIVANHEIGHT };
	policecar_dest = { CARTHIRDLANE,400,COPCARWIDTH,COPCARHEIGHT };
	policecar_dest_2 = { CARSECONDLANE,400,COPCARWIDTH,COPCARHEIGHT };
	minitruck_position = { CARTHIRDLANE,-100,MINITRUCKWIDTH,MINITRUCKHEIGHT };
	limo_position = { CARSECONDLANE,-100,70,90 };
	truck_position = { 160,-150,90,100 };
	audi_dest = { 220, 300,AUDIWIDTH,AUDIHEIGHT };
	ambulance_position = { (THIRDLANE - 5),-100,30,70 };
	longvehicle_position = { (CARSECONDLANE + 5),-180,50,180 };
	yellowBobcat_position = { CARFIRSTLANE,-150,40,80 };
	familycar_position = { CARSECONDLANE + 10,-80,35,70 };
	smallbobcat_position = { CARFIRSTLANE,-180,40,70 };
	greentruck_position = { CARTHIRDLANE + 5,-70,40,60 };
}
//=====================================================================
//=====================================================================
int myGame::LoadAmbulance()
{
	ambulance_surface = IMG_Load("resources/ambulance.png");
	if (ambulance_surface == nullptr)
	{
		cout << "Ambulance not loaded, " << IMG_GetError() << endl;
		return 1;
	}
	return 0;
}
//=====================================================================
//=====================================================================
int myGame::TextureAmbulance()
{
	ambulance_texture = SDL_CreateTextureFromSurface(ren, ambulance_surface);
	if (ambulance_texture == nullptr)
	{
		cout << "no ambulance texture, " << SDL_GetError() << endl;
		return 1;
	}
	else
	{
		SDL_FreeSurface(ambulance_surface);
		ambulance_surface = nullptr;
	}

	return 0;
}
//=====================================================================
//=====================================================================
void myGame::RenderAmbulance(int& frame)
{
	SDL_RenderCopy(ren, ambulance_texture, &ambulance_source[frame / 4], &ambulance_position);
}
//=====================================================================
//=====================================================================
bool myGame::DetectCollisionWithAmbulance()
{
	if ((ACTUAL_AUDI_X > ((ambulance_position.x+7) + ambulance_position.w)) || ((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH) < (ambulance_position.x+9)) || (ACTUAL_AUDI_Y > ((ambulance_position.y+9) + ambulance_position.h)) || ((ACTUAL_AUDI_Y + ACTUAL_AUDI_HEIGHT) < (ambulance_position.y+9)))
	{
		return false;
	}
	else
	{
		return true;
	}
}
//=====================================================================
//=====================================================================
int myGame::LoadLongVehicle()
{
	longvehicle_surface = IMG_Load("resources/long vehicle.png");
	if (longvehicle_surface == nullptr)
	{
		cout << "long vehicle not loaded, " << IMG_GetError() << endl;
		return 1;
	}
	return 0;
}
//=====================================================================
//=====================================================================
int myGame::TextureLongVehicle()
{
	longvehicle_texture = SDL_CreateTextureFromSurface(ren, longvehicle_surface);
	if (longvehicle_texture == nullptr)
	{
		cout << "longvehicle_texture not created, " << SDL_GetError() << endl;
		return 1;
	}
	else
	{
		SDL_FreeSurface(longvehicle_surface);
		longvehicle_surface = nullptr;
		return 0;
	}
}
//=====================================================================
//=====================================================================
void myGame::RenderLoadVehicle()
{
	SDL_RenderCopy(ren, longvehicle_texture, NULL, &longvehicle_position);
}
//=====================================================================
//=====================================================================
int myGame::LoadYellowBobcat()
{
	yellowBobcat_surface = IMG_Load("resources/yellowBobcat.png");
	if (yellowBobcat_surface == nullptr)
	{
		cout << "yellowBobcat_surface not loaded, " <<IMG_GetError() <<endl;
		return 1;
	}
	return 0;
}
//=====================================================================
//=====================================================================
int myGame::TextureYellowBobcat()
{
	yellowBobcat_texture = SDL_CreateTextureFromSurface(ren, yellowBobcat_surface);
	if (yellowBobcat_texture == nullptr)
	{
		cout << "yellowBobcat_texture not created, " << SDL_GetError() << endl;
		return 1;
	}
	else
	{
		SDL_FreeSurface(yellowBobcat_surface);
		yellowBobcat_surface = nullptr;
		return 0;
	}
}
//=====================================================================
//=====================================================================
void myGame::RenderYellowBobcat()
{
	SDL_RenderCopy(ren, yellowBobcat_texture, NULL, &yellowBobcat_position);
}
//=====================================================================
//=====================================================================
bool myGame::DeTectCollisionWithLongvehicle()
{
	if ((ACTUAL_AUDI_X > ((longvehicle_position.x+5) + longvehicle_position.w-20)) || ((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH) < (longvehicle_position.x+5)) || (ACTUAL_AUDI_Y > ((longvehicle_position.y) + longvehicle_position.h)) || ((ACTUAL_AUDI_Y + ACTUAL_AUDI_HEIGHT) < (longvehicle_position.y )))
	{
		return false;
	}
	else
	{
		return true;
	}
}
//=====================================================================
//=====================================================================
bool myGame::DetectCollisionWithYellowBobcat()
{
	if ((ACTUAL_AUDI_X > ((yellowBobcat_position.x/* + 5*/) + yellowBobcat_position.w - 13)) || ((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH) < (yellowBobcat_position.x /*+ 5*/)) || (ACTUAL_AUDI_Y > ((yellowBobcat_position.y) + yellowBobcat_position.h-5)) || ((ACTUAL_AUDI_Y + ACTUAL_AUDI_HEIGHT) < (yellowBobcat_position.y)))
	{
		return false;
	}
	else
	{
		return true;
	}
}
//=====================================================================
//=====================================================================
int myGame::LoadGreenTruck()
{
	greentruck_surface = IMG_Load("resources/greentruck.png");
	if (greentruck_surface == nullptr)
	{
		cout << "greentruck_surface not loaded, " << IMG_GetError() << endl;
		return 1;
	}
	return 0;
}
//=====================================================================
//=====================================================================
int myGame::TextureGreenTruck()
{
	greentruck_texture = SDL_CreateTextureFromSurface(ren, greentruck_surface);
	if (greentruck_texture == nullptr)
	{
		cout << "greentruck_texture not created, " << SDL_GetError() << endl;
		return 1;
	}
	else
	{
		SDL_FreeSurface(greentruck_surface);
		greentruck_surface = nullptr;
		return 0;
	}
}
//=====================================================================
//=====================================================================
void myGame::RenderGreenTruck()
{
	SDL_RenderCopy(ren, greentruck_texture, NULL, &greentruck_position);
}
//=====================================================================
//=====================================================================
bool myGame::DetectCollisionWithGreeenTruck()
{
	if ((ACTUAL_AUDI_X > ((greentruck_position.x + 5) + greentruck_position.w - 20)) || ((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH) < (greentruck_position.x + 5)) || (ACTUAL_AUDI_Y > ((greentruck_position.y) + greentruck_position.h)) || ((ACTUAL_AUDI_Y + ACTUAL_AUDI_HEIGHT) < (greentruck_position.y)))
	{
		return false;
	}
	else
	{
		return true;
	}
}
//=====================================================================
//=====================================================================
int myGame::LoadFamilyCar()
{
	familycar_surface = IMG_Load("resources/whitefamilycar.png");
	return 0;
}
//======================================================================
//======================================================================
int myGame::TextureFamilyCar()
{
	familycar_texture = SDL_CreateTextureFromSurface(ren, familycar_surface);
	if (familycar_texture != nullptr)
	{
		SDL_FreeSurface(familycar_surface);
		familycar_surface = nullptr;
	}
	return 0;
}
//======================================================================
//======================================================================
void myGame::RenderFamilyCar()
{
	SDL_RenderCopy(ren, familycar_texture, NULL, &familycar_position);
}
//=====================================================================
//=====================================================================
bool myGame::DetectCollisionWithFamilyCar()
{
	if ((ACTUAL_AUDI_X > ((familycar_position.x+5) + familycar_position.w-20)) || ((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH) < (familycar_position.x+5)) || (ACTUAL_AUDI_Y > ((familycar_position.y ) + familycar_position.h)) || ((ACTUAL_AUDI_Y + ACTUAL_AUDI_HEIGHT) < (familycar_position.y)))
	{
		return false;
	}
	else
	{
		return true;
	}
}
//=====================================================================
//=====================================================================
int myGame::LoadFirstBullet()
{
	firstbullet_surface = IMG_Load("resources/firstbullet.png");
	return 0;
}
//=====================================================================
//=====================================================================
void myGame::TextureFirstBullet()
{
	for (int w = 0; w < 21; ++w)
	{
		firstbullet_texture[w] = SDL_CreateTextureFromSurface(ren, firstbullet_surface);
	}
}
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_zero()
{
	SDL_RenderCopy(ren, firstbullet_texture[0], NULL, &firstbullet_position[0]);
}
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_one()
{
	SDL_RenderCopy(ren, firstbullet_texture[1], NULL, &firstbullet_position[1]);
}
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_two()
{
	SDL_RenderCopy(ren, firstbullet_texture[2], NULL, &firstbullet_position[2]);
}
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_three()
{
	SDL_RenderCopy(ren, firstbullet_texture[3], NULL, &firstbullet_position[3]);
}
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_four()
{
	SDL_RenderCopy(ren, firstbullet_texture[4], NULL, &firstbullet_position[4]);
}
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_five()
{
	SDL_RenderCopy(ren, firstbullet_texture[5], NULL, &firstbullet_position[5]);
}
//=====================================================================
//=====================================================================
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_six()
{
	SDL_RenderCopy(ren, firstbullet_texture[6], NULL, &firstbullet_position[6]);
}
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_seven()
{
	SDL_RenderCopy(ren, firstbullet_texture[7], NULL, &firstbullet_position[7]);
}
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_eight()
{
	SDL_RenderCopy(ren, firstbullet_texture[8], NULL, &firstbullet_position[8]);
}
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_nine()
{
	SDL_RenderCopy(ren, firstbullet_texture[9], NULL, &firstbullet_position[9]);
}
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_ten()
{
	SDL_RenderCopy(ren, firstbullet_texture[10], NULL, &firstbullet_position[10]);
}
// ====================================================================
//=====================================================================
void myGame::RenderFirstBullet_eleven()
{
	SDL_RenderCopy(ren, firstbullet_texture[11], NULL, &firstbullet_position[11]);
}
// ====================================================================
//=====================================================================
void myGame::RenderFirstBullet_twelve()
{
	SDL_RenderCopy(ren, firstbullet_texture[12], NULL, &firstbullet_position[12]);
}
// ====================================================================
//=====================================================================
void myGame::RenderFirstBullet_thirteen()
{
	SDL_RenderCopy(ren, firstbullet_texture[13], NULL, &firstbullet_position[13]);
}
// ====================================================================
//=====================================================================
void myGame::RenderFirstBullet_fourteen()
{
	SDL_RenderCopy(ren, firstbullet_texture[14], NULL, &firstbullet_position[14]);
}
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_fifteen()
{
	SDL_RenderCopy(ren, firstbullet_texture[15], NULL, &firstbullet_position[15]);
}
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_sixteen()
{
	SDL_RenderCopy(ren, firstbullet_texture[16], NULL, &firstbullet_position[16]);
}
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_seventeen()
{
	SDL_RenderCopy(ren, firstbullet_texture[17], NULL, &firstbullet_position[17]);
}
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_eighteen()
{
	SDL_RenderCopy(ren, firstbullet_texture[18], NULL, &firstbullet_position[18]);
}
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_nineteen()
{
	SDL_RenderCopy(ren, firstbullet_texture[19], NULL, &firstbullet_position[19]);
}
//=====================================================================
//=====================================================================
void myGame::RenderFirstBullet_twenty()
{
	SDL_RenderCopy(ren, firstbullet_texture[20], NULL, &firstbullet_position[20]);
}
//=====================================================================
//=====================================================================
int  myGame::LoadSmallBobcat()
{
	smallbobcat_surface = IMG_Load("resources/smallbobcat.png");
	return 0;
}
//=====================================================================
//=====================================================================
int  myGame::TextureSmallBobcat()
{
	smallbobcat_texture = SDL_CreateTextureFromSurface(ren, smallbobcat_surface);
	if (smallbobcat_texture != nullptr)
	{
		SDL_FreeSurface(smallbobcat_surface);
		smallbobcat_surface = nullptr;
	}
	return 0;
}
//=====================================================================
//=====================================================================
void  myGame::RenderSmallBobcat()
{
	SDL_RenderCopy(ren, smallbobcat_texture, NULL, &smallbobcat_position);
}
//=====================================================================
//=====================================================================
bool myGame::DetectCollisionWithSmallBobcat()
{
	if ((ACTUAL_AUDI_X > ((smallbobcat_position.x) + smallbobcat_position.w -15)) || ((ACTUAL_AUDI_X + ACTUAL_AUDI_WIDTH) < (smallbobcat_position.x)) || (ACTUAL_AUDI_Y > ((smallbobcat_position.y) + smallbobcat_position.h)) || ((ACTUAL_AUDI_Y + ACTUAL_AUDI_HEIGHT) < (smallbobcat_position.y)))
	{
		return false;
	}
	else
	{
		return true;
	}
}
//=====================================================================
//=====================================================================
void myGame::LoadPause()
{
	pause_surface = IMG_Load("resources/pause.png");
	SDL_SetColorKey(pause_surface, SDL_TRUE, SDL_MapRGB(screen_surface->format, 255, 255, 255));
}
//=====================================================================
//=====================================================================
void myGame::TexturePause()
{
	pause_texture = SDL_CreateTextureFromSurface(ren, pause_surface);
	if (pause_texture != nullptr)
	{
		SDL_FreeSurface(pause_surface);
		pause_surface = nullptr;
	}
}
//=====================================================================
//=====================================================================
void myGame::RenderPause(Uint8& mod)
{
	
	SDL_SetTextureAlphaMod(pause_texture,mod);
	SDL_RenderCopy(ren, pause_texture, NULL, &pause_position);
}
//=====================================================================
//=====================================================================
void myGame::LoadPauseButton()
{
	pausebutton_surface = IMG_Load("resources/pausebutton.png");
	
	SDL_SetColorKey(pausebutton_surface, SDL_TRUE, SDL_MapRGB(screen_surface->format, 255, 255, 255));
	pausebutton_texture = SDL_CreateTextureFromSurface(ren, pausebutton_surface);
	SDL_FreeSurface(pausebutton_surface);
	pausebutton_surface = nullptr;
}

//=====================================================================
//=====================================================================
void myGame::RenderPauseButton(int& which_of_the_source_to_render)
{
	SDL_RenderCopy(ren, pausebutton_texture, &pausebutton_source[which_of_the_source_to_render], &pausebutton_position);
}
//=====================================================================
//=====================================================================
void myGame::LoadResumeButton()
{
	resumebutton_surface = IMG_Load("resources/resumebutton.png");
	
	SDL_SetColorKey(resumebutton_surface, SDL_TRUE, SDL_MapRGB(screen_surface->format, 255, 255, 255));

	resumebutton_texture = SDL_CreateTextureFromSurface(ren, resumebutton_surface);
	
	SDL_FreeSurface(resumebutton_surface);
	resumebutton_surface = nullptr;
}
//=====================================================================
//=====================================================================
void myGame::RenderResumeButton(int& which_of_the_source_to_render)
{
	SDL_RenderCopy(ren, resumebutton_texture, &pausebutton_source[which_of_the_source_to_render], &pausebutton_position);
}
//=====================================================================
//=====================================================================
int myGame::theWholeGame()
{
	SDL_Event evt;
	//=================================================================================//
	//=================================================================================//
	//=================================================================================//
	time_one = chrono::steady_clock::now();

	while (Running)
	{
		time_two = chrono::steady_clock::now() - time_spent_during_pause;
		time_passed = time_two - time_one;
		time_passed -= time_spent_when_screen_move_is_false;

		while (SDL_PollEvent(&evt) != 0)
		{
			if (evt.type == SDL_QUIT)
			{
				Running = false;
				Running = false;
				Selection = false;
				pause = false;
				return 0;
			}
			if (evt.type == SDL_KEYDOWN)
			{
				switch (evt.key.keysym.scancode)
				{
				case SDL_SCANCODE_A:
				{
					if (firstbullet_position[bulletnumber].y < 0)
					{
						firstbullet_position[bulletnumber].x = ACTUAL_AUDI_X + 15;
						firstbullet_position[bulletnumber].y = ACTUAL_AUDI_Y;
					}
					bulletnumber++;
					if (bulletnumber > 20)
					{
						bulletnumber = 0;
					}break;
				}
				case SDL_SCANCODE_ESCAPE:
				{
					//goto pauseloop;
					thePauseLoop();
				}
				}
			}
			if (evt.type == SDL_MOUSEMOTION)
			{
				//--------------------------------------------------------------------
				int mouse_x, mouse_y;
				SDL_GetMouseState(&mouse_x, &mouse_y);

				//this conditions are for the retry button
				if (mouse_x > 20 && mouse_x < 80 && mouse_y > 100 && mouse_y < 120)
				{
					which_of_the_source_to_render = 1;
				}
				else
				{
					which_of_the_source_to_render = 0;
				}

				//-------------------------------------------------------------------------
			}
			if (evt.type == SDL_MOUSEBUTTONDOWN)
			{
				int mouse_x, mouse_y;
				SDL_GetMouseState(&mouse_x, &mouse_y);
				if (evt.button.button == SDL_BUTTON_LEFT)
				{
					if (mouse_x > 20 && mouse_x < 80 && mouse_y > 100 && mouse_y < 120)
					{
						//goto  pauseloop;
						thePauseLoop();
					}
				}
			}
		}





		++when_to_decrease_fuel;
		if (when_to_decrease_fuel % 15 == 0)
		{
			--fuelbar_position.h;
		}
		if (fuelbar_position.h < 0)
		{
			fuelbar_position.h = 0;
		}

		++frame;
		if (frame > 10)
		{
			frame = 0;
		}

		++frame_for_ambulance;
		if (frame_for_ambulance > 10)
		{
			frame_for_ambulance = 0;
		}
		SDL_SetRenderDrawColor(ren, 255, 194, 255, 255);
		SDL_RenderClear(ren);

		RenderDispenser();
		RenderFuelBar();

		SDL_RenderCopy(ren, first_road_texture, &first_road_campos, &first_Road_dest);



		//=======================================
		//Rendering fuel
		if (Movescreen == true)
		{
			RenderFuel(time_passed);
		}
		//=======================================

		//start obstruction
		if (time_passed > chrono::seconds(10))
		{
			RenderBomb();

			if (Movescreen == true)
			{
				++bomb_dest.y;
			}

			RenderBomb_2();
			if (Movescreen == true)
			{
				++bomb_dest2.y;
			}

			RenderBomb_3();

			if (Movescreen == true)
			{
				++bomb_dest3.y;
			}


			RenderTaxi();
			if (Movescreen == true)
			{
				++taxi_dest.y;
			}


			RenderMiniVan();
			if (Movescreen == true)
			{
				++minivan_dest.y;
			}
		}
		if (time_passed > chrono::seconds(35))
		{
			//new set of obstruction
			RenderCar();
			if (Movescreen == true)
			{
				++limo_position.y;
			}
			RenderTruck();

			if (Movescreen == true)
			{
				++truck_position.y;
			}
		}
		//render ambulance
		RenderAmbulance(frame_for_ambulance);
		if (Movescreen == true)
		{
			if (time_passed > chrono::seconds(38))
			{
				++ambulance_position.y;
			}
		}
		///render pause button
		RenderPauseButton(which_of_the_source_to_render);


		//render long vehicle
		RenderLoadVehicle();
		if (Movescreen == true)
		{
			if (time_passed > chrono::seconds(42))
			{
				++longvehicle_position.y;
			}
		}
		//render Yellow bobcat
		RenderYellowBobcat();
		if (Movescreen == true)
		{
			if (time_passed > chrono::seconds(45))
			{
				++yellowBobcat_position.y;
			}
		}

		//render green truck
		RenderGreenTruck();
		if (Movescreen == true)
		{
			if (time_passed > chrono::seconds(45))
			{
				++greentruck_position.y;
			}
		}
		RenderFamilyCar();
		if (Movescreen == true)
		{
			if (time_passed > chrono::seconds(55))
			{
				++familycar_position.y;
			}
		}

		RenderSmallBobcat();
		if (Movescreen == true)
		{
			if (time_passed > chrono::seconds(55))
			{
				++smallbobcat_position.y;
			}
		}

		if (Movescreen == true)
		{
			if (minivan_dest.y > 250)
			{
				RenderPoliceCar(frame);
				--policecar_dest.y;
			}
			if (policecar_dest.y < 200)
			{
				--policecar_dest_2.y;
				RenderpoliceCar2(frame);
			}
		}
		//render first minitruck after first police has pass
		if (policecar_dest.y < -50)
		{
			RenderMinitruck();
			if (Movescreen == true)
			{
				++minitruck_position.y;
			}
		}


		RenderAudi();


		//=========================================================================
		//=========================================================================
				//CONTROLLING AUDI
		//=========================================================================
		//=========================================================================
		if (Movescreen == true)
		{
			keystate = SDL_GetKeyboardState(NULL);
			if (keystate[SDL_SCANCODE_RIGHT])
			{
				audi_dest.x += 1;
				ring_position.x += 1;
				angle = 5.0;
			}
			else
			{
				angle = 0.0;
			}
			if (keystate[SDL_SCANCODE_LEFT])
			{
				audi_dest.x -= 1;
				ring_position.x -= 1;
				angle = -5.0;
			}

			if (keystate[SDL_SCANCODE_UP])
			{
				audi_dest.y -= 1;
				ring_position.y -= 1;

			}
			if (keystate[SDL_SCANCODE_DOWN])
			{
				audi_dest.y += 1;
				ring_position.y += 1;
			}
		}
		RenderFirstBullet_zero();
		RenderFirstBullet_one();
		RenderFirstBullet_two();
		RenderFirstBullet_three();
		RenderFirstBullet_four();
		RenderFirstBullet_five();
		RenderFirstBullet_six();
		RenderFirstBullet_seven();
		RenderFirstBullet_eight();
		RenderFirstBullet_nine();
		RenderFirstBullet_ten();
		RenderFirstBullet_eleven();
		RenderFirstBullet_twelve();
		RenderFirstBullet_thirteen();
		RenderFirstBullet_fourteen();
		RenderFirstBullet_fifteen();
		RenderFirstBullet_sixteen();
		RenderFirstBullet_seventeen();
		RenderFirstBullet_eighteen();
		RenderFirstBullet_nineteen();
		RenderFirstBullet_twenty();

		//------------------------------------------------------------//
		//------------------------------------------------------------//
		firstbullet_position[0].y -= 2;//--------------------------------//
		firstbullet_position[1].y -= 2;//--------------------------------//
		firstbullet_position[2].y -= 2;//--------------------------------//
		firstbullet_position[3].y -= 2;//--------------------------------//
		firstbullet_position[4].y -= 2;//--------------------------------//
		firstbullet_position[5].y -= 2;//--------------------------------//
		firstbullet_position[6].y -= 2;//--------------------------------//
		firstbullet_position[7].y -= 2;//--------------------------------//
		firstbullet_position[8].y -= 2;//--------------------------------//
		firstbullet_position[9].y -= 2;//--------------------------------//
		firstbullet_position[10].y -= 2;//--------------------------------//
		firstbullet_position[11].y -= 2;//--------------------------------//
		firstbullet_position[12].y -= 2;//--------------------------------//
		firstbullet_position[13].y -= 2;//--------------------------------//
		firstbullet_position[14].y -= 2;//--------------------------------//
		firstbullet_position[15].y -= 2;//--------------------------------//
		firstbullet_position[16].y -= 2;//--------------------------------//
		firstbullet_position[17].y -= 2;//--------------------------------//
		firstbullet_position[18].y -= 2;//--------------------------------//
		firstbullet_position[19].y -= 2;//--------------------------------//
		firstbullet_position[20].y -= 2;//--------------------------------//
		//-------------------------------------------------------------//
		//-------------------------------------------------------------//

		if (Movescreen == true)
		{
			AccelerateScreen();
		}
		//=======================================
		//Detect collision all collsion
		CheckAllCollision(ringpresent);

		if (Movescreen == false)
		{
			time_two_when_screen_move_false = chrono::steady_clock::now();

			++wait;
			time_spent_when_screen_move_is_false = time_two_when_screen_move_false - time_one_when_screen_move_false;

			//there is still problem here
			if (time_spent_when_screen_move_is_false < chrono::seconds(3))
			{
				Movescreen = true;
				counter = 0;
				CreateAudi();
				wait = 0;
			}

		}

		if (counter < 102)
		{
			ringpresent = RenderRing(counter);
		}


		if (Movescreen == false)
		{
			RenderExplosion();
		}

		//game over when fuel is empty
		if (fuelbar_position.h <= 0)
		{
			theGameOverLoop();
		}
		ResetRoad_one();
		//DestroyAllPastTextures(); i no longer used this function though the definitions is not deleted




		SDL_RenderPresent(ren);
	}

}

void myGame::thePauseLoop()
{
	auto pause_time_1 = chrono::steady_clock::now();
	pause_loop_entered = true;
	Uint8 transparency = 0;
	which_of_the_source_to_render = 0;
	while (pause)
	{
		auto pause_time_2 = chrono::steady_clock::now();
		++transparency;
		if (transparency > 255)
		{
			transparency = 0;
		}
		RenderResumeButton(which_of_the_source_to_render);
		while (SDL_PollEvent(&evt))
		{
			if (evt.type == SDL_QUIT)
			{
				time_spent_during_pause = pause_time_2 - pause_time_1;
				pause = false;
				Gameover = false;
				Running = false;
				Selection = false;
			}
			if (evt.type == SDL_KEYDOWN)
			{
				switch (evt.key.keysym.scancode)
				{
				case SDL_SCANCODE_ESCAPE:
				{
					time_spent_during_pause = pause_time_2 - pause_time_1;
					which_of_the_source_to_render = 0;
					
					theWholeGame();
				}

				}
			}

			if (evt.type == SDL_MOUSEMOTION)
			{
				//--------------------------------------------------------------------
				int mouse_x, mouse_y;
				SDL_GetMouseState(&mouse_x, &mouse_y);

				//this conditions are for the retry button
				if (mouse_x > 20 && mouse_x < 80 && mouse_y > 100 && mouse_y < 120)
				{
					which_of_the_source_to_render = 1;
				}
				else
				{
					which_of_the_source_to_render = 0;
				}

				//-------------------------------------------------------------------------
			}
			if (evt.type == SDL_MOUSEBUTTONDOWN)
			{
				int mouse_x, mouse_y;
				SDL_GetMouseState(&mouse_x, &mouse_y);
				if (evt.button.button == SDL_BUTTON_LEFT)
				{
					if (mouse_x > 20 && mouse_x < 80 && mouse_y > 100 && mouse_y < 120)
					{
						time_spent_during_pause = pause_time_2 - pause_time_1;
						which_of_the_source_to_render = 0;
						
						theWholeGame();
					}
				}
			}


		}

		RenderPause(transparency);
		SDL_RenderPresent(ren);
	}
}

int myGame::theGameOverLoop() {
	//==============================================================================================
	//==============================================================================================
	//GameOver loop
	//==============================================================================================
	while (Gameover)
	{
		while (SDL_PollEvent(&evt) != 0)
		{
			if (evt.type == SDL_QUIT)
			{
				Gameover = false;
				pause = false;
				Running = false;
				Selection = false;
			}
			if (evt.type == SDL_MOUSEMOTION)
			{
				int mouse_x, mouse_y;
				SDL_GetMouseState(&mouse_x, &mouse_y);

				//this conditions are for the retry button
				if (mouse_x > 20 && mouse_x < 80 && mouse_y > 100 && mouse_y < 120)
				{
					which_button_source_to_render = 1;
				}
				else
				{
					which_button_source_to_render = 0;
				}

				//this conditions are for the exit button
				if (mouse_x > 20 && mouse_x < 80 && mouse_y > 130 && mouse_y < 150)
				{
					which_button_source_to_render_2 = 1;
				}
				else
				{
					which_button_source_to_render_2 = 0;
				}
			}

			if (evt.type == SDL_MOUSEBUTTONDOWN)
			{
				int mouse_x, mouse_y;
				SDL_GetMouseState(&mouse_x, &mouse_y);
				if (mouse_x > 20 && mouse_x < 80 && mouse_y > 100 && mouse_y < 120)
				{
					
					Running = true;
					fuelbar_position.h = 150;
					ResetAllPositions();
					fuel_appear_once = 0;

					theWholeGame();
				}
				if (mouse_x > 20 && mouse_x < 80 && mouse_y > 130 && mouse_y < 150)
				{
					return 0;
				}
			}
		}
		RenderGameover();
		RenderRetryButton(which_button_source_to_render);
		RenderExitButton(which_button_source_to_render_2);
		SDL_RenderPresent(ren);
	}

}

int myGame::theSelectionLoop()
{
	while (Selection)
	{

		while (SDL_PollEvent(&evt) != 0)
		{
			if (evt.type == SDL_QUIT)
			{
				Selection = false;
				Gameover = false;
				pause = false;
				Running = false;
				return 0;
			}
			if (evt.type == SDL_MOUSEBUTTONDOWN)
			{
				int mouse_x, mouse_y;
				SDL_GetMouseState(&mouse_x, &mouse_y);

				if (mouse_x > 200 && mouse_x < 300 && mouse_y > 125 && mouse_y < 225)
				{
					LoadBlackviper();
					which_car_to_load = 2;
					Selection = false;
				}
				if (mouse_x > 100 && mouse_x < 200 && mouse_y > 120 && mouse_y < 220)
				{
					LoadAudi();
					which_car_to_load = 1;
					Selection = false;
				}
			}

		}

		SDL_RenderPresent(ren);
	}
}

void decreaseFuel()
{

}