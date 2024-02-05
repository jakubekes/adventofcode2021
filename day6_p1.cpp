#include<iostream>
#include<fstream>
#include<string>
#include<vector>

int main() {

	std::ifstream myfile;
	myfile.open("day6_input.txt");
	std::string temp;
	unsigned long long int born{};
	std::vector<int> v;
	char c;

	if (myfile.good()) {
		
		getline(myfile,temp);
			
		for (int i=0; i<temp.length(); i++){
			if(temp[i]!=','){								
				v.push_back(temp[i]-48);
			}
		}
		
		for (int i=0; i<80; i++){
			for (unsigned long long int j=0; j<v.size(); j++){
				if(--v[j]==-1){
					v[j]=6;
					born++;
				}		
			}

			while(born>0){
				try{
					v.push_back(8);
				}
				catch (const std::exception& e) { 
					std::cout<<e.what()<<"\n";
				}
				born--;
			}	
		}
	}
	else {
		std::cout << "File not opened, quitting";
		return 1;
	}
	
	std::cout<<v.size();
	myfile.close();
	return 0;
}