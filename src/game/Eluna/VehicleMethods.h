/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef ELUNA_H_VEHICLEMETHODS
#define ELUNA_H_VEHICLEMETHODS

#ifndef CLASSIC
#ifndef TBC

namespace LuaVehicle
{
    /* BOOLEAN */
    int IsOnBoard(lua_State* L, Vehicle* vehicle)
    {
        Unit* passenger = Eluna::CHECKOBJ<Unit>(L, 2);
#ifndef TRINITY
        Eluna::Push(L, vehicle->HasOnBoard(passenger));
#else
        Eluna::Push(L, passenger->IsOnVehicle(vehicle->GetBase()));
#endif
        return 1;
    }

    /* GETTERS */
    int GetOwner(lua_State* L, Vehicle* vehicle)
    {
#ifndef TRINITY
        Eluna::Push(L, vehicle->GetOwner());
#else
        Eluna::Push(L, vehicle->GetBase());
#endif
        return 1;
    }

    int GetEntry(lua_State* L, Vehicle* vehicle)
    {
#ifndef TRINITY
        Eluna::Push(L, vehicle->GetVehicleEntry()->m_ID);
#else
        Eluna::Push(L, vehicle->GetVehicleInfo()->m_ID);
#endif
        return 1;
    }

    int GetPassenger(lua_State* L, Vehicle* vehicle)
    {
        int8 seatId = Eluna::CHECKVAL<int8>(L, 2);
        Eluna::Push(L, vehicle->GetPassenger(seatId));
        return 1;
    }

    /* OTHER */
    int AddPassenger(lua_State* L, Vehicle* vehicle)
    {
        Unit* passenger = Eluna::CHECKOBJ<Unit>(L, 2);
        int8 seatId = Eluna::CHECKVAL<int8>(L, 3);
#ifndef TRINITY
        if (vehicle->CanBoard(passenger))
            vehicle->Board(passenger, seatId);
#else
        vehicle->AddPassenger(passenger, seatId);
#endif
        return 0;
    }

    int RemovePassenger(lua_State* L, Vehicle* vehicle)
    {
        Unit* passenger = Eluna::CHECKOBJ<Unit>(L, 2);
#ifndef TRINITY
        vehicle->UnBoard(passenger, false);
#else
        vehicle->RemovePassenger(passenger);
#endif
        return 0;
    }
}

#endif
#endif

#endif