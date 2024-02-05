#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<limits>

unsigned long int pv(std::vector <int> v){
	
	long int s{};
	unsigned long int fuel_total{};
	unsigned long int fuel_point{};
	unsigned long int temp{};
	unsigned long int t;
	
	for (int i=0; i<v.size(); i++){
		if(v[i]>s)s=v[i];
	}
	
	fuel_total=std::numeric_limits<unsigned long int>::max();
	
	while(s>0){
		for (unsigned long int i=0; i<v.size(); i++){
			temp=abs(v[i]-s);
			for (unsigned long int j=1; j<=temp; j++){
				t+=j;
			}
			fuel_point+=t;
			t=0;
		}
		
		if (fuel_point<fuel_total) fuel_total=fuel_point;
		
		s--;
		fuel_point=0;
	}

	return fuel_total;
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
				}else{
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

		std::cout<<"Answer: "<<pv(v)<<"\n";
	}
	else {
		std::cout << "File not opened, quitting";
		return 1;
	}
	
	myfile.close();
	return 0;
}