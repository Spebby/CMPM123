/**
 * Other files changed:
 * Application.cpp, added some log commands to GameStartUp. Also made a window to create more logs.
 * Changed CMakeList.txt to be prettier.
 * Everything else is in the Logger files!
 */

#include "Application.h"
#include "imgui/imgui.h"
#include "Logger.h"

namespace ClassGame {
	//
	// our global variables
	//

	Logger Log;

	//
	// game starting point
	// this is called by the main render loop in main.cpp
	//
	void GameStartUp() {
		Log.log(Logger::Level::INFO, "memory allocated");
		Log.log(Logger::Level::ERROR, "couldn't open file");
		Log.saveLog();
		Log.log(Logger::Level::INFO, "updated log level");
		Log.log(Logger::Level::WARNING, "updated log level");
		Log.log("tester!");
	}

	//
	// game render loop
	// this is called by the main render loop in main.cpp
	//
	void RenderGame() {
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

		ImGui::Begin("Settings");
		ImGui::Text("Game Settings");
		ImGui::End();

		ImGui::Begin("GameWindow");
		ImGui::Text("Game Window");
		ImGui::End();

		Log.draw();

		static char inputText[256] = "";
		ImGui::Begin("Screamer");
		ImGui::InputText("Enter text", inputText, sizeof(inputText));
		// Button to perform action
		if (ImGui::Button("Submit")) {
			Log.log(inputText);
		}

		ImGui::End();
	}

	//
	// end turn is called by the game code at the end of each turn
	// this is where we check for a winner
	//
	void EndOfTurn() {

	}
}
