#include <windows.h>

// 声明回调函数，处理按下按钮的操作
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 创建窗口类
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    wc.lpszClassName = TEXT("MyWindowClass");
    RegisterClass(&wc);

    // 创建窗口
    HWND hwnd = CreateWindow(TEXT("MyWindowClass"), TEXT("我帮你看网络学院_V2.1"), WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, 
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 200, NULL, NULL, hInstance, NULL);

    // 创建文本框
    HWND hText = CreateWindow(TEXT("STATIC"), TEXT("本项目使用的开发语言为C#，基于微软.Net Framework 4.7.2制作；\n\n推荐使用Win10/11系统，如使用Win7或更低版本操作系统可能需要\n安装微软.Net Framework 4.X补丁。"), 
        WS_CHILD | WS_VISIBLE | SS_LEFT, 20, 20, 500, 100, hwnd, NULL, hInstance, NULL);
    
	// 创建新字体
    HFONT hFont = CreateFont(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
        DEFAULT_PITCH | FF_DONTCARE, TEXT("微软雅黑"));

    // 应用新字体
    SendMessage(hwnd, WM_SETFONT, (WPARAM)hFont, TRUE);
    SendMessage(hText, WM_SETFONT, (WPARAM)hFont, TRUE);
    
    // 创建按钮
    CreateWindow(TEXT("BUTTON"), TEXT("启动程序"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 70, 125, 100, 30, hwnd, (HMENU)1, hInstance, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("安装补丁"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 190, 125, 100, 30, hwnd, (HMENU)2, hInstance, NULL);
    CreateWindow(TEXT("BUTTON"), TEXT("取消"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 310, 125, 100, 30, hwnd, (HMENU)3, hInstance, NULL);

    // 居中窗口
    RECT rc;
    GetWindowRect(hwnd, &rc);
    int width = rc.right - rc.left;
    int height = rc.bottom - rc.top;
    int x = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
    int y = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
    MoveWindow(hwnd, x, y, width, height, TRUE);

    // 显示窗口
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // 消息循环
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case 1: // 启动程序
            ShellExecute(NULL, NULL, TEXT("WindowsFormsApp1.exe"), NULL, NULL, SW_SHOWNORMAL);
            DestroyWindow(hwnd);
            break;
        case 2: // 安装补丁
            ShellExecute(NULL, NULL, TEXT("https://www.baidu.com/s?wd=win7%E7%B3%BB%E7%BB%9F%E6%80%8E%E4%B9%88%E5%AE%89%E8%A3%85net4.7.2%E8%A1%A5%E4%B8%81"), NULL, NULL, SW_SHOWNORMAL);
            DestroyWindow(hwnd);
            break;
        case 3: // 取消
            DestroyWindow(hwnd);
            break;
        }
        break;
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}
