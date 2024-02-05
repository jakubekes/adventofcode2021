#include<iostream>
#include<fstream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

int main() {

	std::ifstream myfile;
	myfile.open("day10_input.txt");
	std::string temp;
	unsigned long int answer{};
	std::vector<unsigned long long int> v{};

	if (myfile.good()) {
		
		std::cout << "File opened\n";
		while (getline(myfile, temp)) {
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
			
			if(b==true) continue;
			
			while(!mystack.empty()){														
				if(mystack.top()=='(')mystr+=')';
				if(mystack.top()=='[')mystr+=']';		
				if(mystack.top()=='{')mystr+='}';
				if(mystack.top()=='<')mystr+='>';
				mystack.pop();				
			}
			
			unsigned long long int points{};
			
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
		answer=v[v.size()/2];
		std::cout<<"Answer:"<< answer;
		myfile.close();
	}
	else {
		std::cout << "File not opened, quitting";
		return 1;
	}

	return 0;
}