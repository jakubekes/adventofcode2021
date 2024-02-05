#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main(){

	std::ifstream plik;
	plik.open("day2_input.txt");

	int horizontal{0};
	int depth{0};
	std::vector<std::string> v{};
	std::string temp{};
	
	while(std::getline(plik, temp)) {
		v.push_back(temp);
	}
	
	for (int i=0; i<v.size(); i++){
		if(v[i][0]=='f'){
		horizontal+=v[i][8]-'0';
		//std::cout<<"F: "<<horizontal<<"\n";
		}else if(v[i][0]=='u'){
			depth-=v[i][3]-'0';
		}else{
		if(v[i][0]=='d')depth+=v[i][5]-'0';
		}
	}
	
	std::cout<<horizontal*depth;
}