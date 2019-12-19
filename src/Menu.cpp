#include "Menu.h"
#include <iostream>
#include "MenuFuncs.h"
#include <sstream>

Menu::Menu(){

}

void Menu::StartMenu(){
    std::cout << "Welcome! What would you like to do?" << std::endl;
    std::cout << "1. Create New Character" << 
    std::endl << "2. Import an Old Character" << std::endl;

    int answer = getNum(2);
    
    bool done = false;

    while(!done){
        switch(answer){
            case 1:
                done = true;
                PlayerChar = CreateChar();
                break;
            case 2:
            {
                done = true;
                std::string filePath;
                std::cin >> filePath;
                //Character MyChar(filePath);

                
                //TODO: Import character file
            }
                break;
            default:
                std::cout << "Sorry, that wasn't a great answer! Please input 1 or 2." << std::endl;
                std::cin >> answer;
        }
    }

}

void Menu::MainMenu(){
    std::cout << "Main Menu" << std::endl;;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "| 1. Character                |" << 
    std::endl << "| 2. Moves                    |" << 
    std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    int answer = getNum(2);

    switch(answer){
        case 1:
            CharMenu();
            break;
        case 2:
            MovesMenu();
            break;
    }
}

void Menu::CharMenu(){
    PlayerChar.CharToString();

    std::cout << "Menu: " <<
    std::endl << "1. Roll Stat " <<
    std::endl << "2. Change Character Info" << 
    std::endl << "3. Update/Change Beliefs" <<
    std::endl << "4. Exit" << std::endl;

    int answer = getNum(4);

    switch(answer){
        case 1:
        {
            std::cout << "Which stat would you like to roll?" << std::endl;
            int roll = getNum(6);
            //PlayerChar.RollStat(roll);
        }
            break;
        case 2:
            //PlayerChar.ChangeInfo();
            break;
        case 3:
            //PlayerChar.ChangeInfo();
            break;
        case 4:
            MainMenu();        
            break;
    }
}

void Menu::MovesMenu(){
    PlayerChar.printFullMoves();

    std::cout << "Would you like to: " <<
    std::endl << "1. Roll" << 
    std::endl << "2. Details" <<
    std::endl << "3. Add" << 
    std::endl << "4. Back" << std::endl;

    int answer = getNum(4); 

    if(answer == 1){
        std::cout << "Which move would you like to roll?" << std::endl;
        int answer = getNum(PlayerChar.DMovesSize());
        std::cout << "Result: " << PlayerChar.rollMove(answer) << std::endl;
        MovesMenu();
    }
    else if(answer == 2){
        std::cout << "Which move would you like to view?" << std::endl;
        int move = getNum(PlayerChar.DMovesSize());
        PlayerChar.printSingleMove(move);
        std::cout << "What would you like to change?" << 
        std::endl << "1. Edit Name. " << 
        std::endl << "2. Edit Description" <<
        std::endl << "3. Edit Relevant Stat" <<
        std::endl << "4. Delete" << 
        std::endl << "5. Back" << std::endl;

        int answer = getNum(5);
        
        if(answer != 5){
            PlayerChar.editMove(move, answer);
        }   
        
        
        MovesMenu();
    }
    else if(answer == 3){
        std::string inName;
        std::cout << "Please input the name of your new move. " << std::endl;
        getline(std::cin >> std::ws, inName);
        std::cout << "Now, give a brief move description." << std::endl;
        std::string inDesc;
        getline(std::cin >> std::ws, inDesc);
        std::cout << "What stat should this move use as a modifier?" << std::endl;
        int whichStat = getNum(6);
        std::cout << "It thinks its: " << whichStat << std::endl;
        PlayerChar.addMove(whichStat, inName, inDesc);
        MovesMenu();
    }
    else if(answer == 4){
        MainMenu();
    }
    


}

Character Menu::CreateChar(){
    std::string playerName;
    std::string charName;
    std::string pronouns;

    std::vector< int > stats({0,0,0,0,0,0});
    std::vector<std::string> beliefs;

    std::cout << "Lets make a character!" << std::endl;

    std::cout << "First, what's YOUR name?" << std::endl;

    bool correct = false;
    std::string in;

    //do{
        std::cin >> playerName;

        std::cout << "Your name is: " << playerName << std::endl;
        /*std::cout << "Is this correct? Y/N" << std::endl;

        do{
        std::cin >> in;
            if(in == "N" || in == "n"){
                std::cout << "Ok! Please input the name you desire." << std::endl;
                break;
            }
            else if(in == "Y" || in == "y"){
                correct = true;
                break;
            }
            else{
                std::cout << "I'm sorry, '" << in << "' is not a valid input" << std::endl;
                std::cout << "Please input 'Y' if your name is correct, and 'N' if you would like to input a different name" << std::endl;
            }
        }while(!correct);
    }while(!correct);*/

    std::cout << "Lovely! Welcome, " << playerName << "." << std::endl;

    std::cout << "Now, lets get started on your character." << std::endl;

    /*std::cout << "Do you have a name in mind for your character? You may also set a name later. Y/N" << std::endl;
    correct = false;
    bool hasCharName = false;
    do{
        std::cin >> in;

        if(in == "N" || in == "n"){
            hasCharName = false;
            break;
        }
        else if(in == "Y" || in == "y"){
            hasCharName = true;
            break;
        }
        else{
            std::cout << "I'm sorry, '" << in << "' is not a valid input" << std::endl;
            std::cout << "Please input 'Y' if you have a name in mind, and 'N' if you would like to input a name later" << std::endl;
        }
    }while(1 == 1);*/

    //if(hasCharName){
        
        std::cout << "Please input your desired Character's name now." << std::endl;
        correct = false;
        //do{
            std::cin >> charName;

            std::cout << "Your Character's name is: " << charName << std::endl;
            /*std::cout << "Is this the name you'd like to go with? Y/N" << std::endl;

            do{
            std::cin >> in;
                if(in == "N" || in == "n"){
                    std::cout << "Please input another name" << std::endl;
                    break;
                }
                else if(in == "Y" || in == "y"){
                    correct = true;
                    break;
                }
                else{
                    std::cout << "I'm sorry, '" << in << "' is not a valid input" << std::endl;
                    std::cout << "Please input 'Y' if your name is correct, and 'N' if you would like to input a different name" << std::endl;
                }
            }while(!correct);
        }while(!correct);
    }*/

    std::cout << "What pronouns should I use for your character?" << std::endl;
    std::cin >> pronouns;


    Character myChar(playerName, charName, pronouns, stats);
    std::cout << "Now, the story begins." << std::endl << "You are about to awaken to find yourself with no memory, in a location unfamiliar to you." << std::endl << "Your job in this world is to survive long enough to figure out who you are, why you've lost your memories, and how to find your way out of here." << std::endl << "Before you wake, I'm going to ask you 10 questions. These questions will tell us both how you are disposed. Figuring out exactly who you were, of course, will be up to you." << std::endl << "Good luck, you're going to need it." << std::endl;
    
    int answer;

//Question 1
    std::cout << "Where did you find yourself most often?" << std::endl;
    std::cout << "1. In my room, hiding from the world." <<
    std::endl << "2. With my friends, maybe a party?" <<
    std::endl << "3. Work, the grind don't stop." <<
    std::endl << "4. In a tree, a creek, on a rock, anywhere I can see the sun and the stars." <<
    std::endl << "5. The gym, duh. Want to feel my biceps? ;)" << std::endl;

    answer = getNum(5);

    myChar.statManip(answer,
        {{1, 2, 4}, {2, 4, 6}, {2, 3, 4, 6}, {1, 2, 4, 5}},
        {{-1, 2, -1}, {-1, 2, -1}, {1, -1, -1, 1}, {2, 1, -1, -2}},
        {{4}, {4}, {5, 6}, {5, 6}},
        {{1}, {2}, {1, 2}, {2, 1}}
    );

//Question 2
    std::cout << "What did your peers think of you?" << std::endl;
    std::cout << "1. My ex said it best: hottest tits in the west." << 
    std::endl << "2. I'm like..a stain. Reliable. Consistent." <<
    std::endl << "3. A dick. But I mean, I think they meant a lovable one?" << 
    std::endl << "4. Peers? I prefer to think of them as my large children." <<
    std::endl << "5. Please don't talk to me." << std::endl;

    answer = getNum(5);

    myChar.statManip(answer,
    {{2, 3, 5, 6}, {2, 3, 6}, {4, 5, 6}, {2, 4, 5, 6}, {2, 4, 5, 6}},
    {{-1, 1, -1, 1}, {1, 1, -1}, {-2, 1, 2}, {-1, 2, -1, 1}, {2, -1, 1, -1}},
    {{1, 4, 5}, {1, 2, 5}, {1, 3}, {1, 2, 3, 5}, {1, 4, 6}},
    {{1, 2, 2}, {1, 2, 1}, {2, 1}, {2, 2, 2, 1}, {2, 1, 2}}
    );


    std::cout << "Who was your best friend?" << std::endl;
    std::cout << "1. I think my parole officer likes me." <<
    std::endl << "2. My mom!" <<
    std::endl << "3. The neighborhood cats follow me everywhere." <<
    std::endl; //<< "4. "

    answer = getNum(3);



    std::cout << "Knock Knock." << std::endl;
    std::cout << "1. Who's there!" <<
    std::endl << "2. Ow." << 
    std::endl << "3. Knock knock who?" <<
    std::endl << "4. Don't open the door, it's the cops." <<
    std::endl;

    answer = getNum(4);




 //   std::cout << "Someone taps on your car window in the middle of the night. What do you do?" << std::endl;
//Question 2
    std::cout << "When in danger, are you more likely to:" << std::endl;
    std::cout << "1. Fight." << 
    std::endl << "2. Flee." << 
    std::endl << "3. Freeze." << std::endl;

    answer = getNum(3);

    myChar.statManip(answer, 
    {{1, 2, 4}, {1, 3, 5}, {1, 2, 4, 6}}, 
    {{1, 1, -1}, {-1, 1, 1}, {-1, -1, 1, 1}}, 
    {{2, 3, 5}, {2, 3, 5}, {3, 5, 6}}, 
    {{1, 1, 1}, {2, 2, 1}, {2, 2, 2}}
    );


//Question 2
 /*   std::cout << "What is your most powerful quality?" << std::endl;
    std::cout << "1. I never give up." <<
    std::endl << "2. I can take a beating and keep on kicking" <<
    std::endl << "3. I'm no stranger to tragedy, my emotional resolve is unmatched" <<
    std::endl << "4. My friends, I'm nothing without them" <<
    std::endl << "5. I could survive anywhere, on anything." <<
    std::endl;

    answer = getNum(5);*/



//Question 10
    std::cout << "You wake in an unfamiliar location. What is the first thing you search for?"  << std::endl;
    std::cout << "1. A weapon." <<
    std::endl << "2. An ally." <<
    std::endl << "3. Food, water, shelter." << std::endl;

    answer = getNum(3);

    myChar.statManip(answer, 
    {{1, 2, 4}, {1, 3, 4, 6}, {2, 3, 6}}, 
    {{2, 1, -2}, {-2, 1, 1, 1}, {1, 1, -1}}, 
    {{1, 3}, {1, 3, 4}, {3, 5, 6}}, 
    {{1, 1}, {2, 2, 2}, {2, 1, 1}}
    );

    if(answer == 1){
        myChar.getItem("Rusty Knife");
    }
    else if(answer == 2){
        myChar.getItem("Chosen bond");
    }
    else if(answer == 3){
        myChar.getItem("Waterskin");
        myChar.getItem("Dried Rations: 2");
    }

    myChar.CharToString();

    return myChar;
}