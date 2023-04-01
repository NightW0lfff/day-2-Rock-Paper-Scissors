#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int scoreCalculateByResult(string result){
    int score = 0;
    if (result == "lose") return score += 0;
    if (result == "draw") return score += 3;
    if (result == "win") return score += 6;
    return score;
}

int scoreCalculateByShape(string shape){
    int score = 0;
    if (shape == "X") return score += 1;
    if (shape == "Y") return score += 2;
    if (shape == "Z") return score += 3;
    return score;
}

int scoreCalculate(string shape, string result){
    return scoreCalculateByShape(shape) + scoreCalculateByResult(result);
}

string gameResult(string opponent, string player){
    //A, X for Rock
    //B, Y for Paper
    //C, Z for Scissor
    string result;
    if ((opponent == "A" and player == "X") or (opponent == "B" and player == "Y") or (opponent == "C" and player == "Z")){
        return result = "draw";
    }else if ((opponent == "A" and player == "Z") or (opponent == "B" and player == "X") or (opponent == "C" and player == "Y")){
        return result = "lose";
    }else return result = "win";
}

int main(){
    
    ifstream data("input.txt");
    string line;
    string opponent, player;
    int totalScore = 0;
    
    while(getline(data, line)){
        opponent = line[0];
        player = line[2];
        string result = gameResult(opponent, player);
        totalScore += scoreCalculate(player, result);
    }
    
    cout << totalScore << endl;
    return 0;
}
