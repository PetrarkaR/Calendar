#pragma once;

#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include <d3d9.h>
#include <tchar.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <string>
#include <vector>

class Task {
public:
	std::string task;
	bool done;
	Task(char* zadacic):task(zadacic),done(false){}
};
std::vector<Task> zadaci;
void ToDo() {
	char inputBuffer[256] = "\0";
	if (ImGui::InputText("Input", inputBuffer, sizeof(inputBuffer), ImGuiInputTextFlags_EnterReturnsTrue)) {
		if (inputBuffer[0] != '\0')
			zadaci.emplace_back(Task(inputBuffer));
		inputBuffer[0] = '\0';

	}
	for (size_t i = 0;i < zadaci.size();i++) {

		bool checkboxChecked = zadaci[i].done;
		ImGui::Text("%s", zadaci[i].task.c_str());
		ImGui::SameLine();
		if (ImGui::Checkbox(("##Checkbox" + std::to_string(i)).c_str(), &checkboxChecked)) {
			zadaci[i].done = checkboxChecked;
		}
		if(checkboxChecked){
			if (ImGui::Button(("Remove##" + std::to_string(i)).c_str())) {
				zadaci.erase(zadaci.begin() + i);
				--i;
			}
		}	
	}
}

