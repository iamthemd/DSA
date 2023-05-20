#include<iostream>
#include "array.h"

array::array(){
}

/* For ex: given pair 
* Input:
* nums = [8, 7, 2, 5, 3, 1] 
* target = 10
* Pair found (8, 2) or
* Pair found (7, 3)
*/
void array::pair_with_given_sum() {
	std::cout << __FUNCTION__ << "\n";
	int num, sum;
	std::cout << "Enter length of array" << std::endl;
	std::cin >> num;

	std::cout << "Enter " << num << " number for array\n";
	
	// allocate dynamic memory
	int* dArray = new int(num);
	for(int i= 0; i < num; i++)
	{
		std::cin >> dArray[i];
	}

	std::cout << "Enter the sum num\n";
	std::cin >> sum;

	// print the array
	for (int i = 0; i < num; i++) {
		std::cout << dArray[i] << "\n";
	}

	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if ((dArray[i] + dArray[j]) == sum) {
				std::cout << "Found pair (" << dArray[i] << ", " << dArray[j] << ").\n";
			}
		}
	}
}
