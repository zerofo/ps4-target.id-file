#include "ps4.h"
#define ID "0x81"

int _main(struct thread *td) {
  UNUSED(td);

  initKernel();
  initLibc();

  jailbreak();
  int fd = open("/user/target.id",O_WRONLY | O_CREAT | O_TRUNC, 0777);
  write(fd, ID, 4);
  close(fd);

  initSysUtil();

  printf_notification("/user/target.id Created&Wrote by zerofo.");

  return 0;
}
