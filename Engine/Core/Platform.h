/*
Ducktape | An open source C++ 2D & 3D game engine that focuses on being fast, and powerful.
Copyright (C) 2022 Aryan Baburajan

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

In case of any further questions feel free to contact me at
the following email address:
aryanbaburajan2007@gmail.com
*/

#pragma once

#include <string>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#define DT_EXPORT extern "C" __declspec(dllexport)
#endif
#ifdef __linux__
#include <dlfcn.h>
#define DT_EXPORT extern "C" __attribute__((visibility("default")))
#endif

namespace DT
{
#ifdef _WIN32
	std::string GetLastErrorAsString();
#endif

    class Module
    {
    public:
#ifdef _WIN32
        HMODULE module;
#endif
#ifdef __linux__
        void * module;
#endif

        ~Module()
        {
			Free();
        }

        void Load(const std::string &path)
        {
#ifdef _WIN32
			module = LoadLibrary(path.c_str());

			if (!module)
				std::cout << GetLastErrorAsString();
#endif
#ifdef __linux__
			module = dlopen(path.c_str(), RTLD_LAZY);
#endif
        }

        void Free()
        {
#ifdef _WIN32
			FreeLibrary(module);
#endif
#ifdef __linux__
			dlclose(module);
#endif
        }

        template <typename T>
        T GetSymbolAddress(const std::string &symbolName)
        {
#ifdef _WIN32
            return (T)GetProcAddress(module, symbolName.c_str());
#endif
#ifdef __linux__
            return (T)dlsym(module, symbolName.c_str());
#endif
        }
    };
}