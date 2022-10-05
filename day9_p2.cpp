#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm> //sort vector

int main() {

	std::ifstream  plik;
	plik.open("day9_input.txt", std::ios::in);
	std::string temp;
	std::vector<std::vector<int>> table, v, v_temp;
	std::vector<int> table_temp, basins;
	unsigned long int answer{};
	
	if (plik.is_open()) {
		while(getline(plik,temp)){
			for (int i=0; i<temp.length(); i++){
				table_temp.push_back(temp[i]-48);
			}
			table.push_back(table_temp);
			table_temp.clear();
		
		}
		
		/*for (int i=0; i<table.size(); i++){
			for (int j=0; j<table[0].size(); j++){
				std::cout<<table[i][j];
			}
			std::cout<<"\n";
		}
		std::cout<<table.size()<<" "<<table[0].size()<<"\n";*/
		
		int c{};
		int added{};
		for (int i=0; i<table.size(); i++){
			for (int j=0; j<table[0].size(); j++){	
				if(table[i][j]!=9 && table[i][j]>0){
					table_temp.push_back(i);
					table_temp.push_back(j);
					v.push_back(table_temp);
					table_temp.clear();
					table[i][j]-=9;
					added+=1;
					while(v.size()>0){						
						for(int a=0; a<v.size(); a++){
							for (int k=v[a][0]-1; k<v[a][0]+2; k++){
							for (int l=v[a][1]-1; l<v[a][1]+2; l++){
								if(k<0 || l<0 || k>=table.size() || l>=table[0].size()){
								continue;
								}
								if((k==v[a][0] && l==v[a][1]) || (k!=v[a][0] && l!=v[a][1]))continue; 
								if(table[k][l]!=9 && table[k][l]>=0){
									table_temp.push_back(k);
									table_temp.push_back(l);
									v_temp.push_back(table_temp);
									table_temp.clear();
									table[k][l]-=9;
									added+=1;
								}							
							}
							}							
							
						}	
						for (int z=0; z<v_temp.size(); z++){
							std::cout<<"z: "<<v_temp[z][0]<<"z1: "<<v_temp[z][1]<<"\n";
						}
						
						v=v_temp;
						v_temp.clear();						
					}
					std::cout<<"----------\n";
					basins.push_back(added);
					added=0;									
				}			
			}
		}
		
		for (int i=0; i<basins.size(); i++){
			std::cout<<basins[i]<<" ";
		}
		std::cout<<"\n";
		std::sort(basins.begin(), basins.end(), std::greater<int>());					
		std::cout<<"Answer: "<<basins[0]*basins[1]*basins[2];
	}
	else {
		
		std::cout << "Nie otwarto pliku";
		
	}

	plik.close();


}