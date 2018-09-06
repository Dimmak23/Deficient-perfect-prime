#include <iostream>
#include <time.h>

// Function for schecking number
bool chkNumber(int number, float def, int j, bool ans)
{
	// Inputed number devided by '2', it is minimization of iterations
	int y = number/2, k = 1;
	int sum = 1;
	// Here and next only true value of ans allow print result
	if(ans && def) std::cout<<"\n"<<j<<". (number: "<< number <<") "<<k;
	if(ans && !def) std::cout<<"\n"<<j<<". ";
	// Simple cycle for sum of factors
	while(++k<=y) {
			if( !(number%k) )
				{
					if(ans) std::cout<<"+"<<k;
					sum+=k;
				}
		}
	// If mode is for deficient Sum(factors)<d*Number
	if( ( (sum+number) < (def*number) ) && (def-1) ) {
			if(ans) std::cout<<"+"<<number<<"="<<sum+number
							<<" < "<<def<<"*"<<number<<"="<<def*number;
			// return '1' if conditions is done
			return true;
		}
	// If mode is for prime only factors is 1 and number itself
	if( ( (sum+number-1) == number ) && !def ) {
			if(ans) std::cout<<number;
			// return '1' if conditions is done
			return true;
		}
	// If mode is for perfect Sum(factors)=Number
	if( (sum == number) && !(def-1) && def ) {
			if(ans) std::cout<<"="<<sum<<" = "<<number;
			// return '1' if conditions is done
			return true;
		}
	// return '0' if it is not deficient or perfect
	else return false;
}

// Main function starts here
int main()
{
	// Declaration of multiply const
	float def_const;
	// Declaration of searshing range
	int fist, last;
	// Initialization of iteration variable
	int j;
	// bool container, true - time error, false - everything fine
	bool time_failure = false;
	//
	clock_t t_pause;
	//
	clock_t t_start;

	// Getting const k from user
	std::cout<<"\nEnter deficient const: ";
	std::cin>>def_const;
	// Getting starting point of search from user
	std::cout<<"\nEnter first number in the range for search: ";
	std::cin>>fist;
	// Getting ending point of search from user
	std::cout<<"\nEnter last number in the range for search: ";
	std::cin>>last;
	if ( def_const && (def_const-1) )
		std::cout<<"\nDeficient numbers in the range ["<<fist
				<<", "<<last<<"]:\n";
	if ( !def_const )
		std::cout<<"\nPrime numbers in the range ["<<fist
				<<", "<<last<<"]:\n";
	if ( def_const && !(def_const-1) )
		std::cout<<"\nPerfect numbers in the range ["<<fist
				<<", "<<last<<"]:\n";
	//
	t_start = clock();
	// Iteration checking numbers in the range
	for (int next = fist; ((next <= last) && !time_failure); next++){
		//
		if ( chkNumber(next,def_const,0,0) ) chkNumber(next,def_const,++j,1);	
		//
		t_pause = clock() - t_start;
		//
		if ( t_pause*1.0/CLOCKS_PER_SEC > 1 ) time_failure = true;			
	}

	std::cout<<"\n\nTime spend on calculations: "<<t_pause*1.0/CLOCKS_PER_SEC
				<<" sec."<<"\n";

	return 0;
}