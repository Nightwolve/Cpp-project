#include "thegame.h"

using namespace std;

void Thegame::tryLetters()// De implementatie van het raden van de letters in een reeks van verborgen letters
{
    int loop=1;
    char letter;
    int showncounter=0;

    for(int i=0; i<(int)response.length(); i++)
    {
        if(isalnum(response[i]))//controleert of de locatie van een string een nummer of letter is en verandert het naar een "-"
        {
            shown=shown+"-";
            showncounter++;
        }
        else
        {
            shown=shown+response[i];// Als het een leesteken is, laten staan en niet verbergen
        }
    }
    cout<<shown<<endl;

    cout<<"Welke letter denk je dat in het woord staat?"<<endl;
    cin>>letter;

    for(int b=0; b<(int)response.size(); b++)
    {
        if(response[b]==letter || toupper(letter)==response[b])
        {
            shown[b]=letter;
        }

    }

    cout<<shown<<endl;
    cout<<"Je hebt nog "<<tries<<" pogingen over."<<endl;
    while(loop)
    {
        int tracker=0;// Houd pogingen in de gaten voor het tekenen van Hangman
        int showntracker=0;//Geeft kansen weer om game te kunnen winnen

        cout<<"Welke letter denk je dat er nog in het woord staat? Gebruik (?) om het spel te stoppen."<<endl;
        cin>>letter;

        if(letter=='?')
        {
            break;
        }
        for(int b=0; b<(int)response.size(); b++)
        {
            if(response[b]==letter || toupper(letter)==response[b])
            {
                shown[b]=letter;
                tracker=1;
            }
            else if(response[b]!=letter || response[b]!=toupper(letter))//Herhaling van controle om zeker te zijn van ongewenste dingen
            {
                tracker=tracker+0;
            }
        }

        for(int d=0; d<showncounter; d++)
        {
            if(shown[d]=='-' || shown[d]==' ')
            {
                showntracker=1;
            }
            else if(shown[d]!='-')
            {
                showntracker=showntracker+0;
            }
        }

        if(tracker==0)
        {
            addTries();
            hangmandrawing();
        }

        if(showntracker==0 || shown==response)
        {
            loop=0;
            cout<<"Geheim woord: "<<response<<endl;
            cout<<"--------------------------------------"<<endl;
            cout<<"PROFICIAT JE HEBT HET WOORD GERADEN!!!"<<endl;
            cout<<"--------------------------------------"<<endl;
            cout<<endl;
            cout<<"<< MENU >>"<<endl;
            resetword();
        }
        cout<<shown<<endl;

        if(tries>0 && showntracker!=0 && shown!=response)
        {
            cout<<"Je hebt nog "<<tries<<" pogingen."<<endl;
            cout<<endl;
            cout<<endl;
        }
        if(tries==0)
        {
            loop=0;
            cout<<"Sorry, Je bent verloren :("<<endl;
            cout<<"Het woord dat we zochten was: "<<response<<endl;
            cout<<"Probeer gerust opnieuw!"<<endl;
            cout<<endl;
            cout<<"<< MENU >>"<<endl;
            resetword();
            cout<<endl;
        }

    }
}


void Thegame::storetheword(string x)// plaatst geheim woord in privé variabele
{
    response=x;
}


Thegame::Thegame()
{}

Thegame::~Thegame()//Functie slaat laatst gekozen woord op in een .txt file
{
    QFile file(fileLocation);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    //out << "The last word was: " + usersWord;
    file.close();

    delete obj;
}

void Thegame::game()
{
    Thegame obj;
    while(ans=='n' || ans=='N')
    {
        cout << "Hallo "+ this->name().toStdString() +", welkom bij galgje!" << endl;
        cout<<endl;
        cout<<"Instructies:"<<endl;
        cout<<endl;
        cout<<"1 Speler voert een woord en onderwerp in, een"<<endl;
        cout<<"Wanneer speler1 klaar is selecteer je optie 4: Start Spel"<<endl;
        cout<<"Probeer zo veel mogelijk letters van het woord te raden, bij een foute gok wordt er een streepje bij de galg getekend"<<endl;
        cout<<"Je hebt 7 kansen"<<endl;
        cout<<"Veel Succes"<<endl;
        cout<<endl;
        cout<<"Klik op een toets om verder te gaan en het menu te openen"<<endl;
        cin>>ans;
        system("CLS");
    }
    while(loop)
    {

        cout<<"***************************"<<endl;
        cout<<"1)Voer een woord in         *"<<endl;
        cout<<"2)Voer een onderwerp in     *"<<endl;
        cout<<"3)Bekijk het onderwerp      *"<<endl;
        cout<<"4)Begin met raden           *"<<endl;
        cout<<"5)Spel resetten             *"<<endl;
        cout<<"6)Spel stoppen              *"<<endl;
        cout<<"***************************"<<endl;
        cout<<"Wat is uw keuze? Voer getal in: >";
        cin >> choice;

        if(choice==1)
        {
            HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
            DWORD mode = 0;
            GetConsoleMode(hStdin, &mode);
            SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
            cout << "Typ het geheime woord in:" << endl;
            cin.ignore();
            getline(cin,usersWord);
            SetConsoleMode(hStdin, mode);
            obj.storetheword(usersWord);
            cout<<"GEHEIM WOORD SUCCESVOL OPGESLAGEN"<<endl;
            cout<<endl;
            cout<<endl;
        }

        else if(choice==2)
        {
            cout<<"Voer een onderwerp in voor de speler die moet raden. Dit is een hulpmiddel."<<endl;
            cin.ignore();
            getline(cin,topic);
            cout<<endl;
            cout<<endl;
        }
        else if(choice==3)
        {
            cout<<"Het onderwerp is:"<<topic<<endl;
            cout<<"------------------------------"<<endl;
            cout<<endl;
            cout<<endl;

        }
        else if(choice==4)
        {
            obj.tryLetters();
        }
        else if(choice==5)
        {
            obj.resetword();
            cout<<"Alles is succesvol gereset!"<<endl;
            cout<<endl;
            cout<<endl;
        }
        else if(choice==6)
        {
            cout<<"Bedankt voor het spelen!"<<endl;
            cout<<"Peace out!!"<<endl;
            loop=0;
        }
        else if(choice != 1 && choice != 2  && choice != 3  && choice != 4  && choice != 5  && choice != 6)
        {
          loop=0;

          cout<<"You have entered something wrong, please restart"<<endl;

        }

    }
}

void Thegame::resetword()// Reset het woord en het aantal kansen
{
    response="";
    shown="";
    tries=7;
}




void Thegame::addTries()//Functie geeft aantal kansen weer
{
    tries--;
}

QString Thegame::getName()
{
    int counter = 0;
    srand(time(NULL)); // pakt random waarde, moet erbij staan! anders werkt rand() niet
    int number = rand() % 3; // random getal 1-3 voor naam

    list<players*> playerlist;//container class
       playerlist.push_back(new playerone()); //player 1 naam
       playerlist.push_back(new playertwo()); //player 2 naam
       playerlist.push_back(new playerthree()); //player 3 naam

    for (auto i :  playerlist) {
        if(counter == number){
          return (i->playerName()); //wanneer counter overeenkomt met nummer, dan wordt adress van header mee te geven
        }
        counter ++;
    }
    return "name";
}

void Thegame::hangmandrawing()//Functie voor het tekenen van Hangman
{
    if(tries==6 || tries == maxTries)
    {   cout << "Foute gok!"<<endl;
        cout << " ___________"<<endl;
        cout << " |        }"<<endl;
        cout << " |         " <<endl;
        cout << " |         "<<endl;
        cout << " |         "<<endl;
        cout << "_|______________"<<endl;
    }
    else if(tries==5)
    {
        cout << "Foute gok!"<<endl;
        cout << " ___________"<<endl;
        cout << " |        }"<<endl;
        cout << " |       \\  " <<endl;
        cout << " |         "<<endl;
        cout << " |         "<<endl;
        cout << "_|______________"<<endl;
    }
    else if(tries==4)
    {
        cout << "Foute gok!"<<endl;
        cout << " ___________"<<endl;
        cout << " |         }"<<endl;
        cout << " |       \\ 0 " <<endl;
        cout << " |         "<<endl;
        cout << " |         "<<endl;
        cout << "_|______________"<<endl;
    }
    else if(tries==3)
    {
        cout << "Foute gok!"<<endl;
        cout << " ___________"<<endl;
        cout << " |         }"<<endl;
        cout << " |       \\ 0 /" <<endl;
        cout << " |         "<<endl;
        cout << " |         "<<endl;
        cout << "_|______________"<<endl;
    }
    else if(tries==2)
    {
        cout << "Foute gok!"<<endl;
        cout << " ___________"<<endl;
        cout << " |        }"<<endl;
        cout << " |      \\ 0 /" <<endl;
        cout << " |        |"<<endl;
        cout << " |         "<<endl;
        cout << "_|______________"<<endl;
    }
    else if(tries==1)
    {
        cout << "Foute gok!"<<endl;
        cout << " ___________"<<endl;
        cout << " |         }"<<endl;
        cout << " |       \\ 0 /"<<endl;
        cout << " |         | "<<endl;
        cout << " |        /  "<<endl;
        cout << "_|______________"<<endl;
    }
    else
    {
        cout << "Jammer maar helaas! Weer een foute gok!"<<endl;
        cout << " ___________"<<endl;
        cout << " |         }"<<endl;
        cout << " |       \\ 0 /"<<endl;
        cout << " |         | "<<endl;
        cout << " |        / \\ "<<endl;
        cout << "_|______________"<<endl;
    }
}



