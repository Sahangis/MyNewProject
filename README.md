# **Vector klasės tyrimai**

## **Aprašymas**
Custom parašyta vektoriaus biblioteka skirta ankstesniomis vX.X versijomis

## **Failai**
Užduotį sudaro šie failai:
1. std.vector.version.cpp
2. Studentai.cpp
3. Studentai.h
4. vektorius.h
5. Makefile

## **1. Veikla**

Vektorius veikia(funkcionalumo prasme) lygiai taip pat kaip reikalavo ankstesnės versijos

## **2. Efektyvumo spartos analizė**

debug mode:

Duomenu apdorojimas su std vektoriais 0.0050553 s

Duomenu apdorojimas su std vektoriais 0.0491979 s

Duomenu apdorojimas su std vektoriais 0.481461 s

Duomenu apdorojimas su std vektoriais 4.79834 s

----------------------------------------------------------------------------------------------------------------------------
Duomenu apdorojimas su mano vektoriais 0.0010747 s

Duomenu apdorojimas su mano vektoriais 0.0087669 s

Duomenu apdorojimas su mano vektoriais 0.0934631 s

Duomenu apdorojimas su mano vektoriais 1.10637 s


išvada: mano vektoriai greitesni debug mode.

Release mode:

Duomenu apdorojimas su std vektoriais 0.0005667 s

Duomenu apdorojimas su std vektoriais 0.0037652 s

Duomenu apdorojimas su std vektoriais 0.0479241 s

Duomenu apdorojimas su std vektoriais 0.510285 s

Duomenu apdorojimas su mano vektoriais 0.0005755 s

Duomenu apdorojimas su mano vektoriais 0.0037873 s

Duomenu apdorojimas su mano vektoriais 0.052748 s

Duomenu apdorojimas su mano vektoriais 0.5714 s

išvada: std vektoriai greitesni release mode.


## **3 ir 4 punktai**

kompiuteris pradėjo kritinius memory errorus mėtyti. Duomenų failai tapo pernelyg dideli. Kadangi problemos nepavyko sutvarkyti ir errorai teigė jog kompiuteriui kilo rizika, nors kodas pagal idėją yra geras(be errorų ar warningų), nesugebėjau įgyvendinti likusių 3 ir 4 punktų.
 
---------------------------------------------------------------------------------------------------------------------------
Testavimams buvo naudojama:

   -CPU: AMD Ryzen 7 3800X 8-Core Processor (16 CPUs) ~3.9GHz
 
   -RAM: 32 Gb
 
   -SSD: 1 Tb (500 Gb x2)
