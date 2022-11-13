#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<chrono>

struct cave{

	cave(std::string name, bool is_small, bool is_used)
	:name{name}, is_small{is_small}, is_used{is_used}  {}
	
	std::string name{};
	std::vector<cave*>connections{};
	bool is_small{};
	unsigned int is_used{};
	std::stack<cave*> cave_stack{};
	std::stack<int> cave_stack_level{};

};


cave* find_cave(std::vector<cave*> &v, std::string s){
	
	for (int i{}; i<v.size(); i++){
		if (v[i]->name==s) return v[i];
	}
	
	return v[0];
}

int find_index(std::vector<cave*> &v, std::string s){
	
	for (int i{}; i<v.size(); i++){
		if(v[i]->name==s){
			return i;
			break;
		}
	}
	return 0;
}

unsigned long int traverse(std::vector<cave*> &v, int start_index){
	
	std::stack<cave*> main_stack;
	main_stack.push(v[start_index]);
	unsigned long int answer{};
	int test{};
	bool was_pop{};
	while(!main_stack.empty()){
				
		int added{};
		if (was_pop==false && main_stack.top()->connections.size()>0){// && main_stack.top()->cave_stack.empty()){
			for(size_t i{}; i<main_stack.top()->connections.size(); i++){
				if(main_stack.top()->connections[i]->is_used>0 && main_stack.top()->connections[i]->is_small==true)continue;
				main_stack.top()->cave_stack.push(main_stack.top()->connections[i]);
				main_stack.top()->cave_stack_level.push(main_stack.top()->is_used);
				added++;
			}
			//main_stack.top()->is_used++;
			if(added){
			cave* cave_ptr= main_stack.top()->cave_stack.top();
			main_stack.top()->cave_stack.pop();
			main_stack.top()->cave_stack_level.pop();
			main_stack.push(cave_ptr);
			main_stack.top()->is_used++;
			was_pop=false;		
			//std::cout<<"is_used1\n";
			}else {
				main_stack.top()->is_used--;
				main_stack.pop();
				was_pop=true;
			}
			added=0;
			
		} else if(!main_stack.top()->cave_stack.empty()){
			if(main_stack.top()->cave_stack_level.top()==main_stack.top()->is_used){
			cave* cave_ptr= main_stack.top();
			main_stack.push(main_stack.top()->cave_stack.top());	
			was_pop=false;
			//cave_ptr->is_used++;
			cave_ptr->cave_stack.pop();
			cave_ptr->cave_stack_level.pop();
			main_stack.top()->is_used++;
			//std::cout<<"is_used2\n";
			}else{
				main_stack.top()->is_used--;
				main_stack.pop();
			}
		} else if(main_stack.top()->cave_stack.empty()){
			if(main_stack.top()->name=="end"){	
				answer++;
				
				std::stack <cave*> temp_stack;
				while(!main_stack.empty()){
					temp_stack.push(main_stack.top());
					main_stack.pop();
				}
				//std::cout<<"\n***PATH: ";
				while(!temp_stack.empty()){
					main_stack.push(temp_stack.top());
					//std::cout<<main_stack.top()->name<<" ";
					temp_stack.pop();
				}
				//std::cout<<"\n\n";
				
			}
			main_stack.top()->is_used--;	
			main_stack.pop();
			was_pop=true;			
		}
		
		/*if(!main_stack.empty()){
		std::cout<<main_stack.top()->name<<" |is_used: "<<main_stack.top()->is_used<<" |is_small: "<<main_stack.top()->is_small;
		if(main_stack.top()->name=="A"){
			
			std::stack <cave*> temp_stack;
				while(!main_stack.top()->cave_stack.empty()){
					temp_stack.push(main_stack.top()->cave_stack.top());
					main_stack.top()->cave_stack.pop();
				}
				while(!temp_stack.empty()){
					main_stack.top()->cave_stack.push(temp_stack.top());
					std::cout<<" "<<main_stack.top()->cave_stack.top()->name<<" ";
					temp_stack.pop();
				}
			
		}
		std::cout<<"\n";
		}*/
		/*if(main_stack.top()->name=="b")test++;
		if(test==2){
			std::cout<<main_stack.top()->name<<"\n";	
			std::cout<<main_stack.top()->is_used<<"\n";	
			std::cout<<main_stack.top()->is_small<<"\n";	
			std::cout<<"Cave_stack:\n";	
			while(!main_stack.top()->cave_stack.empty()){
				
				std::cout<<main_stack.top()->cave_stack.top()->name<<"\n";
				main_stack.top()->cave_stack.pop();
			}
			break;
		}*/
		//std::cout<<v[4]->is_used<<"\n";
	}
	//std::cout<<answer;
	return answer;
}

int main() {

	auto start = std::chrono::high_resolution_clock::now();
	
	std::ifstream myfile;
	myfile.open("day12_input.txt", std::ios_base::in);
	std::string temp;
	std::string ch{};
	std::vector<std::string> v_temp;

		
	if (myfile.good()) {
		//std::cout << "File opened\n";
		
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
				
		/*for(int i=0; i<v_temp.size();i++){
			std::cout<<v_temp[i]<<"\n";
		}*/
			
		for(int i=0; i<v_temp.size()-1;i++){
			if(v_temp[i]==v_temp[i+1]){
				v_temp.erase (v_temp.begin() + i);
				i--;
			}
			
		}
		
		//std::cout<<"After dup remove:\n";
		
		std::vector<cave*> vec_2d;
		for(int i=0; i<v_temp.size();i++){
			//if(v_temp[i]=="end")continue;

			vec_2d.push_back(new cave(v_temp[i],islower(v_temp[i][0]),0));	
			
		}
		/*for(int i=0; i<vec_2d.size();i++){
		std::cout<<"name "<<vec_2d[i]->name<<"\n";
		}*/

		std::vector<std::string> vec_2d_temp, vec_2d_erase;
		
		//putting all connections
		for (size_t i=0; i<vec_2d.size(); i++){
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
				if(vec_2d[i]->name=="end")continue;
				if(vec_2d[i]->name==vec_2d_temp[0]){
					if(vec_2d_temp[1]=="start"){
						vec_2d_temp.clear();
						continue;
					}
					vec_2d[i]->connections.push_back(find_cave(vec_2d,vec_2d_temp[1]));
				
				} else if(vec_2d[i]->name==vec_2d_temp[1]){
					if(vec_2d_temp[0]=="start"){
						vec_2d_temp.clear();
						continue;	
					}
					vec_2d[i]->connections.push_back(find_cave(vec_2d,vec_2d_temp[0]));
				
				}
				
				vec_2d_temp.clear();
			}
		
		}
		
		//clear not needed connections (if count is 1x and with small only)
		/*for (size_t i=0; i<vec_2d.size(); i++){
			if(vec_2d[i]->connections.size()==1 && vec_2d[i]->connections[0]->is_small==1){
				vec_2d[i]->connections.clear();
			}
		}*/
		
				
		/*for (size_t i=0; i<vec_2d.size(); i++){
			std::cout<<"\nVEC2D: "<<vec_2d[i]->name<<" "<<vec_2d[i]->is_small<<" "<<" "<<vec_2d[i]->is_used<<"\n";
			for (size_t j=0; j<vec_2d[i]->connections.size(); j++){
				std::cout<<"con: "<<j<<" : "<<vec_2d[i]->connections[j]->name<<"\n";
				
			}

		}*/
		
		//std::cout<<find_index(vec_2d,"start")<<"\nTRAVERSE:\n";
		//std::cout<<"Answer: "<<traverse(vec_2d, find_index(vec_2d,"start"))<<"\n";
		printf("Answer: %d\n",traverse(vec_2d, find_index(vec_2d,"start")));
		myfile.close();
		
		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
        printf("Elapsed time: %f\n",elapsed.count());
	}
	else {
		std::cout << "File not opened, quitting";
		return 1;
	}

	//getchar();
	return 0;
}