#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include "Asset.h"

using namespace std;

struct Block_history
{//структура хранящая инфу о блоке
	int x = 0;
	int y = 0;
	int z = 0;
	int h = 0;
	int block_size = 0;
};

int random_block_size(int &min_size, int &max_size, int &grid)
{//рандомим размер блока с учетом шага сетки
	int temp_size;
	
	for(;;)
	{
		temp_size = rand() % max_size + min_size;
		if(temp_size % grid == 0)
		{
			return temp_size;
			break;
		}
	}
}

int asset_pack(int number, Asset &Asset, Block_history &history, int &block_distance)
{
	if(number == 1) Asset::Line(history, block_distance);
}

void show(Block_history *history, int &blocks)
{//выводим структуру Block_history
	for(int i = 0; i < blocks; i++)
	{
		cout << endl << "Block# " << i << "	-	x = " << history[i].x << "	y = " << history[i].y << "	z = " << history[i].z << "	 h = " << history[i].h << "	size = " << history[i].block_size;
	}
}

void blocks_generate(int &map_x, int &map_y, int &masp_z, int &blocks, int &grid, Block_history *history, int& min_size, int &max_size, int &block_distance, int &h_change)
{
	bool random_do = true; //нужно ли рандомить размер блока, если min и max совпадут, то логично, не надо
	
	if(max_size == min_size) random_do = false;
	
	for(int i = 1; i < blocks; i++)
	{
		S//рандомими размер блока и записываем результат в структуру, либо не рандомим, если не прошло прошлое условие
		if(random_do == true) history[i].block_size = random_block_size(min_size, max_size, grid);
		else history[i].block_size = min_size;
		//рандомими размер блока и записываем результат в структуру, либо не рандомим, если не прошло прошлое условие
		
		asset_pack(1, Asset, history, block_distance, map_x, map_y, map_z, false, h_change);
	}
	
	show(history, blocks);
}

main()
{
	srand(time(0));
	
	int map_x, map_y, map_z, blocks, grid, min_size, max_size, block_distance, h_change;
	Asset Asset();
	
//	Входные данные
	cout << endl << "Razmer karty" << endl << "x = ";
	cin >> map_x;
	
	cout << endl << "y = ";
	cin >> map_y;

	cout << endl << "z = ";
	cin >> map_z;
	
	cout << endl << "kolvo blockov = ";
	cin >> blocks;
	
	cout << endl << "Shag grid = ";
	cin >> grid;

	cout << endl << "Min xize block = ";
	cin >> min_size;
	
	cout << endl << "Max size block = ";
	cin >> max_size;

	cout << endl << "Distance between blocks = ";
	cin >> block_distance;
	
	cout << endl << "h change = ";
	cin >> h_change;
//	Входные данные

	Block_history *history = nullptr;
	history = new Block_history [blocks];
	
	history[0].x = map_x / 2;
	history[0].y = map_y / 2;
	history[0].z = map_z / 2;
	history[0].h = grid;
	history[0].block_size = random_block_size(min_size, max_size, grid)
	
	blocks_generate(map_x, map_y, map_z, blocks, grid, history, min_size, max_size, block_distance, h_change);
	
	return 0;
}
