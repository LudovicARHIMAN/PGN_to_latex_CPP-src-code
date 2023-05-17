#include "PGN.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace pgnp;



int main(){
    

    PGN pgn;
    pgn.FromFile("Conv/Adams.pgn");
    
    while (true)
    {

        // Parser toutes les parties (et pas une seule partie)

        try
        {
            pgn.ParseNextGame();
        }
        catch(const NoGameFound& e)
        {
            break;
        }
        
        // Recuperer tout les tags obligatoires

        try{
            std::cout << "Event is: " << pgn.GetTagValue("Event") << std::endl;
        }

        catch(const InvalidTagName& e) {
            break;
        }


        try{
            std::cout << "Event is: " << pgn.GetTagValue("Site") << std::endl;
        }

        catch(const InvalidTagName& e) {
            break;
        }


        try{
            std::cout << "Event is: " << pgn.GetTagValue("Date") << std::endl;
        }

        catch(const InvalidTagName& e) {
            break;
        }


        try{
            std::cout << "Event is: " << pgn.GetTagValue("Round") << std::endl;
        }

        catch(const InvalidTagName& e) {
            break;
        }


        try{
            std::cout << "Event is: " << pgn.GetTagValue("White") << std::endl;
        }

        catch(const InvalidTagName& e) {
            break;
        }

        try{
            std::cout << "Event is: " << pgn.GetTagValue("Black") << std::endl;
        }

        catch(const InvalidTagName& e) {
            break;
        }

        try{
            std::cout << "Event is: " << pgn.GetTagValue("Result") << std::endl;
        }

        catch(const InvalidTagName& e) {
            break;
        }

        //Tags optionnels 

        try{
            std::cout << "Event is: " << pgn.GetTagValue("WhiteElo") << std::endl;
        }

        catch(const InvalidTagName& e) {
            break;
        }
        
        try{
            std::cout << "Event is: " << pgn.GetTagValue("BlackElo") << std::endl;
        }

        catch(const InvalidTagName& e) {
            break;
        }
        
        try{
            std::cout << "Event is: " << pgn.GetTagValue("ECO") << std::endl;
        }

        catch(const InvalidTagName& e) {
            break;
        }
        
        

        // Recuperer les coups de la partie 

        HalfMove *m = new HalfMove();
        pgn.GetMoves(m);
        
        
        
        for ( int i = 0; i < m->GetLength() ; i++){
        std::cout << i << " move is: " << m->GetHalfMoveAt(i)->move << std::endl;
        

        // Recuperer les commentaires
            if (!m->GetHalfMoveAt(i)->comment.empty()){
                std::cout << m->GetHalfMoveAt(i)->comment << std::endl;
                        
            }

        }

        

        


    }
    
    
    return(0);

    

}
