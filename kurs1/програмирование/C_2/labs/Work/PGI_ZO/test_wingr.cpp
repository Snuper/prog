#define MAXCOLORTC 	// MAXCOLOR16 - 16 цветов
		        // MAXCOLOR256 - 256 цветов
	                // MAXCOLORTC - 16м цветов True Color

#include "wingraph.h"

void main()
{
resize(512,512);
 for(int i=0; i<512; i++)
  for(int j=0; j<512; j++)
    putpixel(i,j,RGB(i/2,j/2,255-j/2));
}
