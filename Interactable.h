//Interactable.h
#ifndef NEOPHYSICS_INTERACTABLE_H
#define NEOPHYSICS_INTERACTABLE_H

#include "Vector2.h"
#include <string>
#include <vector>

namespace Axis {
    static const int None               = 0;
    static const int X                  = 1;
    static const int Y                  = 2;
    static const int XY                 = 3;
}

namespace AtPhys {
    namespace Shapes {
        static const int Rectangle  = 1;
        static const int Disk       = 2;
        static const int Triangle   = 3;
    }

    class Interactable {
        //Members
        public:
            int Shape;
        protected:
            bool Collision, Interactive, Movable, Resizable;
            float Sector;
            Vector2 CollisionSize, InputSize, Position, Size, TargetPosition, TargetSize;
            std::vector<int> CollisionMap;
        //Access Methods
        public:
            Interactable();
            ~Interactable();
            float CollisionHeight();
            float CollisionWidth();
            float dHeight();
            float dWidth();
            float dX();
            float dY();
            float Section();
            float Height(int State = 1);
            bool IsCollidable(int Tile = 0);
            bool IsDriven();
            bool IsInteractive();
            bool IsMovable();
            bool IsResizable();
            float InputHeight();
            float InputWidth();
            float Radius();
            float Width(int State = 1);
            float X(int State = 1);
            float Y(int State = 1);
        //Process Methods
        public:
            void DropAt(float X, float Y);
            void EnableCollision(bool State, std::string CollisionMap = "");
            void EnableInteraction(bool State);
            void EnableMoving(bool State);
            void EnableResizing(bool State);
            void MoveBy(float X, float Y);
            void MoveTo(float X, float Y);
            void NudgeBy(float X, float Y);
            void Relax(int Axis = Axis::XY);
            void RelaxSize();
            void ResizeCollisionTo(float Width, float Height);
            void ResizeInputTo(float Width, float Height);
            void ResizeTo(float Width, float Height);
            void Section(float Sector);
            void StretchBy(float Width, float Height);
            void StretchTo(float Width, float Height);
    };
}

#endif

