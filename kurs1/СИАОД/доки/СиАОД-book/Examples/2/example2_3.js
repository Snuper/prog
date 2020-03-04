function preload()
{
dig = new Array(10);
    dig[0]=new Image();
    dig[0].src="../Examples/pictures/dg0_0.gif";
    dig[1]=new Image();
    dig[1].src="../Examples/pictures/dg1_0.gif";
    dig[2]=new Image();
    dig[2].src="../Examples/pictures/dg2_0.gif";
    dig[3]=new Image();
    dig[3].src="../Examples/pictures/dg3_0.gif";
    dig[4]=new Image();
    dig[4].src="../Examples/pictures/dg4_0.gif";
    dig[5]=new Image();
    dig[5].src="../Examples/pictures/dg5_0.gif";
    dig[6]=new Image();
    dig[6].src="../Examples/pictures/dg6_0.gif";
    dig[7]=new Image();
    dig[7].src="../Examples/pictures/dg7_0.gif";
    dig[8]=new Image();
    dig[8].src="../Examples/pictures/dg8_0.gif";
    dig[9]=new Image();
    dig[9].src="../Examples/pictures/dg9_0.gif";

dig1 = new Array(10);
    dig1[0]=new Image();
    dig1[0].src="../Examples/pictures/dg0_1.gif";
    dig1[1]=new Image();
    dig1[1].src="../Examples/pictures/dg1_1.gif";
    dig1[2]=new Image();
    dig1[2].src="../Examples/pictures/dg2_1.gif";
    dig1[3]=new Image();
    dig1[3].src="../Examples/pictures/dg3_1.gif";
    dig1[4]=new Image();
    dig1[4].src="../Examples/pictures/dg4_1.gif";
    dig1[5]=new Image();
    dig1[5].src="../Examples/pictures/dg5_1.gif";
    dig1[6]=new Image();
    dig1[6].src="../Examples/pictures/dg6_1.gif";
    dig1[7]=new Image();
    dig1[7].src="../Examples/pictures/dg7_1.gif";
    dig1[8]=new Image();
    dig1[8].src="../Examples/pictures/dg8_1.gif";
    dig1[9]=new Image();
    dig1[9].src="../Examples/pictures/dg9_1.gif";

dig2 = new Array(10);
    dig2[0]=new Image();
    dig2[0].src="../Examples/pictures/dg0_2.gif";
    dig2[1]=new Image();
    dig2[1].src="../Examples/pictures/dg1_2.gif";
    dig2[2]=new Image();
    dig2[2].src="../Examples/pictures/dg2_2.gif";
    dig2[3]=new Image();
    dig2[3].src="../Examples/pictures/dg3_2.gif";
    dig2[4]=new Image();
    dig2[4].src="../Examples/pictures/dg4_2.gif";
    dig2[5]=new Image();
    dig2[5].src="../Examples/pictures/dg5_2.gif";
    dig2[6]=new Image();
    dig2[6].src="../Examples/pictures/dg6_2.gif";
    dig2[7]=new Image();
    dig2[7].src="../Examples/pictures/dg7_2.gif";
    dig2[8]=new Image();
    dig2[8].src="../Examples/pictures/dg8_2.gif";
    dig2[9]=new Image();
    dig2[9].src="../Examples/pictures/dg9_2.gif";

vector = new Array(5);
    vector[0]=new Image();
    vector[0].src="../Examples/pictures/vect0.gif";
    vector[1]=new Image();
    vector[1].src="../Examples/pictures/vect_l.gif";
    vector[2]=new Image();
    vector[2].src="../Examples/pictures/vect_r.gif";
    vector[3]=new Image();
    vector[3].src="../Examples/pictures/vect_t.gif";
    vector[4]=new Image();
    vector[4].src="../Examples/pictures/vect2.gif";

dot = new Image();
dot.src="../Examples/pictures/circle.gif";
show();
}

function showdot(l,r)
{
 if ((l==0)||(r==0)){document.vct0.src=dot.src;}
 else {document.vct0.src=vector[0].src;}
 if ((l==1)||(r==1)){document.vct1.src=dot.src;}
 else {document.vct1.src=vector[0].src;}
 if ((l==2)||(r==2)){document.vct2.src=dot.src;}
 else {document.vct2.src=vector[0].src;}
 if ((l==3)||(r==3)){document.vct3.src=dot.src;}
 else {document.vct3.src=vector[0].src;}
 if ((l==4)||(r==4)){document.vct4.src=dot.src;}
 else {document.vct4.src=vector[0].src;}
 if ((l==5)||(r==5)){document.vct5.src=dot.src;}
 else {document.vct5.src=vector[0].src;}
 if ((l==6)||(r==6)){document.vct6.src=dot.src;}
 else {document.vct6.src=vector[0].src;}
 if ((l==7)||(r==7)){document.vct7.src=dot.src;}
 else {document.vct7.src=vector[0].src;}
 if ((l==8)||(r==8)){document.vct8.src=dot.src;}
 else {document.vct8.src=vector[0].src;}
 if ((l==9)||(r==9)){document.vct9.src=dot.src;}
 else {document.vct9.src=vector[0].src;}

}

function RANDOMIZE()
{
Povtor = new Array(10);
Povtor[0]=0;
Povtor[1]=0;
Povtor[2]=0;
Povtor[3]=0;
Povtor[4]=0;
Povtor[5]=0;
Povtor[6]=0;
Povtor[7]=0;
Povtor[8]=0;
Povtor[9]=0;

a = new Array(10);

for(i=0;i<10;i++)
   {
    do
     {iter=0;
      a[i]=Math.round(Math.random()*10);
       if (a[i]>=10){a[i]=0;} 
       for(j=0;j<i;j++)
          {
           if ((Povtor[i]==0)&&(a[i]==a[j])){Povtor[i]=1;Povtor[j]=1;}
           else
           if ((Povtor[i]==1)&&(a[i]==a[j])){iter=1;} 
          }
    }while(iter==1);
  }

Povtor[0]=0;
Povtor[1]=0;
Povtor[2]=0;
Povtor[3]=0;
Povtor[4]=0;
Povtor[5]=0;
Povtor[6]=0;
Povtor[7]=0;
Povtor[8]=0;
Povtor[9]=0;

for(i=0;i<10;i++)
   {
    for(j=0;j<i;j++)
        {
         if (a[i]==a[j]){Povtor[j]=1;Povtor[i]=2;} 
        }
   }
preload();
document.vct0.src=vector[0].src;
document.vct1.src=vector[0].src;
document.vct2.src=vector[0].src;
document.vct3.src=vector[0].src;
document.vct4.src=vector[0].src;
document.vct5.src=vector[0].src;
document.vct6.src=vector[0].src;
document.vct7.src=vector[0].src;
document.vct8.src=vector[0].src;
document.vct9.src=vector[0].src;
show();
i=0;
j=1;
k=i;
}

function changevect(l,r)
{
if (l==0){ document.vct0.src=vector[1].src;}
if (r==0){ document.vct0.src=vector[2].src;}
if ((r==0)&&(l==0)){document.vct0.src=vector[4].src;}
if (l>0) { document.vct0.src=vector[0].src;}
if (r<0) { document.vct0.src=vector[0].src;}
if ((l<0)&&(r>0)){ document.vct0.src=vector[3].src;}
if (l==1){ document.vct1.src=vector[1].src;}
if (r==1){ document.vct1.src=vector[2].src;}
if ((r==1)&&(l==1)){document.vct1.src=vector[4].src;}
if (l>1) { document.vct1.src=vector[0].src;}
if (r<1) { document.vct1.src=vector[0].src;}
if ((l<1)&&(r>1)){ document.vct1.src=vector[3].src;}
if (l==2){ document.vct2.src=vector[1].src;}
if (r==2){ document.vct2.src=vector[2].src;}
if ((r==2)&&(l==2)){document.vct2.src=vector[4].src;}
if (l>2) { document.vct2.src=vector[0].src;}
if (r<2) { document.vct2.src=vector[0].src;}
if ((l<2)&&(r>2)){ document.vct2.src=vector[3].src;}
if (l==3){ document.vct3.src=vector[1].src;}
if (r==3){ document.vct3.src=vector[2].src;}
if ((r==3)&&(l==3)){document.vct3.src=vector[4].src;}
if (l>3) { document.vct3.src=vector[0].src;}
if (r<3) { document.vct3.src=vector[0].src;}
if ((l<3)&&(r>3)){ document.vct3.src=vector[3].src;}
if (l==4){ document.vct4.src=vector[1].src;}
if (r==4){ document.vct4.src=vector[2].src;}
if ((r==4)&&(l==4)){document.vct4.src=vector[4].src;}
if (l>4) { document.vct4.src=vector[0].src;}
if (r<4) { document.vct4.src=vector[0].src;}
if ((l<4)&&(r>4)){ document.vct4.src=vector[3].src;}
if (l==5){ document.vct5.src=vector[1].src;}
if (r==5){ document.vct5.src=vector[2].src;}
if ((r==5)&&(l==5)){document.vct5.src=vector[4].src;}
if (l>5) { document.vct5.src=vector[0].src;}
if (r<5) { document.vct5.src=vector[0].src;}
if ((l<5)&&(r>5)){ document.vct5.src=vector[3].src;}
if (l==6){ document.vct6.src=vector[1].src;}
if (r==6){ document.vct6.src=vector[2].src;}
if ((r==6)&&(l==6)){document.vct6.src=vector[4].src;}
if (l>6) { document.vct6.src=vector[0].src;}
if (r<6) { document.vct6.src=vector[0].src;}
if ((l<6)&&(r>6)){ document.vct6.src=vector[3].src;}
if (l==7){ document.vct7.src=vector[1].src;}
if (r==7){ document.vct7.src=vector[2].src;}
if ((r==7)&&(l==7)){document.vct7.src=vector[4].src;}
if (l>7) { document.vct7.src=vector[0].src;}
if (r<7) { document.vct7.src=vector[0].src;}
if ((l<7)&&(r>7)){ document.vct7.src=vector[3].src;}
if (l==8){ document.vct8.src=vector[1].src;}
if (r==8){ document.vct8.src=vector[2].src;}
if ((r==8)&&(l==8)){document.vct8.src=vector[4].src;}
if (l>8) { document.vct8.src=vector[0].src;}
if (r<8) { document.vct8.src=vector[0].src;}
if ((l<8)&&(r>8)){ document.vct8.src=vector[3].src;}
if (l==9){ document.vct9.src=vector[1].src;}
if (r==9){ document.vct9.src=vector[2].src;}
if ((r==9)&&(l==9)){document.vct9.src=vector[4].src;}
if (l>9) { document.vct9.src=vector[0].src;}
if (r<9) { document.vct9.src=vector[0].src;}
if ((l<9)&&(r>9)){ document.vct9.src=vector[3].src;}
}

function show()
{

if (Povtor[0]==0)
{
 document.pic0.src=dig[a[0]].src;
}
if (Povtor[1]==0)
{
 document.pic1.src=dig[a[1]].src;
}
if (Povtor[2]==0)
{
 document.pic2.src=dig[a[2]].src;
}
if (Povtor[3]==0)
{
 document.pic3.src=dig[a[3]].src;
}
if (Povtor[4]==0)
{
 document.pic4.src=dig[a[4]].src;
}
if (Povtor[5]==0)
{
 document.pic5.src=dig[a[5]].src;
}
if (Povtor[6]==0)
{
 document.pic6.src=dig[a[6]].src;
}
if (Povtor[7]==0)
{
 document.pic7.src=dig[a[7]].src;
}
if (Povtor[8]==0)
{
 document.pic8.src=dig[a[8]].src;
}
if (Povtor[9]==0)
{
 document.pic9.src=dig[a[9]].src;
}

if (Povtor[0]==1)
{
 document.pic0.src=dig1[a[0]].src;
}
if (Povtor[1]==1)
{
 document.pic1.src=dig1[a[1]].src;
}
if (Povtor[2]==1)
{
 document.pic2.src=dig1[a[2]].src;
}
if (Povtor[3]==1)
{
 document.pic3.src=dig1[a[3]].src;
}
if (Povtor[4]==1)
{
 document.pic4.src=dig1[a[4]].src;
}
if (Povtor[5]==1)
{
 document.pic5.src=dig1[a[5]].src;
}
if (Povtor[6]==1)
{
 document.pic6.src=dig1[a[6]].src;
}
if (Povtor[7]==1)
{
 document.pic7.src=dig1[a[7]].src;
}
if (Povtor[8]==1)
{
 document.pic8.src=dig1[a[8]].src;
}
if (Povtor[9]==1)
{
 document.pic9.src=dig1[a[9]].src;
}

if (Povtor[0]==2)
{
 document.pic0.src=dig2[a[0]].src;
}
if (Povtor[1]==2)
{
 document.pic1.src=dig2[a[1]].src;
}
if (Povtor[2]==2)
{
 document.pic2.src=dig2[a[2]].src;
}
if (Povtor[3]==2)
{
 document.pic3.src=dig2[a[3]].src;
}
if (Povtor[4]==2)
{
 document.pic4.src=dig2[a[4]].src;
}
if (Povtor[5]==2)
{
 document.pic5.src=dig2[a[5]].src;
}
if (Povtor[6]==2)
{
 document.pic6.src=dig2[a[6]].src;
}
if (Povtor[7]==2)
{
 document.pic7.src=dig2[a[7]].src;
}
if (Povtor[8]==2)
{
 document.pic8.src=dig2[a[8]].src;
}
if (Povtor[9]==2)
{
 document.pic9.src=dig2[a[9]].src;
}

}

function zapusk()
{
del=300;
Sort();
}

function Slower()
{
del=del+100;
}

function Fast()
{
del=del-100;
if(del<0){del=0;}
}

function Sort()
{show();

if (i>=9){clearTimeout(Timer);}
        if(a[j]<a[k]) {k=j;}
j++;
showdot(i,j);
if (j>=10){
           temp=a[i];
           a[i]=a[k];
           a[k]=temp;
temp=Povtor[i];
Povtor[i]=Povtor[k];
Povtor[k]=temp;
changevect(i,k);
i++;k=i;j=i+1;
}
Timer=setTimeout("Sort()",del);
}
