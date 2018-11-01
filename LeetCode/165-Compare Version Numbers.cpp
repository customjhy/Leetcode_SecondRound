#include<iostream>
#include<cstring>
#include<string>

using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		if (version1.empty() && version2.empty())
			return 0;
		else if (version1.empty() && !version2.empty()){
			return compareVersion("0", version2);
		}
		else if (!version1.empty() && version2.empty()){
			return compareVersion(version1, "0");
		}
		int index1 = 0;
		int index2 = 0;
		for (index1 = 0; index1 < version1.length(); index1++){
			if (version1[index1] == '.')
				break;
		}
		for (index2 = 0; index2 < version2.length(); index2++){
			if (version2[index2] == '.')
				break;
		}
		int a = stoi(version1.substr(0, index1));
		int b = stoi(version2.substr(0, index2));
		if (a > b)
			return 1;
		else if (a < b)
			return -1;
		if (index1 == version1.length()){
			version1 = "";
		}
		else{
			version1 = version1.substr(index1 + 1);
		}
		if (index2 == version2.length()){
			version2 = "";
		}
		else{
			version2 = version2.substr(index2 + 1);
		}
		return compareVersion(version1, version2);
	}
};

