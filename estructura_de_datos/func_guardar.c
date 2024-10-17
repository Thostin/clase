#include "dec_structs.h"

const static uint8_t cantidad_dias_meses[] = {31, 28, 31, 30, 31, 30,
                                              31, 31, 30, 31, 30, 31};

int verif_fecha_valida(struct Date fecha) {
  if (fecha.mes >= 12)
    return 0;

  if (fecha.anio < -5000 || fecha.anio > 2024)
    return 0;

  if (fecha.anio & 3 || fecha.dia != 29)
    if (fecha.dia >= cantidad_dias_meses[fecha.mes])
      return 0;

  return 1;
}
