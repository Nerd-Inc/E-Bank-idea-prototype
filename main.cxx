//Basic:
/* 
- Take in sum amount
- Take out constanst
- Show what's left
- Interaction produces an outcome for what's left
- 
*/

#include <iostream>
#include <vector>
#include <map>
#define Month 31

using namespace std;

vector<string> seperate(string input, bool show = false)
{
	//add each character to a string
	//if character is a symbol, keep adding till end symbol is met
	map<char, bool> char_syms_start, char_syms_stop;
	char_syms_start['['] = true;
	char_syms_start['{'] = true;
	char_syms_start['('] = true;
	char_syms_stop[']'] = true;
	char_syms_stop['}'] = true;
	char_syms_stop[']'] = true;
	string temp;
	bool flag = false;
	vector<string> ret;
	for(unsigned int i=0;i<input.size();i++){
		//cout << "Working with: " << input[i] << endl;
		if(flag) {
			if(char_syms_stop[input[i]]) {
				//cout << "Termination found..." << endl;
				temp += input[i];
				flag = false;
				//continue;
			} else temp += input[i];
		}
		else if(char_syms_start[input[i]]) {
			//cout << "Container found..." << endl;
			temp += input[i];
			flag = true;
		}
		else if(input[i] == ' '){
			ret.push_back(temp);
			temp.erase();
		} else temp += input[i];
	} ret.push_back(temp);
	
	return ret;
}

class AMOUNT {
	double SumAmount = 0.00, TotBalance = 0.00, sum = 0.00, TotBalanceTime = 0.00;
	int time = 0;
	map<string, double> fixedValues;
	string currencyType, operatorType;
	short int feedback = 0;
	
	double fAccountExpense = 0;
public:
	void backInput(), frontInput(), constants(), backAccounts(), frontAccounts(), backView(), frontView(), backEnd(), frontEnd();
	template<class T> string currency(T);
	map<string, int> operatorWords;
};

template<class T> string AMOUNT::currency(T input) {
	//implement a better truncating method!
	//return to_string(input).erase((to_string(input).find('.')+2), (to_string(input).size() - (to_string(input).find('.') -1)))+ currencyType;
	string temp = to_string(input) + currencyType;
	return temp;
}

void AMOUNT::frontInput() {
	string value = "buy shoes 1000";
	cout << "...: " << currency(atoi(seperate(value)[seperate(value).size() -1].c_str())) << endl;
	operatorType = seperate(value)[0];
	fAccountExpense = atoi(seperate(value)[seperate(value).size() -1].c_str());
}

void AMOUNT::frontAccounts() {
	double interaction = 0;
	switch(operatorWords[operatorType]) {
		case 1:
		interaction = TotBalance - fAccountExpense;
		break;
		
		case -1:
		interaction = TotBalance + fAccountExpense;
		break;
		
		default:
		cout << "I don't know that operator!!" << endl;
		break;
	}
	cout << "interaction yields: " << currency(interaction) << endl;
	if(interaction == 0) feedback = -1;
	else if(interaction > 0) feedback = 1;
	else feedback = 0;
}

void AMOUNT::frontView() {
	switch(feedback) {
		case 1:
		cout << "You can buy that..." << endl;
		break;
		
		case 0:
		cout << "You can't buy that..." << endl;
		break;
		
		case -1:
		cout << "You can afford that, but you'd have 0 left!!" << endl;
		break;
	}
}

void AMOUNT::frontEnd() {
	frontInput();
	frontAccounts();
}

void AMOUNT::backEnd() {
	backInput();
	constants();
	backAccounts();
}

void AMOUNT::backInput() {
	//cout << "Sum amount: ";
	//cin >> SumAmount;
	time = 1 * Month;
	SumAmount = 50000;
	currencyType = "FCFA";
	
	operatorWords.insert(make_pair("buy", 1));
	operatorWords.insert(make_pair("sell", -1));
	//cout << "Sum amount set to: " << SumAmount << endl << endl;
}

void AMOUNT::constants() {
	/*cout << "Enter fixed values: ";
	string values;
	getline(cin, values);

	while(!values.empty()) {
		fixedValues.insert(make_pair(seperate(values)[0], atoi(seperate(values)[1].c_str())));
		cout << "Enter fixed values: ";
		getline(cin, values);
	} */

	fixedValues["light"] = 10000.00;
	fixedValues["water"] = 3000.00;
	fixedValues["rent"] = 10000.00;
	fixedValues["internet"] = 25000.00;
}

void AMOUNT::backAccounts() {
	for(map<string, double>::iterator it=fixedValues.begin();it!=fixedValues.end();it++)
		sum += it->second;
	TotBalance = SumAmount - sum;
	TotBalanceTime = TotBalance / time;
}

void AMOUNT::backView() {
	cout << "Sum amount set to: " << currency(SumAmount) << endl << endl;
	cout << "Bills and needs~~~~" << endl;
	cout << "---------------" << endl;
	for(map<string, double>::iterator it=fixedValues.begin();it!=fixedValues.end();it++) 
		cout << it->first << " ---> " << currency(it->second) << endl;
	cout << "Total expenses being " << sum << endl;
	cout << "DONE" << endl << endl << endl;

	cout << "You have " << currency(TotBalance) << " left!" << endl;
	cout << "You have " << currency(TotBalanceTime) << " for each day" << endl << endl;
}

int main(void) {
	/*
	1. Fix position of values with commas
	*/
	AMOUNT amt;
	system("clear");

	amt.backEnd();
	//amt.backView();

	amt.frontEnd();
	amt.frontView();

	return 0;
}
