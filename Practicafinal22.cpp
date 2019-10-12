#include <iostream>
#include "CImg.h"
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
using namespace cimg_library;

class GAME
{
public:
    void recta_final_tipo_1 (void)
    {
        if (x0+20>=566)
        {
            ventana.display(imagen_fondo_negro_1);
            ventana.wait(5000);
            salir=false;
        }
    }
    void recta_final_tipo_2 (void)
    {
        if (x0+20>=566)
        {
            ventana.display(imagen_fondo_negro_2);
            ventana.wait(5000);
            salir=false;
            }
    }
    void inicio (void)
    {

        p=true;
        while(p)
        {
            ventana.display(imagen_inicio_1);
            ventana.wait(100);
            if (ventana.is_keyENTER())
            {
                p=false;
            }
            ventana.display(imagen_inicio_5);
            ventana.wait(100);
            if (ventana.is_keyENTER())
            {
                p=false;
            }
        }
    }

    void game_cuadrado (void)
    {
        imagen_inicio_1.load("Imagen_Inicio_1.bmp");
        imagen_inicio_2.load("Imagen_Inicio_2.bmp");
        imagen_inicio_3.load("Imagen_Inicio_3.bmp");
        imagen_inicio_4.load("Imagen_Inicio_4.bmp");
        imagen_inicio_5.load("Imagen_Inicio_5.bmp");
        imagen_inicio_6.load("Imagen_Inicio_6.bmp");
        imagen_inicio_7.load("Imagen_Inicio_7.bmp");
        imagen.load("Fondo_new.bmp");
        imagen1.load("Fondo_new2.bmp");
        imagen_fondo_negro_1.load("Fondo_negro_1.bmp");
        imagen_fondo_negro_2.load("Fondo_negro_2.bmp");

        ventana.assign(1080,480,"The Hardestest Game (BETA)",0);

      //  inicio();
    }
    void guardar_puntaje ()
    {
    std::ofstream archivo_txt("score_minimo.txt");

    if(archivo_txt.is_open()) {
        archivo_txt << contador_score;

        archivo_txt.close();

        cout<<"\n El score minimo es: "<<contador_score<<endl;
        cout << "Archivo .txt creado" << endl;
    } else {
        cout << "Error!" << endl;
        cout<<"-1";
    }
    }
    void puntaje_minimo (void)
    {
        if (contador_score <= contador_minimo)
        {
            contador_minimo=contador_score;
        }
    }
    void leer_puntaje_minimo (void)
    {
    std::ifstream archivo_txt("score_minimo.txt");

    if(archivo_txt.is_open()) {
        while(archivo_txt >> contador_minimo) {
            cout <<"puntajes mas bajos= \n"<<"\t"<< contador_minimo << '\n';
        }
        archivo_txt.close();

    } else {
        cout << "Error!" << endl;
        cout << "-1";
    }
    }
protected:
    float x0,y0,x1,y1;
    int  v1, v2, v3, v4, v5, q2, q1, q3, q4, q5;
    bool salir;
    bool rebote, rebote2, rebote3, rebote4, rebote5;
    int cyan [3] = {131,231,221};
    int azul_1 [3] = {34,102,176};
    int rojo [3] = {255,0,0};
    int rojo_2 [3] = {136,0,21};
    int negro [3] = {0,0,0};
    int blanco [3] = {255,255,255};
    int contador_muertes = 0;
    int contador_score = 10000;
    int contador_minimo = 0;
    bool p;
    float d,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13,d14;
    string texto_muertes;
    string score;
    string score_minimo;
    char Puntaje_[30];
    char puntaje_minimo_[30];
    char texto_contador_muertes[30];
    CImg<int> imagen;
    CImg<int> imagen1;
    CImg<int> imagen_fondo_negro_1;
    CImg<int> imagen_fondo_negro_2;
    CImg<int> imagen_inicio_1;
    CImg<int> imagen_inicio_2;
    CImg<int> imagen_inicio_3;
    CImg<int> imagen_inicio_4;
    CImg<int> imagen_inicio_5;
    CImg<int> imagen_inicio_6;
    CImg<int> imagen_inicio_7;
    CImgDisplay ventana;

    void Marcador_muertes (void)
    {
        itoa(contador_muertes,texto_contador_muertes,10);
        texto_muertes="Muertes:";
        texto_muertes+=texto_contador_muertes;

        imagen.draw_text(20,15,texto_muertes.c_str(),cyan,0,1,20);
    }
    void puntaje (void)
    {
        itoa(contador_score,Puntaje_,10);
        score="Score:";
        score+=Puntaje_;

        imagen.draw_text(150,15,score.c_str(),cyan,0,1,20);
    }
    void marcador_puntaje_minimo (void)
    {
        itoa(contador_minimo,puntaje_minimo_,10);
        score_minimo="Score Minimo:";
        score_minimo+=puntaje_minimo_;

        imagen.draw_text(300,15,score_minimo.c_str(),cyan,0,1,20);
    }
};
class HEROE : public GAME
{
public:
    void cuadro (void)
    {
        if(ventana.is_keyARROWRIGHT())
        {
            x0=x0+2;
            x1=x1+2;
            if (x0>585)
            {
                x0=x0-2;
                x1=x1-2;

            }
        }

        if(ventana.is_keyARROWDOWN())
        {
            y0=y0+2;
            y1=y1+2;
            if (y0>267)
            {
                y0=y0-2;
                y1=y1-2;
            }
        }

        if(ventana.is_keyARROWLEFT())
        {
            x0=x0-2;
            x1=x1-2;
            if (x0<78)
            {
                x0=x0+2;
                x1=x1+2;
            }
        }

        if(ventana.is_keyARROWUP())
        {
            y0=y0-2;
            y1=y1-2;
            if (y0<45)
            {
                y0=y0+2;
                y1=y1+2;
            }
        }
        imagen.draw_rectangle(x0,y0,x1,y1,azul_1);
    }
};
class ENEMIGOS : public HEROE
{
public:
    void enemigo_izquierda_derecha_1 (void)
    {
        imagen.draw_circle(v4,q4,17,rojo_2,1);

        if (v4 > 55 and rebote == true)
        {
            v4+=8;
            if(v4 >= 280)
            {
                rebote=false;
            }
        }
        if (v4 < 285 and rebote == false)
        {
            v4-=8;
            if (v4 <= 60)
            {
                rebote=true;
            }
        }
    }
    void enemigo_arriba_abajo_1 (void)
    {
        imagen.draw_circle(v1,q1,17,rojo_2,1);

        if (q1 > 55 and rebote == true)
        {
            q1+=8;
            if(q1 >= 280)
            {
                rebote=false;
            }
        }
        if (q1 < 285 and rebote == false)
        {
            q1-=8;
            if (q1 <= 60)
            {
                rebote=true;
            }
        }
    }
    void punto_critico_enemigo_arriba_abajo_1 (void)
    {
        d = sqrt(pow(v1-(x0+20),2)+pow(q1-y0,2));
        d2 = sqrt(pow(v1-(x0),2)+pow(q1-y0,2));
        d3 = sqrt(pow(v1-(x1-20),2)+pow(q1-y1,2));
        d4 = sqrt(pow(v1-(x1),2)+pow(q1-y1,2));
        if (d<=20 or d2<=20 or d3<=20 or d4<=20)
        {
            if (!ventana.is_keyCTRLLEFT())
            {
                contador_muertes++;
                contador_score-=100;
                x0 = 120, y0 = 160, x1 = 140, y1 = 180;
            }
        }
    }
    void enemigo_arriba_abajo_2 (void)
    {
        imagen.draw_circle(v2,q2,17,rojo_2,1);
        if (q2 > 55 and rebote2 == true)
        {
            q2+=8;
            if(q2 >= 280)
            {
                rebote2=false;
            }
        }
        if (q2 < 285 and rebote2 == false)
        {
            q2-=8;
            if (q2 <= 60)
            {
                rebote2=true;
            }
        }
    }
    void punto_critico_enemigo_arriba_abajo_2 (void)
    {
        d = sqrt(pow(v2-(x0+20),2)+pow(q2-y0,2));
        d2 = sqrt(pow(v2-(x0),2)+pow(q2-y0,2));
        d3 = sqrt(pow(v2-(x1-20),2)+pow(q2-y1,2));
        d4 = sqrt(pow(v2-(x1),2)+pow(q2-y1,2));
        if (d<=20 or d2<=20 or d3<=20 or d4<=20)
        {
            if (!ventana.is_keyCTRLLEFT())
            {
                contador_muertes++;
                contador_score-=100;
                x0 = 120, y0 = 160, x1 = 140, y1 = 180;
            }
        }
    }
    void enemigo_abajo_arriba_1 (void)
    {
        imagen.draw_circle(v3,q3,17,rojo_2,1);
        if (q3 < 285  and rebote3 == true)
        {
            q3-=8;
            if(q3 <= 60)
            {
                rebote3=false;
            }
        }
        if (q3 > 55 and rebote3 == false)
        {
            q3+=8;
            if (q3 >= 280)
            {
                rebote3=true;
            }
        }
    }
    void punto_critico_enemigo_abajo_arriba_1 (void)
    {
        d = sqrt(pow(v3-(x0+20),2)+pow(q3-y0,2));
        d2 = sqrt(pow(v3-(x0),2)+pow(q3-y0,2));
        d3 = sqrt(pow(v3-(x1-20),2)+pow(q3-y1,2));
        d4 = sqrt(pow(v3-(x1),2)+pow(q3-y1,2));
        if (d<=20 or d2<=20 or d3<=20 or d4<=20)
        {
            if (!ventana.is_keyCTRLLEFT())
            {
                contador_muertes++;
                contador_score-=100;
                x0 = 120, y0 = 160, x1 = 140, y1 = 180;
            }
        }
    }
};
class Nivel_uno : public ENEMIGOS
{
public:
    void Primera_parte (void)
    {
        x0 = 120, y0 = 160, x1 = 140, y1 = 180;
        q1 = 60, v1 = 380;
        salir = true;
        rebote = true;
        Marcador_muertes();
        while (salir)
        {
            marcadores_nivel_1();
            marcador_puntaje_minimo();
            puntaje();
            Marcador_muertes();
            cuadro();
            enemigo_arriba_abajo_1();
            punto_critico_enemigo_arriba_abajo_1();
            recta_final_tipo_1();
            ventana.display(imagen);
            ventana.wait(10);
            imagen.fill(imagen1);
        }
    }
    void marcadores_nivel_1 (void)
    {
        string texto_nivel_1;
        texto_nivel_1="Nivel 1";

        imagen.draw_text(600,15,texto_nivel_1.c_str(),cyan,0,1,24);
    }
};
class Nivel_dos : public Nivel_uno
{
public:
    void Segunda_parte (void)
    {
        x0 = 120, y0 = 160, x1 = 140, y1 = 180;
        q3 = 280, q1 = 60, v3 = 480, v1 = 280;
        salir = true;
        rebote = true;
        rebote3 = true;
        while (salir)
        {
            marcadores_nivel_2();
            puntaje();
            Marcador_muertes();
            marcador_puntaje_minimo();
            cuadro();
            imagen.draw_rectangle(x0,y0,x1,y1,azul_1);
            enemigo_arriba_abajo_1();
            enemigo_abajo_arriba_1();
            punto_critico_enemigo_arriba_abajo_1();
            punto_critico_enemigo_abajo_arriba_1();
            recta_final_tipo_2();
            ventana.display(imagen);
            ventana.wait(10);
            imagen.fill(imagen1);
        }

    }
    void marcadores_nivel_2 (void)
    {
        string texto_nivel_2;
        texto_nivel_2="Nivel 2";

        imagen.draw_text(600,15,texto_nivel_2.c_str(),cyan,0,1,24);
    }
};
class Nivel_tres : public Nivel_dos
{
public:
    void Tercera_parte (void)
    {
        x0 = 120, y0 = 160, x1 = 140, y1 = 180;
        q1 = 60, q2 = 60, q3 = 280, v1 = 280, v2 = 480, v3 = 380;
        salir = true;
        rebote=true;
        rebote2=true;
        rebote3=true;

        while (salir)
        {
            marcadores_nivel_3();
            puntaje();
            Marcador_muertes();
            marcador_puntaje_minimo();
            cuadro();
            imagen.draw_rectangle(x0,y0,x1,y1,azul_1);
            enemigo_arriba_abajo_1();
            enemigo_abajo_arriba_1();
            enemigo_arriba_abajo_2();
            punto_critico_enemigo_arriba_abajo_1();
            punto_critico_enemigo_abajo_arriba_1();
            punto_critico_enemigo_arriba_abajo_2();
            recta_final_tipo_1();
            ventana.display(imagen);
            ventana.wait(10);
            imagen.fill(imagen1);
        }
    }
    void marcadores_nivel_3 (void)
    {
        string texto_nivel_3;
        texto_nivel_3="Nivel 3";

        imagen.draw_text(600,15,texto_nivel_3.c_str(),cyan,0,1,24);
    }
};
class Nivel_cuatro : public Nivel_tres
{
public:

    void Cuarta_parte (void)
    {
        x0 = 120, y0 = 160, x1 = 140, y1 = 180;
        float x = 0, c0 = 370, c1 = 170;
        salir = true;
        while (salir)
        {
            d = sqrt(pow(c0+100*cos(x)-(x0+20),2)+pow(c1+100*sin(x)-y0,2));
            d2 = sqrt(pow(c0+100*cos(x)-(x0),2)+pow(c1+100*sin(x)-y0,2));
            d3 = sqrt(pow(c0+100*cos(x)-(x1-20),2)+pow(c1+100*sin(x)-y1,2));
            d4 = sqrt(pow(c0+100*cos(x)-(x1),2)+pow(c1+100*sin(x)-y1,2));
            marcadores_nivel_4();
            puntaje();
            Marcador_muertes();
            marcador_puntaje_minimo();
            cuadro();
            x+=.1111;
            imagen.draw_circle(c0+100*cos(x),c1+100*sin(x),17,rojo_2,1);
            if (d<=20 or d2<=20 or d3<=20 or d4<=20)
            {
                if (!ventana.is_keyCTRLLEFT())
                {
                    contador_muertes++;
                    contador_score-=100;
                    x0 = 120, y0 = 160, x1 = 140, y1 = 180;
                }
            }
            if (x>100000)
            {
                x=0;
            }
            recta_final_tipo_1();
            ventana.display(imagen);
            ventana.wait(10);
            imagen.fill(imagen1);
        }
    }
    void marcadores_nivel_4 (void)
    {
        string texto_nivel_4;
        texto_nivel_4="Nivel 4";

        imagen.draw_text(600,15,texto_nivel_4.c_str(),cyan,0,1,24);
    }
};
class Nivel_cinco : public Nivel_cuatro
{
public:

    void Quinta_parte (void)
    {
        x0 = 120, y0 = 160, x1 = 140, y1 = 180;
        float x = 0, c0 = 370, c1 = 170;
        salir = true;
        while (salir)
        {
            d = sqrt(pow(c0+100*cos(x)-(x0+20),2)+pow(c1+100*sin(x)-y0,2));
            d2 = sqrt(pow(c0+100*cos(x)-(x0),2)+pow(c1+100*sin(x)-y0,2));
            d3 = sqrt(pow(c0+100*cos(x)-(x1-20),2)+pow(c1+100*sin(x)-y1,2));
            d4 = sqrt(pow(c0+100*cos(x)-(x1),2)+pow(c1+100*sin(x)-y1,2));
            d5 = sqrt(pow(c0+50*cos(x)-(x0+20),2)+pow(c1+50*sin(x)-y0,2));
            d6 = sqrt(pow(c0+50*cos(x)-(x0),2)+pow(c1+50*sin(x)-y0,2));
            d7 = sqrt(pow(c0+50*cos(x)-(x1-20),2)+pow(c1+50*sin(x)-y1,2));
            d8 = sqrt(pow(c0+50*cos(x)-(x1),2)+pow(c1+50*sin(x)-y1,2));
            marcadores_nivel_5();
            marcador_puntaje_minimo();
            puntaje();
            Marcador_muertes();
            cuadro();
            x+=.08;
            imagen.draw_circle(c0+100*cos(x),c1+100*sin(x),17,rojo_2,1);
            imagen.draw_circle(c0+50*cos(x),c1+50*sin(x),17,rojo_2,1);
            if (d<=20 or d2<=20 or d3<=20 or d4<=20 or d5<=20 or d6<=20 or d7<=20 or d8<=20)
            {
                if (!ventana.is_keyCTRLLEFT())
                {
                    contador_muertes++;
                    contador_score-=100;
                    x0 = 120, y0 = 160, x1 = 140, y1 = 180;
                }
            }
            if (x>100000)
            {
                x=0;
            }
            recta_final_tipo_1();
            ventana.display(imagen);
            ventana.wait(10);
            imagen.fill(imagen1);
        }
    }
    void marcadores_nivel_5 (void)
    {
        string texto_nivel_5;
        texto_nivel_5="Nivel 5";

        imagen.draw_text(600,15,texto_nivel_5.c_str(),cyan,0,1,24);
    }
};
class Nivel_seis : public Nivel_cinco
{
public:

    void Sexta_parte (void)
    {
        x0 = 120, y0 = 160, x1 = 140, y1 = 180;
        float x = 0, c0 = 370, c1 = 170;
        salir = true;
        while (salir)
        {
            d = sqrt(pow(c0+100*cos(x)-(x0+20),2)+pow(c1+100*sin(x)-y0,2));
            d2 = sqrt(pow(c0+100*cos(x)-(x0),2)+pow(c1+100*sin(x)-y0,2));
            d3 = sqrt(pow(c0+100*cos(x)-(x1-20),2)+pow(c1+100*sin(x)-y1,2));
            d4 = sqrt(pow(c0+100*cos(x)-(x1),2)+pow(c1+100*sin(x)-y1,2));
            d5 = sqrt(pow(c0+50*cos(x)-(x0+20),2)+pow(c1+50*sin(x)-y0,2));
            d6 = sqrt(pow(c0+50*cos(x)-(x0),2)+pow(c1+50*sin(x)-y0,2));
            d7 = sqrt(pow(c0+50*cos(x)-(x1-20),2)+pow(c1+50*sin(x)-y1,2));
            d8 = sqrt(pow(c0+50*cos(x)-(x1),2)+pow(c1+50*sin(x)-y1,2));
            d9 = sqrt(pow(c0-(x0+20),2)+pow(c1-y0,2));
            d10 = sqrt(pow(c0-(x0),2)+pow(c1-y0,2));
            d11 = sqrt(pow(c0-(x1-20),2)+pow(c1-y1,2));
            d12 = sqrt(pow(c0-(x1),2)+pow(c1-y1,2));
            marcadores_nivel_6();
            marcador_puntaje_minimo();
            puntaje();
            Marcador_muertes();
            cuadro();
            x+=.09;
            imagen.draw_circle(c0+100*cos(x),c1+100*sin(x),17,rojo_2,1);
            imagen.draw_circle(c0+50*cos(x),c1+50*sin(x),17,rojo_2,1);
            imagen.draw_circle(c0+0*cos(x),c1+0*sin(x),17,rojo_2,1);
            if (d<=20 or d2<=20 or d3<=20 or d4<=20 or d5<=20 or d6<=20 or d7<=20 or d8<=20 or d9<=20 or d10<=20 or d11<=20 or d12<=20)
            {
                if (!ventana.is_keyCTRLLEFT())
                {
                    contador_muertes++;
                    contador_score-=100;
                    x0 = 120, y0 = 160, x1 = 140, y1 = 180;
                }
            }
            recta_final_tipo_1();
            ventana.display(imagen);
            ventana.wait(10);
            imagen.fill(imagen1);
        }
    }
    void marcadores_nivel_6 (void)
    {
        string texto_nivel_6;
        texto_nivel_6="Nivel 6";

        imagen.draw_text(600,15,texto_nivel_6.c_str(),cyan,0,1,24);
    }
};
class Nivel_siete : public Nivel_seis
{
public:


    void Septima_parte (void)
    {
        x0 = 120, y0 = 160, x1 = 140, y1 = 180;
        float x = 0, y = 0, c0 = 370, c1 = 170;
        salir = true;
        while (salir)
        {
            d = sqrt(pow(c0+100*cos(x)-(x0+20),2)+pow(c1+100*sin(x)-y0,2));
            d2 = sqrt(pow(c0+100*cos(x)-(x0),2)+pow(c1+100*sin(x)-y0,2));
            d3 = sqrt(pow(c0+100*cos(x)-(x1-20),2)+pow(c1+100*sin(x)-y1,2));
            d4 = sqrt(pow(c0+100*cos(x)-(x1),2)+pow(c1+100*sin(x)-y1,2));
            d5 = sqrt(pow(c0+50*cos(y)-(x0+20),2)+pow(c1+50*sin(y)-y0,2));
            d6 = sqrt(pow(c0+50*cos(y)-(x0),2)+pow(c1+50*sin(y)-y0,2));
            d7 = sqrt(pow(c0+50*cos(y)-(x1-20),2)+pow(c1+50*sin(y)-y1,2));
            d8 = sqrt(pow(c0+50*cos(y)-(x1),2)+pow(c1+50*sin(y)-y1,2));
            marcadores_nivel_7();
            puntaje();
            marcador_puntaje_minimo();
            Marcador_muertes();
            cuadro();
            x+=.1;
            y-=.1;
            imagen.draw_circle(c0+100*cos(x),c1+100*sin(x),17,rojo_2,1);
            imagen.draw_circle(c0+50*cos(y),c1+50*sin(y),17,rojo_2,1);
            if (d<=20 or d2<=20 or d3<=20 or d4<=20 or d5<=20 or d6<=20 or d7<=20 or d8<=20)
            {
                if (!ventana.is_keyCTRLLEFT())
                {
                    contador_muertes++;
                    contador_score-=100;
                    x0 = 120, y0 = 160, x1 = 140, y1 = 180;
                }
            }
            if (x>100000)
            {
                x=0;
            }
            if (y<-100000)
            {
                y=0;
            }
            recta_final_tipo_1();
            ventana.display(imagen);
            ventana.wait(10);
            imagen.fill(imagen1);
        }
    }
    void marcadores_nivel_7 (void)
    {
        string texto_nivel_7;
        texto_nivel_7="Nivel 7";

        imagen.draw_text(600,15,texto_nivel_7.c_str(),cyan,0,1,24);
    }
};
class Nivel_ocho : public Nivel_siete
{
public:
    void Octava_parte (void)
    {
        x0 = 120, y0 = 160, x1 = 140, y1 = 180;
        q1 = 60, q2 = 60, q3 = 280, q4 = 65 /*60*/, q5 = 60, v1 = 280, v2 = 480, v3 = 380, v4 = 210 /*60*/, v5 = 60;
        salir = true;
        rebote=true;
        rebote2=true;

        while (salir)
        {
            marcadores_nivel_8();
            Marcador_muertes();
            marcador_puntaje_minimo();
            cuadro();
            imagen.draw_rectangle(x0,y0,x1,y1,azul_1);
            imagen.draw_circle(v4,q4,17,rojo_2,1);

                if (v4 >= 190 and rebote == true)
                {
                    v4+=7;
                    if(v4 >= 540)
                    {
                        rebote=false;
                    }
                }
                if (q4 >= 50 and rebote2 == true)
                {
                    q4+=7;
                    if(q4 >= 280)
                    {
                        rebote2=false;
                    }
                }
                if (v4 <= 565 and rebote == false)
                {
                    v4-=7;
                    if(v4 <= 205)
                    {
                        rebote=true;
                    }
                }
                if (q4 <= 305 and rebote2 == false)
                {
                    q4-=7;
                    if (q4 <= 60)
                    {
                        rebote2=true;
                    }
                }
        d = sqrt(pow(v4-(x0+20),2)+pow(q4-y0,2));
        d2 = sqrt(pow(v4-(x0),2)+pow(q4-y0,2));
        d3 = sqrt(pow(v4-(x1-20),2)+pow(q4-y1,2));
        d4 = sqrt(pow(v4-(x1),2)+pow(q4-y1,2));
        if (d<=20 or d2<=20 or d3<=20 or d4<=20)
        {
            if (!ventana.is_keyCTRLLEFT())
            {
                contador_muertes++;
                contador_score-=100;
                x0 = 120, y0 = 160, x1 = 140, y1 = 180;
            }
        }
            puntaje();
            recta_final_tipo_1();
            ventana.display(imagen);
            ventana.wait(10);
            imagen.fill(imagen1);
        }
    }
    void marcadores_nivel_8 (void)
    {
        string texto_nivel_8;
        texto_nivel_8="Nivel 8";

        imagen.draw_text(600,15,texto_nivel_8.c_str(),cyan,0,1,24);
    }
};
class Nivel_nueve : public Nivel_ocho
{
public:
    void Novena_parte (void)
    {
        x0 = 120, y0 = 160, x1 = 140, y1 = 180;
        q4 = 65 , q5 = 65, v4 = 210 , v5 = 210;
        salir = true;
        rebote=true;
        rebote2=true;
        rebote3=true;
        rebote4=true;

        while (salir)
        {
            marcadores_nivel_9();
            Marcador_muertes();
            marcador_puntaje_minimo();
            cuadro();
            imagen.draw_rectangle(x0,y0,x1,y1,azul_1);
            imagen.draw_circle(v4,q4,17,rojo_2,1);
            imagen.draw_circle(v5,q5,17,rojo_2,1);

                if (v4 >= 190 and rebote == true)
                {
                    v4+=7;
                    if(v4 >= 540)
                    {
                        rebote=false;
                    }
                }
                if (q4 >= 50 and rebote2 == true)
                {
                    q4+=7;
                    if(q4 >= 280)
                    {
                        rebote2=false;
                    }
                }
                if (v4 <= 565 and rebote == false)
                {
                    v4-=7;
                    if(v4 <= 205)
                    {
                        rebote=true;
                    }
                }
                if (q4 <= 305 and rebote2 == false)
                {
                    q4-=7;
                    if (q4 <= 60)
                    {
                        rebote2=true;
                    }
                }
                if (v5 >= 190 and rebote3 == true)
                {
                    v5+=9;
                    if(v5 >= 540)
                    {
                        rebote3=false;
                    }
                }
                if (q5 >= 50 and rebote4 == true)
                {
                    q5+=9;
                    if(q5 >= 280)
                    {
                        rebote4=false;
                    }
                }
                if (v5 <= 565 and rebote3 == false)
                {
                    v5-=9;
                    if(v5 <= 205)
                    {
                        rebote3=true;
                    }
                }
                if (q5 <= 305 and rebote4 == false)
                {
                    q5-=9;
                    if (q5 <= 60)
                    {
                        rebote4=true;
                    }
                }
        d = sqrt(pow(v4-(x0+20),2)+pow(q4-y0,2));
        d2 = sqrt(pow(v4-(x0),2)+pow(q4-y0,2));
        d3 = sqrt(pow(v4-(x1-20),2)+pow(q4-y1,2));
        d4 = sqrt(pow(v4-(x1),2)+pow(q4-y1,2));
        d5 = sqrt(pow(v5-(x0+20),2)+pow(q5-y0,2));
        d6 = sqrt(pow(v5-(x0),2)+pow(q5-y0,2));
        d7 = sqrt(pow(v5-(x1-20),2)+pow(q5-y1,2));
        d8 = sqrt(pow(v5-(x1),2)+pow(q5-y1,2));
        if (d<=20 or d2<=20 or d3<=20 or d4<=20 or d5<=20 or d6<=20 or d7<=20 or d8<=20)
        {
            if (!ventana.is_keyCTRLLEFT())
            {
                contador_muertes++;
                contador_score-=100;
                x0 = 120, y0 = 160, x1 = 140, y1 = 180;
            }
        }
            puntaje();
            recta_final_tipo_1();
            ventana.display(imagen);
            ventana.wait(10);
            imagen.fill(imagen1);
        }
    }
    void marcadores_nivel_9 (void)
    {
        string texto_nivel_9;
        texto_nivel_9="Nivel 9";

        imagen.draw_text(600,15,texto_nivel_9.c_str(),cyan,0,1,24);
    }
};


int main ()
{
    bool salir=true;
    Nivel_nueve level;

    level.game_cuadrado();

    while(salir)
    {
         level.inicio();
         level.leer_puntaje_minimo();
         level.puntaje_minimo();
         level.Primera_parte();
         level.Segunda_parte();
         level.Tercera_parte();
         level.Cuarta_parte();
         level.Quinta_parte();
         level.Sexta_parte();
         level.Septima_parte();
         level.Octava_parte();
         level.Novena_parte();

         level.guardar_puntaje();

        salir = false;
    }
        return 0;
}
