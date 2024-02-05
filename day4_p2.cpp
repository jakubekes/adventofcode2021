#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

int main() {

	std::ifstream  plik;
	plik.open("day4_input.txt");

	std::vector <int> bingo_numbers{83,5,71,61,88,55,95,6,0,97,20,16,27,7,79,25,81,29,22,52,43,21,53,59,99,18,35,96,51,93,14,77,15,3,57,28,58,17,50,32,74,63,76,84,65,9,62,67,48,12,8,68,31,19,36,85,98,30,91,89,66,80,75,47,4,23,60,70,87,90,13,38,56,34,46,24,41,92,37,49,73,10,94,26,42,40,33,54,86,82,72,39,2,45,78,11,1,44,69,64};
	std::vector <std::vector <std::vector<int>>> v;
	std::vector <std::vector<int>> v2d;
	std::vector <int> v1d;
	std::string temp, s;
	int i{}, j{};
s
		while (std::getline(plik, temp)) {
			if (temp == "")continue;
			std::stringstream ss(temp);
			while (std::getline(ss, s, ' ')) {			
					v1d.push_back(std::stoi(s));				
			}
			v2d.push_back(v1d);
			j++;
			v1d.clear();

			if (j == 5) {
				j = 0;
				v.push_back(v2d);
				v2d.clear();
			}
		}	
	}

	plik.close();

	int memnum{ -1 };
	bool bbd{false};
	
		for (int z = 0; z < bingo_numbers.size(); z++) {

			for (int i = 0; i < v.size(); i++) {
				for (int j = 0; j < v[0].size(); j++) {
					for (int k = 0; k < v[0][0].size(); k++) {
						if (v[i][j][k] == bingo_numbers[z]) {
							v[i][j][k] = -1;
							if (v[i][j][0] + v[i][j][1] + v[i][j][2] + v[i][j][3] + v[i][j][4] == -5 || v[i][0][k] + v[i][1][k] + v[i][2][k] + v[i][3][k] + v[i][4][k] == -5) {
								if (v.size() > 1) {
									v.erase(v.begin() + i);
									bbd = true;
									break;
								}
								else {
									memnum = bingo_numbers[z];
									break;
								}
							}
						}
					}
					if (memnum > -1) break;

					if (bbd == true) {
						bbd = false;
						i--;
						break;
					}
				}
				if (memnum > -1) break;			
			}
			if (memnum > -1) break;
		}

	int sum{};
	
	for (int j = 0; j < v[0].size(); j++) {
		for (int k = 0; k < v[0][0].size(); k++) {
			if (v[0][j][k] == -1)continue;
			sum += v[0][j][k];
		}
	}

	std::cout << sum*memnum;
}