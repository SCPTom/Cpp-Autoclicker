#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;


wstring hackername = L"SC Clicker";
char keyChar;
int cps;


void Click() {
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &input, sizeof(INPUT));

	ZeroMemory(&input, sizeof(INPUT));
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &input, sizeof(INPUT));
}


int main() {
	SetConsoleTitle(hackername.c_str());
	cout << "PRESS ENTER TO START";
	while (true) {
		if (GetAsyncKeyState(VK_RETURN))
			break;

		Sleep(10);
	}

	Sleep(250);
	system("cls");

	cout << "PRESS KEY TO SET TOGGLE CLICKER BING\n";
	bool checking = true;
	while (checking) {
		for (int keycode = 0; keycode < 256; ++keycode) {
			if (GetAsyncKeyState(keycode) & 0x8000) {
				keyChar = static_cast<char>(keycode);
				checking = false;
			}
		}
		Sleep(10);
	}
	cout << "TOGGLE KEY SET TO " << keyChar << "\n";
	cout << "SET Clicks Per Second: ";
	cin >> cps;
	system("cls");

	wstring keyCharStr(1, keyChar);
	wstring fullTitle = hackername + L" | KEY: " + keyCharStr + L" | CPS: " + to_wstring(cps) + L" | Made by SCPrograms";

	SetConsoleTitle(fullTitle.c_str());

	bool clicking = false;

	while (true) {
		if (GetAsyncKeyState(keyChar) & 0x8000) {
			clicking = !clicking;
			if (clicking) {
				cout << "Autoclicker is now on!\n";
			}
			else {
				cout << "Autoclicker is now off! \n";
			}
			Sleep(250);
		}

		if (clicking) {
			Click();
			Sleep(1000 / cps);
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			cout << "Exiting Autoclicker";
			break;
		}
		
	}

	return 0;
}