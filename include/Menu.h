#include "Character.h"


class Menu {
    private:
        Character PlayerChar;
    
    public:
        Menu();

        void StartMenu();
        Character CreateChar();
        void MainMenu();
        void CharMenu();
        void ChangeCharInfo();
        void ChangeBeliefs();

        void MovesMenu();

        void InjuriesMenu();
        void BackgroundMenu();

};