#define MAXCOLORTC 	// MAXCOLOR16 - 16 цветов
		        // MAXCOLOR256 - 256 16 цветов
	                // MAXCOLORTC - True Color

#include "wingraph.h"

int main()
{
resize(512,512);
 for(int i=0; i<512; i++)
  for(int j=0; j<512; j++)
    putpixel(i,j,RGB(i/2,j/2,255-j/2));
}
