#include "GameTile.h"

GameTile::GameTile(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]) : Scene(renderer, textureArray), m_hover(m_renderer, textureArray[7], 0, 0, TILE_RECT_WIDTH, TILE_RECT_HEIGHT),
                                                                                                                 m_area(m_renderer, textureArray[25], 0, 0, TILE_RECT_WIDTH, TILE_RECT_HEIGHT),
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

    bool isRowEven;
    for(int i=0; i<NB_TILE_X; i++)
    {
        for(int j=0; j<NB_TILE_Y; j++)
        {
            isRowEven = (j%2==0);

            // tile 0
            if(j==0 || j==1)
                m_map[i][j]->SetTile(NULL, 0);
            else
                m_map[i][j]->SetTile(m_map[i][j-2], 0);

            // tile 1
            if(i==NB_TILE_X || j==0)
                m_map[i][j]->SetTile(NULL, 1);
            else if(isRowEven)
                m_map[i][j]->SetTile(m_map[i][j-1], 1);
            else
                m_map[i][j]->SetTile(m_map[i+1][j-1], 1);

            // tile 2
            if(i==NB_TILE_X || j==NB_TILE_Y)
                m_map[i][j]->SetTile(NULL, 2);
            else if(isRowEven)
                m_map[i][j]->SetTile(m_map[i][j+1], 2);
            else
                m_map[i][j]->SetTile(m_map[i+1][j+1], 2);

            // tile 3
            if(j==NB_TILE_Y || j==NB_TILE_Y-1)
                m_map[i][j]->SetTile(NULL, 3);
            else
                m_map[i][j]->SetTile(m_map[i][j+2], 3);

            // tile 4
            if(i==0 || j==NB_TILE_Y)
                m_map[i][j]->SetTile(NULL, 4);
            else if(isRowEven)
                m_map[i][j]->SetTile(m_map[i-1][j+1], 4);
            else
                m_map[i][j]->SetTile(m_map[i][j+1], 4);

            // tile 5
            if(i==0 || j==0)
                m_map[i][j]->SetTile(NULL, 5);
            else if(isRowEven)
                m_map[i][j]->SetTile(m_map[i-1][j-1], 5);
            else
                m_map[i][j]->SetTile(m_map[i][j-1], 5);
        }
    }


    boatPosX = 50;
    boatPosY = 50;

    OriginCameraX = 50;
    OriginCameraY = 40;

    // starting point
    m_boatP.setCurrentTile(m_map[52][52]);
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


    int offset = 0;


    // Update the Boat's position
    for(int i=0; i<6; i++)
    {
        Tile* tile = static_cast <Tile*> (m_boatP.getCurrentTile()->getTile(i));
        if(tile!= NULL)
        {
            if(tile->Sprite::estTouche(input->getX(), input->getY(), input->getRoundDOWN(), input->getRoundUP()))
            {
                m_boatP.setCurrentTile(tile);
            }
        }
    }

    for(int i=0; i<26; i++)
    {
        for(int j=0; j<8; j++)
        {
            m_map[j+OriginCameraX][i+OriginCameraY]->setPosition( j * (TILE_RECT_WIDTH + 39) + offset -(CameraX%TILE_RECT_WIDTH),  i * (TILE_RECT_HEIGHT-21) -(CameraY%TILE_RECT_HEIGHT));

            // hover update
            if(m_map[j+OriginCameraX][i+OriginCameraY]->estTouche(input->getX(), input->getY()))
            {
                m_hoverCordX = j+OriginCameraX;
                m_hoverCordY = i+OriginCameraY;

                SDL_Rect* rectHover = m_map[m_hoverCordX][m_hoverCordY]->getSDL_Rect();
                m_hover.setPosition(rectHover->x, rectHover->y);
            }
        }

        // Allow an offset between row of tiles
        if(offset==0)
            offset=58;
        else
            offset=0;
    }

    // update the boat's Sprite
    SDL_Rect* rectBoat = m_boatP.getCurrentTile()->getSDL_Rect();
    m_boatP.setPosition(rectBoat->x, rectBoat->y -8);
}

void GameTile::render()
{
    // render the map
    for(int i=0; i<26; i++)
    {
        for(int j=0; j<8; j++)
        {
            m_map[j+OriginCameraX][i+OriginCameraY]->render();
        }
    }

    //render the area around the boat
    Tile* tilePtr;
    for(int i=0; i<6; i++)
    {
        tilePtr = static_cast <Tile*> (m_boatP.getCurrentTile()->getTile(i));
        if(tilePtr!=NULL)
        {
            if(tilePtr->getIsEmpty())
            {
                SDL_Rect* rect = tilePtr->getSDL_Rect();
                m_area.setPosition(rect->x, rect->y);
                m_area.render();

            }
        }

    }
    m_hover.render();

    m_boatP.render();

}
