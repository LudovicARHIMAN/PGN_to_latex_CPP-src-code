#include "PGN.hpp"
#include <iostream>
using namespace pgnp;

int main(){
    PGN pgn;
    pgn.FromFile("example.pgn");
    pgn.ParseNextGame();

    

    // Recuperer tout les tags 

    
    std::cout << "Event is: " << pgn.GetTagValue("Event") << std::endl;
    std::cout << "Date is: " << pgn.GetTagValue("Date") << std::endl;
    std::cout << "Round is: " << pgn.GetTagValue("Round") << std::endl;
    std::cout << "White is: " << pgn.GetTagValue("White") << std::endl;
    std::cout << "Black is: " << pgn.GetTagValue("Black") << std::endl;
    std::cout << "Result is: " << pgn.GetTagValue("Result") << std::endl;
    std::cout << "WhiteElo is: " << pgn.GetTagValue("WhiteElo") << std::endl;
    std::cout << "BlackElo is: " << pgn.GetTagValue("BlackElo") << std::endl;
    std::cout << "ECO is: " << pgn.GetTagValue("ECO") << std::endl;
    


    HalfMove *m = new HalfMove();
    pgn.GetMoves(m);
    std::cout << "First move is: " << m->move << std::endl;
    return(0);
}