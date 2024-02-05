#include<iostream>
#include<fstream>
#include<string>
#include<vector>


int main() {

	std::ifstream myfile;
	myfile.open("day8_input.txt");
	std::string temp{},temp_input{};
	std::vector<std::string> v;
	unsigned int sum{};
	
	if (myfile.good()) {
		
		while (getline(myfile, temp)) {		
			for(int i=0; i<temp.length();i++){
				if(temp[i]!='|'){
					continue;
				}else{					
					for(int j=i+2; j<temp.length();j++){
						if(temp[j]!=' '){
							temp_input+=temp[j];
						}else{
							if(temp_input.length()==2 || temp_input.length()==4 || temp_input.length()==3 || temp_input.length()==7)sum++;
							temp_input.clear();						
						}
					}
					if(temp_input.length()==2 || temp_input.length()==4 || temp_input.length()==3 || temp_input.length()==7)sum++;
					temp_input.clear();
				}		
			}			
		}	

		std::cout<<"Answer: "<<sum<<"\n";
	}
	else {
		std::cout << "File not opened, quitting";
		return 1;
	}
	
	myfile.close();
	return 0;
}