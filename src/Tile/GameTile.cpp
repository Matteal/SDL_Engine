#include "GameTile.h"

GameTile::GameTile(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]) : Scene(renderer, textureArray), m_hover(m_renderer, textureArray[7], 0, 0, TILE_RECT_WIDTH, TILE_RECT_HEIGHT),
                                                                                                                 m_boatP(m_renderer, textureArray[8], TILE_RECT_WIDTH, TILE_RECT_HEIGHT)
{
    char tab[NB_TILE_X][NB_TILE_Y];
    for(int i=0; i<NB_TILE_X; i++)
    {
        for(int j=0; j<NB_TILE_Y; j++)
        {
            tab[i][j] = 'D';
        }
    }


    //Copier le tableau dans celui dont on a besoin
    for(int i=0; i<NB_TILE_X; i++)
    {
        for(int j=0; j<NB_TILE_Y; j++)
        {
            switch(tab[i][j])
            {
                case('D'):
                    //m_map[i][j] = new Tile(m_renderer, m_textureArray[2]);
                    break;
            }

            m_map[i][j] = new Tile(renderer, textureArray[rand()%4 +2]);
        }
    }


    boatPosX = 50;
    boatPosY = 50;

    OriginCameraX = 50;
    OriginCameraY = 40;
}

GameTile::~GameTile()
{
    for(int i=0; i<NB_TILE_X; i++)
    {
        for(int j=0; j<NB_TILE_Y; j++)
        {
            delete(m_map[i][j]);
        }
    }

}

float interpolation( float V1, float V2, float t)
{
    return (1-t)*V1 + t*V2;
}

void GameTile::update(Input* input)
{
    int CameraX = 50;
    int CameraY = 50;

    int boatPosX = 50;
    int boatPosY = 50;

    int offset = 0;
    //std::cout<<"debug";

    for(int i=0; i<26; i++)
    {
        for(int j=0; j<8; j++)
        {
            //TODO : Separate Camera X/Y and BoatPos X/Y
            m_map[j+OriginCameraX][i+OriginCameraY]->setPosition( j * (TILE_RECT_WIDTH + 39) + offset -(CameraX%TILE_RECT_WIDTH),  i * (TILE_RECT_HEIGHT-21) -(CameraY%TILE_RECT_HEIGHT));

            // hover update
            if(m_map[j+OriginCameraX][i+OriginCameraY]->estTouche(input->getX(), input->getY()))
            {
                m_hoverCordX = j+OriginCameraX;
                m_hoverCordY = i+OriginCameraY;

                SDL_Rect* rectHover = m_map[m_hoverCordX][m_hoverCordY]->getSDL_Rect();
                m_hover.setPosition(rectHover->x, rectHover->y);

                //si cliqué
                if(m_map[j+OriginCameraX][i+OriginCameraY]->estTouche(input->getX(), input->getY()), input->getRoundDOWN(), input->getRoundUP())
                {
                    m_boatP.setCurrentTile(j+OriginCameraX, i+OriginCameraY);
                }
            }
        }

        // Allow an offset between row of tiles
        if(offset==0)
            offset=58;
        else
            offset=0;
    }
    SDL_Rect* rectBoat = m_map[m_boatP.getCurrentTileX()][m_boatP.getCurrentTileY()]->getSDL_Rect();
    m_boatP.setPosition(rectBoat->x, rectBoat->y -8);
}

void GameTile::render()
{


    for(int i=0; i<26; i++)
    {
        for(int j=0; j<8; j++)
        {
            m_map[j+OriginCameraX][i+OriginCameraY]->render();
        }
    }
    m_hover.render();

    m_boatP.render();

//    for(int i=0; i<NB_TILE_X; i++)
//    {
//        for(int j=0; j<NB_TILE_Y; j++)
//        {
//            m_map[i][j]->render();
//        }
//    }
}
