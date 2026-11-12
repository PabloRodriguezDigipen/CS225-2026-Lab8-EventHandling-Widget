#include <AEEngine.h>
#include <imgui/imgui.h>
#include "Level 1.h"
#include "button.hh"
#include "mouse_event.hh"
int mode = 0;

bool ShowFrameworkMenu();

Button buton(AEVec2(0,0), AEVec2(120,30), AE_COLORS_BLUE, "blip blop");
MouseEventManager eventManager;

void Level_1_Load()
{
    Button* btn = &buton;
    eventManager.AddHandler([&btn](MouseEvent* event) {
        btn->OnMouseClick(event);
        });
}

void Level_1_Init()
{

}

void Level_1_Update()
{
    // core keyboard shortcuts and GUI, do not delete this code!
    KeyboardInput();
    bool guiActive = ShowFrameworkMenu();

    if (AEInputMousePressed(0)) {
        MouseEvent event;
        MousePositionData pos = AEGetMouseData();
        if (AEStaticPointToStaticRect(&pos.position, &buton.position, buton.size.x, buton.size.y))
            eventManager.Trigger(&event);
    }
}

void Level_1_Render()
{
    // clear frame buffer, do not delete this code
    AEGfxSetClearColor(AEGfxColor(0, 0, 0));
    AEGfxClearBuffer();

    buton.Draw();
}

void Level_1_Free()
{

}

void Level_1_Unload()
{
}

void KeyboardInput()
{
    if (AEInputKeyTriggered('R'))
        AESetGameStateNext(AE_GS_RESTART);
    if (AEInputKeyTriggered('Q') && AEInputKeyPressed(AE_KEY_CTRL))
        AESetGameStateNext(AE_GS_QUIT);
}

bool ShowFrameworkMenu()
{
    bool isGuiActive = false;
    mode = 0;

    // show File options 
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Mode")) {

            if (ImGui::MenuItem("Restart", "1"))
                mode = 1;

            ImGui::EndMenu();
        }

        auto mSize = ImGui::GetWindowHeight();
        AEVec2 mouseVP = AEGetMouseData().position + AEVec2((float)AEGetSysWindowWidth() / 2.0f, (float)AEGetSysWindowHeight() / 2.0f);
        auto inMenu = mouseVP.y >= (AEGetSysWindowHeight() - mSize);
        isGuiActive = ImGui::IsAnyItemActive() || ImGui::IsAnyItemHovered() || inMenu;

        ImGui::EndMainMenuBar();
    }

    if (mode == 1) {
        AESetGameStateNext(AE_GS_RESTART);
    }

    return isGuiActive;
}

