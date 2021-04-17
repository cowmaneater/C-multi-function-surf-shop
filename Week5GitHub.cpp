// week5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;



void intro()
{
    cout.width(60);
    cout << setfill('*') << setw(60);
    cout << "" << endl;
    cout << "" << right << setfill('*') << setw(5) << "" << " Welcome to my Johnny Utah's PointBreak Surf Shop " << right << setfill('*') << setw(5) << "" << endl;
    cout << setfill('*') << setw(60);
    cout << "" << endl;
    cout << endl;
    cout << endl;




}

void ShowUsage()
{
    cout << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchases press 'C'" << endl;
    cout << "To display tolal amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl;



}

void MakePurchase(int& iTotalXXXSmall,int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
    iTotalSmall = 0 + iTotalSmall;
    iTotalMedium = 0 + iTotalMedium;
    iTotalLarge = 0 + iTotalLarge;
    iTotalXXXSmall = 0 + iTotalXXXSmall;



}
void DisplayPurchase(const int iTotalXXXSmall,const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{   
    if (iTotalXXXSmall != 0)
        cout << "The total number of XXX small surfboards is " << iTotalXXXSmall << endl;
    if (iTotalSmall != 0)
        cout << "The total number of small surfboards is " << iTotalSmall << endl;
    if (iTotalMedium != 0)
        cout << "The total number of medium surfboards is " << iTotalMedium << endl;
    if (iTotalLarge != 0)
        cout << "The total number of large surfboards is " << iTotalLarge << endl;
    if ((iTotalSmall == 0) && (iTotalMedium == 0) && (iTotalLarge == 0)&& (iTotalXXXSmall == 0))
        cout << "No purchases made yet." << endl;

    cout << endl;


}

void DisplayTotal(const int iTotalXXXSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
    const int XXXScost = 5;
    const int Scost = 175;
    const int Mcost = 190;
    const int Lcost = 200;
    int Stotal = Scost * iTotalSmall;
    int Mtotal = Mcost * iTotalMedium;
    int Ltotal = Lcost * iTotalLarge;
    int XXXStotal = XXXScost * iTotalXXXSmall;
    int Atotal = Stotal + Mtotal + Ltotal + XXXStotal;

    cout.precision(2);
    if (iTotalXXXSmall != 0)
        cout << "The total number of small surfboards is " << iTotalXXXSmall << " at a total of " << fixed << XXXStotal << endl;
    if (iTotalSmall != 0)
        cout << "The total number of small surfboards is " << iTotalSmall << " at a total of " << fixed << Stotal << endl;
    if (iTotalMedium != 0)
        cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << fixed << Mtotal << endl;
    if (iTotalLarge != 0)
        cout << "The total number of large surfboards is " << iTotalMedium << " at a total of $" << fixed << Ltotal << endl;
    if ((iTotalSmall != 0) || (iTotalMedium != 0) || (iTotalLarge != 0)|| (iTotalXXXSmall != 0))
        cout << "Amount due: $" << fixed << Atotal << endl;
    else
        cout << "No purchases made yet." << endl;

    cout << endl;

}


//intro into main program

int main()
{
    int LoopControl = 0;
    string selectLetter;
    string boardSize;
    int boardNum;
    int iTotalSmall = 0;
    int iTotalMedium = 0;
    int iTotalLarge = 0;
    int iTotalXXXSmall = 0;

    intro();

    ShowUsage();
    cout << endl;

    //Loop for user selection
    while (LoopControl == 0)
    {
        cout << "Please enter selection: ";
        cin >> selectLetter;

        //compare string no matter the case
        transform(selectLetter.begin(), selectLetter.end(), selectLetter.begin(), ::tolower);



        if (selectLetter == "s")
        {

            //clears console window
            system("CLS");
            intro();
            ShowUsage();
            cout << endl;

        }
        else if (selectLetter == "p")
        {


            cout << "Please enter the quanity and type( X= XXX Small, S = small, M = medium, L = large) of surfboard you would like to purchase : ";
            cin >> boardNum >> boardSize;
            cout << endl;
            cout << endl;
            //compare string no matter the case
            transform(boardSize.begin(), boardSize.end(), boardSize.begin(), ::tolower);

            //loop through to add selection to total
            if (boardSize == "s")
                iTotalSmall = iTotalSmall + boardNum;
            else if (boardSize == "m")
                iTotalMedium = iTotalMedium + boardNum;
            else if (boardSize == "l")
                iTotalLarge = iTotalLarge + boardNum;
            else if (boardSize == "x")
                iTotalXXXSmall = iTotalXXXSmall + boardNum;
            else
                return -1;

            MakePurchase(iTotalXXXSmall, iTotalSmall, iTotalMedium, iTotalLarge);



        }
        else if (selectLetter == "c")
        {
            DisplayPurchase(iTotalXXXSmall, iTotalSmall, iTotalMedium, iTotalLarge);
        }
        else if (selectLetter == "t")
        {
            DisplayTotal(iTotalXXXSmall , iTotalSmall, iTotalMedium, iTotalLarge);
        }
        else if (selectLetter == "q")
        {
            cout << "Thank you" << endl;
            //ends while loop
            LoopControl == 1;
            system("pause");
            break;

        }

    }


    return 1;
}

