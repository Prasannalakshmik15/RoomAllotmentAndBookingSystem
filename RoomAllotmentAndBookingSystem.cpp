#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

static int p = 0;

class Room {
public:
    char roomNo[5];
    char host[10];
    char start[5];
    char end[5];
    char from[10];
    char to[10];
    char chair[8][4][10];

    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);
};

Room rooms[10];

void vline(char ch) {
    for (int i = 0; i < 80; i++)
        cout << ch;
    cout << endl;
}

void Room::install() {
    cout << "Enter Room no: ";
    cin >> rooms[p].roomNo;

    cout << "Enter Host's name: ";
    cin >> rooms[p].host;

    cout << "Start time: ";
    cin >> rooms[p].start;

    cout << "Session Ends at: ";
    cin >> rooms[p].end;

    cout << "From: ";
    cin >> rooms[p].from;

    cout << "To: ";
    cin >> rooms[p].to;

    rooms[p].empty();
    p++;
}

void Room::allotment() {
    int chairNumber;
    char roomNumber[5];

top:
    cout << "Room no: ";
    cin >> roomNumber;

    int n;
    for (n = 0; n < p; n++) {
        if (strcmp(rooms[n].roomNo, roomNumber) == 0)
            break;
    }

    if (n == p) {
        cout << "Enter correct Room no.\n";
        goto top;
    }

    while (true) {
        cout << "Chair Number: ";
        cin >> chairNumber;

        if (chairNumber < 1 || chairNumber > 32) {
            cout << "There are only 32 Chairs available in this Room.\n";
        }
        else {
            int row = (chairNumber - 1) / 4;
            int col = (chairNumber - 1) % 4;
            if (strcmp(rooms[n].chair[row][col], "Empty") == 0) {
                cout << "Enter occupant's name: ";
                cin >> rooms[n].chair[row][col];
                break;
            }
            else {
                cout << "The Chair no. is already reserved.\n";
            }
        }
    }
}

void Room::empty() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            strcpy_s(rooms[p].chair[i][j], "Empty");
        }
    }
}

void Room::show() {
    int n;
    char roomNumber[5];
    cout << "Enter Room no: ";
    cin >> roomNumber;

    for (n = 0; n < p; n++) {
        if (strcmp(rooms[n].roomNo, roomNumber) == 0)
            break;
    }

    if (n == p) {
        cout << "Enter correct Room no.\n";
        return;
    }

    vline('*');
    cout << "Room no: \t" << rooms[n].roomNo
        << "\nHost: \t" << rooms[n].host
        << "\tStart time: \t" << rooms[n].start
        << "\tEnd time: \t" << rooms[n].end
        << "\nFrom: \t" << rooms[n].from
        << "\tTo: \t" << rooms[n].to << "\n";
    vline('*');
    rooms[n].position(n);

    int a = 1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            if (strcmp(rooms[n].chair[i][j], "Empty") != 0) {
                cout << "The Chair no " << a << " is reserved for " << rooms[n].chair[i][j] << ".\n";
            }
            a++;
        }
    }
}

void Room::position(int l) {
    int s = 0;
    for (int i = 0; i < 8; i++) {
        cout << "\n";
        for (int j = 0; j < 4; j++) {
            s++;
            if (strcmp(rooms[l].chair[i][j], "Empty") == 0) {
                cout.width(5);
                cout.fill(' ');
                cout << s;
                cout.width(10);
                cout.fill(' ');
                cout << "Empty";
            }
            else {
                cout.width(5);
                cout.fill(' ');
                cout << s;
                cout.width(10);
                cout.fill(' ');
                cout << rooms[l].chair[i][j];
            }
        }
    }
}

void Room::avail() {
    for (int n = 0; n < p; n++) {
        vline('*');
        cout << "Room no: \t" << rooms[n].roomNo
            << "\nHost: \t" << rooms[n].host
            << "\tStart time: \t" << rooms[n].start
            << "\tEnd time: \t" << rooms[n].end
            << "\nFrom: \t" << rooms[n].from
            << "\tTo: \t" << rooms[n].to << "\n";
        vline('*');
    }
}

int main() {
    system("cls");
    int w;
    while (1) {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t1. Install\n";
        cout << "\t\t\t2. Reservation\n";
        cout << "\t\t\t3. Show\n";
        cout << "\t\t\t4. Rooms Available\n";
        cout << "\t\t\t5. Exit\n";
        cout << "\t\t\tEnter your choice:-> ";
        cin >> w;

        switch (w) {
        case 1:
            rooms[p].install();
            break;
        case 2:
            rooms[p].allotment();
            break;
        case 3:
            rooms[0].show();
            break;
        case 4:
            rooms[0].avail();
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}
