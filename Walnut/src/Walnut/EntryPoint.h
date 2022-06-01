#pragma once

#ifdef WL_PLATFORM_WINDOWS

extern std::unique_ptr<Walnut::Application> Walnut::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace Walnut {

	int Main(int argc, char** argv)
	{
		while (g_ApplicationRunning)
		{
			std::unique_ptr<Walnut::Application> app = Walnut::CreateApplication(argc, argv);
			app->Run();
		}

		return 0;
	}

}

#ifdef WL_DIST

#include <Windows.h>

int APIENTRY WinMain(HINSTANCE, HINSTANCE, PSTR, int)
{
	return Walnut::Main(__argc, __argv);
}

#else

int main(int argc, char** argv)
{
	return Walnut::Main(argc, argv);
}

#endif // WL_DIST

#endif // WL_PLATFORM_WINDOWS
