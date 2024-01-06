#include <limits>
#include <iostream>
#include <vector>

// true = right, false = left

// Attempt to hop the frog at pos in a direction
bool Hop(std::vector<char>& Frog, int pos, bool direction);

// Attempt to slide the frog at pos in a direction
bool Slide(std::vector<char>& Frog, int pos, bool direction);

// Interactive Play
void IntPlay(std::vector<char>& Frogs, int& num_pairs);

// Computer play
void ComPlay(std::vector<char>& Frogs, int& num_pairs);

// Print out the frogs
void Froggies(std::vector<char>& Frogs);

int main() {
    std::cout << "Input number of Pairs of Frogs: ";
    int num_pairs;
    std::cin >> num_pairs;
    while (!std::cin) {
        std::cout << "Invalid input, try again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> num_pairs;
    }
    std::vector<char> Frogs(num_pairs * 2 + 1);

    // Frogs on the left
    for (int i = 0; i < num_pairs; i++) {
        Frogs[i] = 'X';
    }
    // starting middle empty spot
    Frogs[num_pairs] = ' ';

    // Frogs on the right
    for (int i = num_pairs + 1; i < Frogs.size(); i++) {
        Frogs[i] = 'O';
    }
    char c;
    std::cout << "Computer or Player [c] or [p]: ";
    std::cin >> c;

    // Interactive play
    if (c == 'p') {
        IntPlay(Frogs, num_pairs);
    }

    // Computer Play
    if (c == 'c') {
        ComPlay(Frogs, num_pairs);
    }

}

// left = false, right = true
void ComPlay(std::vector<char>& Frogs, int& num_pairs) {
    int moves = 0;
    // start in left direction
    bool direction = false;
    int empty_spot = num_pairs;
    Froggies(Frogs);

    for (int i = 0; i < num_pairs; i++) {
        //slide
        moves++;
        std::cout << "Slide";
        if (direction == false) {
            Slide(Frogs, empty_spot+1, false);
            empty_spot++;
            std::cout << " left" << std::endl;
        } else {
            Slide(Frogs, empty_spot-1, true);
            empty_spot--;
            std::cout << " right" << std::endl;
        }
        Froggies(Frogs);
        direction = !direction;
        for (int j = 0; j <= i; j++) {
            std::cout << "Hop";
            //hop
            moves++;
            if (direction == true) {
                Hop(Frogs, empty_spot-2, true);
                empty_spot-=2;
                std::cout << " right" << std::endl;
            } else {
                Hop(Frogs, empty_spot+2, false);
                empty_spot+=2;
                std::cout << " left" << std::endl;
            }
            Froggies(Frogs);
        }
       
    }

    for (int i = 0; i < num_pairs; i++) {
        direction = !direction;
        //slide
        moves++;
        std::cout << "Slide";
        if (direction == false) {
            Slide(Frogs, empty_spot+1, false);
            empty_spot++;
            std::cout << " left" << std::endl;
        } else {
            Slide(Frogs, empty_spot-1, true);
            empty_spot--;
            std::cout << " right" << std::endl;
        }
        Froggies(Frogs);
       
        for (int j = 0; j < num_pairs-i-1; j++) {
            std::cout << "Hop";
            //hop
            moves++;
            if (direction == true) {
                Hop(Frogs, empty_spot-2, true);
                empty_spot-=2;
                std::cout << " right" << std::endl;
            } else {
                Hop(Frogs, empty_spot+2, false);
                empty_spot+=2;
                std::cout << " left" << std::endl;
            }
            Froggies(Frogs);
        }
    }
    std::cout << "Completed in " << moves << " moves" << std::endl;
}

void IntPlay(std::vector<char>& Frogs, int& num_pairs) {
    int num_moves = 0;
     while (true) {
        Froggies(Frogs);
        std::cout << "Moves: " << num_moves <<std::endl;
        std::cout << "Choose which frog to move: ";
        int pos;
        std::cin >> pos;
        while (!std::cin) {
        std::cout << "Invalid input, try again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> pos;
    }
        pos--;
        bool temp = false;
        temp = Hop(Frogs, pos, true);
        if (!temp) {
            temp = Hop(Frogs, pos, false);
        }
        if (!temp) {
            temp = Slide(Frogs, pos, true);
        }
        if (!temp) {
            Slide(Frogs, pos, false);
        }
        num_moves++;
        bool win = true;
        for (int i = 0; i < num_pairs; i++) {
            if (Frogs[i] != 'O') {
                win = false;
            }
        }
        for (int i = num_pairs+1; i < Frogs.size(); i++) {
            if (Frogs[i] != 'X') {
                win = false;
            }
        }
        if (win) {
            Froggies(Frogs);
            std::cout << "You Won in " << num_moves << " moves!!" << std::endl;
            break;
        }

    }
}
void Froggies(std::vector<char>& Frogs) {
    for (int i = 0; i < Frogs.size(); i++) {
        std::cout << i+1 << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < Frogs.size(); i++) {
        std::cout << Frogs[i] << " ";
    }
    std::cout << std::endl;
}

// Hop() returns true if valid hop and does the hop, false if invalid
// direction: true for right, false for left
bool Hop(std::vector<char>& Frog, int pos, bool direction) {
    // Attempt to hop to the right
    if (direction) {
        // position is at end of line or 1 before end of line
        if (pos == Frog.size() - 1 || pos == Frog.size() - 2) {
            return false;
        }
        // There is a frog in front of it and there is no frog behind that frog
        if (Frog[pos+1] != ' ' && Frog[pos+2] == ' ') {
            // Do the hop to the right
            Frog[pos+2] = Frog[pos];
            Frog[pos] = ' ';
            return true;
        }
        return false;
    }
    if (pos == 0 || pos == 1) {
        return false;
    }
    if (Frog[pos-1] != ' ' && Frog[pos-2] == ' ') {
        Frog[pos-2] = Frog[pos];
        Frog[pos] = ' ';
        return true;
    }
    return false;
}

// Attempts to slide Frog at pos in a direction
// true = right, false = left
bool Slide(std::vector<char>& Frog, int pos, bool direction) {
    // attempt to slide right
    if (direction) {
        if (pos == Frog.size() - 1) {
            return false;
        }
        if (Frog[pos+1] == ' ') {
            Frog[pos+1] = Frog[pos];
            Frog[pos] = ' ';
            return true;
        }
        return false;
    }
    if (pos == 0) {
        return false;
    }
    if (Frog[pos-1] == ' ') {
        Frog[pos-1] = Frog[pos];
        Frog[pos] = ' ';
        return true;
    }
    return false;
}
