#include "emu.h"
#include "cpu/tms0980/tms0980.h"

/* Layout */
#include "stopthie.lh"


class stopthie_state : public driver_device
{
public:
	stopthie_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag) ,
		m_maincpu(*this, "maincpu") { }

	DECLARE_READ8_MEMBER(stopthie_read_k);
	DECLARE_WRITE16_MEMBER(stopthie_write_o);
	DECLARE_WRITE16_MEMBER(stopthie_write_r);
	required_device<cpu_device> m_maincpu;
};



#define LOG 1

static INPUT_PORTS_START( stopthie )
INPUT_PORTS_END


READ8_MEMBER(stopthie_state::stopthie_read_k)
{
	UINT8 data = 0;

	if (LOG)
		logerror( "stopthie_read_k\n" );

	return data;
}


WRITE16_MEMBER(stopthie_state::stopthie_write_o)
{
	if (LOG)
		logerror( "stopthie_write_o: write %02x\n", data );
}


WRITE16_MEMBER(stopthie_state::stopthie_write_r)
{
	if (LOG)
		logerror( "stopthie_write_r: write %04x\n", data );
}





static MACHINE_CONFIG_START( stopthie, stopthie_state )

	/* basic machine hardware */
	MCFG_CPU_ADD( "maincpu", TMS0980, 500000 ) /* Clock is wrong */
	MCFG_TMS1XXX_READ_K_CB( READ8( stopthie_state, stopthie_read_k ) )
	MCFG_TMS1XXX_WRITE_O_CB( WRITE16( stopthie_state, stopthie_write_o ) )
	MCFG_TMS1XXX_WRITE_R_CB( WRITE16( stopthie_state, stopthie_write_r ) )

	MCFG_DEFAULT_LAYOUT(layout_stopthie)
MACHINE_CONFIG_END

ROM_START( stopthie )
	ROM_REGION( 0x1000, "maincpu", 0 )
	ROM_LOAD16_WORD( "stopthie.bin", 0x0000, 0x1000, CRC(03691115) SHA1(bdcd212aa50bb1c26cb2d0ee97e5cfc04841c108) )

	ROM_REGION( 1246, "maincpu:ipla", 0 )
	ROM_REGION( 1982, "maincpu:mpla", 0 )
	ROM_REGION( 352, "maincpu:opla", 0 )
	ROM_REGION( 157, "maincpu:spla", 0 )
ROM_END

/***************************************************************************

  Game driver(s)

***************************************************************************/

/*    YEAR  NAME        PARENT  COMPAT  MACHINE     INPUT   INIT    COMPANY            FULLNAME      FLAGS */
CONS( 1979, stopthie,   0,      0,      stopthie,   stopthie, driver_device,  0,      "Parker Brothers", "Stop Thief", GAME_NOT_WORKING | GAME_NO_SOUND)
