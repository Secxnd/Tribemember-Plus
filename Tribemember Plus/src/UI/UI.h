#pragma once
#include "../Settings.h"

#include "GLFW/glfw3.h"
#include "ImGui/imgui.h"

#include "ImGui/imgui_impl_opengl3.h"
#include "ImGui/imgui_impl_glfw.h"

bool IsOpen = true;

inline void DoUI() {
	if (!glfwInit()) return;

	GLFWwindow* Window = glfwCreateWindow(1360, 768, "Tribemember Plus", NULL, NULL);

	if (!Window) {
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(Window);

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();

	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\segoeui.ttf", 30.0f);
	io.Fonts->Build();
	io.FontDefault = io.Fonts->Fonts.back();

	ImGui::NewFrame();

	ImGui_ImplGlfw_InitForOpenGL(Window, true);
	ImGui_ImplOpenGL3_Init("#version 130");

	while (!glfwWindowShouldClose(Window)) {
		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::SetNextWindowSize(io.DisplaySize);
		ImGui::SetNextWindowPos(ImVec2(0, 0));

		if (ImGui::Begin("TMP", &IsOpen, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove)) {

			if (ImGui::BeginTabBar("Tabs")) {
				if (ImGui::BeginTabItem("Farm Bot")) {
					Settings.CurrentTab = 0;

					ImGui::Text("F1 - Start | F2 - Stop | You need to use Gamma 5");
					ImGui::NewLine();
					ImGui::SliderInt("Seconds Drop Delay", &Settings.FarmBot.DropDelay, 0, 500);
					ImGui::NewLine();

					ImGui::Checkbox("Drop Stone", &Settings.FarmBot.DropMats.DropStone);
					ImGui::Checkbox("Drop Flint", &Settings.FarmBot.DropMats.DropFlint);
					ImGui::Checkbox("Drop Metal", &Settings.FarmBot.DropMats.DropMetal);
					ImGui::Checkbox("Drop Obsidian", &Settings.FarmBot.DropMats.DropObsidian);
					ImGui::Checkbox("Drop Crystal", &Settings.FarmBot.DropMats.DropCrystal);
					ImGui::Checkbox("Drop Mushrooms", &Settings.FarmBot.DropMats.DropMushrooms);
					ImGui::Checkbox("Drop Flowers", &Settings.FarmBot.DropMats.DropFlowers);
					ImGui::Checkbox("Drop Berries", &Settings.FarmBot.DropMats.DropBerries);
					ImGui::Checkbox("Drop Wood", &Settings.FarmBot.DropMats.DropWood);
					ImGui::Checkbox("Drop Thatch", &Settings.FarmBot.DropMats.DropThatch);
					ImGui::Checkbox("Drop Fiber", &Settings.FarmBot.DropMats.DropFiber);

					ImGui::EndTabItem();
				}
				ImGui::EndTabBar();
			}
			
			ImGui::End();
		}


		ImGui::Render();

		int Width, Height;
		glfwGetFramebufferSize(Window, &Width, &Height);
		glViewport(0, 0, Width, Height);
		glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(Window);
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(Window);
	glfwTerminate();
}