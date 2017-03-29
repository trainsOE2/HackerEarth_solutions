#include<iostream>
#include<vector>
int segment(int) ;
int total_segments(int) ;

using namespace std ;

int segment (int value)
{
	int nos ;
	if ( value == 1)
		nos = 2 ;
	if ( value == 7)
		nos = 3 ;
	if ( value == 4)
		nos = 4 ;
	if ( value == 2 || value == 3 || value == 5 || value == 9 )
		nos = 5 ;
	if ( value == 6 || value == 0)
		nos = 6 ;
	if ( value == 8)
		nos = 7 ;
	return nos ;
}

int total_segments(int input)
{
	int num, nos = 0, total_nos = 0 ; 

		while (input != 0)
		{
			num = input%10 ;
			nos = segment(num) ;
			input = input/10 ;
			total_nos += nos ;	
		}
		return total_nos ;
}

int main()
{
	int t;
	
	cin >> t;
	
	while( t--)
	{
		int n, i, j, temp, temp_nos ;
		unsigned long long item; 
		vector <unsigned long long> A ; 
		vector <unsigned long long> no_of_segments ;
		
		cin >> n ;
		
		for( i=0 ; i<n ; i++)
		{
			cin >> item ;
			A.push_back(item);
			no_of_segments.push_back(total_segments(A[i])) ;
		}
		
		for ( i=1 ; i<n ; i++)
		{
			for ( j=0 ; j<(n-i) ; j++)
			{  
				 
				if ( no_of_segments[j] > no_of_segments[j+1] )
				{
					temp_nos = no_of_segments[j] ;
					no_of_segments[j] = no_of_segments[j+1] ;
					no_of_segments[j+1] = temp_nos ;
					
					temp = A[j] ;
					A[j] = A[j+1] ;
					A[j+1] = temp ;
				}
			}
		}
		
		cout << "\n" << A[0] ;
	}
	
	return 0;
}
