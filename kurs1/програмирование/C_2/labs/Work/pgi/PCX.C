
typedef struct TPCXHeaderStruct
 {
  unsigned char ID;
  unsigned char Version;
  unsigned char Coding;
  unsigned char BitPerPixel;
  unsigned short  XMin;
  unsigned short  YMin;
  unsigned short  XMax;
  unsigned short  YMax;
  unsigned short  HRes;
  unsigned short  VRes;
  unsigned char Palette[48];
  unsigned char Reserved;
  unsigned char Planes;
  unsigned short  BytePerLine;
  unsigned short  PaletteInfo;
  unsigned short  HScreenSize;
  unsigned short  VScreenSize;
  unsigned char Filler[54];
 } TPCXHeader;

typedef struct TPaletteStruct
 {
  unsigned char Red;
  unsigned char Green;
  unsigned char Blue;
 } TPalette;

TPCXHeader PCXHeader;
TPalette PCXPalette[256];

void main()
{

}