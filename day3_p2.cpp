#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>

int main(){

	std::ifstream plik;
	plik.open("day3_input.txt");

	const int num_length=12;
	
	std::vector<std::bitset<num_length>> oxygen{},scrubber{};
	std::string temp{};
	
	while(std::getline(plik, temp)) {	
		std::bitset<num_length> b{temp};	
		oxygen.push_back(b);
		scrubber.push_back(b);			
	}
		
	int b{11},s{};
	bool comp{};
	
	while(oxygen.size()>1){
		
		comp=0;
		s=0;		
		for (int i=0; i<oxygen.size(); i++){
			if(oxygen[i][b]==1)s++;
		}
		
		if(s>=oxygen.size()/2+oxygen.size()%2)comp=1;
		
		for (int i=0; i<oxygen.size(); i++){
			if(oxygen[i][b]!=comp){
				oxygen.erase(oxygen.begin()+i);
				i--;
				if(oxygen.size()==1)break;
			}
		}
		b--;
	}
	
	b=11;
	
	while(scrubber.size()>1){
		comp=1;
		s=0;
		
		for (int i=0; i<scrubber.size(); i++){
			if(scrubber[i][b]==1)s++;
		}
		
		if(s>=scrubber.size()/2+scrubber.size()%2)comp=0;
		
		for (int i=0; i<scrubber.size(); i++){
			if(scrubber[i][b]!=comp){
				scrubber.erase(scrubber.begin()+i);
				i--;
				if(scrubber.size()==1)break;
			}
		}
		b--;
	}

	std::cout<<oxygen[0].to_ulong()*scrubber[0].to_ulong();	
}