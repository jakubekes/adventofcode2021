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

	unsigned long int s{0};
	
	for (int i=1; i<v.size(); i++){
		if (v[i]>v[i-1]) s++;
			
	}
	
	//printf("%u\n",s);
	std::cout<<s;
}