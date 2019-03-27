#include "stdafx.h"
#include "MapleTicket.h"


MapleTicket::MapleTicket()
{
}


MapleTicket::~MapleTicket()
{
}

MapleTicket MapleTicket::Create(TitleInfo * ti)
{
	if (ti->id)
	{
		MapleTicket ticket;

		string tiktem (
			"00010004d15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed15abe11a"
			"d15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed"
			"15abe11ad15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed15abe11a"
			"d15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed"
			"15abe11ad15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed15abe11a"
			"d15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed"
			"15abe11ad15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed15abe11ad15ea5ed15abe11a"
			"d15ea5ed15abe11a00000000000000000000000000000000000000000000000000000000"
			"0000000000000000000000000000000000000000000000000000000000000000526f6f74"
			"2d434130303030303030332d585330303030303030630000000000000000000000000000"
			"000000000000000000000000000000000000000000000000feedfacefeedfacefeedface"
			"feedfacefeedfacefeedfacefeedfacefeedfacefeedfacefeedfacefeedfacefeedface"
			"feedfacefeedfacefeedface010000cccccccccccccccccccccccccccccccc0000000000"
			"0000000000000000aaaaaaaaaaaaaaaa0000000000000000000000000000000000000000"
			"000000000000000000000000000000000000000000000000000000000000000000000000"
			"000000000001000000000000000000000000000000000000000000000000000000000000"
			"000000000000000000000000000000000000000000000000000000000000000000000000"
			"000000000000000000000000000000000000000000000000000000000000000000000000"
			"0000000000000000000000000000000000000000000000000000000000010014000000ac"
			"000000140001001400000000000000280000000100000084000000840003000000000000"
			"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000000"
			"000000000000000000000000000000000000000000000000000000000000000000000000"
			"000000000000000000000000000000000000000000000000000000000000000000000000"
			"0000000000000000000000000000000000000000");
		
		//memcpy(&tiktem[0xA6 * 2], ti->versions, 2);
		//memcpy(&tiktem[0x18C * 2], ti->id, 16);
		memcpy(&tiktem[0x1BF * 2], ti->key, 32);

		ticket.length = (int)tiktem.length();
		ticket.ticket = new char[ticket.length];

		auto vbytes = HexToBytes(tiktem.c_str());
		unsigned char* bytes = vbytes.data();
		ticket.length = (int)vbytes.size();
		memcpy(ticket.ticket, bytes, ticket.length);

		return ticket;
	}

	return MapleTicket();
}
