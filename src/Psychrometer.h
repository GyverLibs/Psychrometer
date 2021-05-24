/*
    Библиотека для определения влажности по сухому и мокрому термометру для Arduino
    Документация:
    GitHub: https://github.com/GyverLibs/Psychrometer
    Возможности:
    - Библиотека не привязана к термометру, принимает чисто температуру
    - Хитрая аппроксимация таблиц парциального давления
    - Возможность откалибровать постоянную психрометра
    
    AlexGyver, alex@alexgyver.ru
    https://alexgyver.ru/
    MIT License
    
    Основано на
    http://www.pogodaiklimat.ru/table.php
    https://alexgyver.ru/lessons/signal-encoding/

    Версии:
    v1.0 - релиз
*/

#ifndef Psychrometer_h
#define Psychrometer_h

#define _PSY_PGM
#ifdef AVR
#define _PSY_PGM PROGMEM
#endif

// разрешение таблицы
//static const int PTable[] _PSY_PGM = {19, 51, 125, 286, 611, 1277, 2337, 4243, 7377};  // step 10, size 9
static const int PTable[] _PSY_PGM = {19, 42, 88, 176, 335, 611, 1072, 1817, 2983, 4755, 7377};  // step 8, size 11
//static const int PTable[] _PSY_PGM = {19, 31, 51, 81, 125, 199, 286, 421, 611, 872, 1225, 1704, 2337, 3167, 4243, 5623, 7377}; // step 5, size 17

#define _PSY_STEP 8
#define _PSY_SIZE 11
#define _PSY_MIN -40
#define _PSY_MAX 40

class Psychrometer {
public:    
    // получить влажность из (темп. сух., темп. влажн.)
    float getHumidity(float dry, float wet) {
        return (getP(wet) - A * P * (dry - wet)) * 100.0 / getP(dry);
    }
    
    // калибровка А по (темп. сух., темп. влажн., реальная влажн.)
    float calibrate(float dry, float wet, float hum) {
        A = (getP(wet) - hum / 100.0 * getP(dry)) / P / (dry - wet);
        return A;
    }
    
    // установить давление (в Паскалях)
    void setP(long p) {
        P = p / 100L;   // перевод в ГПа
    }
    
    // установить давление (в мм. рт. ст.)
    void setPmm(float p) {
        P = p * 1.33322f;    // перевод в ГПа
    } 
    
    // установить постоянную психрометра  
    void setA(float a) {
        A = a;
    }
    
    // получить постоянную психрометра  
    float getA() {
        return A;
    }

private:
    float A = 0.0007947;
    int P = 1000;
    float getP(float signal) {
        signal = constrain(signal, _PSY_MIN, _PSY_MAX);
        int i = map(int(signal), _PSY_MIN, _PSY_MAX - _PSY_STEP, 0, _PSY_SIZE - 2);
        int thisMin = _PSY_STEP * i + _PSY_MIN;
        int thisMax = thisMin + _PSY_STEP;
        return map_f(signal, thisMin, thisMax, table(i), table(i + 1)) / 100.0f;
    }
    int table(int i) {
#ifdef AVR
        return pgm_read_word(&PTable[i]);
#else
        return PTable[i];
#endif
    }
    float map_f(float x, int in_min, int in_max, int out_min, int out_max) {
        return (float)(x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }
};
#endif