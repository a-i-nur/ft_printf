/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:02:53 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/18 18:14:05 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "../includes/ft_printf.h"
 
 static void	report_result(const char *label, int my, int org,
 			int *match, int *mismatch)
 {
 	if (my == org)
 	{
 		(*match)++;
 		printf("[OK] %s: ret=%d\n\n", label, my);
 	}
 	else
 	{
 		(*mismatch)++;
 		printf("[KO] %s: ft_ret=%d org_ret=%d\n\n", label, my, org);
 	}
 }
 
 int main(void)
 {
     int             my;
     int             org;
     int             i_loop;
     int             total_match;
     int             total_mismatch;

     char            c = 'A';
     char            c_zero = '\0';
     char            *s = "строка";
     char            *s_empty = "";
     char            *s_null = NULL;
     void            *p = s;
     void            *p_null = NULL;
     int             d_neg = -1234;
     int             d_zero = 0;
     int             d_pos = 5678;
     int             d_int_max = INT_MAX;
     int             d_int_min = INT_MIN;
     unsigned int    u_small = 42u;
     unsigned int    u_zero = 0u;
     unsigned int    u_big = 4000000000u;
     unsigned int    u_uint_max = UINT_MAX;
     unsigned int    x_val = 0xDEADBEEF;
     unsigned int    x_zero = 0u;
     unsigned int    x_small = 15u;
 
     total_match = 0;
     total_mismatch = 0;

    // 1. Basic mixed test from the example 
     printf("========== BASIC MIXED TEST ==========\n");
     my = ft_printf("ft : c=%c s=%s p=%p d=%d i=%i u=%u x=%x X=%X %%\n",
                    c, s, p, d_neg, d_pos, u_big, x_val, x_val);
     org = printf("org: c=%c s=%s p=%p d=%d i=%i u=%u x=%x X=%X %%\n",
                  c, s, p, d_neg, d_pos, u_big, x_val, x_val);
     report_result("BASIC MIXED", my, org, &total_match, &total_mismatch);

    // 2. %c — regular and null characters 
     printf("========== %%c TESTS ==========\n");
     my = ft_printf("ft : c='%c'\n", c);
     org = printf("org: c='%c'\n", c);
     report_result("%c normal", my, org, &total_match, &total_mismatch);

     my = ft_printf("ft : zero char[%c]\n", c_zero);
     org = printf("org: zero char[%c]\n", c_zero);
     report_result("%c zero-char", my, org, &total_match, &total_mismatch);

    // 3. %s — regular, empty, and NULL strings 
     printf("========== %%s TESTS ==========\n");
     my = ft_printf("ft : s=\"%s\"\n", s);
     org = printf("org: s=\"%s\"\n", s);
     report_result("%s regular", my, org, &total_match, &total_mismatch);

     my = ft_printf("ft : empty=\"%s\"\n", s_empty);
     org = printf("org: empty=\"%s\"\n", s_empty);
     report_result("%s empty", my, org, &total_match, &total_mismatch);

     my = ft_printf("ft : null=\"%s\"\n", s_null);
     org = printf("org: null=\"%s\"\n", s_null);
     report_result("%s NULL", my, org, &total_match, &total_mismatch);

    // 4. %p — regular, NULL, and odd pointer values 
     printf("========== %%p TESTS ==========\n");
     my = ft_printf("ft : p=%p\n", p);
     org = printf("org: p=%p\n", p);
     report_result("%p regular", my, org, &total_match, &total_mismatch);

     my = ft_printf("ft : p_null=%p\n", p_null);
     org = printf("org: p_null=%p\n", p_null);
     report_result("%p null", my, org, &total_match, &total_mismatch);

     my = ft_printf("ft : p_minus1=%p\n", (void *)-1);
     org = printf("org: p_minus1=%p\n", (void *)-1);
     report_result("%p -1", my, org, &total_match, &total_mismatch);

    // 5. %d and %i — various values including int boundaries 
     printf("========== %%d / %%i TESTS ==========\n");
     my = ft_printf("ft : d_zero=%d "
		"d_pos=%d d_neg=%d\n", d_zero, d_pos, d_neg);
     org = printf("org: d_zero=%d d_pos=%d d_neg=%d\n", d_zero, d_pos, d_neg);
     report_result("%d basic", my, org, &total_match, &total_mismatch);

     my = ft_printf("ft : INT_MAX=%d INT_MIN=%d\n", d_int_max, d_int_min);
     org = printf("org: INT_MAX=%d INT_MIN=%d\n", d_int_max, d_int_min);
     report_result("%d limits", my, org, &total_match, &total_mismatch);

     my = ft_printf("ft : i_zero=%i i_pos=%i "
		"i_neg=%i\n", d_zero, d_pos, d_neg);
     org = printf("org: i_zero=%i i_pos=%i i_neg=%i\n", d_zero, d_pos, d_neg);
     report_result("%i basic", my, org, &total_match, &total_mismatch);

    // 6. %u — 0, small, large, and UINT_MAX 
     printf("========== %%u TESTS ==========\n");
     my = ft_printf("ft : u_zero=%u u_small=%u\n", u_zero, u_small);
     org = printf("org: u_zero=%u u_small=%u\n", u_zero, u_small);
     report_result("%u small", my, org, &total_match, &total_mismatch);

     my = ft_printf("ft : u_big=%u UINT_MAX=%u\n", u_big, u_uint_max);
     org = printf("org: u_big=%u UINT_MAX=%u\n", u_big, u_uint_max);
     report_result("%u big", my, org, &total_match, &total_mismatch);

    // 7. %x and %X — 0, small, and large values 
     printf("========== %%x / %%X TESTS ==========\n");
     my = ft_printf("ft : x_zero=%x x_small=%x x_val=%x\n", x_zero, 
 		x_small, x_val);
     org = printf("org: x_zero=%x x_small=%x x_val=%x\n", x_zero, 
 		x_small, x_val);
     report_result("%x mix", my, org, &total_match, &total_mismatch);

     my = ft_printf("ft : X_zero=%X X_small=%X X_val=%X\n", x_zero, 
 		x_small, x_val);
     org = printf("org: X_zero=%X X_small=%X X_val=%X\n", x_zero, 
 		x_small, x_val);
     report_result("%X mix", my, org, &total_match, &total_mismatch);

    // 8. %% — check different percent placements 
     printf("========== %%%% TESTS ==========\n");
     my = ft_printf("ft : plain percent %%\n");
     org = printf("org: plain percent %%\n");
     report_result("%% single", my, org, &total_match, &total_mismatch);

     my = ft_printf("ft : mid %% of %% string\n");
     org = printf("org: mid %% of %% string\n");
     report_result("%% inside", my, org, &total_match, &total_mismatch);

     my = ft_printf("ft : multi %%%% blocks %%%% end\n");
     org = printf("org: multi %%%% blocks %%%% end\n");
     report_result("%% repeated", my, org, &total_match, &total_mismatch);

    // 9. Combined stress test in a single line 
     printf("========== COMBINED STRESS TEST ==========\n");
     my = ft_printf("ft : c=%c s=%s null_s=%s p=%p p0=%p d=%d "
       "i=%i u=%u x=%x X=%X %% int_max=%d int_min=%d uint_max=%u\n",
                    c, s, s_null, p, p_null,
                    d_neg, d_pos, u_big, x_val, x_val,
                    d_int_max, d_int_min, u_uint_max);
     org = printf("org: c=%c s=%s null_s=%s p=%p p0=%p d=%d i=%i u=%u "
       "x=%x X=%X %% int_max=%d int_min=%d uint_max=%u\n",
                  c, s, s_null, p, p_null,
                  d_neg, d_pos, u_big, x_val, x_val,
                  d_int_max, d_int_min, u_uint_max);
     report_result("Combined stress", my, org, &total_match, &total_mismatch);

    // 10. NULL format 
     printf("========== TEST 10: NULL FORMAT ==========\n");
     printf("ft : calling ft_printf(NULL)...\n");
     my = ft_printf(NULL);
     printf("ret: ft=%d\n", my);
     printf("org: calling printf(NULL)...\n");
     org = printf(NULL);
     printf("ret: org=%d\n", org);
     report_result("NULL format", my, org, &total_match, &total_mismatch);
     printf("\n");

    // 11. Leak-focus loop with delay 
     printf("========== TEST 11: LEAK LOOP ==========\n");
     i_loop = 0;
     while (i_loop < 5)
     {
         my = ft_printf("ft : loop=%d ptr=%p str=%s\n", i_loop, p, s);
         org = printf("org: loop=%d ptr=%p str=%s\n", i_loop, p, s);
         {
             char label[32];

             snprintf(label, sizeof(label), "Leak loop %d", i_loop);
             report_result(label, my, org, &total_match, &total_mismatch);
         }
         usleep(100000);
         i_loop++;
     }
     printf("\nLeak loop finished.\n");

     printf("========== SUMMARY ==========\n");
     printf("Matched: %d\n", total_match);
     printf("Mismatched: %d\n", total_mismatch);
     if (total_mismatch == 0)
         printf("All tests reported matching return values.\n");
     else
         printf("Some tests differ — investigate mismatches above.\n");

     return 0;
 }
*/
