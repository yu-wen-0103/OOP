#include	<iostream>
#include	<fstream>
#include	<cctype>	//using::isdigit;
#include	<cstdlib>	//atof
#include	<bits/stdc++.h>
#include	<iomanip>

using namespace std;

//to get the highest power of the input polynomial function and change the type to int
int		highestPower(float coff[10]){
	return int(coff[0]);
}

//to display the f(x) on the screen
void	display(int highestPow, float coff[10]){
	cout << "f(x) = ";
	for(int i = 0; i <= highestPow; i++){
		if(i == 0)
			cout << coff[i+1];	//i+1 because of the coff[0] is number of highest power
		else{
			if(coff[i+1] != 0){
				cout << " + " << coff[i+1];
				for(int x = i; x > 0; x--)
					cout << "*x";
			}
		}
	}
	cout << endl;
}

//compute the derivative coefficient
void	derivative(int highestPow, float coff[10], float dev_coff[]){
	if(highestPow == 0)
		dev_coff[0] = highestPow;
	else
		dev_coff[0] = highestPow-1;

	for(int i = 2; i <= highestPow+1; i++)
			dev_coff[i-1] = coff[i]*(i-1);
	
	cout << "f'(x) = ";
	for(int i = 0; i <= dev_coff[0]; i++){
			if(i == 0)
				if(dev_coff[i+1] != 0 || dev_coff[i] == 0)
					cout << dev_coff[i+1];
			else{
				if(dev_coff[i+1] != 0){
					cout << " + " << dev_coff[i+1];
					for(int x = i; x > 0; x--)
						cout << "*x";
				}
			}
	}
	cout << endl;
}

//to compute the value of f(x) and f'(x)
float	compute(int highestPow, float coff[10], float x){
	float	sum = coff[1], tmp = 0;
	for(int i = 2; i <= highestPow+1; i++){
		tmp = coff[i];
		for(int j = i-1; j > 0; j--)
				tmp = tmp * x;
		sum += tmp;
	}
	return sum;
}

int		main(){
	float	coff[10] = {0}, dev_coff[10] = {0}, poly_out = 0, poly_dev_out = 0, x = 0;
	char	buf[100] = {0}, word[100] = {0}, input[5] = {0};
	int		buf_len = 0, word_len = 0, num = 0, highestPow = 0, flag = 0, debug = 0;

	ifstream 	fin;

	while(1){
		//determine which mode is chose by user
		cout << "Two mode: if you want to input polynomial data from keyboard, please enter '1'. In contrast, if you want to input polynomial data from file, please enter '0'." << endl;
		cin >> input;

		if(atoi(input) == 0 || atoi(input) == 1){
			debug = atoi(input);
			break;
		}
		else
			cout << "Input is not legal." << endl;
	}

	if(debug == 1)
		cin.getline(buf, sizeof(buf));
	else if(debug == 0)
		fin.open("polydata.txt");

	while(fin.getline(buf, sizeof(buf)) || debug == 1){
		//keyboard mode: need to enter polynomial every time
		if(debug == 1){
			cout << "Please enter the polynomial data." << endl;
			cin.getline(buf, sizeof(buf));
		}

		cout << "Please enter the 'x' of the polynomial:" << endl;
		cin >> x;
		cin.get();	//in order to let cin.getline to get the correct input

		//initialization 
		flag = 0;	//determine if the input data is legal or not
		for(int i = 0; i < num; i++){
				coff[i] = 0;
				dev_coff[i] = 0;
		}
		num = 0;

		buf_len = strlen(buf);
		buf[buf_len] = '\0';
	
		//judge of the input polynomial is legal or not. If it is legal, change the type and put into coff[], or print the error message on the screen
		for(int i = 0; i <= buf_len ; i++){
			if(isdigit(buf[i]) || buf[i] == ' ' || buf[i] == '-' || buf[i] == '.' || buf[i] == '\n' || buf[i] == '\0'){
				if(buf[i] == '.' || isdigit(buf[i]) || buf[i] == '-'){
					if(buf[i] == '-' && word_len != 0){
						cout << "Input is not legal." << endl;
						for(int j = 0; j < word_len; j++)
								word[j] = '\0';
						word_len = 0;
						flag = 1;
						break;
					}
					word[word_len++] = buf[i];
				}
				else if(buf[i] == ' '  || buf[i] == '\n' || buf[i] == '\0'){
					coff[num++] = atof(word);
					for(int j = 0; j < word_len; j++)
							word[j] = '\0';
					word_len = 0;
				}
			}
			else{
				cout << "Input is not legal." << endl;
				for(int j = 0; j < word_len; j++)
						word[j] = '\0';
				word_len = 0;
				flag = 1;
				break;
			}
		}
		//If the amount of input is not legal, print the error message on the screen.
		if(num != (coff[0] + 2) && flag != 1){
			cout << "Input is not legal." << endl;
			flag = 1;
		}

		//subroutine
		if(flag != 1){
			highestPow = highestPower(coff);
			display(highestPow, coff);
			derivative(highestPow, coff, dev_coff);
			poly_out = compute(highestPow, coff, x);
			cout << "f(" << x << ") = " << fixed << setprecision(3) << poly_out << endl;
			poly_dev_out = compute(dev_coff[0], dev_coff, x);
			cout.unsetf(ios::fixed);
			cout << "f'(" << x << ") = " << fixed << setprecision(3) << poly_dev_out << endl;
			cout.unsetf(ios::fixed);
		}

		//initialization
		for(int i = 0; i <= buf_len; i++)
			buf[i] = '\0';
	}
	fin.close();
	cout << "Complete all calculations." << endl;
	return 0;
}
