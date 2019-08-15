#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<windows.h>
#include<cstdlib>
#include<time.h>
#include<random>
using namespace std;

class main_screen {
public:
	int map_size=51,difficulty,e,f; vector<vector<string>>map;
	void start() {
		cout << "Game 1\n"; system("PAUSE"); system("CLS");
		cout << "Choose your Difficulty:\n1 for Easy\n2 for Medium\n3 for Hard\n"; cin >> difficulty; system("CLS");
		switch(difficulty) {
		case 1: e = 1; f = 2; break; case 2: e = 2; f = 2; break; case 3: e = 20; f = 100; break;
		}
	}
};
class map_gen : public main_screen {
public:
	void map_layout() {
		if(map_size==51) SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
		for (int i = 0; i < map_size; i++) {
			vector<string>temp;
			if (i % 2 == 0) {
				for (int j = 0; j < map_size; j++) {
					if (j % 2 == 0) {
						string temp2 = "[.]"; temp.push_back(temp2);
					}
					else {
						string temp2 = "[   ]"; temp.push_back(temp2);
					}
				}
			}
			else {
				for (int j = 0; j < map_size; j++) {
					if (j % 2 == 0) {
						string temp2 = "[ ]"; temp.push_back(temp2);
					}
					else {
						string temp2 = "[   ]"; temp.push_back(temp2);
					}
				}
			}
			map.push_back(temp);
		}
	}
};
class in_game :public map_gen {
public:
	int stamina = 100, p; string key; int start_temp = 1;
	void disp() {
		map[(map_size - 1) / 2][(map_size - 1) / 2] = "[ P ]";
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map.size(); j++) {
				cout << map[i][j];
			}
			cout << "\n";
		}
		cin >> key;
		if(start_temp==1) player();
	}
	void player() {
		random_device rd;
		mt19937 mt(rd());
		uniform_int_distribution<int> dist(0, 1);
		start_temp++;
		while (stamina--) {
			if (key == "exit" || key == "EXIT") abort();
			if (key == "w" || key == "W") {
				string a[51][51]; int tx;
				map[(map_size - 1) / 2][(map_size - 1) / 2] = "[   ]";
				for (int i = 0; i < map_size-2; i++) {
					for (int j = 0; j < map_size; j++) {
						a[i + 2][j] = map[i][j];
					}
				} vector<string>tempv; vector<string>tempv2;
				for (int i = 0; i < (map_size - 1) / 2; i = i++) {
					string q1 = "[.]"; string q2 = "[   ]";
					tempv.push_back(q1); tempv.push_back(q2);
				} string q3 = "[.]"; tempv.push_back(q3);
				for (int i = 0; i < (map_size - 1) / 2; i = i++) {
					string q1 = "[ ]"; string q2 = "[   ]";
					tempv2.push_back(q1); tempv2.push_back(q2);
				} q3 = "[ ]"; tempv2.push_back(q3);
				for (int i = 0; i < map_size; i++) {
					a[0][i] = tempv[i]; a[1][i] = tempv2[i];
				}
				for (int i = 0; i < map_size; i++) {
					for (int j = 0; j < map_size; j++) {
						map[i][j] = a[i][j];
					}
				}
				for (int i = 1; i < map_size - 1; i += 2) {
					srand(i); tx = (dist(mt) % f);
					if (tx == 1) {
						map[1][i] = "[ F ]";
					}
				}
				for (int i = 1; i < map_size-1; i+=2) {
					srand(i); tx = (dist(mt) % e);
						if (tx==1) {
							map[1][i] = "[ E ]";
						}
				}
			}
			else if (key == "s" || key == "S") {
				string a[51][51]; int tx;
				map[(map_size - 1) / 2][(map_size - 1) / 2] = "[   ]";
				for (int i = 0; i < map_size - 2; i++) {
					for (int j = 0; j < map_size; j++) {
						a[i][j] = map[i+2][j];
					}
				} vector<string>tempv; vector<string>tempv2;
				for (int i = 0; i < (map_size - 1) / 2; i = i++) {
					string q1 = "[.]"; string q2 = "[   ]";
					tempv.push_back(q1); tempv.push_back(q2);
				} string q3 = "[.]"; tempv.push_back(q3);
				for (int i = 0; i < (map_size - 1) / 2; i = i++) {
					string q1 = "[ ]"; string q2 = "[   ]";
					tempv2.push_back(q1); tempv2.push_back(q2);
				} q3 = "[ ]"; tempv2.push_back(q3);
				for (int i = 0; i < map_size; i++) {
					a[map_size-1][i] = tempv[i]; a[map_size-2][i] = tempv2[i];
				}
				for (int i = 0; i < map_size; i++) {
					for (int j = 0; j < map_size; j++) {
						map[i][j] = a[i][j];
					}
				}
				for(int i = 1; i < map_size - 1; i += 2) {
					srand(i); tx = (dist(mt) % f);
					if (tx == 1) {
						map[map_size-2][i] = "[ F ]";
					}
				}
				for (int i = 1; i < map_size - 1; i += 2) {
					srand(i); tx = (dist(mt) % e);
					if (tx == 1) {
						map[map_size-2][i] = "[ E ]";
					}
				}
			}
			else if (key == "a" || key == "A") {
				string a[51][51]; int t[1000];
				map[(map_size - 1) / 2][(map_size - 1) / 2] = "[   ]";
				for (int i = 0; i < map_size; i++) {
					for (int j = 0; j < map_size-2; j++) {
						a[i][j+2] = map[i][j];
					}
				} vector<string>tempv; vector<string>tempv2;
				for (int i = 0; i < (map_size - 1) / 2; i = i++) {
					string q1 = "[.]"; string q2 = "[ ]";
					tempv.push_back(q1); tempv.push_back(q2);
				} string q3 = "[.]"; tempv.push_back(q3);
				for (int i = 0; i < (map_size - 1) / 2; i = i++) {
					string q1 = "[   ]"; string q2 = "[   ]";
					tempv2.push_back(q1); tempv2.push_back(q2);
				} q3 = "[   ]";  tempv2.push_back(q3);
				for (int i = 0; i < map_size; i++) {
					a[i][0] = tempv[i]; a[i][1] = tempv2[i];
				}
				for (int i = 0; i < map_size; i++) {
					for (int j = 0; j < map_size; j++) {
						map[i][j] = a[i][j];
					}
				}
				for (int i = 0; i < f; i++) {
					srand(time(NULL));  t[i] = (rand() % map_size);
					{
						if (t[i] % 2 != 0) {
							map[t[i]][1] = "[ F ]";
						}
					}
				}
				for (int i = 0; i < e; i++) {
					srand(time(NULL));  t[i] = (rand() % map_size);
					{
						if (t[i] % 2 != 0) {
							map[t[i]][1] = "[ E ]";
						}
					}
				}
			}
			else if (key == "d" || key == "D") {
				string a[51][51]; int t[1000];
				map[(map_size - 1) / 2][(map_size - 1) / 2] = "[   ]";
				for (int i = 0; i < map_size; i++) {
					for (int j = 0; j < map_size - 2; j++) {
						a[i][j] = map[i][j + 2];
					}
				} vector<string>tempv; vector<string>tempv2;
				for (int i = 0; i < (map_size - 1) / 2; i = i++) {
					string q1 = "[.]"; string q2 = "[ ]";
					tempv.push_back(q1); tempv.push_back(q2);
				} string q3 = "[.]"; tempv.push_back(q3);
				for (int i = 0; i < (map_size - 1) / 2; i = i++) {
					string q1 = "[   ]"; string q2 = "[   ]";
					tempv2.push_back(q1); tempv2.push_back(q2);
				} q3 = "[   ]";  tempv2.push_back(q3);
				for (int i = 0; i < map_size; i++) {
					a[i][map_size - 1] = tempv[i]; a[i][map_size - 2] = tempv2[i];
				}
				for (int i = 0; i < map_size; i++) {
					for (int j = 0; j < map_size; j++) {
						map[i][j] = a[i][j];
					}
				}
				for (int i = 0; i < f; i++) {
					srand(time(NULL));  t[i] = (rand() % map_size);
					{
						if (t[i] % 2 != 0) {
							map[t[i]][map_size - 2] = "[ F ]";
						}
					}
				}
				for (int i = 0; i < e; i++) {
					srand(time(NULL));  t[i] = (rand() % map_size);
					{
						if (t[i] % 2 != 0) {
							map[t[i]][map_size - 2] = "[ E ]";
						}
					}
				}
			}
			if (map[(map_size - 1) / 2][(map_size - 1) / 2] == "[ F ]") stamina++;
			else if (map[(map_size - 1) / 2][(map_size - 1) / 2] == "[ E ]") {
				system("CLS"); cout << "You lost!\nPress 1 to retry\nPress 2 to enter title screen\n";
				cin >> p; system("CLS");
				if (p == 1) abort();
			}
			system("CLS"); disp();
		}
	}
};

int main() {
	in_game o1;
	o1.start(); o1.map_layout(); o1.disp();
}