﻿/*
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

// #define FUNCTION_TRACE
#include <Ducktape.h>

using namespace std;
using namespace Ducktape;

void MainScene(Scene &scene)
{
	scene.Call<Tag>();
	scene.Call<Transform>();
	scene.Call<Camera>();
	scene.Call<SpriteRenderer>();
}

int main()
{
	try
	{
		std::cout << "Ducktape  Copyright (C) 2022  Aryan Baburajan\n"
					 "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n"
					 "This is free software, and you are welcome to redistribute it\n"
					 "under certain conditions; type `show c' for details.\n";

		Engine game;
		game.configuration.windowSize = {800, 600};
		game.configuration.windowTitle = "DucktapeTest";

		Scene mainScene = Scene(MainScene);

		Entity camera = mainScene.CreateEntity();
		camera.AddComponent<Tag>().name = "MainCamera";
		camera.AddComponent<Transform>();
		camera.AddComponent<Camera>();

		Entity player = mainScene.CreateEntity();
		player.AddComponent<Tag>().name = "Player";
		player.AddComponent<Transform>();

		SpriteRenderer &sr = player.AddComponent<SpriteRenderer>();
		sr.sprite = "../sprites/ducktapeicon.png";

		game.Run(mainScene);
	}
	catch (const exception &e)
	{
		cout << e.what() << endl;
		exit(1);
	}
}