#include <windows.h> //initializing windows libraries

// test

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR PCmdLine, int nCmdShow)
{
	// Registering of windows class     NOTE: windows cannot be created without registering the class of the yet to be created window
	const wchar_t CLASS_NAME[] = L"Window Class Example";

	WNDCLASS wce = {};
	wce.lpfnWndProc = WindowProc;
	wce.lpszClassName = CLASS_NAME;
	wce.hInstance = hInstance;

	RegisterClassW(&wce);

	// Now to create windows 

	HWND hWnd = CreateWindowExW
	(
		0,
		CLASS_NAME,
		L"FIRST_WINDOW^_^",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL
	);

	if (hWnd == NULL) {
		return  0;
	}
	//window creation Completed
	// window is created but will not show, so pass in ShowWindow Function.... 

	ShowWindow(hWnd, nCmdShow);


	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
	{
		PAINTSTRUCT pst;
		HDC hdc = BeginPaint(hWnd, &pst);
		FillRect(hdc, &pst.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hWnd, &pst);

	}
	return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}