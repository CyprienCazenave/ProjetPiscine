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

    /// Le nom du r�pertoire o� se trouvent les images � charger
    grman::set_pictures_path("pics");

    page=load_bitmap("t.bmp",NULL);

    if(!page)

    {
        allegro_message("pas trouver image");
        exit(EXIT_FAILURE);
    }



    /// Un exemple de graphe
    Graph g;
    g.make_example();



    /// ( contrairement � des frameworks plus avanc�s )
    while ( !key[KEY_ESC])
    {

        while(!key[KEY_ENTER] && (b !=1))
        {
            blit(page,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

            if(mouse_b&1)
            {
                if (mouse_x>40&&mouse_y>380&&mouse_x<66&&mouse_y<402)
                    return 0;
            }

    }
    ///d�claration des variables



    b=1;
        /// Il faut appeler les m�thodes d'update des objets qui comportent des widgets
        g.update();

        /// Mise � jour g�n�rale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();
    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


