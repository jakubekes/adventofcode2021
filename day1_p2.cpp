#include <iostream>
#include <vector>
#include <fstream>

int main(){

	std::ifstream plik;
	plik.open("day1_input.txt");	
	std::vector <int> v;
	int x;
	
	while (plik >> x)
	{
		v.push_back(x);
	}
	
	unsigned long int s1{0},s2{0},s{0};
	
	for (int i=0; i<v.size()-3; i++){
		s1=v[i]+v[i+1]+v[i+2];
		s2=v[i+1]+v[i+2]+v[i+3];
		if (s2>s1) s++;
	}
	
	//printf("%u\n",s);
	std::cout<<s;
}