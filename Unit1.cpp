//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x=-8,y=-8;

bool kolizja(TImage *pilka, TImage *cegla)
{
   if( pilka->Left <= cegla->Left+cegla->Width &&
       pilka->Left >= cegla->Left-pilka->Width &&
       pilka->Top <= cegla->Top+cegla->Height &&
       pilka->Top >= cegla->Top-pilka->Height

       ) return true;
      else return false;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        ball->Left +=x;
        ball->Top +=y;

        if(ball->Left <= tlo->Left) x = -x;

        if(ball->Top <= tlo->Top) y = -y;

        if(ball->Left+ball->Width >= tlo->Width) x=-x;

        //skucha!
    if (ball->Top >= pad->Top+pad->Height+15)
    {
        ball->Visible=false;
    }
    //odbicie pilki (ball) od paletki (pad)
    else if(ball->Left > pad->Left-ball->Width/2 && ball->Left < pad->Left+pad->Width &&
       ball->Top+ball->Height > pad->Top)
       {
               if (y>0) y=-y;
       }

    //Brick1
    if(kolizja(ball, brick1)==true && brick1->Visible==true)
    {
        x=-x; y=-y; brick1->Visible=false;
    }

    //Brick2
    if(kolizja(ball, brick2)==true && brick2->Visible==true)
    {
        x=-x; y=-y; brick2->Visible=false;
    }

    //Brick3
    if(kolizja(ball, brick3)==true && brick3->Visible==true)
    {
        x=-x; y=-y; brick3->Visible=false;
    }

    //Brick4
    if(kolizja(ball, brick4)==true && brick4->Visible==true)
    {
        x=-x; y=-y; brick4->Visible=false;
    }

    //Brick5
    if(kolizja(ball, brick5)==true && brick5->Visible==true)
    {
        x=-x; y=-y; brick5->Visible=false;
    }

    //Brick6
    if(kolizja(ball, brick6)==true && brick6->Visible==true)
    {
        x=-x; y=-y; brick6->Visible=false;
    }

    //Brick7
    if(kolizja(ball, brick7)==true && brick7->Visible==true)
    {
        x=-x; y=-y; brick7->Visible=false;
    }

    //Brick8
    if(kolizja(ball, brick8)==true && brick8->Visible==true)
    {
        x=-x; y=-y; brick8->Visible=false;
    }

    //Brick9
    if(kolizja(ball, brick9)==true && brick9->Visible==true)
    {
        x=-x; y=-y; brick9->Visible=false;
    }

    //Brick10
    if(kolizja(ball, brick10)==true && brick10->Visible==true)
    {
        x=-x; y=-y; brick10->Visible=false;
    }

    //Brick11
    if(kolizja(ball, brick11)==true && brick11->Visible==true)
    {
        x=-x; y=-y; brick11->Visible=false;
    }

    //Brick12
    if(kolizja(ball, brick12)==true && brick12->Visible==true)
    {
        x=-x; y=-y; brick12->Visible=false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LewoTimer(TObject *Sender)
{
        if(pad->Left > tlo->Left+15) pad->Left -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PrawoTimer(TObject *Sender)
{
       if(pad->Left+pad->Width < tlo->Width-15) pad->Left += 10;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_LEFT) Lewo->Enabled=true;
        if(Key == VK_RIGHT) Prawo->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_LEFT) Lewo->Enabled=false;
        if(Key == VK_RIGHT) Prawo->Enabled=false;
}
//---------------------------------------------------------------------------



