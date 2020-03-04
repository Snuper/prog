#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>


using namespace std ;

struct school 
{
	int school_Number ;
	int number_of_school_graduates ;
	int number_of_university_admissions ;
	float the_percentage_of_enrolled_in_universities ;
} gorod ;

int main()
{
	int N ;

	cout << "number of schools : " ; cin >> N  ; cout << endl ;
	cout<<"number of school graduates < number of university admissions"<<endl<<endl ;
	
	struct school mass_info_school [N] ;
	
    	for (int i = 0 ; i < N ; i++)
           {
           	cout<<"school Number : " ; cin >> gorod.school_Number ;
           	cout<<"number of school graduates : " ; cin >> gorod.number_of_school_graduates ;
           	cout<<"number of university admissions : " ; cin >> gorod.number_of_university_admissions ;
           	gorod.the_percentage_of_enrolled_in_universities = ((float)gorod.number_of_school_graduates/(float)gorod.number_of_university_admissions)*100 ;
           	mass_info_school [i] = gorod ; cout << endl ;
	       }
	       
	int *Mass_Index = new int [N] ;
	   for(int i = 0 ; i < N ; i++ )  
	      {
	      	Mass_Index[i] = i+1 ;
	      }
	   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	  teryaetca znak drobi  
     for (int j = 0 ; j < N ; j++ )
     {
	  for (int i = 0 ; i < N - 1 ; i++)
         {
          	if ( mass_info_school[i].the_percentage_of_enrolled_in_universities < mass_info_school [i+1].the_percentage_of_enrolled_in_universities )      ///////////////////////
         	   {
          	   	int temp = mass_info_school [i].the_percentage_of_enrolled_in_universities ;                                                          
          	   	mass_info_school [i].the_percentage_of_enrolled_in_universities = mass_info_school [i+1].the_percentage_of_enrolled_in_universities ;      ///////////////////////
          	   	mass_info_school [i+1].the_percentage_of_enrolled_in_universities = temp ;
          	   }
         }                                                                                           
     }                                                                                                                                                      
///////////////////////////////////////////////////////////////////////////////////////////////// ///////////////////////////////////////////////////////  teryaetca znak drobi   
     
     
	for (int i = 0 ; i < N ; i++)
	{
	 cout << "the percentage of enrolled in universities => " <<"school number "<<mass_info_school [i].school_Number<<" : " << fixed << setprecision(0)<< mass_info_school [i].the_percentage_of_enrolled_in_universities <<" % " << endl ;
	}
	       	   
	delete [] Mass_Index ;
	cin.ignore();
    cin.get();
	return 0;
}
