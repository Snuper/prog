#include <conio.h> 
#include <graphics.h> 
#include <ctime>
int cor1 [25],cor2 [25],P1,P2;
int snow (int pos1, int pos2 ,int color1, int size1, int size2)  //size �������� �� �����, �� ����� � ��� ��������.
{ 
setcolor(color1); 
moveto(pos1,pos2); 
lineto(pos1+size1,pos2);
 lineto(pos1-size1,pos2);  
 moveto(pos1,pos2);
lineto(pos1,pos2+size1);
 lineto(pos1,pos2-size1);
moveto(pos1,pos2);
lineto(pos1-size2,pos2+size2);
lineto(pos1+size2,pos2-size2);
moveto(pos1,pos2);
lineto(pos1+size2,pos2+size2);
lineto(pos1-size2,pos2-size2);

} 
int gen(int d) {
	 
	int C,S1,S2;
	C=rand()%15;
	P1=rand()%630;
	P2=rand()%630;
	snow ( P1, P2, C, 10,8) ;
    cor1[d] = P1; cor2[d] = P2;
}
int clear(int d)	{
	 
	P1=cor1[d]; P2=cor2[d];
	snow ( P1, P2, 0, 10,8) ;
}

main()

{initwindow(640,480);
	while(1){ 
	int i;
	for(i=0;i<20;i++)
	gen(i);
	delay(1000);
	for(i=0;i<20;i++)
	clear(i);
	
	
	
	
	



}




}

