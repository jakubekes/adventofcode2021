#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main(){

	std::fstream plik;
	plik.open("day2_input.txt", std::ios_base::in);

	int horizontal{0};
	int depth{0}, aim{0};
	std::vector<std::string> v{};
	std::string temp{};
	
	while(std::getline(plik, temp)) {
		v.push_back(temp);
	}

	char a;
	for (int i=0; i<v.size(); i++){
		if(v[i][0]=='f'){
		horizontal+=v[i][8]-48;
		depth+=aim*(v[i][8]-48);
		}else if(v[i][0]=='u'){
			aim-=v[i][3]-48;
		}else if (v[i][0]=='d'){
			aim+=v[i][5]-48;
		}
	}
	
	//printf("%u %u\n",horizontal,depth);
	std::cout<<horizontal*depth;
}