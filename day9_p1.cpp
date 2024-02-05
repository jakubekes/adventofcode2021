#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main() {

	std::ifstream  plik;
	plik.open("day9_input.txt");
	std::string temp;
	std::vector<std::vector<int>> table;
	std::vector<int> table_temp, v;
	unsigned long int answer{};
	
	if (plik.is_open()) {
		while(getline(plik,temp)){
			for (int i=0; i<temp.length(); i++){
				table_temp.push_back(temp[i]-48);
			}
			table.push_back(table_temp);
			table_temp.clear();
		}
		
		for (int i=0; i<table.size(); i++){
			for (int j=0; j<table[0].size(); j++){
				std::cout<<table[i][j];
			}
			std::cout<<"\n";
		}
		std::cout<<table.size()<<" "<<table[0].size()<<"\n";
		
		int c{};
		for (int i=0; i<table.size(); i++){
			for (int j=0; j<table[0].size(); j++){			
				for (int k=i-1; k<i+2; k++){
					for (int l=j-1; l<j+2; l++){
						if(k<0 || l<0 || k>=table.size() || l>=table[0].size()){
							c++;
							continue;
						}
						if(k==i && l==j)continue; 
						if(table[k][l]>table[i][j])c++;
					}
				}
				std::cout<<"Number: "<<i<<" "<<j<<" = "<<c<<"\n";
				if(c==8){
					std::cout<<"8\n";
					answer+=table[i][j]+1;
				}
				c=0;
			}
		}
		
		std::cout<<"Answer: "<<answer;
	}
	else {
		
		std::cout << "File not opened, quitting";
	}

	plik.close();
}