#include "grman/grman.h"
#include <iostream>

#include "graph.h"

int main()
{
    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    int a=0;
    int b=0;


    BITMAP *page;
    BITMAP *buffer;
    buffer=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(buffer);
BITMAP* bye=load_bitmap("bye.bmp",NULL);
    grman::set_pictures_path("images");

    page=load_bitmap("t.bmp",NULL);

    if(!page)

    {
        allegro_message("pas trouver image");
        exit(EXIT_FAILURE);
    }



    /// Un exemple de graphe

Graph g;
g.make_example();




    /// ( contrairement à des frameworks plus avancés )
    while ( !key[KEY_ESC])
    {
        while(!key[KEY_ENTER]&&(b!=1))
            {
                std::cout << "coucou" << std::endl;

                blit(page,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                //blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

                if(mouse_b&1)
                {
                    if (mouse_x>40&&mouse_y>380&&mouse_x<66&&mouse_y<402)
                        blit(bye,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                       // return 0;
                }
               /*if(mouse_b&1)
                {
                    if (mouse_x>106&&mouse_y>276&&mouse_x<222&&mouse_y<316)



                }
                /*if(mouse_b&1)
                {
                    if (mouse_x>40&&mouse_y>380&&mouse_x<66&&mouse_y<402)
                        return 0;
                }*/


            }
                b=1;



    ///déclaration des variables



        /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
        g.update();

        /// Mise à jour générale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();

    }
    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


