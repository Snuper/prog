#pragma once

	struct unit
	{
		char name[30];
		unsigned short int debt;
		char date[10];
		char lawyer[22];

	};

	struct list {
		unit note;
		list* next;
	};



