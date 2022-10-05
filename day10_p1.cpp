#include<iostream>
#include<fstream>
#include<string>
#include<stack>

int main() {

	std::ifstream myfile;
	myfile.open("day10_input.txt", std::ios_base::in);
	std::string temp;
	unsigned long int answer{};
	
	if (myfile.good()) {
		std::cout << "File opened\n";
		
		std::stack <char> mystack;
		while (getline(myfile, temp)) {
			//std::cout<<temp<<"\n";

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
					if(temp[i]==')')answer+=3;
					if(temp[i]==']')answer+=57;
					if(temp[i]=='}')answer+=1197;
					if(temp[i]=='>')answer+=25137;	
					break;
				}				
			}								
		}
			
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