#include <Windows.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    HKEY hKey;
    DWORD dwType = REG_SZ;
    char newValue[] = "randomhwid";
    DWORD dwSize = sizeof(newValue);

    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS) {
        RegSetValueExA(hKey, "ProductId", 0, dwType, (BYTE*)newValue, dwSize);
        RegCloseKey(hKey);
        cout << "HWID spoofed successfulyy" << endl;
        system("PAUSE");
        return 0;
    } else {
        cout << "Failed to open registry keyy" << endl;
        system("PAUSE");
        return 1;
    }
}
