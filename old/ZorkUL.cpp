#include <iostream>
#include <vector>

using namespace std;
#include "ZorkUL.h"

int main(int argc, char argv[]) {
    ZorkUL temp;
    temp.play();
    return 0;
}

ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {

    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;

    a = new Room("your house");
        a->addItem(new Item("x", 1, 11));
        a->addItem(new Item("y", 2, 22));
    b = new Room("your car");
        b->addItem(new Item("xx", 3, 33));
        b->addItem(new Item("yy", 4, 44));
    c = new Room("cave entrance");
    d = new Room("upper mine");
    e = new Room("lower mine");
    f = new Room("stairs");
    g = new Room("hall way");
    h = new Room("end of hall");
    i = new Room("glass room");

    //rooms I added
    j = new Room("ruined castle");
    k = new Room("portal home");
    l = new Room("gleaming table");
    m = new Room("wooden table");

//             (N, E, S, W)
    a->setExits(NULL, b, c, NULL );
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(a, NULL, NULL, d);
    d->setExits(NULL, c , e, NULL);
    e->setExits(d, f, NULL, NULL);
    f->setExits(c, g, NULL, e);
    g->setExits(NULL, h, NULL, f);
    h->setExits(j, NULL, i, g);
    i->setExits(h, NULL, NULL, NULL);

    //Rooms i added
    j->setExits(l, m, h, k);
    k->setExits(NULL, j, NULL, NULL);
    l->setExits(NULL, NULL, j, NULL);
    m->setExits(NULL, NULL, NULL, j);
    currentRoom = a;

    rooms.push_back(*a); // this puts the rooms into a vector for my teleport functions
    rooms.push_back(*b);
    rooms.push_back(*c);
    rooms.push_back(*d);
    rooms.push_back(*e);
    rooms.push_back(*f);
    rooms.push_back(*g);
    rooms.push_back(*h);
    rooms.push_back(*i);
    rooms.push_back(*j);
    rooms.push_back(*k);
    rooms.push_back(*l);
    rooms.push_back(*m);
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

void ZorkUL::printWelcome() {
	cout << "start"<< endl;
	cout << "info for help"<< endl;
	cout << endl;
	cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "      [a]---[b]   [k]" << endl;
        cout << "       |           |" << endl;
        cout << "[d]---[c]   [l]---[j]---[m]" << endl;
        cout << " |     |!          |" << endl;
        cout << "[e]---[f]---[g]---[h]" << endl;
        cout << "                   |" << endl;
        cout << "                  [i]" << endl;
        /*
        cout << "symbol key:" << endl;
        cout << "-:bidirectional" << endl;
        cout << "!| or |!: one directional" << endl;*/
        string key1 = "symbol key: \n";
        string key2 = "- or |:bidirectional \n";
        string key3 = "!- or -!, !| or |!: one directional \n";
        string totalKey = key1 + key2 + key3;
        cout << totalKey << endl;

		}

    else if (commandWord.compare("go") == 0)
        goRoom(command);
    else if (commandWord.compare("randomteleport") == 0)
        randTeleport();

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
string ZorkUL::randTeleport(){
    currentRoom = &rooms.at((int) rand() % rooms.size());
    cout << currentRoom->longDescription() << endl;
    return ""; // I've no clue why this works, but it does, if this isn't here it wont output the room description
}

