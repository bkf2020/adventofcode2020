#include <bits/stdc++.h>
using namespace std;

bool check_height(string height) {
	string h_str;
	for(int i = 0; i < (int) height.size(); i++) {
		if(isdigit(height[i])) h_str += height[i];
		else break;
	}
	int h = stoi(h_str);
	string type = to_string(height[height.size() - 2]);
	type += to_string(height[height.size() - 1]);
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
	for(int i = 0; i < (int) hair.size(); i++) {
		if(!isalnum(hair[i])) return false;
	}
	return true;
}

bool is_integer(string s) {
	for(int i = 0; i < (int) s.size(); i++) {
		if(!isdigit(s[i])) {
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
	map<string, bool> filled;
	for(string c : check) {
		filled[c] = false;
	}
	while(getline(cin, line)) {
		if(line == "") {
			bool ok = true;
			cout << info["byr"] << ' ' << info["iyr"] << ' ' << info["eyr"] << ' ' << info["hgt"] << ' ' << info["hcl"] << ' ' << info["ecl"] << ' ' << info["pid"] << '\n';
			if(!filled["byr"] || !is_integer(info["byr"]) || stoi(info["byr"]) > 2002 || stoi(info["byr"]) < 1920) ok = false;
			if(!filled["iyr"] || !is_integer(info["iyr"]) || stoi(info["iyr"]) > 2020 || stoi(info["iyr"]) < 2010) ok = false;
			if(!filled["eyr"] || !is_integer(info["eyr"]) || stoi(info["eyr"]) > 2030 || stoi(info["eyr"]) < 2020) ok = false;
			if(!filled["hgt"] || !check_height(info["hgt"])) ok = false;
			if(!filled["hcl"] || !check_hair(info["hcl"])) ok = false;
			if(!filled["ecl"] || !check_eye(info["ecl"])) ok = false;
			if(!filled["pid"] || !is_integer(info["pid"]) || info["pid"].size() != 9) ok = false;
			if(ok) valid++;
			for(string c : check) {
				filled[c] = false;
			}
		}
		else {
			stringstream ss(line);
			string part;
			while(ss >> part) {
				info[part.substr(0, 3)] = part.substr(4, part.size() - 3);
				filled[part.substr(0, 3)] = true;
			}
		}
	}
	// check for last passport
	bool ok = true;
	if(!filled["byr"] || !is_integer(info["byr"]) || stoi(info["byr"]) > 2002 || stoi(info["byr"]) < 1920) ok = false;
	if(!filled["iyr"] || !is_integer(info["iyr"]) || stoi(info["iyr"]) > 2020 || stoi(info["iyr"]) < 2010) ok = false;
	if(!filled["eyr"] || !is_integer(info["eyr"]) || stoi(info["eyr"]) > 2030 || stoi(info["eyr"]) < 2020) ok = false;
	if(!filled["hgt"] || !check_height(info["hgt"])) ok = false;
	if(!filled["hcl"] || !check_hair(info["hcl"])) ok = false;
	if(!filled["ecl"] || !check_eye(info["ecl"])) ok = false;
	if(!filled["pid"] || !is_integer(info["pid"]) || info["pid"].size() != 9) ok = false;
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
