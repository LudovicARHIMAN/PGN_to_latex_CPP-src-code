#include "PGN.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
using namespace pgnp;




int main(){
    
    std::string outputPath = "/var/www/html/Convert/libpgnp/converted/file.tex"; // Chemin où le fichier sera enregistré

    std::ofstream outfile(outputPath);
    std::stringstream buffer;

    // Début du document latex

    buffer
    << "\\documentclass{article}\n"
    << "\\usepackage{multicol}\n"
    << "\\usepackage{array}\n"
    << "\\usepackage{makeidx}\n"
    << "\\usepackage[skaknew]{chessfss}\n"
    << "\\usepackage{texmate}\n"
    << "\\usepackage{xskak}\n"
    << "\\usepackage[top=1.5cm, bottom=2cm, left=1.5cm, right=1cm,headheight=15pt]{geometry}\n"
    << "\\usepackage{adjmulticol}\n"
    << "\\usepackage{ragged2e}\n\n"
    << "\\begin{document}\n\n";


    
    PGN pgn;
    pgn.FromFile("tmp/hartwig.pgn");
    
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
        


        

        

        // Recuperer tout les 7 tags obligatoires
        
        try{
            pgn.STRCheck();
        }

        catch(const STRCheckFailed& e) {
            break;
        }
        
       
        buffer
        << "\\chessevent{" << pgn.GetTagValue("Event") << "}\n"
        << "\\chessevent{" << pgn.GetTagValue("Site") << "}\n"
        << "\\chessevent{" << pgn.GetTagValue("Date") << "}\n"
        << "\\chessevent{" << pgn.GetTagValue("Round") << "}\n"
        << "\\chessevent{" << pgn.GetTagValue("White") << "}\n"
        << "\\chessevent{" << pgn.GetTagValue("Black") << "}\n"
        << "\\chessevent{" << pgn.GetTagValue("Result") << "}\n\n";

        

        //Tags optionnels existence à tester 
        
        std::string tag_opt; //variable qui servira à tester l'existence des tag optionnels


        
        
        if (!tag_opt.empty()) {

            buffer << "\\chessevent{" << tag_opt << "}\n";

        }
        
        tag_opt.clear(); // effacer le contenu de la variable pour pouvoir la réutiliser pour tester l'existence des autres tags


        // Tester si le tag WhiteElo existe
        try {

           tag_opt = pgn.GetTagValue("WhiteElo");

        } catch (const InvalidTagName& e) {

            // tag non trouvé donc la variable tag_opt sera vide 

        }

        
        if (!tag_opt.empty()) {

            buffer << "\\chessevent{" << tag_opt << "}\n";

        }

        // Effacer le contenu de la variable tampon
        tag_opt.clear();
        
         // Tester si le tag BlackElo existe
        try {

           tag_opt = pgn.GetTagValue("BlackElo");

        } catch (const InvalidTagName& e) {

            // tag non trouvé donc la variable tag_opt sera vide 

        }

        
        if (!tag_opt.empty()) {

            buffer << "\\chessevent{" << tag_opt << "}\n";

        }

        // Effacer le contenu de la variable tampon
        tag_opt.clear();
        
        // Tester si le tag ECO existe
        try {

           tag_opt = pgn.GetTagValue("ECO");

        } catch (const InvalidTagName& e) {

            // tag non trouvé donc la variable tag_opt sera vide 

        }

        
        
        
        

        // Recuperer les coups de la partie 

        HalfMove *m = new HalfMove();
        pgn.GetMoves(m);
        
        

        for ( int i = 0; i < m->GetLength() ; i++){
            
            
            
            buffer
            << "\\mainline{" << i <<"." << m->GetHalfMoveAt(i)->move << " " << m->GetHalfMoveAt(i)->move << "}\n"
            << "\\scalebox{0.90}{\\chessboard}\n"; 
            

            
            /*
            std::cout << i << " move is: " << m->GetHalfMoveAt(i)->move << std::endl;
            */



            // Recuperer les commentaires
            if (!m->GetHalfMoveAt(i)->comment.empty()){
                std::cout << m->GetHalfMoveAt(i)->comment << std::endl;
                        
            }

        }

    }

    // Fin du document 
    buffer 
    << "\\end{document}\n";


    outfile << buffer.str();

    return(0);

    

}