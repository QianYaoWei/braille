#include <iostream>
#include "braille_screen.h"
#include "Pos.h"

using namespace std;

void BrailleScreen::OnTouch(const Pos &pos)
{
    BrailleSquareSptr sptr = GetSqure(pos);
    if (sptr) {
        sptr->Activate();
        cout<<"move here"<<endl;
        return;
    }
    cout<<"move here"<<endl;
}

void BrailleScreen::OnUpScreen()
{
    for (auto &elem : _allSquares) {
        elem->Inactivate();
    }

    return;
}

BrailleSquareSptr BrailleScreen::GetSqure(const Pos &pos)
{
    for (auto &elem : _allSquares) {
        if ( elem->IsInside(pos) ) {
            return elem;
        }
    }

    return nullptr;
}

void BrailleScreen::Down(const Pos &pos)
{
    auto sptr = GetSqure(pos);
    if ( sptr ) {
        sptr->OnDown();
    }
}

void BrailleScreen::DownUp(const Pos &pos)
{
    auto sptr = GetSqure(pos);
    if ( sptr ) {
        sptr->OnDownUp();
    }
}

void BrailleScreen::Up(const Pos &pos)
{
    auto sptr = GetSqure(pos);
    if ( sptr ) {
        sptr->OnUp();
    }
}

void BrailleScreen::UpDown(const Pos &pos)
{
    auto sptr = GetSqure(pos);
    if ( sptr ) {
        sptr->OnUpDown();
    }
}

void BrailleScreen::ResetSquares(SquareType type)
{
    switch ( type ) {
        case SquareType_Norm:	
            for (auto &elem : _normSquares) {
                elem->ResetPoint();
            }
            break;

        case SquareType_Func:	
            for (auto &elem : _funcSquares) {
                elem->ResetPoint();
            }
            break;

        case SquareType_All:
            for (auto &elem : _allSquares) {
                elem->ResetPoint();
            }
            break;
        default:	
            break;
    }				/* -----  end switch  ----- */
}

void BrailleScreen::ClearSquares(SquareType type)
{
    switch ( type ) {
        case SquareType_Norm:	
            _normSquares.clear();
            _allSquares.clear();
            std::copy(_funcSquares.begin(), _funcSquares.end(), back_inserter(_allSquares));
            break;

        case SquareType_Func:	
            _funcSquares.clear();
            _allSquares.clear();
            std::copy(_normSquares.begin(), _normSquares.end(), back_inserter(_allSquares));
            break;

        case SquareType_All:
            _normSquares.clear();
            _funcSquares.clear();
            _allSquares.clear();
            break;
        default:	
            break;
    }				/* -----  end switch  ----- */
}

void BrailleScreen::AddSquare(const Pos &pos, SquareType type)
{
    BrailleSquareSptr sptr = std::make_shared<BrailleSquare>();
    if ( sptr ) {
        sptr->SetPos(pos);
        switch ( type ) {
            case SquareType_Norm:	
                _normSquares.push_back(sptr);
                _allSquares.push_back(sptr);
                break;

            case SquareType_Func:	
                _funcSquares.push_back(sptr);
                _allSquares.push_back(sptr);
                break;

            default:	
                break;
        }				/* -----  end switch  ----- */
    }
}
