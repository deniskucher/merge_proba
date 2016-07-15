#include <stdio.h>
#include "uObjects.h"

//Вставка заголовочных файлов разделов задачи
#include "shu903.h"

void maincircle();

int main(int argc, char argv) {
  int res;
  //Инициализация объектов задачи
  InitObjects();

  //Загрузка данных из БД сигналов и конфигураций
  //...	

  maincircle();
}

void maincircle() {

  while (1) {
    /* Основное тело задачи*/
  _shu903();
  }
  
}

