#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int check(const int& num) {
	if (num < 1 || num >9)
		return -1;
	return 0;
}

int split(const string& line, int* arr, vector<int>& list) {
	// size < 0 return;
	if (line.size() <= 0)
		return -1;
	string line_temp = line;
	try {
		// ����','
		// ���볤�Ƚ�Ϊ1�����
		auto idx1 = line_temp.find_first_of(',');
		if (idx1 == string::npos) {
			auto num = stoi(line_temp);
			if (check(num) != 0)
				return -1;

			arr[num-1] += 1;
			list.push_back(num - 1);

			return 0;
		}

		auto first = stoi(line_temp.substr(0, idx1));
		if (check(first) != 0)
			return -1;
		arr[first - 1] += 1;
		list.push_back(first - 1);


		//���볤�Ȳ�Ϊ1
		auto idx2 = line_temp.find_first_of(',', idx1+1);

		while (idx2 != string::npos)
		{
			auto numStr = line_temp.substr(idx1+1 , idx2 - idx1 - 1);
			auto num = stoi(numStr);

			if (check(num) != 0)
				return -1;

			arr[num-1] += 1;
			list.push_back(num - 1);

			line_temp = line_temp.substr(idx2);

			idx1 = line_temp.find_first_of(',');
			idx2 = line_temp.find_first_of(',', idx1+1);
		}


		string leftStr = line_temp.substr(idx1 + 1);
		auto num = stoi(leftStr);

		if (check(num) != 0)
			return -1;

		arr[num - 1] += 1;
		list.push_back(num - 1);

	}
	catch (std::exception& e) {
		cout << e.what() << endl;
		return -1;
	}

	return 0;
}

//�������е������� ���ȼ� ���뵽 1-9  9��Ͱ�С�
int main(int argc, char* argv) {
	// getline from std::in

	string line;
	cin>> line;

	// backet to put the numbers;
	int backet[9] = { 0 };
	std::vector<int> list;
	int ret = split(line, backet, list);

	if (ret != 0)
		return -1;

	// Ͱ���������е�˳��
	// Ӧ�ð�������˳�� ��Ͱ����ȡ����

	// �ܵ�˳��
	int totalCnt = 0;

	// ��������Ҫ���� ÿ��Ͱ�������ʼindex
	int startIdx[9] = { 0 };

	for (int i = 8; i >= 0; i--) {
		startIdx[i] = totalCnt;
		totalCnt += backet[i];
	}

	string output = "";
	for (auto i : list) {

		// ���ҵ����ĸ�Ͱ��ٴ�ӡͰ����index;�ٽ�Ͱ����� index+=1;
		if (backet[i] > 0) {
			output += std::to_string(startIdx[i]);
			startIdx[i] += 1;
			output += ",";
		}
	}

	output = output.substr(0, output.size() - 1);
	cout << output << endl;
	system("pause");
	return 0;
}