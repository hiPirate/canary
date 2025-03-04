/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (C) 2021 OpenTibiaBR <opentibiabr@outlook.com>
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
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef SRC_LUA_FUNCTIONS_CORE_GAME_CONFIG_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_CORE_GAME_CONFIG_FUNCTIONS_HPP_

#include "config/configmanager.h"
#include "declarations.hpp"
#include "lua/scripts/luascript.h"

class ConfigFunctions final : LuaScriptInterface {
	public:
		static void init(lua_State* L) {
			registerTable(L, "configManager");
			registerMethod(L, "configManager", "getString", ConfigFunctions::luaConfigManagerGetString);
			registerMethod(L, "configManager", "getNumber", ConfigFunctions::luaConfigManagerGetNumber);
			registerMethod(L, "configManager", "getBoolean", ConfigFunctions::luaConfigManagerGetBoolean);

			#define registerEnumIn(L, tableName, value) { \
				std::string enumName = #value; \
				registerVariable(L, tableName, enumName.substr(enumName.find_last_of(':') + 1), value); \
			}
			registerTable(L, "configKeys");
			registerEnumIn(L, "configKeys", ALLOW_CHANGEOUTFIT)
			registerEnumIn(L, "configKeys", ONE_PLAYER_ON_ACCOUNT)
			registerEnumIn(L, "configKeys", AIMBOT_HOTKEY_ENABLED)
			registerEnumIn(L, "configKeys", REMOVE_RUNE_CHARGES)
			registerEnumIn(L, "configKeys", EXPERIENCE_FROM_PLAYERS)
			registerEnumIn(L, "configKeys", FREE_PREMIUM)
			registerEnumIn(L, "configKeys", REPLACE_KICK_ON_LOGIN)
			registerEnumIn(L, "configKeys", ALLOW_CLONES)
			registerEnumIn(L, "configKeys", BIND_ONLY_GLOBAL_ADDRESS)
			registerEnumIn(L, "configKeys", OPTIMIZE_DATABASE)
			registerEnumIn(L, "configKeys", MARKET_PREMIUM)
			registerEnumIn(L, "configKeys", EMOTE_SPELLS)
			registerEnumIn(L, "configKeys", STAMINA_SYSTEM)
			registerEnumIn(L, "configKeys", WARN_UNSAFE_SCRIPTS)
			registerEnumIn(L, "configKeys", CONVERT_UNSAFE_SCRIPTS)
			registerEnumIn(L, "configKeys", CLASSIC_EQUIPMENT_SLOTS)
			registerEnumIn(L, "configKeys", ALLOW_BLOCK_SPAWN)
			registerEnumIn(L, "configKeys", CLASSIC_ATTACK_SPEED)
			registerEnumIn(L, "configKeys", REMOVE_WEAPON_AMMO)
			registerEnumIn(L, "configKeys", REMOVE_WEAPON_CHARGES)
			registerEnumIn(L, "configKeys", REMOVE_POTION_CHARGES)
			registerEnumIn(L, "configKeys", STOREMODULES)
			registerEnumIn(L, "configKeys", WEATHER_RAIN)
			registerEnumIn(L, "configKeys", WEATHER_THUNDER)
			registerEnumIn(L, "configKeys", FREE_QUESTS)
			registerEnumIn(L, "configKeys", ALL_CONSOLE_LOG)
			registerEnumIn(L, "configKeys", SERVER_SAVE_NOTIFY_MESSAGE)
			registerEnumIn(L, "configKeys", SERVER_SAVE_NOTIFY_DURATION)
			registerEnumIn(L, "configKeys", SERVER_SAVE_CLEAN_MAP)
			registerEnumIn(L, "configKeys", SERVER_SAVE_CLOSE)
			registerEnumIn(L, "configKeys", SERVER_SAVE_SHUTDOWN)
			registerEnumIn(L, "configKeys", MAP_NAME)
			registerEnumIn(L, "configKeys", MAP_CUSTOM_NAME)
			registerEnumIn(L, "configKeys", MAP_CUSTOM_FILE)
			registerEnumIn(L, "configKeys", MAP_CUSTOM_SPAWN)
			registerEnumIn(L, "configKeys", MAP_CUSTOM_ENABLED)
			registerEnumIn(L, "configKeys", HOUSE_RENT_PERIOD)
			registerEnumIn(L, "configKeys", SERVER_NAME)
			registerEnumIn(L, "configKeys", OWNER_NAME)
			registerEnumIn(L, "configKeys", OWNER_EMAIL)
			registerEnumIn(L, "configKeys", URL)
			registerEnumIn(L, "configKeys", LOCATION)
			registerEnumIn(L, "configKeys", IP)
			registerEnumIn(L, "configKeys", MOTD)
			registerEnumIn(L, "configKeys", WORLD_TYPE)
			registerEnumIn(L, "configKeys", MYSQL_HOST)
			registerEnumIn(L, "configKeys", MYSQL_USER)
			registerEnumIn(L, "configKeys", MYSQL_PASS)
			registerEnumIn(L, "configKeys", MYSQL_DB)
			registerEnumIn(L, "configKeys", MYSQL_SOCK)
			registerEnumIn(L, "configKeys", DEFAULT_PRIORITY)
			registerEnumIn(L, "configKeys", MAP_AUTHOR)
			registerEnumIn(L, "configKeys", STORE_IMAGES_URL)
			registerEnumIn(L, "configKeys", CLIENT_VERSION_STR)
			registerEnumIn(L, "configKeys", PARTY_LIST_MAX_DISTANCE)
			registerEnumIn(L, "configKeys", SQL_PORT)
			registerEnumIn(L, "configKeys", MAX_PLAYERS)
			registerEnumIn(L, "configKeys", PZ_LOCKED)
			registerEnumIn(L, "configKeys", DEFAULT_DESPAWNRANGE)
			registerEnumIn(L, "configKeys", DEFAULT_DESPAWNRADIUS)
			registerEnumIn(L, "configKeys", RATE_EXPERIENCE)
			registerEnumIn(L, "configKeys", RATE_SKILL)
			registerEnumIn(L, "configKeys", RATE_LOOT)
			registerEnumIn(L, "configKeys", RATE_MAGIC)
			registerEnumIn(L, "configKeys", RATE_SPAWN)
			registerEnumIn(L, "configKeys", HOUSE_PRICE)
			registerEnumIn(L, "configKeys", MAX_MESSAGEBUFFER)
			registerEnumIn(L, "configKeys", ACTIONS_DELAY_INTERVAL)
			registerEnumIn(L, "configKeys", EX_ACTIONS_DELAY_INTERVAL)
			registerEnumIn(L, "configKeys", KICK_AFTER_MINUTES)
			registerEnumIn(L, "configKeys", PROTECTION_LEVEL)
			registerEnumIn(L, "configKeys", DEATH_LOSE_PERCENT)
			registerEnumIn(L, "configKeys", STATUSQUERY_TIMEOUT)
			registerEnumIn(L, "configKeys", FRAG_TIME)
			registerEnumIn(L, "configKeys", WHITE_SKULL_TIME)
			registerEnumIn(L, "configKeys", GAME_PORT)
			registerEnumIn(L, "configKeys", LOGIN_PORT)
			registerEnumIn(L, "configKeys", STATUS_PORT)
			registerEnumIn(L, "configKeys", STAIRHOP_DELAY)
			registerEnumIn(L, "configKeys", MARKET_OFFER_DURATION)
			registerEnumIn(L, "configKeys", CHECK_EXPIRED_MARKET_OFFERS_EACH_MINUTES)
			registerEnumIn(L, "configKeys", MAX_MARKET_OFFERS_AT_A_TIME_PER_PLAYER)
			registerEnumIn(L, "configKeys", EXP_FROM_PLAYERS_LEVEL_RANGE)
			registerEnumIn(L, "configKeys", MAX_PACKETS_PER_SECOND)
			registerEnumIn(L, "configKeys", STORE_COIN_PACKET)
			registerEnumIn(L, "configKeys", CLIENT_VERSION)
			registerEnumIn(L, "configKeys", DAY_KILLS_TO_RED)
			registerEnumIn(L, "configKeys", WEEK_KILLS_TO_RED)
			registerEnumIn(L, "configKeys", MONTH_KILLS_TO_RED)
			registerEnumIn(L, "configKeys", RED_SKULL_DURATION)
			registerEnumIn(L, "configKeys", BLACK_SKULL_DURATION)
			registerEnumIn(L, "configKeys", ORANGE_SKULL_DURATION)
			registerEnumIn(L, "configKeys", RATE_MONSTER_HEALTH)
			registerEnumIn(L, "configKeys", RATE_MONSTER_ATTACK)
			registerEnumIn(L, "configKeys", RATE_MONSTER_DEFENSE)
			registerEnumIn(L, "configKeys", RATE_NPC_HEALTH)
			registerEnumIn(L, "configKeys", RATE_NPC_ATTACK)
			registerEnumIn(L, "configKeys", RATE_NPC_DEFENSE)
			#undef registerEnumIn
		}

	private:
		static int luaConfigManagerGetBoolean(lua_State* L);
		static int luaConfigManagerGetNumber(lua_State* L);
		static int luaConfigManagerGetString(lua_State* L);
};

#endif  // SRC_LUA_FUNCTIONS_CORE_GAME_CONFIG_FUNCTIONS_HPP_
