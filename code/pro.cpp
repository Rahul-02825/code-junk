#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <sstream>
#include <cmath>
#include<algorithm>

class PathNode {
private:
    std::map<char, PathNode> childNodeList;
    void createSubtree();
    static bool checkSolution(const std::string &path, const std::vector<unsigned short> &puzzleBoard);

public:
    void addLevel();
    void clearLastLevel();
    void clearTree();
    bool checkAllPaths(std::string &path, std::vector<unsigned short> &puzzleBoard, const unsigned short &boardSize, unsigned short &emptySlotIndex);
};

class NPuzzleSolver {
private:
    std::vector<unsigned short> puzzleBoard;
    PathNode root;
    static void printSeparator(const char &ch, const unsigned short &boxWidth, const unsigned short &boardSize);

public:
    NPuzzleSolver(const std::string &puzzle, const unsigned short &n);
    void printPuzzle() const;
    void solve();
};

NPuzzleSolver::NPuzzleSolver(const std::string &puzzle, const unsigned short &n) {
    std::stringstream ss(puzzle);
    unsigned short num;
    char ch;
    while (ss >> num) {
        ss >> ch;
        puzzleBoard.push_back(num);
    }
    puzzleBoard.shrink_to_fit();
}

void NPuzzleSolver::printSeparator(const char &ch, const unsigned short &boxWidth, const unsigned short &boardSize) {
    for (unsigned short i = 1; i < boardSize; i++)
        std::cout << std::string(boxWidth, ch) << "|";
    std::cout << std::string(boxWidth, ch) << std::endl;
}

void NPuzzleSolver::printPuzzle() const {
    const unsigned short boxWidth = std::to_string(puzzleBoard.size()).length() + 2;
    const unsigned short boardSize = std::sqrt(puzzleBoard.size());
    std::cout << "Board size: " << boardSize << std::endl;
    std::cout << "Initial grid position:" << std::endl << std::endl;
    for (unsigned short i = 0; i < boardSize; i++) {
        printSeparator(' ', boxWidth, boardSize);
        for (unsigned short j = 0; j < boardSize; j++) {
            const unsigned short currentElement = puzzleBoard[i * boardSize + j];
            const unsigned short currentNumberLength = std::to_string(currentElement ? currentElement : puzzleBoard.size() - 1).length();
            const unsigned short diff = boxWidth - currentNumberLength;
            const std::string separator = std::string(diff / 2, ' ');
            std::cout << separator << (currentElement ? std::to_string(currentElement) : std::string(currentNumberLength, ' ')) << separator;
            if (diff % 2)
                std::cout << " ";
            if (j < boardSize - 1)
                std::cout << "|";
        }
        if (i < boardSize - 1) {
            std::cout << std::endl;
            printSeparator('_', boxWidth, boardSize);
        }
    }
    std::cout << std::endl;
    printSeparator(' ', boxWidth, boardSize);
    std::cout << std::endl << std::endl;
}

void NPuzzleSolver::solve() {
   std::string solution = "";
   const unsigned short emptySlotIndex = static_cast<unsigned short>(std::distance(puzzleBoard.begin(), std::find(puzzleBoard.begin(), puzzleBoard.end(), static_cast<unsigned short>(0))));
    const unsigned short boardSize = static_cast<unsigned short>(std::sqrt(puzzleBoard.size()));
    unsigned short copyEmptySlotIndex;
    std::vector<unsigned short> copyPuzzleBoard;
    const unsigned short MAX_NO_OF_LEVELS = 2 * boardSize * boardSize;  // Set a reasonable maximum number of levels.
    unsigned short levelCount = 0;

    do {
        if (++levelCount > MAX_NO_OF_LEVELS) {
            std::cout << std::endl << "Solution: N/A" << std::endl << std::endl << std::endl;
            break;
        }
        root.addLevel();
        root.checkAllPaths(solution, copyPuzzleBoard = puzzleBoard, boardSize, copyEmptySlotIndex = emptySlotIndex);
    } while (solution.empty());

    root.clearTree();
}

void PathNode::createSubtree() {
    static std::set<char> moves = {'L', 'R', 'U', 'D'};
    for (auto move : moves) {
        childNodeList.emplace(move, PathNode());
    }
}

void PathNode::addLevel() {
    if (childNodeList.empty()) {
        createSubtree();
        return;
    }
    for (auto &childNode : childNodeList) {
        childNode.second.addLevel();
    }
}

void PathNode::clearLastLevel() {
    if (childNodeList.begin()->second.childNodeList.empty()) {
        childNodeList.clear();
        return;
    }
    for (auto &childNode : childNodeList) {
        childNode.second.clearLastLevel();
    }
}

void PathNode::clearTree() {
    childNodeList.clear();
}

bool PathNode::checkSolution(const std::string &path, const std::vector<unsigned short> &puzzleBoard) {
    for (size_t i = 0; i < puzzleBoard.size() - 1; i++) {
        if (puzzleBoard[i] != i + 1) {
            return false;
        }
    }
    std::cout << std::endl << "Solution: " << path << std::endl << std::endl << std::endl;
    return true;
}

bool PathNode::checkAllPaths(std::string &path, std::vector<unsigned short> &puzzleBoard, const unsigned short &boardSize, unsigned short &emptySlotIndex) {
    static std::set<char> moves = {'L', 'R', 'U', 'D'};
    for (auto it = childNodeList.begin(); it != childNodeList.end(); it++) {
        const char move = it->first;
        unsigned short changedElementIndex;

        switch (move) {
            case 'L':
                if (emptySlotIndex % boardSize == 0 || (path.size() > 0 && path.back() == 'R')) {
                    childNodeList.erase(it--);
                    continue;
                }
                changedElementIndex = emptySlotIndex - 1;
                break;
            case 'R':
                if (emptySlotIndex % boardSize == boardSize - 1 || (path.size() > 0 && path.back() == 'L')) {
                    childNodeList.erase(it--);
                    continue;
                }
                changedElementIndex = emptySlotIndex + 1;
                break;
            case 'U':
                if (emptySlotIndex < boardSize || (path.size() > 0 && path.back() == 'D')) {
                    childNodeList.erase(it--);
                    continue;
                }
                changedElementIndex = emptySlotIndex - boardSize;
                break;
            case 'D':
                if (emptySlotIndex >= puzzleBoard.size() - boardSize || (path.size() > 0 && path.back() == 'U')) {
                    childNodeList.erase(it--);
                    continue;
                }
                changedElementIndex = emptySlotIndex + boardSize;
                break;
        }

        path.push_back(move);
        std::swap(puzzleBoard[emptySlotIndex], puzzleBoard[changedElementIndex]);
        std::swap(emptySlotIndex, changedElementIndex);

        if (checkSolution(path, puzzleBoard)) {
            return true;
        }
        if (it->second.checkAllPaths(path, puzzleBoard, boardSize, emptySlotIndex)) {
            return true;
        }

        std::swap(puzzleBoard[emptySlotIndex], puzzleBoard[changedElementIndex]);
        std::swap(emptySlotIndex, changedElementIndex);
        path.pop_back();
    }

    return false;
}

int main() {
    unsigned short n;
    std::cout << "Enter the grid size (e.g., 4 for a 4x4 puzzle): ";
    std::cin >> n;

    if (n < 2) {
        std::cout << "The grid size must be greater than 1 for a solvable puzzle." << std::endl;
        return 1;
    }

    unsigned short maxNumber = n * n - 1;
    std::cout << "Enter the puzzle configuration (use numbers from 0 to " << maxNumber << " and hyphens, e.g., '1-2-3-4-5-6-7-8-0'): ";
    std::string puzzleInput;
    std::cin >> puzzleInput;

    // Validate the input.
    std::stringstream ss(puzzleInput);
    std::set<unsigned short> seenNumbers;
    bool validInput = true;
    unsigned short num;
    while (ss >> num) {
        if (num > maxNumber || seenNumbers.count(num) > 0) {
            validInput = false;
            break;
        }
        seenNumbers.insert(num);
    }

    /*if (!validInput || seenNumbers.size() != maxNumber + 1) {
        std::cout << "Invalid puzzle configuration. Please enter a valid configuration." << std::endl;
        return 1;
    }*/

    NPuzzleSolver Npuzzle(puzzleInput, n);
    Npuzzle.printPuzzle();
    Npuzzle.solve();

    return 0;
}


























