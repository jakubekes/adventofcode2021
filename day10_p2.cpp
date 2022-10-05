#include<iostream>
#include<fstream>
#include<string>
#include<stack>
#include<vector>
#include <algorithm>

int main() {

	std::ifstream myfile;
	myfile.open("day10_input.txt", std::ios_base::in);
	std::string temp;
	unsigned long int answer{};
	std::vector<unsigned long long int> v{};

	if (myfile.good()) {
		std::cout << "File opened\n";
		
		while (getline(myfile, temp)) {
			//std::cout<<temp<<"\n";
			std::stack <char> mystack{};
			bool b{};
			std::string mystr{};
			
			for(int i=0; i<temp.length();i++){
				if(temp[i]=='(' || temp[i]=='[' || temp[i]=='{' || temp[i]=='<'){
					mystack.push(temp[i]);
				}else if(temp[i]==')' && mystack.top()=='('){
					mystack.pop();
				}else if(temp[i]==']' && mystack.top()=='['){
					mystack.pop();
				}else if(temp[i]=='}' && mystack.top()=='{'){
					mystack.pop();
				}else if(temp[i]=='>' && mystack.top()=='<'){
					mystack.pop();
				} else {
						b=true;
						break;									
				}			
			}
			if(b==true){
				continue;
			}
			while(!mystack.empty()){														
				if(mystack.top()=='(')mystr+=')';
				if(mystack.top()=='[')mystr+=']';		
				if(mystack.top()=='{')mystr+='}';
				if(mystack.top()=='<')mystr+='>';
				mystack.pop();				
			}
			
			unsigned long long int points{};
			std::cout<<"mystr"<<mystr<<"\n";
			for(int i=0; i<mystr.length();i++){
				points*=5;
				if(mystr[i]==')')points+=1;
				if(mystr[i]==']')points+=2;				
				if(mystr[i]=='}')points+=3;
				if(mystr[i]=='>')points+=4;				
			}
			v.push_back(points);
			
		}
	
		std::sort(v.begin(), v.end());
		for(int i=0; i<v.size();i++){
			std::cout<<i<<": "<<v[i]<<"\n";
		}
		
		answer=v[v.size()/2];
		
		std::cout<<"Answer:"<< answer;
		myfile.close();
	}
	else {
		std::cout << "File not opened, quitting";
		return 1;
	}

	//getchar();
	return 0;
}