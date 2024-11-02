#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>
#include <cmath>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position; //posision de la animacion
    int frame = 0;

    while (frame <51)
    {
        int x = frame;
        int z = cos((frame % 9)*5);
        auto can = Canvas(600,200); // tamaño del lienzo
        int cx = 40;
        int cy = 20 + z;
        int r = 20;
        if (frame % 10 == 0)
        {
            can.DrawPointCircle(40, 20 + z, 10 + 10, Color::DarkGreen);
            can.DrawText(34, 18 + z, ">", Color::Yellow);
            can.DrawText(44, 19 + z, "<", Color::Yellow);
            can.DrawBlockLine(38, 25 + z, 41, 28 + z, Color::Blue1);
            can.DrawBlockLine(42, 26, 43, 25, Color::Blue1);
            int picos = 3;
            for(picos; picos >= 0; picos--) {
                for (int i = 0; i < 360; i += 30) {
                    int x1 = cx + (r * cos(i * M_PI / 180.0)); 
                    int y1 = cy + (r * sin(i * M_PI / 180.0));
                    int x2 = cx + ((r + picos) * cos(i * M_PI / 180.0));
                    int y2 = cy + ((r + picos) * sin(i * M_PI / 180.0));

                    can.DrawPoint(x1, y1, Color::Yellow); // Punto en el borde del círculo
                    can.DrawPoint(x2, y2, Color::Red);    // Punto en el extremo del pico
                }
            }
        }else{
            bool y = frame % 4 == 0 ? 0 : 1;
            can.DrawPointCircle(40, 20, 10 + z);
            can.DrawBlock(35, 18 + z, y);
            can.DrawBlock(45, 19 + z, y);
            can.DrawBlockLine(38, 25 + z, 43, 25 + z);
        }
        

        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::NavyBlue, canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.5s);
        frame++;
    }

    return 0;
}