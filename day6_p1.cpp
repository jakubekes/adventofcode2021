#include<iostream>
#include<fstream>
#include<string>
#include<vector>

int main() {

	std::ifstream myfile;
	myfile.open("day6_input.txt", std::ios_base::in);
	std::string temp;
	unsigned long long int born{};
	std::vector<int> v;
	char c;

	if (myfile.good()) {
		
		getline(myfile,temp);
		
		//std::cout<<"v maxsize: "<<v.max_size()<<"\n";
			
		for (int i=0; i<temp.length(); i++){
			
			if(temp[i]!=','){								
				v.push_back(temp[i]-48);
				//std::cout<<"Pushuje: "<<temp[i]-48<<"\n";
			}
			
		}
		//std::cout<<"v size: "<<v.size()<<"\n";			
		for (int i=0; i<80; i++){

			//for (int j=0; j<v.size(); j++){
			for (unsigned long long int j=0; j<v.size(); j++){
				//std::cout<<"Offset: "<<j<<"v[j] przed: "<<v[j];
				if(--v[j]==-1){
					v[j]=6;
					born++;
				}
				//std::cout<<", v[j] po: "<<v[j]<<"\n";				
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
			//std::cout<<"v size: "<<v.size()<<"\n";	
		}
	}
	else {
		std::cout << "File not opened, quitting";
		return 1;
	}
	
	std::cout<<v.size();

	myfile.close();
	//getchar();
	return 0;
}