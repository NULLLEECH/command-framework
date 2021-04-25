// this file; cmdoptions.h will allow easy use of options without complex code

#ifndef CMDOPTIONS_H
#define CMDOPTIONS_H

// @for CMDBS_Arguments_t
#include "cmdutils.h"

// @for strcmp & strlen
#include <string.h>

/* @func CMDBS_GetShortOption
 *
 * expects the cmdbs argument structure
 * @param CMDBS_Args_t args
 *
 * expects a int position to check
 * @param int argc_pos
 * @invalid if not in argv
 *
 * expects a int sub position, -thischaracter->a<-thisone. allows long short arguments
 * @param int sub_pos
 * @invalid if not within argv or args substring
 *
 * returns the found character
 * @returns char
 *
 * if @invalid @returns char NUL (AKA {DEC 0, HEX 0, OCT 0 CODE, NULL})
 */
static inline char      CMDBS_GetShortOption    (CMDBS_Arguments_t args,
                                                int argc_pos,
                                                int sub_pos)
{
  if (args.argc < argc_pos)
    {
      return 0;
    }
  else
    {
      if (strlen(args.argv[argc_pos] >= sub_pos))
        {
          if (args.argv[argc_pos][0] == g_cmdbs_expected_prefix_char &&
             args.argv[argc_pos][sub_pos] != g_cmdbs_expected_prefix_char)
            return args.argv[argc_pos][sub_pos];
          else
            return 0;
        }
      else
        {
          return 0;
        }
    }
}

/* @func CMDBS_GetLongOption
 *
 * @see CMDBS_GetShortOption
 *
 * expects arguments for compasion
 * @param CMDBS_Arguments_t args
 *
 * expects a int position to check
 * @param int argc_pos
 * @invalid if not in argv
 *
 * expects a string from, includes two g_cmdbs_expected_prefix_char
 * @param const char *expected_string
 * @invalid if NULL or no prefix
 *
 * true if the expected string matches with the argv position elsewise false.
 * @returns _Bool
 *
 * if @invalid @returns char NUL
 */
static inline _Bool     CMDBS_GetLongOption     (CMDBS_Arguments_t args,
                                                int argc_pos,
                                                const char *expected_string)
{
  if (args.argc < argc_pos)
    {
      return 0;
    }
  else
    {
      if (strcmp(strcat("--",expected_string),args.argv[argc_pos]) == 0)
        return 1;
      else
        return 0;
    }
}

#endif /* CMDOPTIONS_H */
