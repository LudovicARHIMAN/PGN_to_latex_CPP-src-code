#include "PGN.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
using namespace pgnp;




int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: ./program <input_file> <output_file>" << std::endl;
        return 1;
    }

    


    std::string in_path = argv[1]; //emplacement du fichier à convertir
    std::string out_path = argv[2]; // Chemin où le fichier sera enregistré le fichier .tex


    
    // std::string outputPath = "/var/www/html/Convert/libpgnp/converted/file.tex"; 

    std::ofstream outfile(out_path);
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
    pgn.FromFile(in_path);
    
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


        


        // Tester si le tag ECO existe
        try {

           tag_opt = pgn.GetTagValue("ECO");

        } catch (const InvalidTagName& e) {

            // tag non trouvé donc la variable tag_opt sera vide 

        }
        
        
        if (!tag_opt.empty()) {

            buffer << "\\ECO{" << tag_opt << "}\n";

        }
        
        tag_opt.clear(); // effacer le contenu de la variable pour pouvoir la réutiliser pour tester l'existence des autres tags


        // Tester si le tag WhiteElo existe
        try {

           tag_opt = pgn.GetTagValue("WhiteElo");

        } catch (const InvalidTagName& e) {

            // tag non trouvé donc la variable tag_opt sera vide 

        }

        
        if (!tag_opt.empty()) {

            buffer << "\\whiteelo{" << tag_opt << "}\n";

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

            buffer << "\\blackelo{" << tag_opt << "}\n";

        }

        // Effacer le contenu de la variable tampon
        tag_opt.clear();

        // Tag PlyCount
        try {

           tag_opt = pgn.GetTagValue("PlyCount");

        } catch (const InvalidTagName& e) {

            // tag non trouvé donc la variable tag_opt sera vide 

        }

        
        if (!tag_opt.empty()) {

            buffer << "\\PlyCount{" << tag_opt << "}\n";

        }

        // Effacer le contenu de la variable tampon
        tag_opt.clear();
        
        

             
        
        

        // Recuperer les coups de la partie 

        HalfMove *m = new HalfMove();
        pgn.GetMoves(m);
        

        int j = 0;
        int count = 1;

        for ( int i = 0; i < m->GetLength() ; i++){
            j++;
            if (j==1) {
                
                buffer
                << "\\mainline{" << count << ". " ;
                
                
            }

            buffer
            << m->GetHalfMoveAt(i)->move << "  ";
            
           
            
            if (j != 8) {
                

                if(m->GetHalfMoveAt(i)->isBlack==1){
                count+=1;
                
                buffer
                << count << ". " ;
                }   

            }

            if (j==8){
                count++;
                buffer
                << "}\n";
                
            }

            
            if (i==(m->GetLength()-1)) {
                buffer
                << "}\n";
            }


                

                
            /*
            std::cout << i << " move is: " << m->GetHalfMoveAt(i)->move << std::endl;
            */
            
            
            // << "\\mainline{" << i <<"." << m->GetHalfMoveAt(i)->move << "}\n"
            
            
            
            if (j==8) {
                
                buffer
                << "\\scalebox{0.90}{\\chessboard}\n"; 



                // Recuperer les commentaires
                if (!m->GetHalfMoveAt(i)->comment.empty()){
                // std::cout << m->GetHalfMoveAt(i)->comment << std::endl;
                    buffer
                    << "\\xskakcomment{\\small\texttt\\justifying{\\textcolor{darkgray}{~ " << m->GetHalfMoveAt(i)->comment << "}}}\n";
                            
                }

                j=0;




            }
            
           

        }

    }

    // Fin du document 
    buffer 
    << "\\newpage\\end{document}";


    outfile << buffer.str();

    return(0);

    

}