#include <iostream>
#include <vector>

int main(){

std::vector<unsigned int> v ={
196
};
	
	unsigned long int s{0};
	
	for (int i=1; i<v.size(); i++){
		if (v[i]>v[i-1]) s++;
			
	}
	
	//printf("%u\n",s);
	std::cout<<s;
}