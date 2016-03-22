/* !MODIFIED! */
/* source https://en.wikipedia.org/wiki/Getopt */

#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */

#include <ngetopt.h>
int main (int argc, argv_t argv) {
    int c;
    int digit_optind = 0;
    int aopt = 0, bopt = 0;
    const char *copt = 0, *dopt = 0;
    while ( (c = ngetopt(argc, argv, "-abc:d:012")) != -1) {
        int this_option_optind = noptind ? noptind : 1;
        switch (c) {
		case '-': goto end;
        case '0':
        case '1':
        case '2':
            if (digit_optind != 0 && digit_optind != this_option_optind)
              printf ("digits occur in two different argv-elements.\n");
            digit_optind = this_option_optind;
            printf ("option %c\n", c);
            break;
        case 'a':
            printf ("option a\n");
            aopt = 1;
            break;
        case 'b':
            printf ("option b\n");
            bopt = 1;
            break;
        case 'c':
            printf ("option c with value '%s'\n", noptarg);
            copt = noptarg;
            break;
        case 'd':
            printf ("option d with value '%s'\n", noptarg);
            dopt = noptarg;
            break;
        case '?':
            break;
        default:
            printf ("?? getopt returned character code 0%o ??\n", c);
        }
    }
	end:
	
    if (noptind < argc) {
        printf ("non-option ARGV-elements: ");
        while (noptind < argc)
            printf ("%s ", argv[noptind++]);
        printf ("\n");
    }
    exit (0);
}

