#include<iostream>
#include<fstream>
#include<string>
#include<vector>

unsigned long int pv(std::vector <int> v){
	
	int s{};
	unsigned long int w{};
	int r{};
	
	for (int i=0; i<v.size(); i++){
		if(v[i]>s)s=v[i];
	}
	
	w=s*1000;
	
	while(s>0){
		
		for (int i=0; i<v.size(); i++){
		r+=abs(v[i]-s);
		}
		
		if(r<w)w=r;
		
		s--;
		r=0;
	}
	
	return w;
}

int main() {

	std::ifstream myfile;
	myfile.open("day7_input.txt", std::ios_base::in);
	std::string temp,temp_num;
	int num;
	std::vector<int> v;

	if (myfile.good()) {
		
		while (getline(myfile, temp)) {
			for(int i=0; i<temp.length();i++){
				if(temp[i]>=48 && temp[i]<=57){
					temp_num+=temp[i];
				}
				else {
					if(temp_num.length()>0){
					num=std::stoi(temp_num);
					v.push_back(num);	
					temp_num.clear();
					}
				}
			}
			
			if(temp_num.length()>0){
				num=std::stoi(temp_num);
				v.push_back(num);	
				temp_num.clear();
			}
		}	

		std::cout<<"Answer: "<<pv(v);
	}
	else {
		std::cout << "File not opened, quitting";
		return 1;
	}
	
	myfile.close();
	return 0;
}