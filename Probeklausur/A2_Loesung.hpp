#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
using namespace std;


/***********************************************/
/* Bitte die folgenden Makros einkommentieren, */
/* so bald die entsprechende Unteraufgabe      */
/* gelöst ist !!!                              */
/***********************************************/
#define A2_a
#define A2_b
#define A2_c
#define A2_d
#define A2_e

vector<string> text;

#ifdef  A2_a
void einlesen() {
	string s;
	fstream iofs("Datei.txt");
	if (iofs.is_open()) {
		while ( iofs.good() ) {
			getline (iofs,s);
			text.push_back(s);
		}
		iofs.close();
	}
}
#endif

#ifdef  A2_b
auto lambda1 = [] (char c) {
	string vok="aeiouAEIOU";
	return (vok.find(c) != string::npos);
};
#endif

#ifdef  A2_c
int vokal_counter = 0;
auto lambda2 = [&] (string s) -> int {
	int count = count_if(s.begin(), s.end(), lambda1);
	vokal_counter += count;
	return count;
};
#endif

#ifdef  A2_d
function<bool(string, string)> getComp () {
	return [] (string a, string b) { return lambda2(a) < lambda2(b); };
}
#endif

#ifdef  A2_e
void sortieren() {
	auto comp = getComp();
	sort(text.begin(), text.end(), comp);
}
#endif

