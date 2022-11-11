#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

	

struct cave{

	std::string name;
	std::vector<cave>connections;
	bool is_small;
	bool is_visited;
	
};

int find_index(std::vector<std::vector<std::string>> &v, std::string s){
	
	for (int i{}; i<v.size(); i++){
		if(v[i][0]==s){
			return i;
			break;
		}
	}
	return 0;
}

/*int block_path(std::vector<std::vector<std::string>> &v, int index, std::string s){
	
	for (size_t i{1}; i<v[index].size(); i++){
		if(v[index][i]==s){
			v[index][i]+=
			break;
		}
	}
	return 0;
}*/

int traverse(std::vector<std::vector<std::string>> &v, int start_index){

	std::stack<std::string> mystack{};
	
	for (size_t i{(v[start_index]).size()-1}; i>0; i--){
		mystack.push(v[start_index][i]+"0");
	}
	
	std::vector<std::string> current_path;
	current_path.push_back("start");
	unsigned int level{};
	
	int index_in_v{};
	/*while(!mystack.empty()){
		
		
		index_in_v = find_index(v, current_path.back().substr(0,current_path.back().length()-2));
		current_path.push_back(mystack.top());
		block_path(v, index_in_v, mystack.top());
		
		mystack.pop();
		level++;

		index_in_v = find_index(v, current_path.back().substr(0,current_path.back().length()-2));
		
		for (size_t i{(v[index_in_v]).size()-1}; i>=0; i--){
			mystack.push(v[index_in_v][i]+std::to_string(level));
		}
		
		
		
	}*/
	
	return 0;
}

int main() {

	std::ifstream myfile;
	myfile.open("day12_input.txt", std::ios_base::in);
	std::string temp;
	std::string ch{};
	std::vector<std::string> v_temp;

		
	if (myfile.good()) {
		std::cout << "File opened\n";
		
		while (getline(myfile, temp)) {
			//std::cout<<temp<<"\n";

			for(int i=0; i<temp.length();i++){
				if(temp[i]!='-'){
					ch+=temp[i];
				}else{
					v_temp.push_back(ch);
					ch="";
					continue;
				}			
			}				
			v_temp.push_back(ch);
			ch="";
		}
		
		std::sort(v_temp.begin(), v_temp.end());	
				
		for(int i=0; i<v_temp.size();i++){
			std::cout<<v_temp[i]<<"\n";
		}
			
		for(int i=0; i<v_temp.size()-1;i++){
			if(v_temp[i]==v_temp[i+1]){
				v_temp.erase (v_temp.begin() + i);
				i--;
			}
			
		}
		
		std::cout<<"After dup remove:\n";
		
		std::vector<std::vector<std::string>> vec_2d;
		std::vector<std::string> v_temp2;
		for(int i=0; i<v_temp.size();i++){
			std::cout<<v_temp[i]<<"\n";
			if(v_temp[i]=="end")continue;
			v_temp2.push_back(v_temp[i]);
			vec_2d.push_back(v_temp2);
			v_temp2.clear();			
		}
			

		

		std::vector<std::string> vec_2d_temp, vec_2d_erase;
		
		for (int i=0; i<vec_2d.size(); i++){
		myfile.clear();
		myfile.seekg(0);
			while (getline(myfile, temp)) {
				//std::cout<<temp<<"\n";

				for(int i=0; i<temp.length();i++){
					if(temp[i]!='-'){
						ch+=temp[i];
					}else{
						vec_2d_temp.push_back(ch);
						ch="";
						continue;
					}			
				}				
				vec_2d_temp.push_back(ch);
				ch="";
				
				
				
				if(vec_2d[i][0]==vec_2d_temp[0]){
					if(vec_2d_temp[1]=="start"){
						vec_2d_temp.clear();
						continue;
					}
					vec_2d[i].push_back(vec_2d_temp[1]);
					//vec_2d[i].push_back(vec_2d_temp[1]);
				} else if(vec_2d[i][0]==vec_2d_temp[1]){
					if(vec_2d_temp[0]=="start"){
						vec_2d_temp.clear();
						continue;	
					}
					vec_2d[i].push_back(vec_2d_temp[0]);
					//vec_2d[i].push_back(vec_2d_temp[0]);
				}
				
				vec_2d_temp.clear();
			}
			
			//clearing:
			//2. if cave has only 1x connection and it's small cave (that connection), then it's useless (delete it).
			if(vec_2d[i].size()==2 && (vec_2d[i][1])[0]>=97 && (vec_2d[i][1])[0]<=122){
				vec_2d_erase.push_back(vec_2d[i][0]);
				vec_2d.erase (vec_2d.begin() + i);
				i--;

			}
		}
	
		for(int i=0; i<vec_2d_erase.size();i++){
			std::cout<<vec_2d_erase[i]<<" ";
		}
		std::cout<<"\n\n";
		//clearing deleted above
		for(int i=0; i<vec_2d.size();i++){
			for(int j=0; j<vec_2d[i].size();j++){
				for(int k=0; k<vec_2d_erase.size();k++){
					if(vec_2d[i][j]==vec_2d_erase[k]){
						vec_2d[i].erase (vec_2d[i].begin() + j);
						j--;
						break;
					}
				}
				
			}			
		}
		
		std::cout<<"\nVec 2D:\n";
		for(int i=0; i<vec_2d.size();i++){
			for(int j=0; j<vec_2d[i].size();j++){
				std::cout<<vec_2d[i][j]<<" ";
			}
			std::cout<<"\n";
		}
		
		std::vector<std::vector<std::string>> vec_2d_operation = vec_2d;
		
		std::cout<<"\nVec 2D operation:\n";
		for(int i=0; i<vec_2d_operation.size();i++){
			for(int j=0; j<vec_2d_operation[i].size();j++){
				std::cout<<vec_2d_operation[i][j]<<" ";
			}
			std::cout<<"\n";
		}
		
		int start_index = find_index(vec_2d_operation, "start");
		std::cout<<"Start index:"<<start_index<<"\n";
		traverse (vec_2d_operation,start_index);
				
		myfile.close();
	}
	else {
		std::cout << "File not opened, quitting";
		return 1;
	}

	//getchar();
	return 0;
}