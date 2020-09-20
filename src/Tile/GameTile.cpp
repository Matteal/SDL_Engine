#include "GameTile.h"

GameTile::GameTile(SDL_Renderer* renderer, SDL_Texture* textureArray[NB_IMAGE]) : Scene(renderer, textureArray), m_hover(m_renderer, textureArray[36], 0, 0, TILE_RECT_WIDTH, TILE_RECT_HEIGHT),
                                                                                                                 m_area(m_renderer, textureArray[35], 0, 0, TILE_RECT_WIDTH, TILE_RECT_HEIGHT),
                                                                                                                 m_player(m_renderer, textureArray[25], textureArray[26], TILE_RECT_WIDTH, TILE_RECT_HEIGHT), m_interpolate(1)
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

            m_map[i][j] = new Tile(renderer, textureArray[rand()%4 +37], i, j);
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
            if((i==NB_TILE_X-1 && !isRowEven) || j==0)
                m_map[i][j]->SetTile(NULL, 1);
            else if(isRowEven)
                m_map[i][j]->SetTile(m_map[i][j-1], 1);
            else
                m_map[i][j]->SetTile(m_map[i+1][j-1], 1);

            // tile 2
            if((i==NB_TILE_X-1 && !isRowEven) || j==NB_TILE_Y)
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
            if((i==0 && isRowEven) || j==NB_TILE_Y)
                m_map[i][j]->SetTile(NULL, 4);
            else if(isRowEven)
                m_map[i][j]->SetTile(m_map[i-1][j+1], 4);
            else
                m_map[i][j]->SetTile(m_map[i][j+1], 4);

            // tile 5
            if((i==0 && isRowEven) || j==0)
                m_map[i][j]->SetTile(NULL, 5);
            else if(isRowEven)
                m_map[i][j]->SetTile(m_map[i-1][j-1], 5);
            else
                m_map[i][j]->SetTile(m_map[i][j-1], 5);
        }
    }

    // Creating ennemies
    for(int i=0; i<NB_ENNEMIES; i++)
    {
        m_TabBoat[i] = new Boat(renderer, textureArray[25], textureArray[26], 5, 5);
        int x = rand()%NB_TILE_X;
        int y = rand()%NB_TILE_Y;
        m_TabBoat[i]->setCurrentTile(m_map[x][y]);
        m_TabBoat[i]->setCurrentTile(m_map[x][y]);
    }

    m_CameraX = 0*TILE_RECT_WIDTH;
    m_CameraY = 0;

    // starting point
    m_player.setCurrentTile(m_map[97][5]);
    m_player.setCurrentTile(m_map[4][97]);
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

    for(int i=0; i<NB_ENNEMIES; i++)
    {
        delete(m_TabBoat[i]);
    }
}

void GameTile::updateBoatPos(Boat* boat, int cursorX, int cursorY)
{

}

void GameTile::update(Input* input)
{
//    m_CameraX += 0.2;
//    m_CameraY += 0.1;

    m_OriginCameraX = 50;
    m_OriginCameraY = 50;

    int offset = 0;

    // Update the Boat's position
    for(int i=0; i<6; i++)
    {
        Tile* tile = static_cast <Tile*> (m_player.getCurrentTile()->getTile(i));
        if(tile!= NULL)
        {
            if(tile->Sprite::estTouche(input->getX(), input->getY(), input->getRoundDOWN(), input->getRoundUP()))
            {
                m_player.setCurrentTile(tile);

                // Updating Ennemies position
                for(int i=0; i<NB_ENNEMIES; i++)
                {
                    Tile* tileOpponent = static_cast <Tile*>(m_TabBoat[i]->getCurrentTile()->getTile(rand()%6));
                    if(tileOpponent != NULL)
                    {
                        if(tileOpponent->getIsEmpty())
                            m_TabBoat[i]->setCurrentTile(tileOpponent);
                    }

                }

                // reset interpolate for animations
                m_interpolate = 0;
            }
        }
    }

    // Update Camera
//    return (1-t)*V1 + t*V2;
    m_CameraX = (1-CAMERA_SPEED)*m_CameraX + CAMERA_SPEED * (m_player.getCurrentTile()->getPosX()*TILE_RECT_WIDTH*1.5 - 350);
    m_CameraY = (1-CAMERA_SPEED)*m_CameraY + CAMERA_SPEED * (m_player.getCurrentTile()->getPosY()*TILE_RECT_HEIGHT*0.5 - 250);


    // Set the tiles positions
    for(int i=0; i<NB_TILE_Y; i++)
    {
        for(int j=0; j<NB_TILE_X; j++)
        {
            m_map[j][i]->setPosition( j * (TILE_RECT_WIDTH + 39) + offset -m_CameraX,  i * (TILE_RECT_HEIGHT-21) -m_CameraY);

            // hover update
            if(m_map[j][i]->estTouche(input->getX(), input->getY()))
            {
                m_hoverCordX = j;
                m_hoverCordY = i;

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
}

void GameTile::render()
{
    // render the map
    for(int i=0; i<NB_TILE_X; i++)
    {
        for(int j=0; j<NB_TILE_Y; j++)
        {
            m_map[i][j]->render();
        }
    }

    //render the area around the boat
    if(m_interpolate == 1)
    {
        Tile* tilePtr;
        for(int i=0; i<6; i++)
        {
            tilePtr = static_cast <Tile*> (m_player.getCurrentTile()->getTile(i));
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
    }
    m_hover.render();

    // Ships interpolation
    m_interpolate += 0.01;
    if (m_interpolate >= 1)
        m_interpolate = 1;

    for(int i=0; i<NB_ENNEMIES; i++)
    {
        m_TabBoat[i]->render(m_interpolate);
    }

    m_player.render(m_interpolate);

}


// PLAYER

Player::Player(SDL_Renderer* renderer, SDL_Texture* textureR, SDL_Texture* textureL, int posx, int posy) : Boat(renderer, textureR, textureL, posx, posy)
{
    //ctor
}
