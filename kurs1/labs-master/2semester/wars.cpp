#include <iostream>
#include <ctime>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

int select(SDL_Event event);

int main() {
	srand(time(0));
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_DisplayMode displayMode;
	int size_window_h = 720, size_window_w = 1280;
	int display_get = SDL_GetDesktopDisplayMode(0, &displayMode);
	SDL_Window* win = SDL_CreateWindow("Newwindow", 100, 100, size_window_w, size_window_h, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	SDL_Texture* texture = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 100, 100);
	int amount_numb = 10000;
	SDL_Rect kek_r[2][amount_numb];
	for(int i = 0; i < amount_numb; i++) {
		kek_r[0][i].x = rand() % size_window_w;
		kek_r[0][i].y = rand() % size_window_h;
		kek_r[0][i].w = 50;
		kek_r[0][i].h = 50;
		kek_r[1][i].x = size_window_w;
		kek_r[1][i].y = size_window_h;
		kek_r[1][i].w = 50;
		kek_r[1][i].h = 50;
	}
	SDL_Rect background_r;
		background_r.x = 0;
		background_r.y = 0;
		background_r.h = size_window_h;
		background_r.w = size_window_w;
	SDL_Surface *background_BMP = SDL_LoadBMP("black.bmp");
	SDL_Surface *kek_png = IMG_Load("kek.png");
	if(background_BMP == NULL) {
		cout << "Фон не загрузился блять, вот почему: " << SDL_GetError() << endl;
	}
	if(kek_png == NULL) {
		cout << "Текстурка не загрузилась блять, вот почему: " << SDL_GetError() << endl;
	}
	SDL_Texture *background = SDL_CreateTextureFromSurface(ren, background_BMP);
	SDL_Texture *kek = SDL_CreateTextureFromSurface(ren, kek_png);
	SDL_FreeSurface(background_BMP);
	SDL_SetRenderDrawColor(ren, 150, 150, 100, 255);
	SDL_Event event;
	int sped_kek = 5;
	bool quit = true;
	int select_numb = 0;
	int time_st = event.button.timestamp, time_st0 = event.button.timestamp, time_st_tab = event.button.timestamp, time_st_tab0 = event.button.timestamp;
	bool active[2][amount_numb]; //думаю тут и так понятно, что это нужн для выключения наших текстурок:)
	for(int i = 0; i < amount_numb; i++) {
		active[0][i] = true;
	}
	for(int i = 0; i < amount_numb; i++) {
		active[1][i] = false;
	}
	int speed[amount_numb];
	for(int i = 0; i < amount_numb; i++) {
		speed[i] = 1 + rand() % 3;
	}
	while(quit) {
		SDL_RenderClear(ren);
		SDL_RenderCopy(ren, background, NULL, &background_r);
		for(int i = 0; i < amount_numb; i++) {
			SDL_RenderCopy(ren, kek, NULL, &kek_r[0][i]);
		}
		for(int i = 0; i < amount_numb; i++) {
			if(kek_r[0][i].x < 0) {
				if(kek_r[0][i].x < - kek_r[0][i].w) {
					kek_r[0][i].x = size_window_w - kek_r[0][i].w;
					kek_r[1][i].x = size_window_w;
					kek_r[1][i].y = size_window_h;
					SDL_RenderCopy(ren, kek, NULL, &kek_r[1][i]);
				} else {
					kek_r[1][i].x = kek_r[0][i].x + size_window_w;
					kek_r[1][i].y = kek_r[0][i].y;
					SDL_RenderCopy(ren, kek, NULL, &kek_r[1][i]);
				}
			}
			if(kek_r[0][i].x > size_window_w - kek_r[0][i].w) {
				if(kek_r[0][i].x > size_window_w) {
					kek_r[0][i].x = 0;
					kek_r[1][i].x = size_window_w;
					kek_r[1][i].y = size_window_h;
					SDL_RenderCopy(ren, kek, NULL, &kek_r[1][i]);
				} else {
					kek_r[1][i].x = kek_r[0][i].x - size_window_w;
					kek_r[1][i].y = kek_r[0][i].y;
					SDL_RenderCopy(ren, kek, NULL, &kek_r[1][i]);
				}
			}
			if(kek_r[0][i].y < 0) kek_r[0][i].y = 0;
			if(kek_r[0][i].y > size_window_h - kek_r[0][i].h) kek_r[0][i].y = size_window_h - kek_r[0][i].h;
		}
		SDL_PollEvent(&event);
		SDL_RenderPresent(ren);
		if(event.type == SDL_MOUSEWHEEL) {
			time_st = event.button.timestamp;
			if(time_st > time_st0) {
				time_st0 = event.button.timestamp;
				if(event.button.x == 1) {	
					/*for(int i = 0; i < amount_numb; i++) {
						kek_r[0][i].y--;
						kek_r[1][i].y--;
					}*/
					kek_r[0][select_numb].h +=1;
					kek_r[0][select_numb].w +=1;
					kek_r[1][select_numb].h +=1;
					kek_r[1][select_numb].w +=1;	
				}
				if(event.button.x == -1) {
					/*for(int i = 0; i < amount_numb; i++) {
						kek_r[0][i].y++;
						kek_r[1][i].y++;
					}*/
					kek_r[0][select_numb].h -=1;
					kek_r[0][select_numb].w -=1;
					kek_r[1][select_numb].h -=1;
					kek_r[1][select_numb].w -=1;
				}
			}
		}
		if(event.type == SDL_KEYDOWN) {
			if(event.button.button == SDL_SCANCODE_P) {
				for(int i = 0; i < amount_numb; i++) {
					kek_r[0][i].x+= speed[i];
				}
			}
		}
		if(event.type == SDL_KEYDOWN) {
			switch (event.button.button) {
				case SDL_SCANCODE_S: 
					kek_r[0][select_numb].y += sped_kek;
					break;
				case SDL_SCANCODE_W:
					kek_r[0][select_numb].y -= sped_kek;
					break;
				case SDL_SCANCODE_D:
					kek_r[0][select_numb].x += sped_kek;
					break;
				case SDL_SCANCODE_A:
					kek_r[0][select_numb].x -= sped_kek;
					break;
				case SDL_SCANCODE_ESCAPE:
					quit = false;
					break;
				case SDL_SCANCODE_1:
					select_numb = 1;
					break;
				case SDL_SCANCODE_2:
					select_numb = 2;
					break;
				case SDL_SCANCODE_3:
					select_numb = 3;
					break;
				case SDL_SCANCODE_4:
					select_numb = 4;
					break;
				case SDL_SCANCODE_5:
					select_numb = 5;
					break;
				case SDL_SCANCODE_6:
					select_numb = 6;
					break;
				case SDL_SCANCODE_7:
					select_numb = 7;
					break;
				case SDL_SCANCODE_8:
					select_numb = 8;
					break;
				case SDL_SCANCODE_9:
					select_numb = 9;
					break;
				case SDL_SCANCODE_0:
					select_numb = 0;
					break;
				case SDL_SCANCODE_TAB:
					time_st_tab = event.button.timestamp;
					if (time_st_tab > time_st_tab0) {
						time_st_tab0 = event.button.timestamp;
						if (select_numb < amount_numb - 1) select_numb += 1;
						else select_numb = 0;
					}
			}
		}
		if(event.type == SDL_MOUSEBUTTONDOWN) {
			if(event.button.button == SDL_BUTTON_LEFT) {
				for(int i = 0; i < amount_numb; i++) {
					if(kek_r[0][i].x < event.button.x) kek_r[0][i].x++;
					if(kek_r[0][i].x > event.button.x) kek_r[0][i].x--;
					if(kek_r[1][i].x < event.button.x) kek_r[1][i].x++;
					if(kek_r[1][i].x > event.button.x) kek_r[1][i].x--;
					if(kek_r[0][i].y < event.button.y) kek_r[0][i].y++;
					if(kek_r[0][i].y > event.button.y) kek_r[0][i].y--;
					if(kek_r[1][i].y < event.button.y) kek_r[1][i].y++;
					if(kek_r[1][i].y > event.button.y) kek_r[1][i].y--;
				}
			}
		}
		for(int i = 0; i < amount_numb; i++) {
			if(!active[0][i]) {
				kek_r[0][i].x = size_window_w;
				kek_r[0][i].y = size_window_h;
			}
			if(!active[1][i]) {
				kek_r[1][i].x = size_window_w;
				kek_r[1][i].y = size_window_h;
			}
		}
		if(event.type == SDL_QUIT) quit = false;
	}
	cout << "не УБИТО а ЗАВЕРШЕНО. ганстащит" << endl;
	SDL_Quit();
}