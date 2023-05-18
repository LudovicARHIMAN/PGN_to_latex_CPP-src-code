#include "PGN.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
using namespace pgnp;



int main(int argc, char* argv[]){

    if (argc < 3) {
        std::cout << "Usage: ./your_program <input_file> <output_file>\n";
        return 1;
    }

        

    std::string inputFileName = argv[1];
    std::string outputFileName = argv[2];

    std::cout << "Input file: " << inputFileName << std::endl;
    std::cout << "Output file: " << outputFileName << std::endl;

    // chemin du ficher en sortie
    std::string outputPath = "/var/www/html/Convert/libpgnp/converted/file.tex"; // Chemin où le fichier sera enregistré


    // creation du buffer en definissant où les donnes du buffer vont être écrites 
    std::ofstream outfile(outputPath);
    std::stringstream buffer;
    
    

    PGN pgn;
    pgn.FromFile("tmp/Adams.pgn");
    
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
        
        

        // En-tete du fichier latex

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
        << "\\usepackage{ragged2e}\n"
        << "\\begin{document}\n";

        

        // Recuperer les 7 tags obligatoires
        
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
        << "\\chessevent{" << pgn.GetTagValue("Result") << "}\n";



        //Tags optionnels 

        try{
            buffer
            << "\\chessevent{" << pgn.GetTagValue("WhiteElo") << "}\n";
            
        }

        catch(const InvalidTagName& e) {
            break;
        }
        
        try{
            buffer
            << "\\chessevent{" << pgn.GetTagValue("BlackElo") << "}\n";
            
        }

        catch(const InvalidTagName& e) {
            break;
        }
        
        try{
            buffer
            << "\\chessevent{" << pgn.GetTagValue("ECO") << "}\n";
            
        }

        catch(const InvalidTagName& e) {
            break;
        }

        try{
            buffer
            << "\\chessevent{" << pgn.GetTagValue("PlyCount") << "}\n";
            
        }

        catch(const InvalidTagName& e) {
            break;
        }
        


        // Recuperer les coups de la partie 

        HalfMove *m = new HalfMove();
        pgn.GetMoves(m);
        
        

        // En-tête du jeu actuel 

        buffer 
        <<"\\makegametitle\n"
        <<"\\begin{multicols}{2}\n"
        <<"\\noindent"
        <<"\\newchessgame[id=main]\n"
        <<"\\xskakset{style=styleC}\n";
        


        for ( int i = 0; i < m->GetLength() ; i++){

            
            
            std::cout << i << " move is: " << m->GetHalfMoveAt(i)->move << std::endl;
        
            
            // Recuperer les commentaires
            if (!m->GetHalfMoveAt(i)->comment.empty()){
                

                buffer
                << "\\xskakcomment{\\small\texttt\\justifying{\textcolor{darkgray}{~ " << m->GetHalfMoveAt(i)->comment  << "}}}\n";



                        
            }
        
        }
        
         
        


    }
    
    outfile << buffer.str();

    return 0;

    

}
