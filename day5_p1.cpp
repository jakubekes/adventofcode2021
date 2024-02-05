#include<iostream>
#include<fstream>
#include<string>
#include<vector>

int main() {

	std::ifstream myfile;
	myfile.open("day5_input.txt");
	std::string temp, temp_num;
	int num;
	std::vector<int> vtemp;
	std::vector<std::vector<int>> v;
	std::vector<std::vector<int>> arr( 1000 , std::vector<int> (1000, 0));

	if (myfile.good()) {
		std::cout << "File opened\n";
		
		while (getline(myfile, temp)) {
			
			for(int i=0; i<temp.length();i++){
				if(temp[i]>=48 && temp[i]<=57){
					temp_num+=temp[i];
				}else{
					if(temp_num.length()>0){
					num=std::stoi(temp_num);
					vtemp.push_back(num);	
					//std::cout<<"Pushuje:" <<num<<"\n";
					temp_num.clear();
					}
				}
			}
			
			if(temp_num.length()>0){
				num=std::stoi(temp_num);
				vtemp.push_back(num);	
				//std::cout<<"Pushuje:" <<num<<"\n";
				temp_num.clear();
			}
			v.push_back(vtemp);
			vtemp.clear();
		}

		int larger{},smaller{};
		unsigned long int check{};
		
		for(int i=0; i<v.size(); i++){
			if(v[i][0]!=v[i][2] && v[i][1]!=v[i][3])continue;
			
			if(v[i][0]==v[i][2]){
				int t=v[i][0];
				if(v[i][1]>v[i][3]){
					larger=v[i][1]; 
					smaller=v[i][3];
				}else{
					larger=v[i][3]; 
					smaller=v[i][1];
				}
				for (int j=smaller; j<=larger; j++){
					arr[j][t]++;
				}
			}else{
				int t=v[i][1];
				if(v[i][0]>v[i][2]){
					larger=v[i][0]; 
					smaller=v[i][2];
				}else{
					larger=v[i][2]; 
					smaller=v[i][0];
				}
				for (int j=smaller; j<=larger; j++){
					arr[t][j]++;
				}
			}
		}
	
		for (int i=0; i<1000; i++){				
			for (int j=0; j<1000; j++){
				if(arr[i][j]>1)check++;		
			}
		}
		
		std::cout<<"Answer:"<< check;
		myfile.close();
	}
	else {
		std::cout << "File not opened, quitting";
		return 1;
	}

	return 0;
}