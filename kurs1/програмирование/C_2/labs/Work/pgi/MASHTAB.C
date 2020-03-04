  w=(head_file.width+3)/4*4;
  for(l=j=0;j<head_file.height*k;j++) {
    for(;l<j;l+=k) fread(buffer,1,w,f1);
    for(i=0; i<w*k; i++) {
        WritePixel(i,(480-j),buffer[(int)(i/k)]);
    }
  }
