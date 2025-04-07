#include<SFML/Graphics.hpp>
#include<cmath>
using namespace sf;

void movePlayer(Sprite& spritePlayer,float& pixelPerSecPlayerX,float& pixelPerSecPlayerY,Time& dt){
    float x=spritePlayer.getPosition().x;
    float y=spritePlayer.getPosition().y;
    if(Keyboard::isKeyPressed(Keyboard::A)){
        x=x-dt.asSeconds()*pixelPerSecPlayerX;
    }
    if(Keyboard::isKeyPressed(Keyboard::D)){
        x=x+dt.asSeconds()*pixelPerSecPlayerX;
    }
    if(Keyboard::isKeyPressed(Keyboard::W)){
        y=y-dt.asSeconds()*pixelPerSecPlayerY;
    }
    if(Keyboard::isKeyPressed(Keyboard::S)){
        y=y+dt.asSeconds()*pixelPerSecPlayerY;
    }
    spritePlayer.setPosition(x,y);

    float dx=Mouse::getPosition().x-x;
    float dy=Mouse::getPosition().y-y;

    float angle=atan2(dy,dx)*(180.0/3.141159f);
    spritePlayer.setRotation(angle);
}

int main(){
    VideoMode video(800,600);
    RenderWindow window(video,"ZOMBIE ARENA !!!");

    Sprite spritePlayer;
    Texture texturePlayer;
    texturePlayer.loadFromFile("player.png");
    spritePlayer.setTexture(texturePlayer);
    FloatRect playerBound=spritePlayer.getLocalBounds();
    spritePlayer.setOrigin(playerBound.width/2,playerBound.height/2);

    float pixelPerSecPlayerX=800/5;
    float pixelPerSecPlayerY=800/5;

    spritePlayer.setPosition(window.getSize().x/2,window.getSize().y/2);
    
    Clock clock;
    Time dt;
    while (window.isOpen()){
        Event ev;
        while (window.pollEvent(ev))
        {
            if(ev.type==Event::Closed){
                window.close();
            }
        }
        dt=clock.restart();
        movePlayer(spritePlayer,pixelPerSecPlayerX,pixelPerSecPlayerY,dt);
               
        window.clear();
        window.draw(spritePlayer);

        window.display();
    }
    return 0;
}
