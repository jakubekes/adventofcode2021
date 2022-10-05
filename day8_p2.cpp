#include<iostream>
#include<fstream>
#include<string>
#include<vector>


int main() {

	std::ifstream myfile;
	myfile.open(".\\day8_input.txt", std::ios_base::in);
	std::string temp{}, temp_input{};
	std::vector<std::string> v, v_output, v_temp;
	std::vector<std::vector<std::string>> v_5x, v_6x;
	unsigned int sum{};
	int input_indexes[10];

	if (myfile.good()) {

		while (getline(myfile, temp)) {
			//std::cout<<temp<<"\n";

			for (int i = 0; i < temp.length(); i++) {

				if (temp[i] != ' ' && temp[i] != '|') {
					temp_input += temp[i];
				}
				else {
					if(temp_input.length()>0)v.push_back(temp_input);
					temp_input.clear();
				}
			}

			if (temp_input.length() > 0) {
				v.push_back(temp_input);
				temp_input.clear();
			}
//cout
				//for (int j = 0; j < 14; j++) {
				//	std::cout << "v " << j << ":" << v[j] << "\n";
				//}
				//determining what is what
				if (v.size() == 14) {//==10

					//finding 2x(1), 4x(4), 3x(7), 7x(8) and putting 5x, 6x with indexes
					for (int j = 0; j < v.size(); j++) {
						if (v[j].length() == 2) {
							input_indexes[1] = j;
						}
						else if (v[j].length() == 4) {
							input_indexes[4] = j;
						}
						else if (v[j].length() == 3) {
							input_indexes[7] = j;
						}
						else if (v[j].length() == 7) {
							input_indexes[8] = j;
						}
						else if (v[j].length() == 5) {
							v_temp.push_back(v[j]);
							v_temp.push_back(std::to_string(j));
							v_5x.push_back(v_temp);
							v_temp.clear();
						}
						else if (v[j].length() == 6) {
							v_temp.push_back(v[j]);
							v_temp.push_back(std::to_string(j));
							v_6x.push_back(v_temp);
							v_temp.clear();
						}
					}

					//finding 5x == 2 or 3 or 5
					//if 5x-2x(1) == 3x -> 3
					for (int j = 0; j < v_5x.size(); j++) {
						bool check1{}, check2{};

						for (int k = 0; k < v_5x[j][0].size(); k++) {
							if ((v_5x[j][0])[k] == v[input_indexes[1]][0])check1 = true;
							if ((v_5x[j][0])[k] == v[input_indexes[1]][1])check2 = true;
							if (check1 == true && check2 == true)break;
						}
						if (check1 == true && check2 == true) {
							input_indexes[3] = std::stoi(v_5x[j][1]);
							v_5x.erase(v_5x.begin() + j);
							break;
						}

					}

					//finding 5x == 2 or 5
					//if 5x-2x(1) == 3x -> 3
					for (int j = 0; j < v_5x.size(); j++) {
						bool check1{}, check2{}, check3{}, check4{};

						for (int k = 0; k < v_5x[j][0].size(); k++) {
							if ((v_5x[j][0])[k] == v[input_indexes[4]][0])check1 = true;
							if ((v_5x[j][0])[k] == v[input_indexes[4]][1])check2 = true;
							if ((v_5x[j][0])[k] == v[input_indexes[4]][2])check3 = true;
							if ((v_5x[j][0])[k] == v[input_indexes[4]][3])check4 = true;

						}
						if (check1 + check2 + check3 + check4 == 2) {
							input_indexes[2] = std::stoi(v_5x[j][1]);
							v_5x.erase(v_5x.begin() + j);
							input_indexes[5] = std::stoi(v_5x[0][1]);
							v_5x.clear();
							break;
						}
						else { //if==3
							input_indexes[5] = std::stoi(v_5x[j][1]);
							v_5x.erase(v_5x.begin() + j);
							input_indexes[2] = std::stoi(v_5x[0][1]);
							v_5x.clear();
							break;
						}

					}

					//we have now 1 2 3 4 5 7 8, missing 0,6,9 which are all 6x
					//if 6x - 2x(1) == 5x -> 6
					for (int j = 0; j < v_6x.size(); j++) {
						bool check1{}, check2{};

						for (int k = 0; k < v_6x[j][0].size(); k++) {
							if ((v_6x[j][0])[k] == v[input_indexes[1]][0])check1 = true;
							if ((v_6x[j][0])[k] == v[input_indexes[1]][1])check2 = true;
						}
						if (check1 + check2 == 1) {
							input_indexes[6] = std::stoi(v_6x[j][1]);
							v_6x.erase(v_6x.begin() + j);
							break;
						}

					}

					//0 and 9 -4x(4) -> 3x(0), 2x(9)
					for (int j = 0; j < v_6x.size(); j++) {
						bool check1{}, check2{}, check3{}, check4{};

						for (int k = 0; k < v_6x[j][0].size(); k++) {
							if ((v_6x[j][0])[k] == v[input_indexes[4]][0])check1 = true;
							if ((v_6x[j][0])[k] == v[input_indexes[4]][1])check2 = true;
							if ((v_6x[j][0])[k] == v[input_indexes[4]][2])check3 = true;
							if ((v_6x[j][0])[k] == v[input_indexes[4]][3])check4 = true;

						}
						if (check1 + check2 + check3 + check4 == 3) {
							input_indexes[0] = std::stoi(v_6x[j][1]);
							v_6x.erase(v_6x.begin() + j);
							input_indexes[9] = std::stoi(v_6x[0][1]);
							v_6x.clear();
							break;
						}
						else { //if==4
							input_indexes[9] = std::stoi(v_6x[j][1]);
							v_6x.erase(v_6x.begin() + j);
							input_indexes[0] = std::stoi(v_6x[0][1]);
							v_6x.clear();
							break;
						}

					}
//cout
					for (int j = 0; j < 10; j++) {
						std::cout << "Index "<<j<<":"<<input_indexes[j]<<"\n";
					}
					//We have now all numbers determined.

					std::string temp_number_string{};
					for (int j = 10; j < 14; j++) {
						if (v[j].length() == 2) {
							temp_number_string += "1";
							continue;
						}
						if (v[j].length() == 3) {
							temp_number_string += "7";
							continue;
						}
						if (v[j].length() == 4) {
							temp_number_string += "4";
							continue;
						}
						if (v[j].length() == 7) {
							temp_number_string += "8";
							continue;
						}
						if (v[j].length() == 5) { //can be 2, 3 or 5
							bool check1{}, check2{}, check3{}, check4{}, check5{};
							for (int k = 0; k < 5; k++) {
								if (v[j][k] == v[input_indexes[2]][0])check1 = true;
								if (v[j][k] == v[input_indexes[2]][1])check2 = true;
								if (v[j][k] == v[input_indexes[2]][2])check3 = true;
								if (v[j][k] == v[input_indexes[2]][3])check4 = true;
								if (v[j][k] == v[input_indexes[2]][4])check5 = true;
							}
							if (check1 + check2 + check3 + check4 + check5 == 5) {
								temp_number_string += "2";
							}
							else {
								check1 = false;
								check2 = false;
								check3 = false;
								check4 = false;
								check5 = false;
								for (int k = 0; k < 5; k++) {
									if (v[j][k] == v[input_indexes[3]][0])check1 = true;
									if (v[j][k] == v[input_indexes[3]][1])check2 = true;
									if (v[j][k] == v[input_indexes[3]][2])check3 = true;
									if (v[j][k] == v[input_indexes[3]][3])check4 = true;
									if (v[j][k] == v[input_indexes[3]][4])check5 = true;
								}
								if (check1 + check2 + check3 + check4 + check5 == 5) {
									temp_number_string += "3";
								}
								else {
									check1 = false;
									check2 = false;
									check3 = false;
									check4 = false;
									check5 = false;
									for (int k = 0; k < 5; k++) {
										if (v[j][k] == v[input_indexes[5]][0])check1 = true;
										if (v[j][k] == v[input_indexes[5]][1])check2 = true;
										if (v[j][k] == v[input_indexes[5]][2])check3 = true;
										if (v[j][k] == v[input_indexes[5]][3])check4 = true;
										if (v[j][k] == v[input_indexes[5]][4])check5 = true;
									}
									if (check1 + check2 + check3 + check4 + check5 == 5) {
										temp_number_string += "5";
									}

								}
							}

						}

						if (v[j].length() == 6) { //can be 0, 6 or 9
							bool check1{}, check2{}, check3{}, check4{}, check5{}, check6{};;
							for (int k = 0; k < 6; k++) {
								if (v[j][k] == v[input_indexes[0]][0])check1 = true;
								if (v[j][k] == v[input_indexes[0]][1])check2 = true;
								if (v[j][k] == v[input_indexes[0]][2])check3 = true;
								if (v[j][k] == v[input_indexes[0]][3])check4 = true;
								if (v[j][k] == v[input_indexes[0]][4])check5 = true;
								if (v[j][k] == v[input_indexes[0]][5])check6 = true;
							}
							if (check1 + check2 + check3 + check4 + check5 + check6 == 6) {
								temp_number_string += "0";
							}
							else {
								check1 = false;
								check2 = false;
								check3 = false;
								check4 = false;
								check5 = false;
								check6 = false;
								for (int k = 0; k < 6; k++) {
									if (v[j][k] == v[input_indexes[6]][0])check1 = true;
									if (v[j][k] == v[input_indexes[6]][1])check2 = true;
									if (v[j][k] == v[input_indexes[6]][2])check3 = true;
									if (v[j][k] == v[input_indexes[6]][3])check4 = true;
									if (v[j][k] == v[input_indexes[6]][4])check5 = true;
									if (v[j][k] == v[input_indexes[6]][5])check6 = true;
								}
								if (check1 + check2 + check3 + check4 + check5 + check6 == 6) {
									temp_number_string += "6";
								}
								else {
									check1 = false;
									check2 = false;
									check3 = false;
									check4 = false;
									check5 = false;
									check6 = false;
									for (int k = 0; k < 6; k++) {
										if (v[j][k] == v[input_indexes[9]][0])check1 = true;
										if (v[j][k] == v[input_indexes[9]][1])check2 = true;
										if (v[j][k] == v[input_indexes[9]][2])check3 = true;
										if (v[j][k] == v[input_indexes[9]][3])check4 = true;
										if (v[j][k] == v[input_indexes[9]][4])check5 = true;
										if (v[j][k] == v[input_indexes[9]][5])check6 = true;
									}
									if (check1 + check2 + check3 + check4 + check5 == 5) {
										temp_number_string += "9";
									}

								}
							}

						}
					}

					sum += std::stoi(temp_number_string);
					std::cout << temp_number_string << "\n";
					temp_number_string = "";

				}//if v.size()==10
				v.clear();
			
		}

		std::cout << "Answer: " << sum << "\n";

	}
	else {
		std::cout << "File not opened, quitting";
		return 1;
	}


	myfile.close();
	//getchar();
	return 0;
}