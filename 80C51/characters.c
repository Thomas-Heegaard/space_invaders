#include <string.h>
#include "characters.h"
#include "main.h"
#include "t6963c.h"

#define ROM_CG_ADDRESS 0x0000

/**
 * Copie la définition d'un caractère depuis la ROM vers la zone de définition
 * des caractères du T6963C.
 * @param positionInRom Position du caractère dans la ROM.
 * @param cgCode Code du caractère dans le t6963c.
 */
void CHAR_copyFromRomToCg(unsigned char positionInRom, unsigned char cgCode) {
	unsigned char *rom_cg_address = (unsigned char __xdata *) (ROM_CG_ADDRESS + positionInRom * 8);
	unsigned int video_cg_address = cgCode * 8 + T6963C_ZONE_CG;
	T6963C_autoWrite(video_cg_address, rom_cg_address, 8);
}


/**
 * Initialise les caractères utilisés pendant le jeu.
 */
void CHAR_initialize() {
	CHAR_copyFromRomToCg( 0, OBSTACLE_A);
	CHAR_copyFromRomToCg( 1, OBSTACLE_B);
	CHAR_copyFromRomToCg( 2, OBSTACLE_C);
	CHAR_copyFromRomToCg( 3, OBSTACLE_D);
	CHAR_copyFromRomToCg( 4, OBSTACLE_E);
	CHAR_copyFromRomToCg( 5, OBSTACLE_F);
	CHAR_copyFromRomToCg( 6, OBSTACLE_G);
	CHAR_copyFromRomToCg( 7, OBSTACLE_H);

	CHAR_copyFromRomToCg( 8, PLAYER_CHAR);
	CHAR_copyFromRomToCg( 9, PROJECTILE_CHAR);
	CHAR_copyFromRomToCg(10, EXPLOSION_CHAR);
	CHAR_copyFromRomToCg(11, ALIENLVL1_CHAR);
	CHAR_copyFromRomToCg(12, ALIENLVL2_CHAR);
	CHAR_copyFromRomToCg(13, ALIENLVL3_CHAR);
	CHAR_copyFromRomToCg(14, SHIELDTL_CHAR);
	CHAR_copyFromRomToCg(15, SHIELDTR_CHAR);
	CHAR_copyFromRomToCg(16, SHIELDBL_CHAR);
	CHAR_copyFromRomToCg(17, SHIELDBR_CHAR);

}