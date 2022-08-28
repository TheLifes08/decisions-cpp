#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <locale>
#include <Windows.h>

using namespace std;
 
int main(){
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector <string> words(0);
	ifstream is("words.txt");
	
	if(is.fail()){
		cout << "���� words.txt �� ������.";
		return 1;
	}
	
	for(int i = 0; !is.eof(); i++){
		words.push_back("");
		getline(is, words[i]);		
	}
	
	random_shuffle(words.begin(), words.end());
	
	int size = words.size();
	int right = 0;
	cout << "���������� ����: " << size << endl;
	cout << "� �������� ������ ����� ���������� �����, � ������� ����� ������� ���������. ������� /exit, ����� ���������." << endl << endl;
	
	for(int i = 0; i < size; i++){
		string data = words[i], answer;
		
		std::transform(data.begin(), data.end(), data.begin(), ::tolower);
		cout << i+1 << ") " << data << endl;
		cout << "������� �����: ";
		cin >> answer;
		
		if(answer == "/exit"){
			size = i;
			break;
		} else if(answer == words[i]){
			cout << "���������� �����." << endl << endl;
			right++;
		} else {
			cout << "�������� �����. ���������� �����: " << words[i] << endl << endl;
		}
	}
	
	cout << "���������: " << right << " �� " << size;
	
	return 0;
}
