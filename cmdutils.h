// this file; cmdutils.h, will sumerize needed structures and other small things

#ifndef CMDUTILS_H
#define CMDUTILS_H

// global to handle strange prefix (if you wish)
static char g_cmdbs_expected_prefix_char = '-';

/* @struct CMDBS_Arguments_t
 *
 * basic struture to sum up args
 *
 * @part int argc
 * @part char **argv
 */
typedef struct CMDBS_Arguments_t
{
  int argc; // matches the main.c standard argc name
  char **argv; // identical to 'char *argv[]'
} CMDBS_Arguments_t, CMDBS_Args_t;

#endif /* CMDUTILS_H */
