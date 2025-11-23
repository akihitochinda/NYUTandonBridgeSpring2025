/*
Homework 13: Doodlebug
    CH16# 9: The goal for this Project is to create a simple two-dimensional predator-prey
simulation. In this simulation the prey are ants and the predators are doodlebugs.
These critters live in a world composed of a 20 × 20 grid of cells. Only one critter
may occupy a cell at a time. The grid is enclosed, so a critter is not allowed to move
off the edges of the world. Time is simulated in time steps. Each critter performs
some action every time step.

The ants behave according to the following model:

Move: Every time step, randomly try to move up, down, left, or right. If the neighboring cell in the
selected direction is occupied or would move the ant off the grid, then the ant stays in the
current cell.
Breed: If an ant survives for three time steps, then at the end of the time step (that is; after
moving) the ant will breed. This is simulated by creating a new ant in an adjacent (up, down, left,
or right) cell that is empty. If there is no empty cell available, then no breeding occurs. Once an
off-spring is produced, an ant cannot produce an offspring until three more time steps have
elapsed.

The doodlebugs behave according to the following model:

Move: Every time step, if there is an adjacent ant (up, down, left, or right), then the doodlebug
will move to that cell and eat the ant. Otherwise, the doodlebug moves according to the same
rules as the ant. Note that a doodlebug cannot eat other doodlebugs.
Breed: If a doodlebug survives for eight time steps, then at the end of the time step it will spawn
off a new doodlebug in the same manner as the ant.
Starve: If a doodlebug has not eaten an ant within the last three time steps, then at the end of
the third time step it will starve and die. The doodlebug should then be removed from the grid of
cells.

During one turn, all the doodlebugs should move before the ants do.

Write a program to implement this simulation and draw the world using ASCII characters of “o”
for an ant and “X” for a doodlebug or "-" for an empty space. Create a class named Organism
that encapsulates basic data common to both ants and doodlebugs. This class should have a
virtual function named move that is defined in the derived classes of Ant and Doodlebug. You
may need additional data structures to keep track of which critters have moved.

Your task: Initialize the world with 5 doodlebugs and 100 ants. After each time step, prompt the
user to press Enter to move to the next time step. You should see a cyclical pattern between the
population of predators and prey, although random perturbations may lead to the elimination of
one or both species. Please submit a single .cpp; do NOT separate this into multiple .h files.
The .cpp should contain all classes and structures needed so that it can execute when running
the main function.

An example of a program timestep output is given below. It does not need to look exactly like
this but this can be a good starting point if you are confused.

World at time 0:

o - o o o o o - - o - - - - - o o - o o
- - - - o - - o X - - - - o - - o - - -
- - - - - - - o o - o - - - o - o - o -
- - - - - o - - o - - - - - - - - - - -
- o - - - - - o - - - o - - - - - - o -
- - - - - - - o o - - o o o o - - - - -
- - - o o - - - o - - - - o - - - - - -
- - - - - - - X - o - o - - - - o - o -
- - - - - - - o - - o - o o - - - - - -
- - - o - - - - - - - o o - - - - - - X
- - - - o - - - o o - o - o - - - - - -
- - - - - - - - - o - - - - o - - - - -
o - - - - - - - o - - - - - - - - - - -
- o - o - - - o - - o - X - - - - - - -
o o - o - o - o - - o - - o - o - o o o
- - - o - - o - - o - o - o - - o - - o
o - - - - - - - - - o - - o - - - - - o
o - - o - - o o - o o - - - - - - - - o
- - o - - - X o - - - - - - o - - o o o
- o - - o o o - - - - - - - - - - - - -

Press ENTER to continiue
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Organism {
protected:
    int x, y; // Position on the grid
    int age;  // Age of the organism
    bool moved; // Flag to check if the organism has moved this turn
public:
    Organism(int x, int y) : x(x), y(y), age(0), moved(false) {}
    virtual ~Organism() {}

    // Pure virtual functions to be implemented by derived classes
    virtual void move(vector<vector<Organism*>>& grid) = 0;
    virtual void breed(vector<vector<Organism*>>& grid) = 0;
    virtual char display() const = 0;

    // Utility functions for all organisms
    void incrementAge() { age++; }
    int getAge() const { return age; }
    void setMoved(bool m) { moved = m; }
    bool hasMoved() const { return moved; }
    int getX() const { return x; }
    int getY() const { return y; }
    void setPosition(int newX, int newY) {
        x = newX;
        y = newY;
    }
};

class Ant : public Organism {
public:
    Ant(int x, int y) : Organism(x, y) {}

    // Ant move: randomly try to move to an adjacent empty cell (up/down/left/right)
    void move(vector<vector<Organism*>>& grid) override {
        vector<pair<int, int>> emptyCells;
        // Check all 4 directions for empty cells
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) + abs(dy) == 1) { // Only consider orthogonal moves
                    int newX = x + dx;
                    int newY = y + dy;
                    // Check if the new position is within bounds and empty and stay within the grid
                    if (newX >= 0 && newY >= 0 && newX < grid[0].size() && newY < grid.size()) {
                        if (grid[newY][newX] == nullptr) {
                            emptyCells.push_back({newX, newY});
                        }
                    }
                }
            }
        }
        // If there are empty cells, move to a random empty cell
        if (!emptyCells.empty()) {
            int idx = rand() % emptyCells.size();
            int newX = emptyCells[idx].first;
            int newY = emptyCells[idx].second;
            grid[newY][newX] = this;
            grid[y][x] = nullptr;
            setPosition(newX, newY);
        }
    }

    // Ant breed: after 3 steps, create a new ant in an adjacent empty cell
    void breed(vector<vector<Organism*>>& grid) override {
        if (getAge() >= 3) {
            vector<pair<int, int>> emptyCells;
            // Check all 4 directions for empty cells
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (abs(dx) + abs(dy) == 1) {
                        int newX = x + dx;
                        int newY = y + dy;
                        if (newX >= 0 && newY >= 0 && newX < grid[0].size() && newY < grid.size()) {
                            if (grid[newY][newX] == nullptr) {
                                emptyCells.push_back({newX, newY});
                            }
                        }
                    }
                }
            }
            // If there are empty cells, breed by creating a new ant
            if (!emptyCells.empty()) {
                int idx = rand() % emptyCells.size();
                int newX = emptyCells[idx].first;
                int newY = emptyCells[idx].second;
                grid[newY][newX] = new Ant(newX, newY);
                age = 0; // Reset age after breeding
            }
        }
    }

    // Display character for ant
    char display() const override {
        return 'o';
    }
};

class Doodlebug : public Organism {
private:
    int hunger; // Hunger counter for doodlebug
    bool ateThisTurn; // Flag to check if doodlebug ate this turn
public:
    Doodlebug(int x, int y) : Organism(x, y), hunger(0), ateThisTurn(false) {} // Add ateThisTurn init

    // Doodlebug move: try to eat adjacent ant, else move like an ant
    void move(vector<vector<Organism*>>& grid) override {
        ateThisTurn = false; // Reset ateThisTurn at the start of each move
        // Try to eat adjacent ant
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) + abs(dy) == 1) {
                    int newX = x + dx;
                    int newY = y + dy;
                    if (newX >= 0 && newY >= 0 && newX < grid[0].size() && newY < grid.size()) {
                        if (grid[newY][newX] && dynamic_cast<Ant*>(grid[newY][newX])) {
                            delete grid[newY][newX]; // Eat the ant
                            grid[newY][newX] = this;
                            grid[y][x] = nullptr;
                            setPosition(newX, newY);
                            ateThisTurn = true; // Mark that the doodlebug has eaten
                            return; // Exit after eating an ant
                        }
                    }
                }
            }
        }
        // If no ant eaten, move to random empty cell (like an ant)
        vector<pair<int, int>> emptyCells;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) + abs(dy) == 1) {
                    int newX = x + dx;
                    int newY = y + dy;
                    if (newX >= 0 && newY >= 0 && newX < grid[0].size() && newY < grid.size()) {
                        if (grid[newY][newX] == nullptr) {
                            emptyCells.push_back({newX, newY});
                        }
                    }
                }
            }
        }
        if (!emptyCells.empty()) {
            int idx = rand() % emptyCells.size();
            int newX = emptyCells[idx].first;
            int newY = emptyCells[idx].second;
            grid[newY][newX] = this;
            grid[y][x] = nullptr;
            setPosition(newX, newY);
        }
    }

    // Doodlebug breed: after 8 steps, create a new doodlebug in an adjacent empty cell
    void breed(vector<vector<Organism*>>& grid) override {
        if (getAge() >= 8) {
            vector<pair<int, int>> emptyCells;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (abs(dx) + abs(dy) == 1) {
                        int newX = x + dx;
                        int newY = y + dy;
                        if (newX >= 0 && newY >= 0 && newX < grid[0].size() && newY < grid.size()) {
                            if (grid[newY][newX] == nullptr) {
                                emptyCells.push_back({newX, newY});
                            }
                        }
                    }
                }
            }
            if (!emptyCells.empty()) {
                int idx = rand() % emptyCells.size();
                int newX = emptyCells[idx].first;
                int newY = emptyCells[idx].second;
                grid[newY][newX] = new Doodlebug(newX, newY);
                age = 0; // Reset age after breeding
            }
        }
    }

    // Display character for doodlebug
    char display() const override {
        return 'X';
    }

    // Hunger/Starvation logic
    void incrementHunger() { hunger++; }
    void resetHunger() { hunger = 0; }
    int getHunger() const { return hunger; }
    bool hasEaten() const { return ateThisTurn; }
    void setHasEaten(bool ate) { ateThisTurn = ate; }
};

class World {
private:
    vector<vector<Organism*>> grid; // 2D grid to hold organisms
    int width, height; // Dimensions of the grid
public:
    World(int width = 20, int height = 20) : width(width), height
(height) {
        grid.resize(height, vector<Organism*>(width, nullptr));
        initializeWorld();
    }
    ~World() {
        // Clean up dynamically allocated organisms
        for (auto& row : grid) {
            for (auto& org : row) {
                delete org;
            }
        }
    }

    // Place 5 doodlebugs and 100 ants randomly in the grid
    void initializeWorld() {
        srand(static_cast<unsigned int>(time(0)));
        for (int i = 0; i < 5; i++) {
            placeOrganism(new Doodlebug(rand() % width, rand() % height));
        }
        for (int i = 0; i < 100; i++) {
            placeOrganism(new Ant(rand() % width, rand() % height));
        }
    }

    // Helper to place an organism in a random empty cell
    void placeOrganism(Organism* org) {
        int x, y;
        do {
            x = rand() % width;
            y = rand() % height;
        } while (grid[y][x] != nullptr); // Find an empty cell
        grid[y][x] = org;
        org->setPosition(x, y);
    }

    // Display the grid
    void display() const {
        for (const auto& row : grid) {
            for (const auto& org : row) {
                if (org) {
                    cout << org->display() << " ";
                } else {
                    cout << "- ";
                }
            }
            cout << endl;
        }
    }

    // Simulate one step in the world
    void simulate_step() {
    // Move all doodlebugs first
    vector<Organism*> doodlebugs;
    for (int y = 0; y < grid.size(); y++)
        for (int x = 0; x < grid[y].size(); x++)
            if (grid[y][x] && grid[y][x]->display() == 'X')
                doodlebugs.push_back(grid[y][x]);
    for (auto* db : doodlebugs)
        if (db && !db->hasMoved())
            db->move(grid), db->setMoved(true);

    // Move all ants
    vector<Organism*> ants;
    for (int y = 0; y < grid.size(); y++)
        for (int x = 0; x < grid[y].size(); x++)
            if (grid[y][x] && grid[y][x]->display() == 'o')
                ants.push_back(grid[y][x]);
    for (auto* ant : ants)
        if (ant && !ant->hasMoved())
            ant->move(grid), ant->setMoved(true);

    // Reset moved flag and increment age for all organisms
    for (int y = 0; y < grid.size(); y++)
        for (int x = 0; x < grid[y].size(); x++)
            if (grid[y][x]) {
                grid[y][x]->setMoved(false);
                grid[y][x]->incrementAge();
            }

    // Breed doodlebugs
    for (auto* db : doodlebugs)
        if (db)
            db->breed(grid);

    // Breed ants
    for (auto* ant : ants)
        if (ant)
            ant->breed(grid);

        // Handle starvation for doodlebugs
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[y].size(); x++) {
                Doodlebug* db = dynamic_cast<Doodlebug*>(grid[y][x]);
                if (db) {
                    if (!db->hasEaten()) {
                        db->incrementHunger();
                    } else {
                        db->resetHunger();
                        db->setHasEaten(false);
                    }
                    if (db->getHunger() > 3) {
                        delete grid[y][x];
                        grid[y][x] = nullptr; // Remove starved doodlebug
                    }
                }
            }
        }
        /* (Optional) Clean up empty cells (not needed, just for clarity)
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[y].size(); x++) {
                if (grid[y][x] == nullptr) {
                    // Nothing to do here, cell is already empty
                }
            }
        }*/   
    }
};

int main() {
    World world;
    int time = 0;

    while (true) {
        cout << "World at time " << time << ":\n\n";
        world.display();
        cout << endl << "Press Enter to continue";
        cin.get();
        world.simulate_step();
        time++;
    }

    return 0;
}