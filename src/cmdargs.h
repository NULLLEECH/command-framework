#ifndef CMDARGS_H
#define CMDARGS_H

#include "cmdutils.h"

#include <ctype.h>
#include <stdlib.h>

typedef enum CMDBS_Arg_Mode
{
  CMDBS_ARGM_REAL,
  CMDBS_ARGM_REAL_FILE,
  CMDBS_ARGM_NUMBER,
  CMDBS_ARGM_TEXT
} CMDBS_Arg_Mode;

/* @func CMDBS_GetArg
 *
 * ensures that this is a valid argument
 *
 * @param CMDBS_Arguments_t args
 * @param int argc_pos
 *
 * @returns bool
 */

static inline _Bool     CMDBS_GetArg        (CMDBS_Arguments_t args,
                                            int argc_pos,
                                            CMDBS_Arg_Mode mode)
{
  if (args.argc < argc_pos)
    {
      return 0;
    }
  else
    {
      if (isalnum(args.argv[argc_pos]) != 0 &&
         args.argv[argc_pos][0] != '-')
        switch (mode)
          {
            case CMDBS_ARGM_REAL:
              if (isalnum(args.argv[argc_pos]) != 0)
                return 1;
              break;

            case CMDBS_ARGM_REAL_FILE:
              // checks if a file exists and if so returns true
              break;

            case CMDBS_ARGM_NUMBER:
              if (isdigit(args.argv[argc_pos]) != 0)
                return 1;
              break;

            case CMDBS_ARGM_TEXT:
              if (isalpha(args.argv[argc_pos]) != 0)
                return 1;
              break;

            default:
              abort();
              break;
          }
      else
        {
          return 0;
        }
    }
}

#endif /* CMDARGS_H */
