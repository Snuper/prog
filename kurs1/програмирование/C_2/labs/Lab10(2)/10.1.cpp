 #include <cstdio>
 #include <iostream>
 #include <string>
 #include <graphics.h>
 using namespace std;
 int main ()
{
  	string checkstring;
  	
	char repeat = 1,ch;
  	char o[10];
  	cin>>o;
  	do
	{
	  	cout<<"Commands (create, start, reverse):"<<endl<<"-";
	  	cin>>checkstring;
	  	if(checkstring=="create")
	  	{
	  		FILE *fw;
			fw=fopen("text.txt","wt");
			//fscanf("",)
			/*printf("vvedite slova");
			if(!='')
			    putc(*fw,o);
			    */
		//	while(k<10);
		//	{
		//	fscanf();
		//	k++;
		//}
			//fputs();
			fputs(o,fw);
			//fprintf(fw,"%c\n",o);
		//	fwrite(&o,sizeof(char),1,fw)
		///	while(!feof(fw))
		//	{ch=getc(fw);
		//	getc;
		//	putchar(ch);
		//	getch();
			fclose(fw);
			repeat = 2;
		}
	  	if(checkstring=="start")
	  	{
	  		FILE *fr,*fwg,*fws;
	  		char ch,temp;
	  		bool gl=0;
	  		fr=fopen("text.txt","rt");
	  		fwg=fopen("glas.txt","wt");
	  		fws=fopen("sogl.txt","wt");
	  		while(!feof(fr))
	  		{
	  			ch=getc(fr);
	  			if(ch==',' || ch=='.') continue;
	  			if(ch!=' ')
	  			{
	  				temp=tolower(ch);
	  				if(temp=='a'||temp=='e'||temp=='i'||temp=='o'||temp=='u'||temp=='y')
	  				{
	  					while(!feof(fr))
	  					{
	  						if(ch==',' || ch=='.' || ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9')
	  						{
	  							ch=getc(fr);
	  							continue;
							}
	  						if(ch==' ' ||  ch=='\n')
	  						{
	  							fprintf(fwg,"\n");
	  							break;
							}
	  						putc(ch,fwg);
	  						ch=getc(fr);
						}
					}
					else
					{
	  					while(!feof(fr))
	  					{
	  						if(temp==',' || temp=='.' || temp=='0' || temp=='1' || temp=='2' || temp=='3' || temp=='4' || temp=='5' || temp=='6' || temp=='7' || temp=='8' || temp=='9')
	  						{
	  							ch=getc(fr);
	  							continue;
							}
	  						if(ch==' ' ||  ch=='\n')
	  						{
	  							fprintf(fws,"\n");
	  							break;
							}
	  						putc(ch,fws);
	  						ch=getc(fr);
						}
					}
				}
			}
			fclose(fr);
			fclose(fwg);
			fclose(fws);
	  		repeat = 3;	
		}
		if(checkstring=="starttolower")
	  	{
	  		FILE *fr,*fwg,*fws;
	  		char ch;
	  		bool gl=0;
	  		fr=fopen("text.txt","rt");
	  		fwg=fopen("glas(tolower).txt","wt");
	  		fws=fopen("sogl(tolower).txt","wt");
	  		while(!feof(fr))
	  		{
	  			ch=getc(fr);
	  			if(ch==',' || ch=='.') continue;
	  			if(ch!=' ')
	  			{
	  				ch=tolower(ch);
	  				if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='y')
	  				{
	  					while(!feof(fr))
	  					{
	  						if(ch==',' || ch=='.' || ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9')
	  						{
	  							ch=getc(fr);
	  							continue;
							}
	  						if(ch==' ' ||  ch=='\n')
	  						{
	  							fprintf(fwg,"\n");
	  							break;
							}
	  						putc(ch,fwg);
	  						ch=tolower(getc(fr));
						}
					}
					else
					{
	  					while(!feof(fr))
	  					{
	  						if(ch==',' || ch=='.' || ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9')
	  						{
	  							ch=getc(fr);
	  							continue;
							}
	  						if(ch==' ' ||  ch=='\n')
	  						{
	  							fprintf(fws,"\n");
	  							break;
							}
	  						putc(ch,fws);
	  						ch=tolower(getc(fr));
						}
					}
				}
			}
			fclose(fr);
			fclose(fwg);
			fclose(fws);
	  		repeat = 4;	
		}
		if(checkstring=="reverse")
		{
			FILE *fr,*fwg,*ftemp;
	  		char ch;
	  		int count=0,s=0;
	  		fr=fopen("text.txt","rt");
	  		fwg=fopen("reverse.txt","wt");
	  		rewind(fr);
	  		while(!feof(fr))
	  		{
	  			ch=getc(fr);
	  			if(feof(fr)) break;
	  			if(ch=='\n') {s+=2; continue;}
	  			s++;
	  		}
	  		rewind(fr);
	  		int i=-1;
	  		while(s>=(i*(-1)))
	  		{
	  			fseek(fr,i,2);
	  			ch=getc(fr);
	  			if(ch=='\n') {putc('\n',fwg); ch=getc(fr); i-=2; continue;}
	  			putc(ch,fwg);
	  			i--;
	  		}
			fclose(fr);
	  		fclose(fwg);
	  		repeat=5;
		}
		if(repeat == 1) cout<<"This command doesn't exist."<<endl;
		else cout<<"-- OK."<<endl;
		cout<<endl<<"Prodolzit?(yes/no)";
		if(getch() == 110) repeat = 0;
		if(repeat)
		{
			system("cls");
			repeat = 1;
		}
	}
	while(repeat);
  	return 0;
}
