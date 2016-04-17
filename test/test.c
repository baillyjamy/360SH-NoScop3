/*
** test.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Feb 23 00:12:28 2016 antoine
** Last update Sat Apr 16 13:52:07 2016 Valentin Pichard
*/

#include <stdlib.h>
#include "test.h"

void            fail_impl(const char *position)
{
  egc_printf("%s: Test failed\n", position);
  STATS->failed_test_count++;
}

void            assert_impl(int a, const char *position)
{
  if (!a)
    fail_impl(position);
  STATS->total_test_count++;
}

int             main2()
{
  float         failure;
  t_test_stats  stats;

  stats.failed_test_count = 0;
  stats.total_test_count = 0;
  egc_set_statics(&stats, sizeof(t_test_stats));
  run_test_suites();
  egc_printf("%d tests, %d failures\n",
             stats.total_test_count,
             stats.failed_test_count);
  failure = stats.failed_test_count / (float)stats.total_test_count;
  if (failure > 0.5)
    return (1);
  else
    return (0);
}

int             main()
{
  return (egc_run(0, NULL, main2));
}
