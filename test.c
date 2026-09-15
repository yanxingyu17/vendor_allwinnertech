#include <nuttx/config.h>
#include <stdio.h>

struct bmp280_dev_s
{
  int i2c_addr;
};

int bmp280_register(const char *devpath, struct bmp280_dev_s *priv)
{
  /* BUG1: nxsem_init used without including <nuttx/semaphore.h> */
  nxsem_init(&priv->devsem, 0, 1);

  /* BUG2: struct bmp280_dev_s has no member named 'freq' */
  priv->freq = CONFIG_BMP280_I2C_FREQUENCY;

  printf("bmp280 registered at %s\n", devpath);
  return 0;
}
