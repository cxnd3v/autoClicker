#include <stdio.h>
#include <windows.h>

//Função para clicar com o botão esquerdo
void LeftClick(int x, int y) {
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
}

void main() {
    POINT cursorPos;

    do {
        if (GetKeyState(VK_CAPITAL)) { // Verifica se o caps lock está ativado
            printf("Autoclicker iniciado\n");
            do {
                GetCursorPos(&cursorPos);
                LeftClick(cursorPos.x, cursorPos.y);

                if (GetKeyState(VK_END)) break; // Verifica se o usuário clicou na tecla "END" para parar a execução
            } while (GetKeyState(VK_CAPITAL));
            printf("Autoclicker parado\n");
        }
    } while (!GetKeyState(VK_END));
}
