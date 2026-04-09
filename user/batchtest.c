#include "kernel/types.h"
#include "kernel/param.h"
#include "user/user.h"

int
main(void)
{
  char small[] = "abc";
  char large[80];
  int i;

  write(1, "batchtest start\n", 16);

  write(1, small, 3);
  write(1, small, 3);
  write(1, small, 3);
  write(1, "\n", 1);

  for(i = 0; i < sizeof(large); i++)
    large[i] = 'X';

  for(i = 0; i < 350; i++)
    write(1, small, 3);

  write(1, large, sizeof(large));
  write(1, "\n", 1);
  write(1, "batchtest done\n", 15);

  exit(0);
}
