//
//  solution.cpp
//
//

#include <iostream>
#include <vector>

using namespace std;

string singleD(unsigned long int n){
	int ans = n;
	if(ans == 0){
		return "";
	}
	else if(ans == 1){
		return "one";
	}
	else if(ans == 2){
		return "two";
	}
	else if(ans == 3){
		return "three";
	}
	else if(ans == 4){
		return "four";
	}
	else if(ans == 5){
		return "five";
	}
	else if(ans == 6){
		return "six";
	}
	else if(ans == 7){
		return "seven";
	}
	else if(ans == 8){
		return "eight";
	}
	else if(ans == 9){
		return "nine";
	}
	else if(ans == 10){
		return "ten";
	}
	else if(ans == 11){
		return "eleven";
	}
	else if(ans == 12){
		return "twelve";
	}
	else if(ans == 13){
		return "thirteen";
	}
	else if(ans == 14){
		return "fourteen";
	}
	else if(ans == 15){
		return "fifteen";
	}
	else if(ans == 16){
		return "sixteen";
	}
	else if(ans == 17){
		return "seventeen";
	}
	else if(ans == 18){
			return "eighteen";
	}
	else if(ans == 19){
		return "nineteen";
	}
	return "";
}

string doubleD(unsigned long int n){
	int ans = n / 10;
	if(ans == 0){
		return "";
	}
	else if(ans == 1){
		return "";
	}
	else if(ans == 2){
		return "twenty";
	}
	else if(ans == 3){
		return "thirty";
	}
	else if(ans == 4){
		return "forty";
	}
	else if(ans == 5){
		return "fifty";
	}
	else if(ans == 6){
		return "sixty";
	}
	else if(ans == 7){
		return "seventy";
	}
	else if(ans == 8){
		return "eighty";
	}
	else if(ans == 9){
		return "ninety";
	}
	return "";
}

string wordHelp(long unsigned int n, string s){
	if(n > 19){
		string w = doubleD(n);
		if (n % 10 > 0){
			w += "-" + singleD(n % 10) + s;
		}
		else{
			w+= s;
		}
		return w;
	}
	else if(n == 0){
		return "";
	}
	return singleD(n) + s;

}


string puncArt(long unsigned int n, string w){
	if(n > 100 && n % 100 && w != "" ){
		return " and ";
	}
	else if(w != ""){
		return " ";
	}
	return "";
}

bool emptyHelp(string w){
	if(w == ""){
		return true;
	}
	return false;
}

string processHelp(long unsigned int n){
	string word;

	if(n == 0){
		return "zero";
	}

	word = wordHelp((n % 100), "");

	string numberString = to_string(n);
	if((n/100) % 10 > 0){
		word = puncArt((n % 1000), word) + word;
		word = wordHelp((n/100)%10, " hundred")+ word;
	}
	if((n / 1000) % 100 > 0){
		if(word.find("hundred") != string::npos){
			word = wordHelp((n / 1000) % 100, " thousand, ")+ word;
		}
		else if (emptyHelp(word) == false){
			word = wordHelp((n / 1000) % 100, " thousand and ")+ word;
		}
		else{
			word = wordHelp((n / 1000) % 100, " thousand")+ word;
		}
	}
	if((n / 100000 )% 10 > 0){
		puncArt((n/1000)% 1000, word);
		if(word.find("thousand") != string::npos){
			word = wordHelp((n / 100000) % 10, " hundred and ")+ word;
		}

		else if(emptyHelp(word) == false){
			word = wordHelp((n / 100000) % 10, " hundred thousand and ")+ word;
		}
		else{
			word = wordHelp((n / 100000) % 10, " hundred thousand")+ word;
		}
	}
	if((n / 1000000) % 100 > 0){
		if(word.find("thousand") != string::npos ){
			word = wordHelp((n/1000000)% 100, " million, ") + word;
		}
		else if(word.find("hundred") != string::npos ){
			word = wordHelp((n/1000000)% 100, " million, ") + word;
		}
		else if(emptyHelp(word) == false){
			word = wordHelp((n/1000000)% 100, " million and ") + word;
		}
		else{
			word = wordHelp((n/1000000)% 100, " million") + word;
		}
	}
	if((n/100000000)% 10){
		puncArt((n/1000000)% 1000, word);
		if(word.find("million") != string::npos){
			word = wordHelp((n/100000000)% 10, " hundred and ")+ word;
		}
		else if(word.find("thousand") != string::npos ){
			word = wordHelp((n/100000000)% 10, " hundred million, ")+ word;
		}
		else if(word.find("hundred") != string::npos ){
			word = wordHelp((n/100000000)% 10, " hundred million, ")+ word;
		}
		else if(emptyHelp(word) == false){
			word = wordHelp((n/100000000)% 10, " hundred million and ")+ word;
		}
		else{
			word = wordHelp((n/100000000)% 10, " hundred million")+ word;
		}
	}



	return word;
}

vector<string>* process(vector<unsigned long>& input) {
    vector<string>* conversion = new vector <string>;
    for(long unsigned int i = 0 ; i < input.size(); i++){
    	int number = input.at(i);
    	string word = processHelp(number);
    	conversion->push_back(word);
    }
    return conversion;
}


