#include "framework.h"
#include "GraphicsEngine_D2D.h"
#include "JTimer.h"

#include "MazeSolvingProblem.h"

D2DRenderer* g_d2dRenderer;

//스크린 사이즈
int g_ScreenWidth = 1100;
int g_ScreenHeight = 880;

// 윈도 프로시저의 전방선언
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int MousePosX = 0;
int MousePosY = 0;

// 메인 함수
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine, _In_ int       nCmdShow)
{
	/// 윈도를 등록한다.
	WNDCLASSEXW wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = NULL; // LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL; // MAKEINTRESOURCEW(IDC_PROJECT1);
	wcex.lpszClassName = L"PROJECT1";
	wcex.hIconSm = NULL;// LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	RegisterClassExW(&wcex);

	// 애플리케이션 초기화를 수행합니다:
	HWND hWnd = CreateWindowW(L"PROJECT1", L"JongPhago", WS_OVERLAPPEDWINDOW,
		400, 50, g_ScreenWidth + 15, g_ScreenHeight + 40, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	JTimer timer;
	timer.Initialize();
	g_d2dRenderer = new D2DRenderer(hWnd);

	// Algorithm
	MazeSolvingProblem maze;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;

	// 기본 메시지 루프입니다:
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
			{
				break;
			}
		}
		else
		{
			if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
			{
				break;
			}

			timer.Update();

			int fps = timer.GetFPS();
			float dTime = timer.GetDeltaTime();

			static float firstTime = 0;
			if (dTime < 10000)
				firstTime += dTime;

			g_d2dRenderer->BeginRender();
			
			g_d2dRenderer->DrawTextW(0, 0, ColorF(ColorF::Yellow), L"%d FPS", fps);

			if (firstTime > 0.01)
			{
				maze.Update(dTime);
				maze.Draw(g_d2dRenderer);
			}

			g_d2dRenderer->EndRender();
		}
	}

	delete g_d2dRenderer;
	g_d2dRenderer = nullptr;

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_LBUTTONUP:
		MousePosX = LOWORD(lParam);
		MousePosY = HIWORD(lParam);

		break;
	case WM_SIZE:
	case WM_EXITSIZEMOVE:

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}