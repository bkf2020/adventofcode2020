#include <bits/stdc++.h>
using namespace std;

bool check_height(string height) {
	int h = height.substr(0 ,height.size() - 2);
	string type = height.substr(height.size() - 3, 2);
	if(type == "in") {
		if(h >= 59 && h <= 76) return true;
		return false;
	}
	else if(type == "cm") {
		if(h >= 150 && h <= 193) return true;
		return false;
	}
	return false;
}

bool check_eye(string eye) {
	return (eye == "amb") || (eye == "blu") || (eye == "gry") || (eye == "grn") || (eye == "hzl") || (eye == "oth");
}

bool check_hair(string hair) {
	if(hair[0] != '#') return false;
	if(hair.size() != 7) return false;
	for(int i = 1; i <= hair.size(); i++) {
		if(!isalnum(hair[i])) return false;
	}
	return true;
}

bool is_integer(string s) {
	for(int i = 0; i < s.size(); i++) {
		if(!(s == '0' || s == '1' || s == '2' || s == '3' || s == '4' || s == '5' || s == '6' || s == '7' || s == '8' || s == '9')) {
			return false;
		}
	}
	return true;
}

void part2() {
	string line = " ";
	int valid = 0;
	string check[8] = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};
	map<string, string> info;
	map<string, string> filled;
	for(string c : check) {
		filled[c] = false;
	}
	while(getline(cin, line)) {
		if(line == "") {
			bool ok = true;
			if(!filled["byr"] || !is_integer(info["byr"] || stoi(info["byr"]) > 2002 || stoi(info["byr"]) < 1920) ok = false;
			if(!filled["iyr"] || !is_integer(info["iyr"] || stoi(info["iyr"]) > 2020 || stoi(info["iyr"]) < 2010) ok = false;
			if(!filled["eyr"] || !is_integer(info["eyr"] || stoi(info["eyr"]) > 2030 || stoi(info["eyr"]) < 2020) ok = false;
			if(!filled["hgt"] || !check_height(info["hgt"])) ok = false;
			if(!filled["hcl"] || !check_hair(info["hcl"]) ok = false;
			if(!filled["ecl"] || !check_eye(info["ecl"]) ok = false;
			if(!filled["pid"] || !is_integer(info["pid"] || pid.size() != 9) ok = false;
			if(ok) valid++;
			for(string c : check) {
				filled[c] = false;
			}
		}
		stringstream ss(line);
		string part;
		while(ss >> part) {
			info[part.substr(0, 3)] = part.substr(3, part.size() - 3);
			filed[part.substr(0, 3)] = true;
		}
	}
	// check for last passport
	bool ok = true;
	if(!filled["byr"] || !is_integer(info["byr"] || stoi(info["byr"]) > 2002 || stoi(info["byr"]) < 1920) ok = false;
	if(!filled["iyr"] || !is_integer(info["iyr"] || stoi(info["iyr"]) > 2020 || stoi(info["iyr"]) < 2010) ok = false;
	if(!filled["eyr"] || !is_integer(info["eyr"] || stoi(info["eyr"]) > 2030 || stoi(info["eyr"]) < 2020) ok = false;
	if(!filled["hgt"] || !check_height(info["hgt"])) ok = false;
	if(!filled["hcl"] || !check_hair(info["hcl"]) ok = false;
	if(!filled["ecl"] || !check_eye(info["ecl"]) ok = false;
	if(!filled["pid"] || !is_integer(info["pid"] || pid.size() != 9) ok = false;
	if(ok) valid++;
	for(string c : check) {
		filled[c] = false;
	}
	cout << valid << '\n';
}

void part1() {
	string line = " ";
	int valid = 0;
	vector<string> missing = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};
	while(getline(cin, line)) {
		if(line == "") {
			bool ok = true;
			for(string missed : missing) {
				if(missed != "cid") {
					ok = false;
				}
			}
			if(ok) valid++;
			missing = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};
		}
		stringstream ss(line);
		string part;
		while(ss >> part) {
			auto it = find(missing.begin(), missing.end(), part.substr(0,3));
			if(it != missing.end()) missing.erase(it); // first three letters
			// make sure to check if element exists
		}
	}
	// check for last passport
	bool ok = true;
	for(string missed : missing) {
		if(missed != "cid") {
			ok = false;
		}
	}
	if(ok) valid++;
	cout << valid << '\n';
}

int main() {
	part2();
}