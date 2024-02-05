#include<iostream>
#include<fstream>
#include<string>
#include<vector>

int main() {

	std::ifstream myfile;
	myfile.open("day11_input.txt");
	std::string temp;
	unsigned long int answer{};
	std::vector <std::vector<int>> v;
	std::vector <int> tempv;
	
	if (myfile.good()) {
		std::cout << "File opened\n";
		
		while (getline(myfile, temp)) {
			for(int i=0; i<temp.length();i++){
				tempv.push_back(temp[i]-48);				
			}								
			v.push_back(tempv);
			tempv.clear();
		}
		
		for (int i=0; i<v.size(); i++){
			for(int j=0; j<v[0].size(); j++){
				std::cout<<v[i][j];
			}
				std::cout<<"\n";
		}
			
		int stepper = 100;	
			
		while(stepper>0){
		
			for(int i=0; i<v.size(); i++){
				for(int j=0; j<v[0].size(); j++){
					v[i][j]++;
					if(v[i][j]==0)v[i][j]++;
				}
			}
			int stepflashes{1};
			while(stepflashes>0){
				stepflashes=0;
				for(int i=0; i<v.size(); i++){
				for(int j=0; j<v[0].size(); j++){
					if (v[i][j]==-1)continue;
					if (v[i][j]>9){
						v[i][j]=-1;
						stepflashes++;
						for(int k=i-1; k<i+2; k++){
						for(int l=j-1; l<j+2; l++){
							if ( k<0 || l<0 || k>v.size()-1 || l>v[0].size()-1 || (k==i && l==j) || v[k][l]==-1)continue;
							v[k][l]++;
						}
						}
					}
				}				
				}
				answer+=stepflashes;
				
			}
			std::cout<<"Answer:"<< answer<<" stepper: "<<stepper<<"\n";
			stepper--;
		}			
		std::cout<<"Answer:"<< answer;
		myfile.close();
	}
	else {
		std::cout << "File not opened, quitting";
		return 1;
	}

	return 0;
}