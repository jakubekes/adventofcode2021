#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>

int main(){

	std::fstream plik;
	plik.open("day3_input.txt", std::ios_base::in);

	int num_length=12;
	std::vector<unsigned long int> v{0,0,0,0,0,0,0,0,0,0,0,0};
	std::string temp{};
	unsigned long int s{};
	
	while(std::getline(plik, temp)) {
		s++;		
		for(int i=0; i<num_length; i++){
			if(temp[i]=='1')v[i]++;
		}		
	}
	
	std::bitset<12> gamma{},epsilon{};
	for(int i=0; i<num_length; i++){		
		if(v[i]>=s/2){
			gamma[11-i]=1;
		} else {
			epsilon[11-i]=1;
		}
	}
	
	std::cout<<gamma.to_ulong()*epsilon.to_ulong();
	

}