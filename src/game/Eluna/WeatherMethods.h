/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef ELUNA_H_WEATHERMETHODS
#define ELUNA_H_WEATHERMETHODS

namespace LuaWeather
{
    /* GETTERS */
    int GetZoneId(lua_State* L, Weather* weather)
    {
        Eluna::Push(L, weather->GetZone());
        return 1;
    }

    /* SETTERS */
    int SetWeather(lua_State* L, Weather* weather)
    {
        uint32 weatherType = Eluna::CHECKVAL<uint32>(L, 2);
        float grade = Eluna::CHECKVAL<float>(L, 3);

        weather->SetWeather((WeatherType)weatherType, grade);
        return 0;
    }

    int SendWeatherUpdateToPlayer(lua_State* L, Weather* weather)
    {
        Player* player = Eluna::CHECKOBJ<Player>(L, 2);

        weather->SendWeatherUpdateToPlayer(player);
        return 0;
    }

    /* OTHER */
    int Regenerate(lua_State* L, Weather* weather)
    {
        Eluna::Push(L, weather->ReGenerate());
        return 1;
    }

    int UpdateWeather(lua_State* L, Weather* weather)
    {
        Eluna::Push(L, weather->UpdateWeather());
        return 1;
    }
};

#endif
