#include <windows.h>
#include <stdio.h>
#include "..\PriorityBooster\PriorityBoosterCommon.h"

int Error(const char* message);

int main(int argc, const char* argv[]) {
	if (argc < 3) {
		printf("Usage: Booster <threadid> <priority>\n");
		return 0;
	}

	HANDLE hDevice = CreateFile(L"\\\\.\\PriorityBooster",
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		nullptr,
		OPEN_EXISTING,
		0,
		nullptr);
	if (hDevice == INVALID_HANDLE_VALUE)
		return Error("Failed to open device");

	ThreadData data;
	data.THreadId = atoi(argv[1]);
	data.Priority = atoi(argv[2]);

	DWORD returned;
	BOOL success = DeviceIoControl(hDevice,
		IOCTL_PRIORITY_BOOSTER_SET_PRIORITY,  // control operation code
		&data,                                // data
		sizeof(data),                         // size of data
		nullptr,                              // input buffer
		0,                                    // size of input buffer
		&returned,
		nullptr
	);
	if (success)
		printf("Priority change succeded!\n");
	else
		Error("Priority change failed!");

	CloseHandle(hDevice);
}

int Error(const char* message) {
	printf("%s (error=%d)\n", message, GetLastError());
	return 0;
}