#define MAXCOLOR256 	// MAXCOLOR16 - 16 цветов
		             		// MAXCOLOR256 - 256 цветов
	                           		// MAXCOLORTC - 16м цветов True Color

#include "wingraph.h"
#include <stdio.h>

void main()
{
 int i,j;
  for(int i=0; i<16; i++)
   setpalette(i,RGB(random(256),random(256),random(256)));
for(i=0;i<640;i++)
  for(j=0;j<480;j++) putpixel(i,j,(j/120)*4+i/160);


  }
