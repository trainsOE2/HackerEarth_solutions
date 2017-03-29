#include<iostream>
#include<string>
using namespace std;
int check(int);

int check(int num)
{
	int i, j, temp, smallest, temp_prime ;
    int diff[12];
	int prime[12] = { 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113 } ;
	
	
	for ( i=0 ; i<12 ; i++)
	{
		diff[i] = prime[i] - num;
		if ( diff[i] < 0)
		{
			diff[i] =  (diff[i] * -1 );
		}
	}
	
	for ( i=1 ; i<12 ; i++)
	{
		for ( j=0 ; j<(12-i) ; j++)
		{  
			 
			if ( diff[j] > diff[j+1])
			{
				temp = diff[j] ;
				diff[j] = diff[j+1] ;
				diff[j+1] = temp ;
				temp_prime = prime[j] ; 
				prime[j] = prime[j+1] ;
				prime[j+1] = temp_prime ;
			}
		}
	}
	num = prime[0] ; 

	return num;
}


int main()
{
   char ch[100][500];
   int n[500], t, val, i, j, newval;
   
   std::cout << "Enter the number of strings : " ;
   std::cin >> t;
   
   for ( i=0 ; i<t ; i++)
   {
	   	std::cout << "Enter the number of characters for string " << i+1 << " : " ; 
	   	std::cin >> n[i] ;
	   	
	   	for ( j=0 ; j<n[i] ; j++ )
	   	{
	   		std::cin >> ch[i][j] ;
		}
   }
   
   for ( i=0 ; i<t ; i++)
   {
	for ( j=0 ; j<n[i] ; j++)
	{
		val = (int)ch[i][j];
		newval = check(val);
		ch[i][j] = (char)newval;	
	}
   }
   
   for ( i=0 ; i<t ; i++)
   {
   	std::cout << "The converted string : " ;
   	for ( j=0 ; j<n[i] ; j++)
   	{
   		std::cout << ch[i][j] ;
	}
	std::cout << "\n" ; 
   }
   
   return 0;
}
