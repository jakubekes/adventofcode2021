#include<iostream>
#include<fstream>
#include<string>
#include<vector>

int main() {

	std::ifstream myfile;
	myfile.open("day6_input.txt");
	std::string temp;
	unsigned long long int born{};
	std::vector<unsigned long long int> v {0,0,0,0,0,0,0,0,0};
	char c;

	if (myfile.good()) {
		getline(myfile,temp);
		
		for (int i=0; i<temp.length(); i++){
			
			if(temp[i]!=','){								
				v[temp[i]-48]++;
			}
		}
		unsigned long long int m;
		for (int i=0; i<256; i++){
			m=v[0];
			std::rotate(v.begin(), v.begin() + 1, v.end());
			v[6]+=m;
		}
		
		m=0;
		for (int i=0; i<v.size(); i++){
			m+=v[i];
		}
		
		std::cout<<"Answer: "<<m;			
	}
	else {
		std::cout << "File not opened, quitting";
		return 1;
	}
	
	myfile.close();
	return 0;
}