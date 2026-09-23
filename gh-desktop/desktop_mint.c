/* ATOS DESKTOP.PRG - wariant pod toolchain mint (sprawdzony crt0 + gemlib).
 * Budowa:  m68k-atari-mint-gcc -mshort -O2 -o DESKTOP.PRG desktop_mint.c
 * Uruchamiany z GEM (po starcie AES). Rysuje gorny pasek + zegar.
 */
#include <aes.h>
#include <vdi.h>
#include <osbind.h>

static void bar_and_clock(int handle)
{
    int i;
    /* v_bar: wypelniony prostokat (2 punkty) */
    int pxy[4] = { 0, 0, 639, 15 };
    vsf_color(handle, 1);
    v_bar(handle, pxy);
    (void)i;
}

int main(void)
{
    int handle = 1;
    int i, dum;
    int work_in[11];
    int work_out[57];

    appl_init();
    for (i = 0; i < 10; i++) work_in[i] = 1;
    work_in[10] = 2;
    v_opnvwk(work_in, &handle, work_out);
    if (handle <= 0) handle = 1;

    bar_and_clock(handle);

    for (;;) {
        unsigned long t = Tgettime();      /* GEMDOS: czas systemowy */
        (void)t;
        /* docelowo: v_gtext(handle, x, y, "HH:MM:SS") przy zmianie sekundy,
           odswiezany tylko prostokat zegara (wzor EmuTOS). */
        (void)dum;
    }
    return 0;
}
