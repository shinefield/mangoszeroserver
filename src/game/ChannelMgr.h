/**
 * mangos-zero is a full featured server for World of Warcraft in its vanilla
 * version, supporting clients for patch 1.12.x.
 *
 * Copyright (C) 2005-2014  MaNGOS project  <http://getmangos.com>
 * Parts Copyright (C) 2013-2014  CMaNGOS project <http://cmangos.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * World of Warcraft, and all World of Warcraft or Warcraft art, images,
 * and lore are copyrighted by Blizzard Entertainment, Inc.
 */

#ifndef MANGOS_H_CHANNELMGR
#define MANGOS_H_CHANNELMGR

#include <map>
#include <string>

#include "Policies/Singleton.h"
#include "Common.h"
#include "Channel.h"

class ChannelMgr
{
    public:
        typedef std::map<std::wstring, Channel*> ChannelMap;
        ChannelMgr() {}
        ~ChannelMgr();

        Channel* GetJoinChannel(std::string name, uint32 channel_id);
        Channel* GetChannel(std::string name, Player* p, bool pkt = true);
        void LeftChannel(std::string name);
    private:
        ChannelMap channels;
        void MakeNotOnPacket(WorldPacket* data, std::string name);
};

class AllianceChannelMgr : public ChannelMgr {};
class HordeChannelMgr    : public ChannelMgr {};

ChannelMgr* channelMgr(Team team);

#endif
