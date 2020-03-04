
struct  head {
        short bftype;
        long  bfsize;
        short rez1, rez2;
        long  bfoffbits;
        long  bisize;
        long  biwidth;
        long  biheight;
        short biplanes;
        short bibitcount;
        long  bicompression;
        long  bisizeimage;
        long  bix;
        long  biy;
        long  biclrused;
        long  biclrimp;
} head_file;

unsigned char palitra[256][4];


void main() {

  fread(&head_file,sizeof(head_file),1,f1);
  for(i=0; i<(head_file.bfoffbits-54)/4; i++) {
    fread(palitra[i],4,1,f1);
  }
  do {
    n=fread(buffer,1,1024,f1);
  } while(n==1024);
  fcloseall();
}
