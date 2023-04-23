#include "PGN.hpp"
#include <iostream>
using namespace pgnp;



int main(){
    PGN pgn;
    pgn.FromFile("Conv/hartwig.pgn");
    pgn.ParseNextGame();
    
    

    // Recuperer tout les tags 

    
    std::cout << "Event is: " << pgn.GetTagValue("Event") << std::endl;
    std::cout << "Date is: " << pgn.GetTagValue("Date") << std::endl;
    std::cout << "Round is: " << pgn.GetTagValue("Round") << std::endl;
    std::cout << "White is: " << pgn.GetTagValue("White") << std::endl;
    std::cout << "Black is: " << pgn.GetTagValue("Black") << std::endl;
    std::cout << "Result is: " << pgn.GetTagValue("Result") << std::endl;
    /*
    std::cout << "WhiteElo is: " << pgn.GetTagValue("WhiteElo") << std::endl;
    std::cout << "BlackElo is: " << pgn.GetTagValue("BlackElo") << std::endl;
    std::cout << "ECO is: " << pgn.GetTagValue("ECO") << std::endl;
    */


    // Recuperer les coups de la partie 

    HalfMove *m = new HalfMove();
    pgn.GetMoves(m);

    for ( int i = 0; i < m->GetLength() ; i++)
    {
       std::cout << i << " move is: " << m->GetHalfMoveAt(i)->move << std::endl; s
       

       // Recuperer les commentaire
        if (!m->GetHalfMoveAt(i)->comment.empty())
        {
             std::cout << m->GetHalfMoveAt(i)->comment << std::endl;
                       
        }
        

    }
    
    


    
    
    

    
    
    
    return(0);
}