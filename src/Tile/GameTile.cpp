#include "GameTile.h"

GameTile::GameTile(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]) : Scene(renderer, textureArray)
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
            m_map[i][j] = new Tile(m_renderer, m_textureArray[2]);
        }
    }

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

void GameTile::update(Input* input)
{
    int bateauX = 50;
    int bateauY = 50;

    int offset = 0;
    for(int i=0; i<NB_TILE_Y; i++)
    {
        for(int j=0; j<NB_TILE_X; j++)
        {
            m_map[j][i]->setPosition((float) j * (TILE_RECT_WIDTH + 39) + offset,  i * (TILE_RECT_HEIGHT-21) );
        }

        if(offset==0)
            offset=58;
        else
            offset=0;
    }
}

void GameTile::render()
{
    for(int i=0; i<NB_TILE_X; i++)
    {
        for(int j=0; j<NB_TILE_Y; j++)
        {
            m_map[i][j]->render();
        }
    }
}
